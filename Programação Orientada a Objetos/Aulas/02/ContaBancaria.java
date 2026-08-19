
public class ContaBancaria {
    private String titular;
    private int numeroConta;
    private double saldo;

    public ContaBancaria() {
        this.titular = "";
        this.numeroConta = 000;
        this.saldo = 0;
    }

    public ContaBancaria(String newTitular, int newNumeroConta) {
        if(newTitular == null || newNumeroConta <= 0 ) {
            System.err.println("ERRO: dados obrigatórios inválidos");
        } else {
            this.titular = newTitular;
            this.numeroConta = newNumeroConta;
            this.saldo = 0;
        }
    }

    public void Imprime() {
        System.out.println("\nTitular: " + this.titular
            + "\nN° conta: " + this.numeroConta
            + "\nSaldo: R$" + this.saldo
        );
    }

    public void SetTitular(String newTitular) {
        if(newTitular != null) {
            this.titular = newTitular;
        }
    }

    public void SetNumConta(int newNumConta) {
        if(newNumConta > 0) {
            this.numeroConta = newNumConta;
        }
    }

    private void SetSaldo(double newSaldo) {
        if(newSaldo >= 0) {
            this.saldo = newSaldo;
        }
    }

    public String GetTitular() {
        return this.titular;
    }

    public int GetNumConta() {
        return this.numeroConta;
    }

    public double GetSaldo() {
        return this.saldo;
    }

    public void Saque(double valor) {
        if(valor > this.saldo || valor <= 0) {
            System.err.println("ERRO: valor de saque inválido");
        } else {
            this.saldo -= valor;
        }
    }

    public void Deposito(double valor) {
        if(valor <= 0) {
            System.err.println("ERRO: valor de depósito inválido");
        } else {
            this.saldo += valor;
        }
    }
}
