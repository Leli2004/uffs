
public class Brinquedo {
    private String nome;
    
    public Brinquedo() {
        this.nome = "Sem nome";
    }

    public Brinquedo(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void mover() {
        System.out.println(this.nome + ": mover brinquedo");
    }
}
