
public class Revista extends ItemAcervo {
    private String edicao;

    public Revista(String titulo, String codigo, int anoPublicacao, String edicao) {
        super(titulo, codigo, anoPublicacao);
        this.edicao = edicao;
    }

    public String getEdicao() {
        return this.edicao;
    }

    @Override 
    public String toString() {
        return super.toString() + " | Edição: " + this.getEdicao();
    }
}
