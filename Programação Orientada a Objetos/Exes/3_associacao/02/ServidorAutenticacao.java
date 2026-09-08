
public class ServidorAutenticacao {
    private boolean active;
    
    public ServidorAutenticacao() {
        this.active = true;
    }

    public void desativa() {
        this.active = false;
    }

    public void ativa() {
        this.active = true;
    }

    public boolean validarLogin(Usuario u) {
        if(this.active == false) {
            return true;
        }

        if(u.getLogin().equals(u.getSenha()) || u.getSenha().length() < 6) {
            return false;
        }

        return true;
    }
}
