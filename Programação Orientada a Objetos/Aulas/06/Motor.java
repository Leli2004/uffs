public class Motor {

    private double cilindrada;
    private String combustivel;

    public Motor(double cilindrada, String combustivel) {
        this.cilindrada = cilindrada;
        this.combustivel = combustivel;
    }

    public double getCilindrada() {
        return cilindrada;
    }

    public String getCombustivel() {
        return combustivel;
    }

    public boolean aceita(String outro) {
 
        // Equals = Compara o conteúdo ou valor lógico dos objetos.
        // Pertence originalmente à classe java.lang.Object, mas é sobrescrito por classes como String 
        // para verificar se o interior delas é igual.
         
        if (combustivel.equals("flex")) {
            return outro.equals("gasolina") || outro.equals("alcool");
        }


        return combustivel.equals(outro);
    }
}