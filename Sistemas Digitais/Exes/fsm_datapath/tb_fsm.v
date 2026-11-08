
// iverilog -o tb_fsm_sim tb_fsm.v fsm.v 
// vvp tb_fsm_sim

module tb_fsm;
    // Entradas da FSM
    reg clk;
    reg reset;
    reg inicio;
    reg transicao;

    reg [9:0] va;
    reg [9:0] vb;
    reg z;
    reg c;
    reg [9:0] SW;

    // Saidas da FSM
    wire escreve;
    wire [2:0] sel_ra;
    wire [2:0] sel_rb;
    wire [2:0] sel_rw;
    wire [2:0] sel_op;
    wire [9:0] ext_w;
    wire mux_w_sel;
    wire [3:0] estado;

    // dut da FSM
    fsm uut (
        .clk(clk),
        .reset(reset),
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

    // simula clock
    always #5 clk = ~clk;

    // simula pressionamento de key[0]
    task avancar;
        begin
            @(negedge clk);
            transicao = 1;

            @(posedge clk);
            #1;
            transicao = 0;

            $display("estado = %b | escreve = %b | RA = %b | RB = %b | RW = %b | OP = %b",
                estado, escreve, sel_ra, sel_rb, sel_rw, sel_op);
        end
    endtask

    initial begin
        // valores iniciais
        clk = 0;
        reset = 0;
        inicio = 0;
        transicao = 0;
        va = 0;
        vb = 0;
        z = 0;
        c = 0;
        SW = 0;

        // INICIA TESTES

        $display("\n**********************************************");
        $display("\nTESTE 1: AGUARDANDO INICIO");
        // inicio continua em zero => FSM deve permanecer em s0

        reset = 1;
        #2;
        reset = 0;

        avancar();
        avancar();
        
        $display("\n**********************************************");
        $display("\nTESTE 2: EXECUTANDO ESTADOS");
        // percorrer estados a cada transicao de KEY[0] pressionado, com inicio=1

        reset = 1;
        #2;
        reset = 0;

        inicio = 1;

        // s0 -> s1
        avancar();

        // s1 -> s2 (contador diferente de N)
        z = 0;
        avancar();

        // s2 -> s3 (Q[0] = 0)
        va = 10'b0000000000;
        avancar();

        // s3 -> s4
        avancar();

        // s4 -> s5
        avancar();

        // s5 -> s6 (A[0] = 0)
        va = 10'b0000000000;
        avancar();

        // s6 -> s7
        va = 10'b0000001101;
        avancar();

        // s7 -> s8
        avancar();

        // s8 -> s1
        avancar();

        $display("\n===== FIM DOS TESTES =====");
        $finish;
    end

endmodule
