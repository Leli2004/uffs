
public class ContaCorrente {
    private int numeroConta;
    private String titular;
    private double saldo;
    
    public ContaCorrente(int numeroConta, String titular) {
        this.numeroConta = numeroConta;
        this.titular = titular;
        this.saldo = 0;
    }

    public int GetNumeroConta() {
        return this.numeroConta;
    }

    public String GetTitular() {
        return this.titular;
    }

    public double GetSaldo() {
        return this.saldo;
    }

    public boolean depositar(double valor) {
        if(valor <= 0) {
            System.err.println(">> ERRO: valor de depósito inválido.\n");
            return false;
        } 
        this.saldo += valor;
        return true;
    }

    public boolean sacar(double valor) {
        if(valor <= 0) {
            System.err.println(">> ERRO: valor de saque inválido.\n");
            return false;
        }
        if(this.saldo < valor) {
            System.err.println(">> ERRO: saldo insuficiente para saque.\n");
            return false;
        }
        this.saldo -= valor;
        return true;
    }

    public boolean transferir(double valor, ContaCorrente contaDestino) {
        boolean sucesso = this.sacar(valor); // remover valor da conta de origem
        if(!sucesso) {
            System.err.println(">> ERRO: Saque inválido na conta de origem.\n");
            return false;
        }

        sucesso = contaDestino.depositar(valor); // adiciona valor na conta de destino
        if(!sucesso) {
            System.err.println(">> ERRO: Depósito inválido na conta de destino.\n");
            return false;
        }

        return true;
    }
}
