// iverilog -o tb_atividade_sim tb_atividade.v atividade.v contador4.v divisor_frequencia.v hex_to_7seg.v
// vvp tb_atividade_sim

module tb_atividade;

    // ---------------------------------------------------------------
    // Sinais de estímulo / observação
    // ---------------------------------------------------------------
    reg  [3:0] KEY;        // KEY[0] = reset ativo em nível baixo
    wire [6:0] HEX0;
    reg        CLOCK_50;

    integer erros = 0;
    integer i;

    // ---------------------------------------------------------------
    // Instancia o DUT (Device Under Test)
    // ---------------------------------------------------------------
    atividade uut (
        .KEY(KEY),
        .HEX0(HEX0),
        .CLOCK_50(CLOCK_50)
    );

    // ---------------------------------------------------------------
    // Reduz CLK_FREQ do divisor interno só para a simulação.
    // Caminho hierárquico: uut (atividade) -> df (divisor_frequencia)
    // Assim clk_out alterna a cada poucos ciclos de CLOCK_50,
    // em vez de a cada 50 milhões.
    // ---------------------------------------------------------------
    defparam uut.df.CLK_FREQ = 4;

    // ---------------------------------------------------------------
    // Geração do clock de 50 MHz (período 20 ns só de referência,
    // a escala real não importa pois CLK_FREQ foi reduzido acima)
    // ---------------------------------------------------------------
    initial CLOCK_50 = 0;
    always #10 CLOCK_50 = ~CLOCK_50;

    // ---------------------------------------------------------------
    // Tabela esperada de segmentos (mesma lógica de hex_to_7seg.v)
    // ---------------------------------------------------------------
    function [6:0] seg_esperado;
        input [3:0] valor;
        begin
            case (valor)
                4'h0: seg_esperado = 7'b1000000;
                4'h1: seg_esperado = 7'b1111001;
                4'h2: seg_esperado = 7'b0100100;
                4'h3: seg_esperado = 7'b0110000;
                4'h4: seg_esperado = 7'b0011001;
                4'h5: seg_esperado = 7'b0010010;
                4'h6: seg_esperado = 7'b0000010;
                4'h7: seg_esperado = 7'b1111000;
                4'h8: seg_esperado = 7'b0000000;
                4'h9: seg_esperado = 7'b0000100;
                4'hA: seg_esperado = 7'b0001000;
                4'hB: seg_esperado = 7'b0000011;
                4'hC: seg_esperado = 7'b1000110;
                4'hD: seg_esperado = 7'b0100001;
                4'hE: seg_esperado = 7'b0000110;
                4'hF: seg_esperado = 7'b0001110;
                default: seg_esperado = 7'b1111111;
            endcase
        end
    endfunction

    // ---------------------------------------------------------------
    // Task auxiliar: espera uma borda de subida de clk_out interno
    // ---------------------------------------------------------------
    task espera_borda_contador;
        begin
            @(posedge uut.clock_out);
        end
    endtask

    // ---------------------------------------------------------------
    // Verificação self-checking
    // ---------------------------------------------------------------
    task verifica (input [3:0] valor_esperado_contador);
        reg [6:0] esperado_hex;
        begin
            esperado_hex = seg_esperado(valor_esperado_contador);
            if (uut.contador_out !== valor_esperado_contador) begin
                $display("[ERRO] t=%0t | contador_out=%h esperado=%h",
                          $time, uut.contador_out, valor_esperado_contador);
                erros = erros + 1;
            end
            if (HEX0 !== esperado_hex) begin
                $display("[ERRO] t=%0t | HEX0=%b esperado=%b (valor=%h)",
                          $time, HEX0, esperado_hex, valor_esperado_contador);
                erros = erros + 1;
            end
        end
    endtask

    // ---------------------------------------------------------------
    // Sequência principal de testes
    // ---------------------------------------------------------------
    initial begin
        // 1) Aplica reset (KEY[0] = 0 é reset ativo baixo)
        KEY = 4'b0000;
        repeat (5) @(posedge CLOCK_50);
        verifica(4'hF); // após reset, contador deve estar em F
        $display("[OK] Reset -> contador em F, HEX0 = %b", HEX0);

        // 2) Libera o reset (KEY[0] = 1) e observa a contagem regressiva
        KEY[0] = 1'b1;

        for (i = 15; i >= 1; i = i - 1) begin
            espera_borda_contador;   // espera a borda de subida de clk_out
            #1;                      // pequena folga para os regs atualizarem
            verifica(i[3:0] - 1'b1);
        end

        $display("[OK] Contagem regressiva de F ate 0 conferida");

        // 3) Garante que o contador trava em 0 (não tem underflow p/ F de novo)
        for (i = 0; i < 4; i = i + 1) begin
            espera_borda_contador;
            #1;
            verifica(4'h0);
        end
        $display("[OK] Contador permanece em 0 apos chegar ao fim");

        // 4) Testa reset assíncrono no meio da contagem
        repeat (2) @(posedge CLOCK_50);
        KEY[0] = 1'b0;   // aciona reset
        #1;
        verifica(4'hF);
        $display("[OK] Reset assincrono no meio da contagem volta para F");
        KEY[0] = 1'b1;

        // ---------------------------------------------------------
        // Resultado final
        // ---------------------------------------------------------
        if (erros == 0)
            $display("\n==== TESTBENCH PASSOU: nenhum erro encontrado ====");
        else
            $display("\n==== TESTBENCH FALHOU: %0d erro(s) encontrado(s) ====", erros);

        $finish;
    end

    // Timeout de segurança
    initial begin
        #100000;
        $display("[ERRO] Timeout: simulacao nao terminou a tempo");
        $finish;
    end

endmodule
