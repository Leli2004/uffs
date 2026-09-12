`timescale 1ns/1ps

module tb_somador_completo;

    // Sinais aplicados ao DUT
    reg a, b, cin;

    // Sinais de saida do DUT
    wire s, cout;

    // Valores esperados (modelo de referencia)
    reg s_esperado, cout_esperado;

    // Contadores de resultado
    integer testes = 0;
    integer erros  = 0;

    // Instancia do DUT (Device Under Test)
    somador_completo DUT (
        .a    (a),
        .b    (b),
        .cin  (cin),
        .s    (s),
        .cout (cout)
    );

    // Task que aplica um vetor de teste, calcula o valor esperado
    // e compara com a saida real do DUT, reportando PASS ou FAIL
    task aplicar_teste;
        input t_a, t_b, t_cin;
        begin
            a   = t_a;
            b   = t_b;
            cin = t_cin;
            #10; // aguarda a propagacao da logica combinacional

            // Modelo de referencia (calculado de forma independente do DUT)
            s_esperado    = t_a ^ t_b ^ t_cin;
            cout_esperado = (t_a & t_b) | (t_cin & (t_a ^ t_b));

            testes = testes + 1;

            if ((s === s_esperado) && (cout === cout_esperado)) begin
                $display("PASS [%0d] a=%b b=%b cin=%b -> s=%b cout=%b (esperado s=%b cout=%b)",
                          testes, a, b, cin, s, cout, s_esperado, cout_esperado);
            end else begin
                erros = erros + 1;
                $display("FAIL [%0d] a=%b b=%b cin=%b -> s=%b cout=%b (esperado s=%b cout=%b)  <<< ERRO DETECTADO",
                          testes, a, b, cin, s, cout, s_esperado, cout_esperado);
            end
        end
    endtask

    initial begin
        $display("==================================================");
        $display(" Testbench: somador_completo");
        $display(" Testando todas as 8 combinacoes de a, b, cin");
        $display("==================================================");

        // Cobertura exaustiva: todas as combinacoes possiveis de 1 bit
        aplicar_teste(1'b0, 1'b0, 1'b0);
        aplicar_teste(1'b0, 1'b0, 1'b1);
        aplicar_teste(1'b0, 1'b1, 1'b0);
        aplicar_teste(1'b0, 1'b1, 1'b1);
        aplicar_teste(1'b1, 1'b0, 1'b0);
        aplicar_teste(1'b1, 1'b0, 1'b1);
        aplicar_teste(1'b1, 1'b1, 1'b0);
        aplicar_teste(1'b1, 1'b1, 1'b1);

        $display("==================================================");
        if (erros == 0) begin
            $display(" SUCESSO: todos os %0d testes passaram.", testes);
        end else begin
            $display(" FALHA: %0d de %0d testes falharam.", erros, testes);
        end
        $display("==================================================");

        $finish;
    end

    // Dump de ondas (opcional, util para depuracao em GTKWave)
    initial begin
        $dumpfile("tb_somador_completo.vcd");
        $dumpvars(0, tb_somador_completo);
    end

endmodule
