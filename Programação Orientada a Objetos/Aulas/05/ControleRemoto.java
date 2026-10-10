
public class ControleRemoto {
    private Brinquedo brinquedo; // atributo do tipo pai

    public ControleRemoto(Brinquedo b) {
        this.brinquedo = b;
    }

    public void mover() {
        this.brinquedo.mover();
    }

    public void configurar(Brinquedo b) {
        System.out.println("Modo genérico");
    }
    
    public void configurar(Carro c) {
        System.out.println("Modo genérico");
    } 
}
