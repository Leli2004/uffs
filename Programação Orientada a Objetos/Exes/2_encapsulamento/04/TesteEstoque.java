
public class TesteEstoque {
    public static void main(String[] args) {
        ProdutoAgro produto1 = new ProdutoAgro(1, "Arroz", 100, 10);
        ProdutoAgro produto2 = new ProdutoAgro(2, "Feijão", 200, 5);

        System.out.println("\n*******************************");
        System.out.println("Produto 1: " + produto1.GetDescricao());
        System.out.println("Código: " + produto1.GetCodigo());
        System.out.println("Preço: R$" + produto1.GetPrecoUnitario());
        System.out.println("Quantidade em estoque: " + produto1.GetQuantidadeEstoque());
        
        System.out.println("\n*******************************");
        System.out.println("Produto 2: " + produto2.GetDescricao());
        System.out.println("Código: " + produto2.GetCodigo());
        System.out.println("Preço: R$" + produto2.GetPrecoUnitario());
        System.out.println("Quantidade em estoque: " + produto2.GetQuantidadeEstoque());

        System.out.println("\n*******************************");
        System.out.println("Aumentando o preço do Produto 1 em 10%.");
        produto1.reajustarPreco(10); 
        System.out.println("Produto 1 após reajuste de preço: Preço: R$" + produto1.GetPrecoUnitario());

        System.out.println("\n*******************************");
        System.out.println("Diminuindo o preço do Produto 2 em 10%.");
        produto2.reajustarPreco(-10);
        System.out.println("Produto 2 após reajuste de preço: Preço: R$" + produto2.GetPrecoUnitario());

        System.out.println("\n*******************************");
        System.out.println("Adicionando 5 unidades ao estoque do Produto 1.");
        produto1.adicionarEstoque(5);
        System.out.println("Produto 1 após adição de estoque: Quantidade: " + produto1.GetQuantidadeEstoque());

        System.out.println("\n*******************************");
        System.out.println("Debitando 1 unidade do estoque do Produto 2.");
        boolean debitoProduto2 = produto2.debitarEstoque(1);
        System.out.println("Débito realizado: " + debitoProduto2);
        System.out.println("Produto 2 após débito: Quantidade: " + produto2.GetQuantidadeEstoque());

    }
}
