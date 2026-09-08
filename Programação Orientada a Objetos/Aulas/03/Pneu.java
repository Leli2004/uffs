
public class Pneu {
    private String marca, modelo;

    public Pneu(String marca, String modelo) {
        this.marca = marca;
        this.modelo = modelo;
    }

    public String GetDescricao() {
        return "Pneu: " + this.marca + " " + this.modelo;
    }
}
