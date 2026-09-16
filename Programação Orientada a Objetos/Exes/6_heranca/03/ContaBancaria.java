
public class ContaBancaria {
    private final int numero;
    private double saldo;

    public ContaBancaria(int numero) {
        this.numero = numero;
        this.saldo = 0;
    }

    public int getNumero() {
        return this.numero;
    }

    public double getSaldo() {
        return this.saldo;
    }

    public void imprime(){
        System.out.println("Conta bancária n° " + this.getNumero() + " | saldo: R$" + this.getSaldo());
    }

    public boolean depositar(double valor) {
        this.saldo += valor;
        return true;
    } 
   
    public boolean sacar(double valor) {
        if(valor > this.saldo) {
            return false;
        }
        this.saldo -= valor;
        return true;
    } 
}
