
public class Veiculo {
    private final String placa;
    private final String marca;
    private final int anoFabricacao ;
    private final double valorVenal;

    private double TarifaIPVA = 0.03;

    public Veiculo(String placa, String marca, int anoFabricacao, double valorVenal) {
        this.placa = placa;
        this.marca = marca;
        this.anoFabricacao = anoFabricacao;
        this.valorVenal = valorVenal;
    }

    public String getPlaca() {
        return this.placa;
    }

    public String getMarca() {
        return this.marca;
    }

    public int getAnoFabricacao() {
        return this.anoFabricacao;
    }

    public double getValorVenal() {
        return this.valorVenal;
    }

    public double calcularIPVA() {
        return this.valorVenal * TarifaIPVA;
    }

    public void imprime() {
        System.out.print("Placa: " + this.getPlaca() + " | "
            + "Marca: " + this.getMarca() + " | "
            + "Ano fabricação: " + this.getAnoFabricacao() + " | "
            + "Valor venal: R$" + this.getValorVenal()
        );
    }
}
