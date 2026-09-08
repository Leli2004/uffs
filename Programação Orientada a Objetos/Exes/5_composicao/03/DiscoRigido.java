
public class DiscoRigido {
    private boolean status;

    public DiscoRigido() {
        this.status = false;
    }

    public boolean Iniciar() {
        this.status = true;
        return true;
    }

    public boolean Desligar() {
        this.status = false;
        return true;
    }

    public boolean getStatus() {
        return this.status;
    }
}
