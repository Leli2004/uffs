
public class BancoDeDadosLocal {
    private String nome;
    private String host;
    private String usuario;
    private String senha;
    private String[] dados;

    public BancoDeDadosLocal(String nome, String host, String usuario, String senha) {
        this.nome = nome;
        this.host = host;
        this.usuario = usuario;
        this.senha = senha;
    }

    public void SalvarDados(String[] dados) {
        this.dados = dados;
        System.out.println("\nDados salvos no banco de dados local: " + nome);
    }

    public void ImprimeDados() {
        System.out.println("\nDados do banco de dados local " + nome + ":");
        
        if (dados != null) {
            for (String dado : dados) {
                System.out.println(dado);
            }
        } else {
            System.out.println("\nNenhum dado salvo.");
        }
    }
}
