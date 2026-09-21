
public class Principal {
    public static void main(String[] args) {
        ContaBancaria c = new ContaBancaria(123);
        c.imprime();
        c.depositar(100);
        c.imprime();
        c.sacar(10);
        c.imprime();

        ContaCorrente cc = new ContaCorrente(456);
        cc.depositar(20);
        cc.imprime();
        cc.sacar(10);
        cc.imprime();

        ContaPoupanca cp = new ContaPoupanca(789);
        cp.depositar(10);
        cp.imprime();
        cp.renderJuros(50);
        cp.imprime();
    }
}
