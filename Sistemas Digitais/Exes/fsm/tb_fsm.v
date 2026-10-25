
// iverilog -o tb_fsm tb_fsm.v fsm.v 
// vvp tb_fsm

module tb_fsm;
  integer testes = 0;
  integer erros  = 0;
  
  reg clk;
  reg dir;
  reg rst;  
  wire [2:0] z;
  
  initial clk = 0; 
  always #5 clk = ~clk; 
  
  fsm dut (
  	.clk(clk),
    .dir(dir),
    .rst(rst),
    .z(z)
  );
  
  task aplicar_teste;
    input t_dir;
    input t_rst;
    
    begin
      @(negedge clk);
      rst = t_rst;
      dir = t_dir;
      #10;
      
      @(posedge clk);
      #5;
      
      testes = testes + 1;
      
      $monitor("TESTE: rst=%b, dir=%b", rst, dir);
    end
  endtask;
  
  initial begin
    aplicar_teste(1'b0, 1'b0);
    aplicar_teste(1'b0, 1'b1);
    aplicar_teste(1'b1, 1'b0);
    aplicar_teste(1'b1, 1'b1);
    
    $display("================================================");
    if (erros == 0) begin
    	$display("SUCESSO: todos os %0d testes passaram.", testes);
  	end else begin
    	$display("FALHA: %0d de %0d testes falharam.", erros, testes);
  	end
    
    $finish;
  end
  
endmodule;
