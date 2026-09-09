
### TAREFA: Contador Decrescente em Verilog

#### Objetivo
O objetivo da atividade consiste no desenvolvimento de um sistema digital
síncrono para contagem decrescente no intervalo hexadecimal de F a 0. A transição
de estados do contador deve ser controlada por um clock interno do FPGA. O valor
corrente do contador deve ser exibido nos displays de sete segmentos (HEX) da
FPGA. A cada borda de subida do sinal do relógio, caso o valor atual seja superior a
0, o sistema deve decrementar o estado em uma unidade (ex.: F → E → D → ... →
0).

#### Estrutura dos modules
```
module atividade (Módulo Top-Level)
├── divisor_frequencia (Instância do divisor de clock)
├── contador4 (Instância do contador)
└── hex_to_7seg (Instância do decodificador de 7 segmentos)
```

#### Estrutura do module top-level
```
module atividade (
input wire [3:0] KEY, // Entradas (botões/chaves)
output wire [6:0] HEX0, // Saída para o display de 7 segmentos
input wire CLOCK_50 // Sinal de clock de 50 MHz
);
```
