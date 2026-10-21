public class Veiculo {

    private String prefixo;
    private Motor motor;
    private double tanque;
    private boolean ativo;

    public Veiculo(String prefixo, Motor motor) {
        this.prefixo = prefixo;
        this.motor = motor;
        this.tanque = 0;
        this.ativo = true;
    }

    public String getPrefixo() {
        return prefixo;
    }

    public Motor getMotor() {
        return motor;
    }

    public double getTanque() {
        return tanque;
    }

    public boolean isAtivo() {
        return ativo;
    }

    public void setAtivo(boolean ativo) {
        this.ativo = ativo;
    }

    public void abastecer(double litros, String combustivel) throws OperacaoInvalidaException {

        if (litros <= 0) {
            throw new IllegalArgumentException("Quantidade deve ser positiva: " + litros);
        }
        if (!ativo) {
            throw new VeiculoInativoException(prefixo);
        }
        if (!motor.aceita(combustivel)) {
            throw new CombustivelIncompativelException(prefixo,
                                                       motor.getCombustivel(),
                                                       combustivel);
        }
        tanque = tanque + litros;
    }
}