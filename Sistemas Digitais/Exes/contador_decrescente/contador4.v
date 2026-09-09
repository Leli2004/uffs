
module contador4 (
    input clk, 
    input rstn, 
    output reg[3:0] out
);

always @ (posedge clk or negedge rstn) begin
	if (!rstn)
	    out <= 4'b1111; // reset começa em F (15)
	else if (out > 0)
	    out <= out - 1;
end

endmodule
