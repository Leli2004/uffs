
public class Motorista {
    private String nome;

    public Motorista(String nome) {
        this.nome = nome;
    }

    public void Imprime() {
        System.out.println("\nMotorista: " + this.nome);
    }

    public void Dirigir(Carro carro) {
        System.out.println("\nMotorista " + this.nome + " está dirigindo o carro " + carro.GetModelo() + "!");
        carro.Ligar();
    }
}
