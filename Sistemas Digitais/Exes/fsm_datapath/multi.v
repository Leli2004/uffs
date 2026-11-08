module multi(
   // entradas da placa
   input wire CLOCK_50, 
   input wire [3:0] KEY, // KEY[0]=comando de transicao fsm, KEY[1]=reset, KEY[2]=inicio da multiplicacao
   input wire [9:0] SW, // entrada de 10 bits

   // saidas para display
   output wire [6:0] HEX0, 
   output wire [6:0] HEX1, 
   output wire [6:0] HEX2, 
   output wire [6:0] HEX3,

   // saida para teste
   output wire [19:0] resultado 
);

// sinais internos de entrada
wire clk = CLOCK_50; // clock
wire transicao = ~KEY[0]; // 1 habilita transicao de estado da fsm
wire rst = ~KEY[1]; // reset
wire inicio = ~KEY[2]; // habilita a multiplicacao
wire [3:0] estado; // usado somente no tb

// sinais de controle da fsm para o datapath
wire escreve; // 1 habilita escrita
wire [2:0] sel_ra, sel_rb, sel_rw; // endereços dos registradores de leitura e escrita
wire [2:0] sel_op; // seleciona operação da ula
wire mux_w_sel; // seleciona entre ula e ext_w
wire [9:0] ext_w; // valor externo pra escrita

// outputs do datapath
wire [9:0] va, vb; // valores dos registradores de leitura
wire [9:0] s; // saida da ula
wire z; // flag zero da ula
wire c; // flag carry da ula

// instancia do fsm
fsm f (
   .clk(clk),
   .reset(rst),
   .inicio(inicio),
   .transicao(transicao),
   .va(va),
   .vb(vb),
   .z(z),
   .c(c),
   .SW(SW),
   .escreve(escreve),
   .sel_ra(sel_ra),
   .sel_rb(sel_rb),
   .sel_rw(sel_rw),
   .sel_op(sel_op),
   .ext_w(ext_w),
   .mux_w_sel(mux_w_sel),
   .estado(estado)
);

// habilita escrita se a fsm estiver no estado de escrita e o key[0] estiver habilitado
wire deve_escrever = escreve & transicao;

// instancia do datapath
datapath d (
   .clk(clk),
   .escreve(deve_escrever),
   .sel_ra(sel_ra),
   .sel_rb(sel_rb),
   .sel_rw(sel_rw),
   .sel_op(sel_op),
   .mux_w_sel(mux_w_sel),
   .ext_w(ext_w),
   .va(va),
   .vb(vb),
   .s(s),
   .z(z),
   .c(c),
   .resultado(resultado)
);

// instancia do conversor para display
bin10_to_7seg b (
   .bin(s),
   .hex0(HEX0),
   .hex1(HEX1),
   .hex2(HEX2),
   .hex3(HEX3)
);

endmodule
