
module fsm(
    input clk,
    input inicio, // inicia a multiplicacao 
    input rst, // reset
    input [9:0] va, // valor do reg. selecionado em sel_ra
    input [9:0] vb, // valor do reg. selecionado em sel_rb
    input z, //flag zero da ula
    input c, // flag carry da ula

    output reg escreve, // escreve=1 habilita escrita
    output reg [2:0] sel_ra, // endereço do reg de leitura a
    output reg [2:0] sel_rb, // endereço do reg de leitura b
    output reg [2:0] sel_rw, // endereço do reg de escrita
    output reg [2:0] sel_op, // operação da ula
    output reg mux_w_sel, // seleção do multiplexador, ula ou ext_w
    output reg [9:0] ext_w, // valor externo pra escrita no banco de registradores
    output reg finalizou // finalizou=1 indica que a multiplicacao terminou
);

    // defin os possiveis estados
    localparam [3:0] s0 = 4'b0000; // espera
    localparam [3:0] s1 = 4'b0001; // inicializacao
    localparam [3:0] s2 = 4'b0010; // verifica q0
    localparam [3:0] s3 = 4'b0011; // a = a + m
    localparam [3:0] s4 = 4'b0100; // q >> 1 e Qn = a0
    localparam [3:0] s5 = 4'b0101; // a >> 1
    localparam [3:0] s6 = 4'b0110; // verifica contador
    localparam [3:0] s7 = 4'b0111; // espera antes de escrever q
    localparam [3:0] s8 = 4'b1000; // espera antes de escrever a

    // estado atual e proximo estado da fsm 
    reg [3:0] state, next_state;

    reg [3:0] contador; // contador de iteracoes
    reg carry_reg; // guarda o carry da soma, pra deslocar A
    localparam [3:0] n = 4'd10; // qtd de bits = 10

    // registrador de estado
    always @(posedge clk) begin
        if (rst) begin
            state <= s0;
        end else begin
            state <= next_state;
        end
    end

    // logica de proximo estado
    always @(*) begin
        next_state = state; // default

        case(state)
            // agaurda inicio = 1
            s0: if (inicio) begin
                    next_state = s1;
                end

            // inicializacao
            s1: next_state = s2;

            // verifica q0
            s2: if (vb[0] == 1'b1) begin
                    next_state = s3;
                end else begin
                    next_state = s7;
                end

            // a = a + m
            s3: next_state = s7;

            // espera antes de escrever q
            s7: next_state = s4;

            // q >> 1
            s4: next_state = s8;

            // espera antes de escrever a
            s8: next_state = s5;

            // a >> 1
            s5: next_state = s6;

            // verifica contador
            s6: if (contador < n-1) begin
                    next_state = s2;
                end else begin 
                    if (!inicio) next_state = s0;
                end

            default: next_state = s0;

        endcase
    end


    // contador e carry
    always @(posedge clk) begin
        if (rst) begin // zera contador e carry
            contador <= 4'd0;
            carry_reg <= 1'b0;
        end

        else begin
            // reiinicia contador e carry
            if (state == s1) begin
                contador <= 4'd0;
                carry_reg <= 1'b0;
            end
            // guarda o carry da soma
            else if (state == s3) begin
                carry_reg <= c;
            end
            // incrementa contador
            else if (state == s6 && contador < n) begin
                contador <= contador + 1'b1;
            end

        end
    end

    // logica de saida
    always @(*) begin
        // valores padrao
        escreve = 1'b0; // nao escreve
        sel_ra = 3'd0; // r0 = a
        sel_rb = 3'd0; // r0 = b
        sel_rw = 3'd0; // r0 para escrita
        sel_op = 3'b011; // operacao de soma
        mux_w_sel = 1'b0; // usa saida da ula
        ext_w = 10'd0; // dado externo zerado
        finalizou = 1'b0; // não finalizou

        case(state)
            // s0: aguarda inicio = 1
            s0: begin
            end

            // s1: a = 0
            s1: begin
                sel_rw = 3'd2; // r2 para escrita
                mux_w_sel = 1'b1; // usa dado externo
                ext_w = 10'd0; // a = 0
                escreve = 1'b1; // escreve em r2
            end

            // s2: verifica q0
            s2: begin
                sel_rb = 3'd1; // q = r1
            end

            // s3: a = a + m
            s3: begin
                sel_ra = 3'd2; // a = r2
                sel_rb = 3'd0; // m = r0
                sel_rw = 3'd2; // r2 para escrita
                sel_op = 3'b011; // operação de soma
                mux_w_sel = 1'b0; // usa saida da ULA
                escreve = 1'b1; // escreve em sel_rw
            end

            // s7: espera e seta escreve = 0
            s7: begin
                escreve = 1'b0;
            end

            // s4: q >> 1 e Qn = a0
            s4: begin
                sel_ra = 3'd2; // a = r2
                sel_rb = 3'd1; // q = r1
                sel_rw = 3'd1; // r1 para escrita
                mux_w_sel = 1'b1; // usa dado externo
                ext_w = {va[0], vb[9:1]}; // q >> 1 e Q9 = a0
                escreve = 1'b1; // escreve
            end

            // s8: espera e seta escreve = 0
            s8: begin
                escreve = 1'b0;
            end

            // s5: a >> 1
            s5: begin
                sel_ra = 3'd2; // a = r2
                sel_rw = 3'd2; // r2 para escrita
                mux_w_sel = 1'b1; // usa dado externo
                ext_w = {carry_reg, va[9:1]}; // a >> 1 e a9 = carry
                escreve = 1'b1; // escreve
            end

            // s6: verifica o contador
            s6: begin
                if (contador >= n) // se >= n, finalizou = 1
                    finalizou = 1'b1;
            end

        endcase
    end

endmodule

