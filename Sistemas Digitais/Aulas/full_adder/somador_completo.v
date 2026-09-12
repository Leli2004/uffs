
module somador_completo (
    input a,
    input b,
    input cin,
    output s,
    output cout
);
    // Lógica da soma
    assign s = a ^ b ^ cin;
    // Lógica do transporte de saída (Carry Out)
  assign cout = (a & ~b) | (cin & (a ^ b));
endmodule
