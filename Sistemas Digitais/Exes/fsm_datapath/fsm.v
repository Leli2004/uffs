
module fsm (
    // entradas
    input wire clk,
    input wire reset,
    input wire inicio, // inicia a multiplicacao 
    input wire transicao, // sinal de transicao do clock manual

    // informações do datapath
    input wire [9:0] va,
    input wire [9:0] vb,
    input wire z, //flag zero da ula
    input wire c, // flag carry da ula

    // entrada externa
    input wire [9:0] SW,

    // saidas
    output reg escreve,  // escreve=1 habilita escrita
    output reg [2:0] sel_ra, // endereço do reg de leitura a
    output reg [2:0] sel_rb, // endereço do reg de leitura b
    output reg [2:0] sel_rw,  // endereço do reg de escrita
    output reg [2:0] sel_op, // operação da ula
    output reg [9:0] ext_w, // valor externo pra escrita
    output reg mux_w_sel,  // seleção do multiplexador: saida da ula ou ext_w
    output reg [3:0] estado // usado sometne no tb
);

    // define os possiveis estados
    localparam [3:0] s0 = 4'b0000; // verifica inicio
    localparam [3:0] s1 = 4'b0001; // verifica contador 
    localparam [3:0] s2 = 4'b0010; // verifica q0
    localparam [3:0] s3 = 4'b0011; // A = A + M
    localparam [3:0] s4 = 4'b0100; // Q = Q >> 1
    localparam [3:0] s5 = 4'b0101; // verifica A[0]
    localparam [3:0] s6 = 4'b0110; // Q = Q + 1000000000
    localparam [3:0] s7 = 4'b0111; // A = A >> 1
    localparam [3:0] s8 = 4'b1000; // contador++
    localparam [3:0] s_final = 4'b1001; // finalizou a multiplicacao

    // define os endereços dos registradores e oq será guardado
    // endereços com valores foram inicializados em register_file
    localparam [2:0] endereco_contador = 3'b000; // contador = R0
    localparam [2:0] endereco_N = 3'b001; // N = R1
    localparam [2:0] endereco_Q = 3'b010; // Q = R2
    localparam [2:0] endereco_M = 3'b011; // M = R3
    localparam [2:0] endereco_A = 3'b100; // A = R4
    localparam [2:0] constante_um = 3'b101; // constante 1
	localparam [2:0] endereco_soma = 3'b110; // r6 = 1000000000

    // estado atual e proximo estado da fsm 
    reg [3:0] state, next_state;

    // registrador de estado
    always @(posedge clk or posedge reset) begin
        if (reset)
            state <= s0;
        else if (transicao) 
            state <= next_state;
    end

    // logica de proximo estado
    always @(*) begin
        case (state)
            s0:      next_state = inicio ? s1 : s0; // se inicio=1 vai pra s1 
            s1:      next_state = z ? s_final : s2; // se n=contador (subtracao deu zero) vai pra s_final, senao vai pra s2
            s2:      next_state = z ? s4 : s3; // se q[0]=1 soma em s3, se nao vai pra s4   
            s3:      next_state = s4; // soma A = A + M e vai pra s4
            s4:      next_state = s5; // shift Q e vai pra s5
            s5:      next_state = z ? s7 : s6; // se A[0]=1 vai pra s6, senao vai pra s7 
            s6:      next_state = s7; // coloca 1 no bit mais significativo e vai pra s7
            s7:      next_state = s8; // desloca A e vai pra s8
            s8:      next_state = s1; // contador++ e volta pra s1                 
            s_final: next_state = s_final; // permanece sm s_final            
        endcase
    end

    // logica de saida
    always @(*) begin
        // instanciar valores padrao
        escreve = 0;
        sel_ra = 3'b000;
        sel_rb = 3'b000;
        sel_rw = 3'b000;
        sel_op = 3'b000;
        mux_w_sel = 0;
        ext_w = SW;

        // logica de transição de estado
        case(state)
            // s0: aguarda inicio = 1
            s0: begin
                estado = s0;
            end

            // s1: compara contador com n, com va=contador e vb=n
            s1: begin
                estado = s1;
                sel_ra = endereco_contador;
                sel_rb = endereco_N;
                sel_op = 3'b110; // subtracao
            end

            // s2: verifica Q[0] em va
            s2: begin
                estado = s2;
                sel_ra = endereco_Q;
                sel_rb = constante_um;
                sel_op = 3'b100; // and 
            end

            // s3: A = A + M
            s3: begin
                estado = s3;
                sel_ra = endereco_A;
                sel_rb = endereco_M;
                sel_rw = endereco_A;
                sel_op = 3'b011; // soma
                escreve = 1'b1;
            end

            // s4: Q = Q >> 1
            s4: begin
                estado = s4;
                sel_ra = endereco_Q;
                sel_rb = constante_um;
                sel_rw = endereco_Q;
                sel_op = 3'b010; // shift pra direita
                escreve = 1'b1;
            end

            // s5: verifica A[0]
            s5: begin
                estado = s5;
                sel_ra = endereco_A;
                sel_rb = constante_um;
                sel_op = 3'b100; // and 
            end

            // s6: Q = Q + 1000000000 ou seja, Q[9] = 1
            s6: begin
                estado = s6;
                sel_ra = endereco_Q;
                sel_rb = endereco_soma;
                sel_rw = endereco_Q;
                sel_op = 3'b011; // soma
                mux_w_sel = 1'b0;
                //mux_w_sel = 1'b0; // usa dado externo
                //ext_w = {1'b1, va[8:0]}; // coloca 1 no inicio e usa os 9 bits menos significativos de Q
                escreve = 1'b1;
            end
            
            // s7: A = A >> 1
            s7: begin
                estado = s7;
                sel_ra = endereco_A;
                sel_rb = constante_um;
                sel_rw = endereco_A;
                sel_op = 3'b010; // shift pra direita
                escreve = 1'b1;
            end

            // s8: contador++
            s8: begin
                estado = s8;
                sel_ra = endereco_contador;
                sel_rb = constante_um;
                sel_rw = endereco_contador;
                sel_op = 3'b011; // soma
                mux_w_sel = 1'b0; // usa resultado da ula
                escreve = 1'b1;
            end

            // s_final: acabou a multiplicação
            s_final: begin
                estado = s_final;
                        
                sel_ra = endereco_Q;
                sel_rb = constante_um;
                sel_op = 3'b000; // multiplicacao
            end

        endcase
    end

endmodule
