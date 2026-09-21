
public class Motocicleta extends Veiculo {
    private double cilindradas;
    private double TarifaIPVA = 0.02;

    public Motocicleta(String placa, String marca, int anoFabricacao, double valorVenal, double cilindradas) {
        super(placa, marca, anoFabricacao, valorVenal);
        this.cilindradas = cilindradas;
    }

    public double getCilindradas() {
        return this.cilindradas;
    }

    @Override 
    public double calcularIPVA() {
        return super.getValorVenal() * TarifaIPVA;
    }

    @Override 
    public void imprime() {
        super.imprime();
        System.out.print(" | Cilindradas: " + this.getCilindradas());
    }
}
