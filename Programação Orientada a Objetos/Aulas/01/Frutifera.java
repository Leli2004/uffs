
// javac Frutifera.java

public class Frutifera {
    // Atributos
    String tipo = "Desconhecido";
    int qtd_frutos = 0;
    boolean frutificando = false;
    
    // Métodos
    public void Imprime(String object_name) {
        System.out.println("--------------------------\nImprimindo " + object_name + "...\n");
        System.out.println("Tipo: " + this.tipo 
            + "\nFrutos: " + this.qtd_frutos 
            + "\nEstá frutificando: " + this.frutificando);
        System.out.println("--------------------------\n");
    }

    public void Produzir(int qtd) {
        if (qtd <= 0 ) {
            System.out.println("\nERROR: quantidade inválida!");
            return;
        } 

        this.qtd_frutos = qtd;

        if (this.frutificando == false) {
            this.frutificando = true;
        }
    }

    // main
    public static void main(String[] args) {
        Frutifera macieira = new Frutifera();
        Frutifera laranjeira = new Frutifera();
        Frutifera jabuticabeira = new Frutifera();

        macieira.Imprime("macieira");
        laranjeira.Imprime("laranjeira");
        jabuticabeira.Imprime("jabuticabeira");

        macieira.tipo = "Maçã";
        macieira.qtd_frutos = 50;
        macieira.frutificando = true;

        laranjeira.tipo = "Laranja";
        laranjeira.qtd_frutos = 103;
        laranjeira.frutificando = true;

        jabuticabeira.tipo = "Jabuticaba";
        jabuticabeira.qtd_frutos = 746;
        jabuticabeira.frutificando = true;

        macieira.Imprime("macieira");
        laranjeira.Imprime("laranjeira");
        jabuticabeira.Imprime("jabuticabeira");

        jabuticabeira.Produzir(1005);
        jabuticabeira.Imprime("jabuticabeira");
    }
}
