
public class Principal {
    public static void main(String[] args) {
        Livro livro = new Livro("Dom Casmurro", "L001", 1899, "Machado de Assis", "123456789");
        Revista revista = new Revista("Superinteressante", "R001", 2024, "452");
        DVD dvd = new DVD("O Poderoso Chefão", "D001", 1972, 175);

        System.out.println(livro);
        System.out.println(revista);
        System.out.println(dvd);

        livro.emprestar();
        revista.emprestar();
        dvd.emprestar();

        System.out.println();
        System.out.println(livro);
        System.out.println(revista);
        System.out.println(dvd);

        livro.devolver();
        revista.devolver();
        dvd.devolver();

        System.out.println();
        System.out.println(livro);
        System.out.println(revista);
        System.out.println(dvd);
    }
}
