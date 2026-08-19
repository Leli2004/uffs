
public class Principal {
    public static void main(String[] args) {
        ContaBancaria suaConta = new ContaBancaria();
        ContaBancaria minhaConta = new ContaBancaria("Leli", 123);

        minhaConta.Imprime();
        minhaConta.Deposito(1000.75);
        minhaConta.Imprime();
        minhaConta.Saque(273.05);
        System.out.println("\nN° conta: "+ minhaConta.GetNumConta() + "\nSaldo: R$" + minhaConta.GetSaldo());

        suaConta.Imprime();
        suaConta.SetNumConta(456);
        suaConta.SetTitular("Danieli");
        suaConta.Imprime();
        suaConta.Deposito(355.90);
        System.out.println("\nN° conta: "+ suaConta.GetNumConta() + "\nSaldo: R$" + suaConta.GetSaldo());
    }
}
