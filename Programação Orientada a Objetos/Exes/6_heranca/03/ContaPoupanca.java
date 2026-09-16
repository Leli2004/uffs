
public class ContaPoupanca extends ContaBancaria {

    public ContaPoupanca(int numero) {
        super(numero);
    }    
    
    public void renderJuros(double taxa) {
        super.depositar(this.getSaldo() * taxa);
    }
}
