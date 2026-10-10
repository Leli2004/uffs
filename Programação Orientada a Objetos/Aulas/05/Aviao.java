
public class Aviao extends Brinquedo {
    
    public Aviao(String nome) {
        super(nome);
    }

    @Override 
    public void mover() {
        System.out.println(this.getNome() + ": voar");
    }
}
