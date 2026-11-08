// ============================================================================
// bin10_to_7seg
// Converte um número binário de 10 bits (0..1023) para 4 displays de
// 7 segmentos (milhar, centena, dezena, unidade).
//
// Formato dos segmentos: seg = {g, f, e, d, c, b, a}
//
//        a
//      -----
//   f |     | b
//     |  g  |
//      -----
//   e |     | c
//     |     |
//      -----
//        d
//
// Parâmetros:
//   ACTIVE_LOW = 1 -> segmento aceso com '0' (anodo comum, ex.: DE10-Lite/DE2)
//   ACTIVE_LOW = 0 -> segmento aceso com '1' (catodo comum)
//   BLANK_ZEROS = 1 -> apaga zeros à esquerda (ex.: "  42" em vez de "0042")
// ============================================================================
module bin10_to_7seg #(
    parameter ACTIVE_LOW  = 1,
    parameter BLANK_ZEROS = 0
)(
    input  wire [9:0] bin,
    output wire [6:0] hex0,   // unidades
    output wire [6:0] hex1,   // dezenas
    output wire [6:0] hex2,   // centenas
    output wire [6:0] hex3    // milhar
);

    // ------------------------------------------------------------------
    // Binário -> BCD (algoritmo double dabble / shift-add-3), combinacional
    // ------------------------------------------------------------------
    reg [15:0] bcd;
    integer i;

    always @(*) begin
        bcd = 16'd0;
        for (i = 9; i >= 0; i = i - 1) begin
            // soma 3 a cada dígito >= 5 antes do deslocamento
            if (bcd[3:0]   >= 5) bcd[3:0]   = bcd[3:0]   + 4'd3;
            if (bcd[7:4]   >= 5) bcd[7:4]   = bcd[7:4]   + 4'd3;
            if (bcd[11:8]  >= 5) bcd[11:8]  = bcd[11:8]  + 4'd3;
            if (bcd[15:12] >= 5) bcd[15:12] = bcd[15:12] + 4'd3;
            bcd = {bcd[14:0], bin[i]};
        end
    end

    wire [3:0] d0 = bcd[3:0];
    wire [3:0] d1 = bcd[7:4];
    wire [3:0] d2 = bcd[11:8];
    wire [3:0] d3 = bcd[15:12];

    // ------------------------------------------------------------------
    // Apagamento de zeros à esquerda (opcional)
    // ------------------------------------------------------------------
    wire blank3 = BLANK_ZEROS && (d3 == 0);
    wire blank2 = blank3 && (d2 == 0);
    wire blank1 = blank2 && (d1 == 0);
    // a unidade nunca é apagada (o número 0 mostra "0")

    // ------------------------------------------------------------------
    // Decodificadores
    // ------------------------------------------------------------------
    seg7_decoder #(.ACTIVE_LOW(ACTIVE_LOW)) u0 (.digit(d0), .blank(1'b0),  .seg(hex0));
    seg7_decoder #(.ACTIVE_LOW(ACTIVE_LOW)) u1 (.digit(d1), .blank(blank1), .seg(hex1));
    seg7_decoder #(.ACTIVE_LOW(ACTIVE_LOW)) u2 (.digit(d2), .blank(blank2), .seg(hex2));
    seg7_decoder #(.ACTIVE_LOW(ACTIVE_LOW)) u3 (.digit(d3), .blank(blank3), .seg(hex3));

endmodule


// ============================================================================
// seg7_decoder: um dígito BCD (0..9) -> 7 segmentos {g,f,e,d,c,b,a}
// ============================================================================
module seg7_decoder #(
    parameter ACTIVE_LOW = 1
)(
    input  wire [3:0] digit,
    input  wire       blank,
    output wire [6:0] seg
);
    reg [6:0] s;   // lógica positiva: 1 = segmento aceso

    always @(*) begin
        if (blank)
            s = 7'b000_0000;
        else case (digit)
            //            gfedcba
            4'd0: s = 7'b0111111;
            4'd1: s = 7'b0000110;
            4'd2: s = 7'b1011011;
            4'd3: s = 7'b1001111;
            4'd4: s = 7'b1100110;
            4'd5: s = 7'b1101101;
            4'd6: s = 7'b1111101;
            4'd7: s = 7'b0000111;
            4'd8: s = 7'b1111111;
            4'd9: s = 7'b1101111;
            default: s = 7'b1000000; // "-" para valores inválidos
        endcase
    end

    assign seg = ACTIVE_LOW ? ~s : s;
endmodule