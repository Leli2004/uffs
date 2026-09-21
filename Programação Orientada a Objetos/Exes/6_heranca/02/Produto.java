
public class Produto {
    private final String nome;
    private final double preco;

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
        System.out.println("Construtor de Produto");
    }
    
    public String getNome() {
        return this.nome;
    }

    public double getPreco() {
        return this.preco;
    }

    public void imprime() {
        System.out.print("\nNome: " + this.getNome() + " | Preço: R$" + this.getPreco());
    }
}
