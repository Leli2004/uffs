
public class DVD extends ItemAcervo {
    private int duracaoMinutos;

    public DVD(String titulo, String codigo, int anoPublicacao, int duracaoMinutos) {
        super(titulo, codigo, anoPublicacao);
        this.duracaoMinutos = duracaoMinutos;
    }

    public int getDuracaoMinutos() {
        return this.duracaoMinutos;
    }

    @Override 
    public String toString() {
        return super.toString() + " | Duração em minutos: " + this.getDuracaoMinutos();
    }
}
