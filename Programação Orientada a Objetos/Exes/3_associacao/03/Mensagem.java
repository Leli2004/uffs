
public class Mensagem {
    private String remetente;
    private String destinatario;
    private String conteudo;

    public Mensagem(String remetente, String destinatario, String conteudo) {
        this.remetente = remetente;
        this.destinatario = destinatario;
        this.conteudo = conteudo;
    }

    public void imprime() {
        System.out.println("\nDados da mensagem... \nRemetente: " + this.remetente
            + "\nDestinatário: " + this.destinatario
            + "\nConteúdo: " + this.conteudo
        );
    }

    public String getConteudo() {
        return this.conteudo;
    }

    public static void main(String[] args) {
        Mensagem msg = new Mensagem("abc", "cde", "Ratos entrem nos sapatos!");
        msg.imprime();

        AgenteIA agente1 = new AgenteIA("agente1");
        AgenteIA agente2 = new AgenteIA("agente2");

        agente1.enviarMensagem(agente2, msg.getConteudo());

        agente2.receberMensagem(msg);
    }
}
