
public class AgenteIA {
    private String nome;

    public AgenteIA() {}

    public AgenteIA(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void enviarMensagem(AgenteIA destino, String conteudo) {
        System.out.println("\nMsg enviada com sucesso do agente '" + this.nome+ "' para o agente '" + destino.getNome() + "'");
    }

    public void receberMensagem(Mensagem msg) {
        System.out.println("\nMsg recebida no agente '" + this.nome + "'. Conteúdo: " + msg.getConteudo() + "'");
    }
}
