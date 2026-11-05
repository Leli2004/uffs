
// desenvolvido

module top();

datapath d(
    .clk(clk),
    .escreve(escreve),
    .sel_ra(sel_ra),
    .sel_rb(sel_rb),
    .sel_rw(sel_rw),
    .sel_op(sel_op),
    .mux_w_sel(mux_w_sel),
    .ext_w(ext_w),
    .va(va),
    .vb(vb),
    .s(s),
    .z(Z),
    .c(C)
);

assign resultado = s;

endmodule;