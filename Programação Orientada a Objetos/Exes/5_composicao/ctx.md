
## Exercícios Agregação
 
#### 1
Crie uma classe Registro (data, operacao). Crie uma classe ContaBancaria que, em seu construtor, instancia um Registro inicial escrito "Conta Criada".
    
#### 2
Crie uma classe BancoDeDadosLocal com um método privado/protegido para salvarDados(). Crie uma classe PlataformaSaaS. A plataforma deve instanciar o banco de dados em seu próprio construtor. A plataforma terá um método cadastrarCliente(), que internamente chama o salvarDados() do banco.
     
#### 3
Desafio: Crie as classes CPU, MemoriaRAM e DiscoRigido, todas com métodos iniciar() que retornam boolean. Crie a classe ServidorCloud. No construtor do Servidor, ele deve compor essas três peças. Crie um método boot() no Servidor que liga a CPU, depois a RAM, depois o Disco. Se qualquer um falhar, o boot falha.
