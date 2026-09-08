
public class Secretaria {
    private String nome;
    private ProjetoInovacao[] projetos;
    private int totalProjetos;
    
    public Secretaria(String nome, int totalProjetos) {
        this.nome = nome;
        this.projetos = new ProjetoInovacao[totalProjetos];
        this.totalProjetos = 0;
    }

    void adicionarProjeto(ProjetoInovacao p) {
        if (totalProjetos < projetos.length) {
            projetos[totalProjetos] = p;
            totalProjetos++;
            System.out.println("\nProjeto adicionado com sucesso!");
        } else {
            System.out.println("\nNão é possível adicionar mais projetos. Limite atingido.");
        }
    }

    void listarProjetos() {
        System.out.println("\nProjetos da " + nome + ":");
        for (int i = 0; i < totalProjetos; i++) {
            System.out.println("- " + projetos[i].getTitulo() + " (Orçamento: " + projetos[i].getOrcamento() + ")");
        }
    }

    public static void main(String[] args) {
        Secretaria secretaria = new Secretaria("Secretaria de Inovação", 3);
        ProjetoInovacao projeto1 = new ProjetoInovacao("Projeto A", 10000.0);
        ProjetoInovacao projeto2 = new ProjetoInovacao("Projeto B", 20000.0);
        ProjetoInovacao projeto3 = new ProjetoInovacao("Projeto C", 15000.0);
        ProjetoInovacao projeto4 = new ProjetoInovacao("Projeto D", 25000.0);

        secretaria.adicionarProjeto(projeto1);
        secretaria.listarProjetos();

        secretaria.adicionarProjeto(projeto2);
        secretaria.listarProjetos();

        secretaria.adicionarProjeto(projeto3);
        secretaria.listarProjetos();

        secretaria.adicionarProjeto(projeto4); // Tentativa de adicionar um projeto além do limite  
        secretaria.listarProjetos();
    }
}
