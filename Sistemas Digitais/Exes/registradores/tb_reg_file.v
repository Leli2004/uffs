// iverilog -o tb_reg_file_sim tb_reg_file.v reg_file.v 
// vvp tb_reg_file_sim

module tb_reg_file;
  
  // Sinais aplicados ao DUT
  reg clk; 
  reg rst_n;
  reg we;
  reg [2:0] w_addr;
  reg [15:0] w_data;
  reg [2:0] r_addr_a; 
  reg [2:0] r_addr_b;
  
  // Sinais de saida do DUT
  wire [15:0] r_data_a; 
  wire [15:0] r_data_b;

  // Valores de saída esperados (modelo de referencia)
  reg [15:0] r_data_a_esperado;
  reg [15:0] r_data_b_esperado;

  // Contadores de resultado
  integer testes = 0;
  integer erros  = 0;
  integer i, j; // contador para loop

  // Geração do ciclo de clock
  initial clk = 0; 
  always #5 clk = ~clk; // ocorre a cada 5 ns

  // Modelo de referencia para os testes (registradores)
  reg [15:0] modelo [0:7];

  // Variáveis para cenário 10 com random
  integer k;
  integer valor_aleatorio;
  reg [2:0] addr_rand;
  reg [15:0] data_rand;
  reg [15:0] ultimo_valor;

  // Implementa lógica com base na lógica do DUT para gerar os valores esperados 
  always @(posedge clk) begin
    if(!rst_n) begin
        modelo[0] <= 16'b0;
        modelo[1] <= 16'b0;
        modelo[2] <= 16'b0;
        modelo[3] <= 16'b0;
        modelo[4] <= 16'b0;
        modelo[5] <= 16'b0;
        modelo[6] <= 16'b0;
        modelo[7] <= 16'b0;
    end else if (we) begin
        modelo[w_addr] <= w_data;
    end
  end

  // Instancia do DUT (Device Under Test)
  reg_file dut (
    .clk(clk),
    .rst_n(rst_n),
    .we(we),
    .w_addr(w_addr),
    .w_data(w_data),
    .r_addr_a(r_addr_a),
    .r_addr_b(r_addr_b),
    .r_data_a(r_data_a),
    .r_data_b(r_data_b)
    );
    
  // Task que aplica um vetor de teste, calcula o valor esperado
  // e compara com a saida real do DUT, reportando PASS ou FAIL
  task aplicar_teste;
    input [3:0] t_cenario; // qual cenário está sendo testado
    input t_rst_n;
    input t_we;
    input [2:0] t_w_addr;
    input [2:0] t_r_addr_a; 
    input [2:0] t_r_addr_b;
    input [15:0] t_w_data;

    begin

        @(negedge clk); 
        rst_n = t_rst_n;
        we = t_we;
        w_addr = t_w_addr;
        w_data = t_w_data;
        r_addr_a = t_r_addr_a;
        r_addr_b = t_r_addr_b;
        #10; // aguarda a propagacao da logica combinacional

        @(posedge clk); 
        #1; // aguarda a propagacao da logica sequencial

        // Modelo de referencia (calculado de forma independente do DUT)
        r_data_a_esperado = modelo[t_r_addr_a];
        r_data_b_esperado = modelo[t_r_addr_b];

        testes = testes + 1;

        if ((r_data_a === r_data_a_esperado) && (r_data_b === r_data_b_esperado)) 
            begin
                $display("PASS [Teste %0d | Cenário %0d] clk=%b rst_n=%b, we=%b, w_addr=%b, w_data=%h, r_addr_a=%b, r_addr_b=%b -> r_data_a=%h, r_data_b=%h, (esperado r_data_a=%h, r_data_b=%h)",
                        testes,t_cenario, clk, rst_n, we, w_addr, w_data,
                        r_addr_a, r_addr_b, r_data_a, r_data_b,
                        r_data_a_esperado, r_data_b_esperado);
            end else begin
                erros = erros + 1;
                $display("FAIL [Teste %0d | Cenário %0d] clk=%b rst_n=%b, we=%b, w_addr=%b, w_data=%h, r_addr_a=%b, r_addr_b=%b -> r_data_a=%h, r_data_b=%h, (esperado r_data_a=%h, r_data_b=%h)  <<< ERRO DETECTADO",
                        testes,t_cenario, clk, rst_n, we, w_addr, w_data,
                        r_addr_a, r_addr_b, r_data_a, r_data_b,
                        r_data_a_esperado, r_data_b_esperado); 
            end
    end
    
  endtask

  // Usada para cobrir cenário de teste 8 -> pré clock
  task aplicar_teste_pre_clk;
    input [3:0] t_cenario; // qual cenário está sendo testado
    input t_rst_n;
    input t_we;
    input [2:0] t_w_addr;
    input [2:0] t_r_addr_a; 
    input [2:0] t_r_addr_b;
    input [15:0] t_w_data;

    begin

        @(negedge clk); 
        rst_n = t_rst_n;
        we = t_we;
        w_addr = t_w_addr;
        w_data = t_w_data;
        r_addr_a = t_r_addr_a;
        r_addr_b = t_r_addr_b;
        #1; // só o suficiente para a leitura combinacional se estabilizar, SEM cruzar a borda de subida

        // Modelo de referencia
        r_data_a_esperado = modelo[t_r_addr_a];
        r_data_b_esperado = modelo[t_r_addr_b];

        testes = testes + 1;

        if ((r_data_a === r_data_a_esperado) && (r_data_b === r_data_b_esperado)) 
            begin
                $display("PASS [Teste %0d | Cenário %0d] clk=%b rst_n=%b, we=%b, w_addr=%b, w_data=%h, r_addr_a=%b, r_addr_b=%b -> r_data_a=%h, r_data_b=%h, (esperado r_data_a=%h, r_data_b=%h)",
                        testes,t_cenario, clk, rst_n, we, w_addr, w_data,
                        r_addr_a, r_addr_b, r_data_a, r_data_b,
                        r_data_a_esperado, r_data_b_esperado);
            end else begin
                erros = erros + 1;
                $display("FAIL [Teste %0d | Cenário %0d] clk=%b rst_n=%b, we=%b, w_addr=%b, w_data=%h, r_addr_a=%b, r_addr_b=%b -> r_data_a=%h, r_data_b=%h, (esperado r_data_a=%h, r_data_b=%h)  <<< ERRO DETECTADO",
                        testes,t_cenario, clk, rst_n, we, w_addr, w_data,
                        r_addr_a, r_addr_b, r_data_a, r_data_b,
                        r_data_a_esperado, r_data_b_esperado); 
            end

            @(posedge clk); // deixa a borda passar DEPOIS de já ter comparado, para não acumular atraso na simulação
            #1; // aguarda a propagacao da logica sequencial
    end

  endtask

  // Aplicar os testes e reportar resultados
  initial begin
    $display("==================================================");
    $display(" Testbench: Registradores");
    $display("==================================================");
    
    // Cobertura dos casos de teste:
    
    /***********************************************************/
    /// 1) Reset síncrono => Todos os regs = 0x0000
    aplicar_teste(
        4'd1, // cenário 1
        1'b0, // t_rst_n=0
        1'b0, // t_we=0
        3'd0, // t_w_addr=000
        3'd0, // t_r_addr_a=000
        3'd1, // t_r_addr_b=001
        16'h0 // t_w_data=0
    );

    /***********************************************************/
    /// 2) Escrita em R0 => R0 = 0xDEAD após clock
    aplicar_teste(
        4'd2, // cenário 2
        1'b1, // t_rst_n=1
        1'b1, // t_we=1
        3'd0, // t_w_addr=000
        3'd0, // t_r_addr_a=000
        3'd7, // t_r_addr_b=111
        16'hDEAD // t_w_data=DEAD
    );

    /***********************************************************/
    /// 3) Escrita em R7 => R7 = 0xBEEF após clock
    aplicar_teste(
        4'd3, // cenário 3
        1'b1, // t_rst_n=1
        1'b1, // t_we=1
        3'd7, // t_w_addr=111
        3'd0, // t_r_addr_a=000
        3'd7, // t_r_addr_b=111
        16'hBEEF // t_w_data=BEEF
    );

    /***********************************************************/
    /// 4) Leitura A=R0, B=R7 => r_data_a=0xDEAD, r_data_b=0xBEEF
    aplicar_teste(
        4'd4, // cenário 4
        1'b1, // t_rst_n=1
        1'b0, // t_we=0
        3'd0, // t_w_addr=000
        3'd0, // t_r_addr_a=000
        3'd7, // t_r_addr_b=111
        16'h0 // t_w_data=0
    );

    /***********************************************************/
    /// 5) Escrita em todos => Cada reg com valor distinto
    for (i=0; i<8; i=i+1) begin
        aplicar_teste(
            4'd5, // cenário 5
            1'b1, // t_rst_n=1
            1'b1, // t_we=1
            i[2:0], // t_w_addr = i
            i[2:0], // t_r_addr_a = i (confere o que acabou de escrever)
            (i === 0) ? 3'd7 : i-1, // t_r_addr_b = registrador anterior (confere que não foi sobrescrito)
            16'h1000 + i // t_w_data = usar o i pra gerar um valor distinto pra cada registrador
        );
    end

    /***********************************************************/
    /// 6) Leitura simultânea A=Ri, B=Rj => Ambas portas corretas
    aplicar_teste(
        4'd6, // cenário 6
        1'b1, // t_rst_n=1
        1'b0, // t_we=0
        3'd0, // t_w_addr=000
        3'd2, // t_r_addr_a=010
        3'd5, // t_r_addr_b=101
        16'h0 // t_w_data=0
    );
    
    /***********************************************************/
    /// 7) we=0: tentativa de escrita => R2 não muda
    aplicar_teste( // escreve novo valor conhecido em R2
        4'd7, // cenário 7
        1'b1, // t_rst_n=1
        1'b1, // t_we=1
        3'd2, // t_w_addr=010
        3'd0, // t_r_addr_a=000
        3'd0, // t_r_addr_b=000
        16'h0015 // t_w_data=15
    );
    aplicar_teste( // tenta sobrescrever com we=0, já lê R2 no mesmo passo pra conferir que não mudou
        4'd7, // cenário 7
        1'b1, // t_rst_n=1
        1'b0, // t_we=0
        3'd2, // t_w_addr=010
        3'd2, // t_r_addr_a=010
        3'd0, // t_r_addr_b=000
        16'h0 // t_w_data=0
    );

    /***********************************************************/
    /// 8) Leitura/escrita mesmo endereço Porta lê val_antigo (antes do clock)
    aplicar_teste_pre_clk( // escreve novo valor conhecido em R3, lê R3 e R0 no mesmo passo, antes do clock, pra conferir que ainda lê o valor antigo de R3
        4'd8, // cenário 8
        1'b1, // t_rst_n=1
        1'b1, // t_we=1
        3'd3, // t_w_addr=011
        3'd3, // t_r_addr_a=011
        3'd0, // t_r_addr_b=000
        16'h0001 // t_w_data=1
    );

    /***********************************************************/
    /// 9) Reset durante operação => Todos zerados
    for (i = 0; i < 8; i = i + 2) begin // compara em duplas com leitura A e B
        j = i + 1;
        aplicar_teste(
            4'd9, // cenário 9
            1'b0, // t_rst_n=0
            1'b0, // t_we=0
            3'd0, // t_w_addr=000
            i[2:0], // t_r_addr_a = i
            j[2:0], // t_r_addr_b = i+1
            16'h0 // t_w_data=0
        );
    end

    /***********************************************************/
    /// 10) Endereços variáveis com $random => Verificar consistência escrita/leitura
    for (k = 0; k < 10; k = k + 1) begin
        valor_aleatorio = $random;
        addr_rand = valor_aleatorio[2:0]; // 3 bits menos significativos para endereços de 0 a 7
        data_rand = valor_aleatorio[15:0]; // 16 bits menos significativos

        aplicar_teste (
            4'd10, // cenário 10
            1'b1, // t_rst_n=1
            1'b1, // t_we=1
            addr_rand, // t_w_addr = endereço aleatório
            addr_rand, // t_r_addr_a = mesmo endereço para ler o que acabou de escrever
            3'd0, // t_r_addr_b = 0
            data_rand // t_w_data = valor aleatório
        );
    end

    for (k = 0; k < 5; k = k + 1) begin
        valor_aleatorio = $random;
        ultimo_valor = valor_aleatorio[15:0]; // 16 bits menos significativos
        
        aplicar_teste (
            4'd10, // cenário 10
            1'b1, // t_rst_n=1
            1'b1, // t_we=1
            3'd4, // t_w_addr = endereço fixo escolhido para esse teste
            3'd0, // t_r_addr_a=000
            3'd0, // t_r_addr_b=000
            ultimo_valor // t_w_data = valor aleatório
        );
    end

    aplicar_teste (
        4'd10, // cenário 10
        1'b1, // t_rst_n=1
        1'b0, // t_we=0
        3'd0, // t_w_addr=000
        3'd4, // t_r_addr_a = mesmo endereço fixo escolhido para esse teste
        3'd0, // t_r_addr_b=000
        16'h0 // t_w_data=0
    );

    /***********************************************************/

    $display("==================================================");
    
    if (erros == 0) begin
            $display(" SUCESSO: todos os %0d testes passaram.", testes);
        end else begin
            $display(" FALHA: %0d de %0d testes falharam.", erros, testes);
        end
    
    $display("==================================================");
    
    $finish;
    
  end
  
//   // Opcional: gerar ondas para visualização/conferência
//   initial begin 
//     $dumpfile("tb_reg_file.vcd"); 
//     $dumpvars(0, tb_reg_file);
//   end
  
endmodule
