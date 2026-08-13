
// javac Carro.java

public class Carro {
    /*************************************************************/
    // Atributos
    String modelo, cor, placa;
    int num_portas=2;
    boolean motor_on=false, farol_on=false, limpa_parabrisa_on=false;

    /*************************************************************/
    // Métodos
    public void Imprime() {
        System.out.println("\n--------------------------");
        System.out.println("Modelo: " + this.modelo 
            + "\nCor: " + this.cor
            + "\nPlaca: " + this.placa
            + "\nNúmero de portas: " + this.num_portas
            + "\nMotor ligado? " + this.motor_on
            + "\nFarol ligado? " + this.farol_on
            + "\nLimpador parabrisa ligado? " + this.limpa_parabrisa_on);
        System.out.println("--------------------------");
    }

    public void AlteraMotor() {
        if (this.motor_on) {
            System.out.println("\n>>> Motor desligado!");
        } else {
            System.out.println("\n>>> Motor ligado!");
        }

        this.motor_on = !this.motor_on;
    }

    public void AlteraFarol() {
        if (this.farol_on) {
            System.out.println("\n>>> Farol desligado!");
        } else {
            System.out.println("\n>>> Farol ligado!");
        }

        this.farol_on = !this.farol_on;
    }

    public void AlteraLimpadorParabrisa() {
        if (this.limpa_parabrisa_on) {
            System.out.println("\n>>> Limpador parabrisa desligado!");
        } else {
            System.out.println("\n>>> Limpador parabrisa ligado!");
        }

        this.limpa_parabrisa_on = !this.limpa_parabrisa_on;
    }

    public void VirarDireita() {
        System.out.println("\n>>> Virando à direita!");
    }

    public void VirarEsquerda() {
        System.out.println("\n>>> Virando à esquerda!");
    }

    /*************************************************************/
    // Main
    public static void main(String[] args) {
        Carro carro1 = new Carro();

        carro1.modelo = "Mobi";
        carro1.cor = "Branco";
        carro1.placa = "ABC-1234";
        carro1.num_portas = 4;
        carro1.motor_on = false;
        carro1.farol_on = false;
        carro1.limpa_parabrisa_on = false;

        carro1.Imprime();

        // Testes
        carro1.AlteraMotor();
        carro1.AlteraFarol();
        carro1.Imprime();

        carro1.VirarDireita();
        carro1.VirarEsquerda();

        carro1.AlteraLimpadorParabrisa();
        carro1.Imprime();

        carro1.AlteraLimpadorParabrisa();
        carro1.Imprime();
        carro1.VirarEsquerda();

        carro1.AlteraMotor();
        carro1.AlteraFarol();
        carro1.Imprime();
    }
}
