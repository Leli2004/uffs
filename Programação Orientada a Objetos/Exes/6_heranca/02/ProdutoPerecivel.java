
public class ProdutoPerecivel extends Produto {
    private int diasValidade;
    
    public ProdutoPerecivel(String nome, double preco, int diasValidade) {
        super(nome, preco);
        this.diasValidade = diasValidade;
        System.out.println("Construtor de ProdutoPerecivel");
    }
}
