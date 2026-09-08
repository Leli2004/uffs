
public class Personagem {
    private String nome;
    private float pontosVida;
    private float vidaMaxima;

    public Personagem(String nome, float pontosVida, float vidaMaxima) {
        this.nome = nome;
        this.pontosVida = pontosVida;
        this.vidaMaxima = vidaMaxima;
    }

    public float getPontosVida() {
        return this.pontosVida;
    }

    public void imprime() {
        System.out.println("\nPersonagem... \nNome: " + this.nome
            + "\nPontos Vida: " + this.pontosVida
            + "\nVida Máxima: " + this.vidaMaxima
        );
    }

    public void consumir(PocaoCura pocao) {
        float n = pontosVida + pocao.poderCura;

        if(n > this.vidaMaxima) {
            n = this.vidaMaxima;
        }

        this.pontosVida =+ n;
        System.out.println("\n=> Poção consumida com sucesso!" );
    }

    public static void main(String[] args) {
        Personagem p = new Personagem("teste", 55, 100);
    
        p.imprime();

        PocaoCura pocao = new PocaoCura(10);
        p.consumir(pocao);

        p.imprime();

        PocaoCura pocao2 = new PocaoCura(101);
        p.consumir(pocao2);

        p.imprime();
    }
}
