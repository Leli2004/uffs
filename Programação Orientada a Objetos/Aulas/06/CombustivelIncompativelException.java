public class CombustivelIncompativelException extends OperacaoInvalidaException {

    private String esperado;
    private String recebido;

    public CombustivelIncompativelException(String prefixo, String esperado, String recebido) {
        super("Veiculo " + prefixo + " usa " + esperado + ", nao " + recebido);
        this.esperado = esperado;
        this.recebido = recebido;
    }

    public String getEsperado() {
        return esperado;
    }

    public String getRecebido() {
        return recebido;
    }
}