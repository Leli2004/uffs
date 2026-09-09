
module main(
	input [7:0] SW,
	output reg [4:0] LEDR // reg por ser usado dentro do always
);

// usando always
always @(*) begin 
	LEDR = SW[3:0] + SW[7:4];
end

// ou usando assign
// assign LEDR = SW[3:0] + SW[7:4];

endmodule