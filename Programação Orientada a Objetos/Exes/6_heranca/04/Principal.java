
public class Principal {
    public static void main(String[] args) {
        Cachorro cachorro = new Cachorro("Rex", 20.0, "Pastor Alemão", 2);

        System.out.println("Nome: " + cachorro.getNome());
        System.out.println("Peso: " + cachorro.getPeso());
        System.out.println("Raça: " + cachorro.getRaca());
        System.out.println("Dose: " + cachorro.calcularDose());

        Coleira coleira = new Coleira(cachorro, "Vermelha");

        System.out.println("Cor da coleira: " + coleira.getCor());
        System.out.println("Coleira pertence ao: " + coleira.getCachorro().getNome());
    }
}
