
// iverilog -o tb_piso4_sim tb_piso4.v piso4.v 
// vvp tb_piso4_sim

module tb_piso4;
  integer testes = 0;
  integer erros  = 0;
  
  // sinais aplicados ao DUT
  reg clk;
  reg reset;
  reg shift;
  reg [3:0] d;
  
  // sinais de saída do DUT
  wire [3:0] q;
  wire serial_out;
  
  // saídas esperadas
  reg [3:0] q_esperado;
  reg serial_out_esperado;
  
  // sinal do clock
  initial clk = 0; 
  always #5 clk = ~clk; // ocorre a cada 5 ms
  
  // simula comportamento do module
  reg [3:0] regs;
  always @(posedge clk) begin
    if(reset) begin
      regs[0] <= 4'b0;
      regs[1] <= 4'b0;
      regs[2] <= 4'b0;
      regs[3] <= 4'b0;
    end else begin
      if(shift) begin
        regs[3] <= regs[2];
        regs[2] <= regs[1];
        regs[1] <= regs[0];
        regs[0] <= d[0];
      end else begin
        regs[0] <= d[0];
        regs[1] <= d[1];
        regs[2] <= d[2];
        regs[3] <= d[3];
      end
    end
  end
  
  // instancia o DUT
  piso4 dut (
    .clk(clk),
    .reset(reset),
    .shift(shift),
    .d(d),
    .q(q),
    .serial_out(serial_out)
  );
  
  // cria a task
  task aplicar_teste;
  	input t_reset;
  	input t_shift;
    input [3:0] t_d;
    
    begin
      
      @(negedge clk);
      reset = t_reset;
      shift = t_shift;
      d = t_d;
      #10; // aguarda
      
      @(posedge clk);
      #1;
      
      q_esperado = regs;
      serial_out_esperado = regs[3];

      testes = testes + 1;
      
      if(q === q_esperado && serial_out === serial_out_esperado) begin
        $monitor("PASSOU: reset=%b, shift=%b, d=%h", reset, shift, d);
      end else begin
        erros = erros + 1;
        $monitor("FALHOU: reset=%b, shift=%b, d=%h", reset, shift, d);
      end
    end
    
  endtask
 
  // chama o teste
  initial begin
    aplicar_teste(0, 0, 4'b0000);
    aplicar_teste(0, 0, 4'b1111);
    aplicar_teste(0, 1, 4'b0000);
    aplicar_teste(1, 0, 4'b0101);
   
    $display("================================================");
    if (erros == 0) begin
    $display("SUCESSO: todos os %0d testes passaram.", testes);
  end else begin
    $display("FALHA: %0d de %0d testes falharam.", erros, testes);
  end
    
    $finish;
  end
  
endmodule
