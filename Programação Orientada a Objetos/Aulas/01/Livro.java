// javac Livro.java

public class Livro {
    String titulo, autor;
    int ano_publicacao, qtd_pagina;

    public void Imprime() {
        System.out.println("--------------------------");
        System.out.println("Título: " + this.titulo 
            + "\nAutor: " + this.autor
            + "\nAno Publicação: " + this.ano_publicacao
            + "\nQtd. Páginas: " + this.qtd_pagina);
        System.out.println("--------------------------\n");
    }

    public void AlteraQtdPagina(int new_qtd) {
        this.qtd_pagina = new_qtd;
    }

    public static void main(String[] args) {
        Livro book1 = new Livro();
        Livro book2 = new Livro();

        book1.titulo = "O conto da aia";
        book1.autor = "Margaret Atwood";
        book1.ano_publicacao = 1985;
        book1.qtd_pagina = 368;

        book2.titulo = "Enterre seus mortos";
        book2.autor = "Ana Paula Maia";
        book2.ano_publicacao = 2018;
        book2.qtd_pagina = 136;

        book1.Imprime();

        book2.Imprime();
        book2.AlteraQtdPagina(143);
        book2.Imprime();
    }
}
