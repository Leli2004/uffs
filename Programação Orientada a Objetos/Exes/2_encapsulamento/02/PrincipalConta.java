
public class PrincipalConta {
    public static void main(String[] args) {
        ContaCorrente conta1 = new ContaCorrente(123, "João");
        ContaCorrente conta2 = new ContaCorrente(456, "Maria");
        boolean sucesso;

        System.out.println("\n*******************************");
        System.out.println("Saldo inicial da conta 1: " + conta1.GetSaldo());
        System.out.println("Saldo inicial da conta 2: " + conta2.GetSaldo());

        System.out.println("\n*******************************");
        sucesso = conta1.depositar(1000);
        System.out.println("=> Operação realizado? " + sucesso);
        System.out.println("Saldo da conta 1 após depósito: " + conta1.GetSaldo());
       
        System.out.println("\n*******************************");
        sucesso = conta1.sacar(500);
        System.out.println("=> Operação realizado? " + sucesso);
        System.out.println("Saldo da conta 1 após saque: " + conta1.GetSaldo());
        
        System.out.println("\n*******************************");
        sucesso = conta1.transferir(200, conta2);
        System.out.println("=> Operação realizado? " + sucesso);
        System.out.println("Saldo da conta 1 após transferência: " + conta1.GetSaldo());
        System.out.println("Saldo da conta 2 após transferência: " + conta2.GetSaldo());

        System.out.println("\n*******************************");
        sucesso = conta2.transferir(1, conta1);
        System.out.println("=> Operação realizado? " + sucesso);
        System.out.println("Saldo da conta 1 após transferência: " + conta1.GetSaldo());
        System.out.println("Saldo da conta 2 após transferência: " + conta2.GetSaldo());

        System.out.println("\n*******************************");
        sucesso = conta2.transferir(1000000000, conta1);
        System.out.println("=> Operação realizado? " + sucesso);
        System.out.println("Saldo da conta 1 após transferência: " + conta1.GetSaldo());
        System.out.println("Saldo da conta 2 após transferência: " + conta2.GetSaldo());

    }
}
