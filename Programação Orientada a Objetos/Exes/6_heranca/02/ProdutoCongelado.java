
public class ProdutoCongelado extends Produto {
    private double temperaturaMinima;

    public ProdutoCongelado(String nome, double preco, double temperaturaMinima) {
        super(nome, preco);
        this.temperaturaMinima = temperaturaMinima;
        System.out.println("Construtor de ProdutoCongelado");
    }

    public double getTemperaturaMinima() {
        return this.temperaturaMinima;
    }

    public void setTemperaturaMinima(double temp) {
        this.temperaturaMinima = temp;
    }

    @Override 
    public void imprime() {
        super.imprime();
        System.out.print(" | " + this.getTemperaturaMinima());
    }
}
