// javac Ave.java

public class Ave {
    String especie, alimentacao;
    double altura_voo;
    int anos_vida;

    public void Imprime() {
        System.out.println("--------------------------");
        System.out.println("Espécie: " + this.especie 
            + "\nAlimentação: " + this.alimentacao
            + "\nAltura voo (m): " + this.altura_voo
            + "\nAnos vida (média): " + this.anos_vida);
        System.out.println("--------------------------\n");
    }

    public void AlteraAnosVida(int new_anos_vida) {
        if (new_anos_vida <= 0) {
            System.err.println("\nERROR: quantia de anos inválida!");
            return;
        }
        this.anos_vida = new_anos_vida;
    }

    public void AlteraAlturaVoo(double new_altura_voo) {
        if (new_altura_voo <= 0) {
            System.err.println("\nERROR: altura de voo inválida!");
            return;
        }
        this.altura_voo = new_altura_voo;
    }

    public static void main(String[] args) {
        Ave ave1 = new Ave();
        Ave ave2 = new Ave();

        ave1.especie = "Galinha";
        ave1.alimentacao = "Onívora";
        ave1.altura_voo = 2.5;
        ave1.anos_vida = 8;

        ave2.especie = "harpia";
        ave2.alimentacao = "Carnívora";
        ave2.altura_voo = 100;
        ave2.anos_vida = 30;

        ave1.Imprime();
        ave1.AlteraAnosVida(10);
        ave1.Imprime();

        ave2.Imprime();
        ave2.AlteraAnosVida(35);
        ave2.AlteraAlturaVoo(103.5);
        ave2.Imprime();
    }
}
