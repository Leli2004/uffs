
### TAREFA: Banco de Registradores (8 × 16 bits)

Implementar, em Verilog, um banco de registradores (BR) composto por 8 registradores
de 16 bits. O banco deve suportar leitura simultânea de dois registradores (portas A e B) e
escrita síncrona em um registrador, servindo como componente típico de um caminho de dados
de processador.

##### Testbench

| # | Cenário | Estado Anterior | Resultado Esperado |
|---|---------|------------------|---------------------|
| 1 | Reset síncrono | – | Todos os regs = 0x0000 |
| 2 | Escrita em R0: 0xDEAD | R0 = 0x0000 | R0 = 0xDEAD após clock |
| 3 | Escrita em R7: 0xBEEF | R7 = 0x0000 | R7 = 0xBEEF após clock |
| 4 | Leitura A=R0, B=R7 | R0=0xDEAD / R7=0xBEEF | r_data_a=0xDEAD, r_data_b=0xBEEF |
| 5 | Escrita em todos (R0-R7) | – | Cada reg com valor distinto |
| 6 | Leitura simultânea A=Ri, B=Rj | Valores distintos | Ambas portas corretas |
| 7 | we=0: tentativa de escrita | R2 = valor_x | R2 não muda |
| 8 | Leitura/escrita mesmo endereço | R3 = val_antigo | Porta lê val_antigo (antes do clock) |
| 9 | Reset durante operação | Registradores com dados | Todos zerados |
| 10 | Endereços variáveis com $random | – | Verificar consistência escrita/leitura |

Corner Cases Obrigatórios do tb:
* Escrita e leitura no mesmo endereço no mesmo ciclo de clock
* Leitura com we = 0 — saídas não devem ser afetadas pela port
* Reset com todas as posições escritas, verificando que todos os registradores são zerados
* Leitura das portas A e B com o mesmo endereço — ambas devem retornar o mesmo valor
* Escrita em R0 e R7 (extremos do banco) com valores 0xFFFF e 0x0001
* Sequência de escritas consecutivas no mesmo endereço — apenas o último valor deve persistir

