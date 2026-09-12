
module reg_file (
    input clk, // Clock principal (borda de subida)
    input rst_n, // Reset síncrono ativo em nível baixo
    input we, // Write Enable
    input [2:0] w_addr, // Endereço do registrador a ser escrito
    input [15:0] w_data, // Dado a ser escrito
    input [2:0] r_addr_a, // Endereço do registrador lido na porta A
    input [2:0] r_addr_b, // Endereço do registrador lido na porta B
    output [15:0] r_data_a, // Dado lido na porta A
    output [15:0] r_data_b // Dado lido na porta B
);

reg [15:0] regs [0:7];

always @(posedge clk) begin
    if (!rst_n) begin
        regs[0] <= 16'b0; // 16 bits zerado 
        regs[1] <= 16'b0;
        regs[2] <= 16'b0;
        regs[3] <= 16'b0;
        regs[4] <= 16'b0;
        regs[5] <= 16'b0;
        regs[6] <= 16'b0;
        regs[7] <= 16'b0;
    end else if (we) begin
        regs[w_addr] <= w_data; // não bloqueante
    end
end

assign r_data_a = regs[r_addr_a];
assign r_data_b = regs[r_addr_b];

endmodule
