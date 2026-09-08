
public class Registro {
    private String data;
    private String operacao;

    public Registro(String data, String operacao) {
        this.data = data;
        this.operacao = operacao;
    }

    public void ImprimirRegistro() {
        System.out.println("Data: " + data + ", Operação: " + operacao);
    }
}
