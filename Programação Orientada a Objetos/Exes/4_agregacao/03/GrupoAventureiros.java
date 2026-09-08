
public class GrupoAventureiros {
    int limiteHerois = 4;

    Heroi[] herois = new Heroi[limiteHerois];

    public void adicionarHeroi(Heroi h) {
        for (int i = 0; i < limiteHerois; i++) {
            if (herois[i] == null) {
                herois[i] = h;
                System.out.println("\nHerói " + h.getNome() + " adicionado ao grupo.");
                return;
            }
        }
        System.out.println("\nNão é possível adicionar mais heróis. Limite atingido.");
    }

    public void removerHeroi(String nome) {
        for (int i = 0; i < limiteHerois; i++) {
            if (herois[i] != null && herois[i].getNome().equals(nome)) {
                System.out.println("\nHerói " + herois[i].getNome() + " removido do grupo.");
                herois[i] = null;
                return;
            }
        }
        System.out.println("\nHerói " + nome + " não encontrado no grupo.");
    }

    public void listarMembros() {
        System.out.println("\nHeróis no grupo:");
        for (int i = 0; i < limiteHerois; i++) {
            if (herois[i] != null) {
                System.out.println("- " + herois[i].getNome() + " (Classe: " + herois[i].getClasseRPG() + ")");
            }
        }
    }

    public static void main(String[] args) {
        GrupoAventureiros grupo = new GrupoAventureiros();

        Heroi heroi1 = new Heroi("Aragorn", "Guerreiro");
        Heroi heroi2 = new Heroi("Legolas", "Arqueiro");
        Heroi heroi3 = new Heroi("Gandalf", "Mago");
        Heroi heroi4 = new Heroi("Frodo", "Ladino");
        Heroi heroi5 = new Heroi("Boromir", "Guerreiro");

        grupo.adicionarHeroi(heroi1);
        grupo.adicionarHeroi(heroi2);
        
        grupo.listarMembros();

        grupo.adicionarHeroi(heroi3);
        grupo.adicionarHeroi(heroi4);
        grupo.adicionarHeroi(heroi5); // Tentativa de adicionar um herói além do limite

        grupo.listarMembros();

        grupo.removerHeroi("Legolas");
        grupo.listarMembros();
    }
}
