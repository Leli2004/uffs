
public class Usuario {
    private String login;
    private String senha;

    public Usuario(String login, String senha) {
        this.login = login;
        this.senha = senha;
    }

    public String getLogin() {
        return this.login;
    }

    public String getSenha() {
        return this.senha;
    }

    public void imprimeResultado(boolean ok) {
        if(!ok) {
            System.out.println("\nUsuário "+ this.login +" válido :)");
        } else {
            System.out.println("\nUsuário "+ this.login +" inválido :(");
        }
    }

    public static void main(String[] args) {
        ServidorAutenticacao auth = new ServidorAutenticacao();
        boolean ok;

        Usuario user1 = new Usuario("teste1", "1234456");
        ok = auth.validarLogin(user1);
        user1.imprimeResultado(ok);

        Usuario user2 = new Usuario("teste2", "teste");
        ok = auth.validarLogin(user2);
        user2.imprimeResultado(ok);

        Usuario user3 = new Usuario("teste3", "123");
        
        auth.desativa();
        ok = auth.validarLogin(user3);
        user3.imprimeResultado(ok);

        auth.ativa();
        ok = auth.validarLogin(user3);
        user3.imprimeResultado(ok);
    }
}
