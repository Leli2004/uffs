
public class Motor {
    private String tipo;
    private boolean ligado;

    public Motor(String tipo) {
        this.tipo = tipo;
        this.ligado = false;
    }

    public void Imprime() {
        System.out.println("\nTipo: " + this.tipo
            + "\nLigado: " + this.ligado
        );
    }

    public String GetTipo() {
        return this.tipo;
    }

    public void LigarMotor() {
        this.ligado = true;
        System.out.println("\nMotor " + this.tipo + " ligado!");
    }

    public void DesligarMotor() {
        this.ligado = false;
        System.out.println("\nMotor " + this.tipo + " desligado!");
    }
}
