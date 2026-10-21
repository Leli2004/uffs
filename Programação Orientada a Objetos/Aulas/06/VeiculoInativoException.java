public class VeiculoInativoException extends OperacaoInvalidaException {
    public VeiculoInativoException(String prefixo) {
        super("Veiculo " + prefixo + " esta inativo na frota.");
    }
}