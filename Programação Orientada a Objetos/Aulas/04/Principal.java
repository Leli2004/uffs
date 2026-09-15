
public class Principal {
    
    public static void main(String[] args) {
        Gerente beyonce = new Gerente("Beyonce", "12345", 5000999, 1000);
        System.out.println(beyonce);

        Vendedor gaga = new Vendedor("Lady Gaga", "67890", 4000000, 100);
        System.out.println(gaga);

        gaga.RegistrarVenda(10);
        System.out.println("Nome: " + gaga.GetNome() + " | Comissão: R$" + gaga.GetComissao() + "\n");

        Departamento divasPop = new Departamento("Divas Pop", 5);

        divasPop.Contratar(beyonce);
        divasPop.Contratar(gaga);

        System.out.println("Equipe " + divasPop.GetNome() + ":");
        divasPop.ListaNomes();

        System.out.println("\nFolha pagamento: R$" + divasPop.CalculaFolhaBase());
    }
}
