
module atividade(
	input wire [3:0] KEY,
	output  wire [6:0] HEX0,
	input wire CLOCK_50); 
	
	wire clock_out;
	wire [3:0] contador_out;
	
	divisor_frequencia df (.clk(CLOCK_50), .clk_out(clock_out));
	contador4 cont4 (.clk(clock_out), .rstn(KEY[0]), .out(contador_out));
	hex_to_7seg hex7 (.hex_val(contador_out), .seg(HEX0));
	
endmodule
