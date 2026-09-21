
public class ContaCorrente extends ContaBancaria {

    public ContaCorrente(int numero) {
        super(numero);
    }    

    @Override 
    public boolean sacar(double valor) {
        super.sacar(valor + 0.50);
        return true;
    }
}
