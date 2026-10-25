
// iverilog -o tb_fsm tb_fsm.v fsm.v 
// vvp tb_fsm

module tb_fsm;
  integer testes = 0;
  integer erros  = 0;
  
  reg clk;
  reg dir;
  reg rst;  
  wire [2:0] z;

  reg [2:0] z_esperado;
  
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
    input [2:0] t_z_esperado;
    
    begin
      @(negedge clk);
      rst = t_rst;
      dir = t_dir;
      
      @(posedge clk);
      #1;
      
      testes = testes + 1;

      if(z === t_z_esperado) begin
        $display("PASSOU: rst=%b, dir=%b", rst, dir);
      end else begin
        erros = erros + 1;
        $display("FALHOU: rst=%b, dir=%b", rst, dir);
      end
    end
  endtask;
  
  initial begin
    rst = 1'b1;
    dir = 1'b0;

    @(posedge clk);
    #1;
    
    aplicar_teste(1'b0, 1'b1, 3'b000);
    aplicar_teste(1'b0, 1'b1, 3'b000);
    aplicar_teste(1'b1, 1'b0, 3'b110);
    aplicar_teste(1'b1, 1'b0, 3'b101);
    
    $display("================================================");
    if (erros == 0) begin
    	$display("SUCESSO: todos os %0d testes passaram.", testes);
  	end else begin
    	$display("FALHA: %0d de %0d testes falharam.", erros, testes);
  	end
    
    $finish;
  end
  
endmodule;
