
public class Computador {
    private String nome;
    private Monitor monitor;

    public Computador(String nome) {
        this.nome = nome;
    }

    public void conectarMonitor(Monitor m) {
        System.out.println("\nMonitor " + m.getNome() + " conectado ao computador " + this.nome + "!");
        this.monitor = m;
    }

    public void desconectarMonitor() {
        System.out.println("\nMonitor desconectado do computador " + this.nome + "!");
        this.monitor = null;
    }

    public static void main(String[] args) {
        Computador c1 = new Computador("computador1");
        Computador c2 = new Computador("computador2");

        Monitor m = new Monitor("monitor1");

        c1.conectarMonitor(m);
        c1.desconectarMonitor();
        c2.conectarMonitor(m);
    }    
}
