
module contador4 (
    input clk, 
    input rstn, 
    output [3:0] out
);

reg[3:0] temp;

always @ (posedge clk or negedge rstn) begin
	if (!rstn)
	    temp <= 4'b1111; // reset começa em F (15)
	else if (temp > 0)
	    temp <= temp - 1;
end

assign out = temp;

endmodule
