
public class ItemAcervo {
    private String titulo;
    private String codigo;
    private int anoPublicacao;
    private boolean disponivel;

    public ItemAcervo(String titulo, String codigo, int anoPublicacao) {
        this.titulo = titulo;
        this.codigo = codigo;
        this.anoPublicacao = anoPublicacao;
        this.disponivel = true;
    }

    public String getTitulo() {
        return this.titulo;
    }

    public String getCodigo() {
        return this.codigo;
    }

    public int getAnoPublicacao() {
        return this.anoPublicacao;
    }

    public boolean getDisponivel() {
        return this.disponivel;
    }

    public void emprestar() {
        this.disponivel = false;
    }

    public void devolver() {
        this.disponivel = true;
    }

    @Override 
    public String toString() {
        return String.format("Título: %s | Código: %s | Ano publicação: %d | Disponível: %s", 
            this.titulo, 
            this.codigo, 
            this.anoPublicacao, 
            disponivel ? "sim" : "não");
    }
}
