
public class Carro {
    private String modelo;
    private String placa;

    // Composição
    private Motor motor;

    // Agregação
    private Pneu []pneus;

    public Carro(String modelo, String placa, String tipoMotor) {
        this.modelo = modelo;
        this.placa = placa;
        this.pneus = new Pneu[4];

        // Composição
        this.motor = new Motor(tipoMotor);
    }

    public void Imprime() {
        System.out.println("Modelo: " + this.modelo 
            + "\nPlaca: " + this.placa
        );
    }

    public String GetModelo() {
        return this.modelo;
    }

    public String GetPlaca() {
        return this.placa;
    }

    public void InstalarPneus(Pneu p1, Pneu p2, Pneu p3, Pneu p4) {
        this.pneus[0] = p1;
        this.pneus[1] = p2;
        this.pneus[2] = p3;
        this.pneus[3] = p4;
        System.out.println("Pneus instalados com sucesso no carro " + this.modelo + " - " + this.placa);
    }

    public void Ligar() {
        this.motor.LigarMotor();
    }

    public static void main(String[] args) {
        Pneu p1 = new Pneu("X-Arrow", "Slick 2000");
        Pneu p2 = new Pneu("X-Arrow", "Slick 2000");
        Pneu p3 = new Pneu("X-Arrow", "Slick 2000");
        Pneu p4 = new Pneu("X-Arrow", "Slick 2000");

        Carro c = new Carro("Sandero", "123456", "motor teste");

        c.InstalarPneus(p1, p2, p3, p4);

        // Associação
        Motorista leli = new Motorista("Leli");
        leli.Dirigir(c);
    }
}
