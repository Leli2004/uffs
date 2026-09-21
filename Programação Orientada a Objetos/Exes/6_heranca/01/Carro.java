
public class Carro extends Veiculo {
    private int numeroPortas;
    private double TarifaIPVA = 0.04;

    public Carro(String placa, String marca, int anoFabricacao, double valorVenal, int numeroPortas) {
        super(placa, marca, anoFabricacao, valorVenal);
        this.numeroPortas = numeroPortas;
    }

    public int getNumeroPortas() {
        return this.numeroPortas;
    }

    @Override 
    public double calcularIPVA() {
        return super.getValorVenal() * TarifaIPVA;
    }

    @Override 
    public void imprime() {
        super.imprime();
        System.out.print(" | N° portas: " + this.getNumeroPortas());
    }
}
