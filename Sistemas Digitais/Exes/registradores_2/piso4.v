

module piso4 (
  input clk,
  input reset,
  input shift, // 0 = carga paralela , 1 = deslocamento
  input [3:0] d , // d [3:0] = D3 D2 D1 D0
  output [3:0] q , // q [3:0] = Q3 Q2 Q1 Q0
  output serial_out // = q[3]
);
  
  reg [3:0] regs;
  
  always @(posedge clk) begin
    if(reset) begin
      // zera todas as saidas
      regs[0] <= 4'b0;
      regs[1] <= 4'b0;
      regs[2] <= 4'b0;
      regs[3] <= 4'b0;
    end else begin
      // shift 1: Deslocamento
      // shift 0: Carga paralela
      
      if(shift) begin
        // Q3 ← Q2, Q2 ← Q1, Q1 ← Q0
        regs[3] <= regs[2];
        regs[2] <= regs[1];
        regs[1] <= regs[0];
        regs[0] <= d[0];
      end else begin
        //  Qi ← Di para i = 0,...,3
        regs[0] <= d[0];
        regs[1] <= d[1];
        regs[2] <= d[2];
        regs[3] <= d[3];
      end
    end
  end
  
  assign q = regs;
  assign serial_out = regs[3];
  
endmodule
