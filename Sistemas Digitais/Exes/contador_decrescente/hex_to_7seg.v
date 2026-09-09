
module hex_to_7seg (input wire [3:0] hex_val, output reg [6:0] seg);

always @(*) begin
case (hex_val)
4'b0000 : seg = 7'b1000000; // Exibe 0
4'b0001 : seg = 7'b1111001; // Exibe 1
4'b0010 : seg = 7'b0100100; // Exibe 2
4'b0011 : seg = 7'b0110000; // Exibe 3
4'b0100 : seg = 7'b0011001; // Exibe 4
4'b0101 : seg = 7'b0010010; // Exibe 5
4'b0110 : seg = 7'b0000010; // Exibe 6
4'b0111 : seg = 7'b1111000; // Exibe 7
4'b1000 : seg = 7'b0000000; // Exibe 8
4'b1001 : seg = 7'b0000100; // Exibe 9
4'b1010 : seg = 7'b0001000; // Exibe A
4'b1011 : seg = 7'b0000011; // Exibe b
4'b1100 : seg = 7'b1000110; // Exibe C
4'b1101 : seg = 7'b0100001; // Exibe d
4'b1110 : seg = 7'b0000110; // Exibe E
4'b1111 : seg = 7'b0001110; // Exibe F
default : seg = 7'b1111111; // Desliga todos os segmentos
endcase
end
endmodule
