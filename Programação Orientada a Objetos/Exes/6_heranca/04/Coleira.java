
public class Coleira  {
    private String cor;
    private Cachorro cachorro;

    public Coleira(Cachorro cachorro, String cor) {
        this.cachorro = cachorro;
        this.cor = cor;
    }

    public String getCor() {
        return this.cor;
    }

    public Cachorro getCachorro() { 
        return this.cachorro; 
    }

    public void setCor(String cor) {
        this.cor = cor;
    }
}
