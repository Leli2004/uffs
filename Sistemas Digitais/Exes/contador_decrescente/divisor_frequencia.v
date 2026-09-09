
module divisor_frequencia #(parameter CLK_FREQ = 50_000_000) (
	input clk,
	output reg clk_out = 1'b0
);

reg [31:0] counter = 32'd0;

always @(posedge clk) begin
	if (counter >= CLK_FREQ ) begin
	counter <= 0;
	clk_out = ~clk_out;
	end else begin
	counter <= counter + 1;
	end
end

endmodule
