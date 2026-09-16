
public class Animal {
    private final String nome;
    private final double peso;

    public Animal(String nome, double peso) {
        this.nome = nome;
        this.peso = peso;
    }

    public String getNome() { return this.nome; }
    public double getPeso() { return this.peso; }

    public double calcularDose() {
        return this.peso * 0.1;
    }
}
