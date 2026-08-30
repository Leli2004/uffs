// iverilog -o tb_full_adder_sim full_adder.v tb_full_adder.v
// vvp tb_full_adder_sim

module tb_full_adder;

reg a, b, cin;
wire s, cout;

full_adder test1(a, b, cin, s, cout);

initial begin

    $monitor("a=%b b=%b cin=%b | s=%b cout=%b", a, b, cin, s, cout);

    a = 0;
    b = 0;
    cin = 0;
    #10;

    a = 0;
    b = 0;
    cin = 1;
    #10;

    a = 0;
    b = 1;
    cin = 0;
    #10;

    a = 0;
    b = 1;
    cin = 1;
    #10;

    a = 1;
    b = 0;
    cin = 0;
    #10;

    a = 1;
    b = 0;
    cin = 1;
    #10;

    a = 1;
    b = 1;
    cin = 0;
    #10;

    a = 1;
    b = 1;
    cin = 1;
    #10;

    $finish;

end

endmodule
