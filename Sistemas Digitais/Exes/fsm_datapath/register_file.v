// Banco de Registradores: 8 registradores de 10 bits
module register_file (
    input  wire        clk,
    input  wire        escreve,       // Escrita na borda de subida
    input  wire [2:0]  sel_ra,        // Seleção do registrador A (leitura)
    input  wire [2:0]  sel_rb,        // Seleção do registrador B (leitura)
    input  wire [2:0]  sel_rw,        // Seleção do registrador a escrever
    input  wire [9:0]  vw,            // Valor a escrever
    output wire [9:0]  va,            // Saída do registrador A
    output wire [9:0]  vb             // Saída do registrador B
);

    reg [9:0] regs [0:7];   // 8 registradores de 10 bits

    integer i;
    initial begin
        regs[0] = 10'd0; // contador
        regs[1] = 10'd10; // N = 10
        regs[2] = 10'd3; // Q = 3
        regs[3] = 10'd5; // M = 5
        regs[4] = 10'd0; // A = 0
        regs[5] = 10'd1; // constante 1
        regs[6] = 10'd0;
        regs[7] = 10'd0;

        // for (i = 0; i < 8; i = i + 1) 
        //     regs[i] = 10'd0;
        //     regs[1] = 10'd5; //M
        //     regs[2] = 10'd4; //Q
        //     regs[4] = 10'd10; //N
        //     regs[5] = 10'b0000000001;
        //     regs[6] = 10'b1000000000;  
    end

    // Escrita síncrona na borda de subida de 'escreve'
    always @(posedge clk) begin
        if(escreve)
            regs[sel_rw] <= vw;
    end

    // Leitura combinacional
    assign va = regs[sel_ra];
    assign vb = regs[sel_rb];

endmodule