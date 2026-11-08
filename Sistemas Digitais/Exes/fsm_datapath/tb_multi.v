// iverilog -o tb_multi_sim tb_multi.v multi.v fsm.v ula.v register_file.v datapath.v bin10_to_7seg.v
// vvp tb_multi_sim

// Os valores de A e B a serem multiplicados devem estar entre 17 e 31
// KEY[0] = habilita transicao de estados da fsm => a cada clique chama proximo estado
// KEY[1] = habilita reset
// KEY[2] = habilita o início da multiplicacao => só começa multiplicar quando inicio=1
// SW = entrada de 10 bits
// resultado = resultado da multiplicação

module tb_multi;
    reg clk = 0;
    reg [3:0] KEY;
    reg [9:0] SW;

    wire [19:0] resultado;
    wire [6:0] HEX0, HEX1, HEX2, HEX3;

    reg [9:0] s_esperado;

    integer testes = 0;
    integer erros = 0;

    always #5 clk = ~clk;

    multi dut (
        .CLOCK_50(clk),
        .KEY(KEY),
        .SW(SW),
        .HEX0(HEX0),
        .HEX1(HEX1),
        .HEX2(HEX2),
        .HEX3(HEX3),
        .resultado(resultado)
    );

    // Simula um clique em KEY[0]
    task avanca_estado;
        begin
            @(negedge clk);
            KEY[0] = 0;

            @(posedge clk);
            #1;
            KEY[0] = 1;

            #1;
        end
    endtask;

    task multiplicar;
        input [19:0] s_esperado;
        input integer qtd_estados;
        
        integer i;

        begin
            // reset
            KEY[1] = 0;
            #10;
            KEY[1] = 1;

            // inicio
            KEY[2] = 0;
            avanca_estado();
            KEY[2] = 1;

            // Avança os estados da FSM
            for (i = 0; i < qtd_estados; i = i + 1)
                avanca_estado();
            
            testes = testes + 1;

            if (resultado === s_esperado) begin
                $display("PASSOU: Esperado=%b | Obtido=%b", s_esperado, resultado);
            end else begin 
                erros = erros + 1;
                $display("FALHOU: Esperado=%b | Obtido=%b", s_esperado, resultado);
            end
        end
    endtask;

    initial begin
        KEY = 4'b0000;
        SW = 10'd0;

        @(posedge clk);
        #1;

        $display("\n************************* Início dos testes *************************\n");

        // resultado esperado de acordo com valores inicializados no register_file
        multiplicar(20'd15, 100);

        $display("\n*************************** Fim dos testes ***************************");
        $finish;
    end

endmodule
