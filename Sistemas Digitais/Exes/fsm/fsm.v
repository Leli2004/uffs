
// Atividade: fazer a máquina de estados finitos em Verilog

module fsm(
  input clk, dir, rst,
  output reg [2:0] z
);
  
  localparam [2:0] s0 = 3'b000;
  localparam [2:0] s1 = 3'b001;
  localparam [2:0] s2 = 3'b010;
  localparam [2:0] s3 = 3'b011;
  localparam [2:0] s4 = 3'b100;
  localparam [2:0] s5 = 3'b101;
  localparam [2:0] s6 = 3'b110;
  localparam [2:0] s7 = 3'b111;
  
  reg [2:0] state, next_state;
  
  // (1) registrador de estado
  always @(posedge clk) begin
    if(rst) begin
      state <= s0;
    end else begin
      state <= next_state;
     end
  end
  
  // (2) lógica de próximo estado
  always @(*) begin
    next_state = state;
    
    case(state)
      s0: next_state = s1;
      s1: next_state = s2;
      s2: next_state = s3;
      s3: next_state = s4;
      s4: next_state = s5;
      s5: next_state = s6;
      s6: next_state = s7;
      s7: next_state = s0;
    endcase
  end
  
  // (3) lógica de saída (Moore)
  always @(*) begin
    z = 3'b000;
    
    case(state)
      s0: z = dir ? 3'b111 : 3'b000;
      s1: z = dir ? 3'b110 : 3'b001;
      s2: z = dir ? 3'b101 : 3'b011;
      s3: z = dir ? 3'b100 : 3'b010;
      s4: z = dir ? 3'b011 : 3'b110;
      s5: z = dir ? 3'b010 : 3'b111;
      s6: z = dir ? 3'b001 : 3'b101;
      s7: z = dir ? 3'b000 : 3'b100;
    endcase
  end
  
endmodule
