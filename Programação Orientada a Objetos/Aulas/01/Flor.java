// javac Flor.java

public class Flor {
    String especie, tipo_petala;
    double altura;
    boolean eh_venenosa;

    public void Imprime() {
        System.out.println("--------------------------");
        System.out.println("Espécie: " + this.especie 
            + "\nTipo de pétala: " + this.tipo_petala
            + "\nAltura: " + this.altura
            + "\nÉ venenosa: " + this.eh_venenosa);
        System.out.println("--------------------------\n");
    }

    public void AlteraTipoPetala(String new_data) {
        this.tipo_petala = new_data;
    }

    public void AlteraAltura(double new_data) {
        this.altura = new_data;
    }

    public void AlteraEhVenenosa(boolean new_data) {
        this.eh_venenosa = new_data;
    }

    public static void main(String[] args) {
        Flor flower1 = new Flor();
        Flor flower2 = new Flor();

        flower1.especie = "Margarida";
        flower1.tipo_petala = "Simples";
        flower1.altura = 65;
        flower1.eh_venenosa = false;

        flower2.especie = "Rosa do Deserto";
        flower2.tipo_petala = "Dobradas";
        flower2.altura = 250;
        flower2.eh_venenosa = false;

        flower1.Imprime();
        flower1.AlteraAltura(75.3);
        flower1.Imprime();

        flower2.Imprime();
        flower2.AlteraEhVenenosa(true);
        flower2.AlteraTipoPetala("Dobradas/triplas");
        flower2.Imprime();
    }
}
