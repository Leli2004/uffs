
public class PlataformaSaaS {

    private BancoDeDadosLocal bancoDeDados;

    public PlataformaSaaS() {
        this.bancoDeDados = new BancoDeDadosLocal("BancoLocal", "localhost", "usuario", "senha");
    }

    public void CadastrarCliente(String[] dadosCliente) {
        bancoDeDados.SalvarDados(dadosCliente);
    }

    public void ImprimeDados() {
        bancoDeDados.ImprimeDados();
    }
    
    public static void main(String[] args) {
        PlataformaSaaS plataforma = new PlataformaSaaS();
        
        String[] dadosCliente = {"Cliente1", "Cliente2", "Cliente3"};
        plataforma.CadastrarCliente(dadosCliente);
        
        plataforma.ImprimeDados();
    }
}
