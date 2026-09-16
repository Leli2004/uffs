
public class Livro extends ItemAcervo {
    private String autor;
    private String isbn;

    public Livro(String titulo, String codigo, int anoPublicacao, String autor, String isbn) {
        super(titulo, codigo, anoPublicacao);
        this.autor = autor;
        this.isbn = isbn;
    }

    public String getAutor() {
        return this.autor;
    }

    public String getIsbn() {
        return this.isbn;
    }

    @Override 
    public String toString() {
        return super.toString() + " | Autor: " + this.getAutor() + " | ISBN: " + this.getIsbn();
    }
}
