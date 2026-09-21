
public class Principal {
    
    public static void main(String[] args) {
        Motocicleta m = new Motocicleta("BBB2222", "Renault", 2025, 12000, 10);

        System.out.println("\nMoto: ");
        m.imprime();

        double ipvaMoto = m.calcularIPVA();
        System.out.println("\nIPVA moto: R$" + ipvaMoto);

        Carro c = new Carro("AAA1111", "Renault", 2023, 50000, 4);

        System.out.println("\nCarro: ");
        c.imprime();

        double ipvaCarro = c.calcularIPVA();
        System.out.println("\nIPVA carro: R$" + ipvaCarro);
    }
}
