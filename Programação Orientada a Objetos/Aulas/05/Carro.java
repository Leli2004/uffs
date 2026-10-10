
public class Carro extends Brinquedo {
    
    public Carro(String nome) {
        super(nome);
    }
    
    @Override 
    public void mover() {
        System.out.println(this.getNome() + ": correr");
    }
}
