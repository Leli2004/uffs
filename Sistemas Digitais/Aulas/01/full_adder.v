
module full_adder(
    input a, b, cin,
    output s, cout
);

assign s = a ^ b ^ cin;
assign cout = (a & b) | (cin & (a ^ b));

endmodule

module half_adder (
    input a, b,
    output s, cout
);

assign s = a ^ b; // XOR
assign cout = a & b; // AND

endmodule