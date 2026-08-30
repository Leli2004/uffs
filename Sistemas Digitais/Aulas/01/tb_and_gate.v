// iverilog -o and_gate_sim and_gate.v tb_and_gate.v
// vvp and_gate_sim

module tb_and_gate;

reg a, b;
wire s;

and_gate test1(a, b, s);

initial begin

    $monitor("a = %b | b = %b | s = %b", a, b, s);

    a=0;
    b=0;
    #10; // esperar 10 unidades de tempo

    a = 0;
    b = 1;
    #10;

    a = 1;
    b = 0;
    #10;

    a = 1;
    b = 1;
    #10;

    $finish;

end

endmodule