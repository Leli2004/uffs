
public class Cachorro extends Animal {
    private final String raca;
    private double fator;

    public Cachorro(String nome, double peso, String raca, double fator) {
        super(nome, peso);
        this.raca = raca;
        this.fator = fator;
    }

    public String getRaca() {
        return this.raca;
    }

    @Override
    public double calcularDose() {
        return this.getPeso() * 0.15 * this.fator;
    }
}
