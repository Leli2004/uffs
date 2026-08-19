
public class ProdutoAgro {
    private long codigo;
    private String descricao;
    private double precoUnitario;
    private int quantidadeEstoque;
    
    public ProdutoAgro(long codigo, String descricao, double precoUnitario, int quantidadeEstoque) {
        if(precoUnitario < 0) {
            precoUnitario = 0;
        }
        if(quantidadeEstoque < 0) {
            quantidadeEstoque = 0;
        }

        this.codigo = codigo;
        this.descricao = descricao;
        this.precoUnitario = precoUnitario;
        this.quantidadeEstoque = quantidadeEstoque;
    }

    public ProdutoAgro(long codigo, String descricao, double precoUnitario) {
        this(codigo, descricao, precoUnitario, 0);
    }

    public long GetCodigo() {
        return codigo;
    }

    public String GetDescricao() {
        return descricao;
    }

    public double GetPrecoUnitario() {
        return precoUnitario;
    }

    public int GetQuantidadeEstoque() {
        return quantidadeEstoque;
    }

    private void SetPrecoUnitario(double precoUnitario) {
        if(precoUnitario < 0) {
            precoUnitario = 0;
        }
        this.precoUnitario = precoUnitario;
    }   

    private void SetQuantidadeEstoque(int quantidadeEstoque) {
        if(quantidadeEstoque < 0) {
            quantidadeEstoque = 0;
        }
        this.quantidadeEstoque = quantidadeEstoque;
    }

    public void reajustarPreco(double percentual) {
        if(percentual < -100) {
            System.err.println(">> ERRO: Percentual inválido. O preço não pode ser reajustado.");
        } else {
            double novoPreco = this.precoUnitario + (this.precoUnitario * percentual / 100);
            SetPrecoUnitario(novoPreco);
        }
    }

    public void adicionarEstoque(int quantidade) {
        if(quantidade < 0) {
            System.err.println(">> ERRO: Quantidade inválida.");
        } else {
            SetQuantidadeEstoque(this.quantidadeEstoque + quantidade);
        }
    }

    public boolean debitarEstoque(int quantidade) {
        if(quantidade < 0) {
            System.err.println(">> ERRO: Quantidade inválida.");
            return false;
        } else if(quantidade > this.quantidadeEstoque) {
            System.err.println(">> ERRO: Quantidade insuficiente em estoque.");
            return false;
        } else {
            SetQuantidadeEstoque(this.quantidadeEstoque - quantidade);
            return true;
        }
    }

}
