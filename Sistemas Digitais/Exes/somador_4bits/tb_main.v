// iverilog -o tb_main_sim main.v tb_main.v
// vvp tb_main_sim

module tb_main;

reg [7:0] SW;
wire [4:0] LEDR;

main test1(SW, LEDR);

initial begin

    $monitor("SW = %b | A = %b | B = %b | LEDR = %b", SW, SW[3:0], SW[7:4], LEDR);
    
    // A = 0, B = 0
    SW = 8'b0000_0000;
    #10;

    // A = 1, B = 2
    SW = 8'b0010_0001; // 0010 + 0001 = 00011
    #10;

    // A = 5, B = 3
    SW = 8'b0011_0101;
    #10;

    // A = 7, B = 8
    SW = 8'b1000_0111;
    #10;

    // A = 15, B = 15
    SW = 8'b1111_1111;
    #10;

    $finish;

end

endmodule;