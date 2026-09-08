
public class CPU {
    private boolean status;

    public CPU() {
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
