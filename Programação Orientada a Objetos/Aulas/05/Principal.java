
public class Principal {
    
    public static void main(String[] args) {
        // Maior m = new Maior();
        // System.out.println(m.calcMaior(7.2, 4.2));
        // System.out.println(m.calcMaior(2, 3));
        // System.out.println(m.calcMaior(1.1, 2.8, 3.4));

        Aviao a = new Aviao("aviaozinho");
        a.mover();

        Carro c = new Carro("carrinho");
        c.mover();

        Brinquedo b = new Brinquedo("tedy bear");

        ControleRemoto crb = new ControleRemoto(b);
        crb.mover();

        ControleRemoto crc = new ControleRemoto(c); // inclusão + conversão
        crc.mover(); // sobreposição

        new ControleRemoto(new Aviao("aviaozao")).mover();
        new ControleRemoto(new Carro("carrão")).mover();
    }
}
