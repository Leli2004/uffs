
public class LoteSementes {
    private String codigoLote, cultura;
    private double quilosDisponiveis, taxaGerminacaoPercentual;
    private String statusCertificacao; // Valores permitidos: "EM_ANALISE", "APROVADO", "REJEITADO"

    String StatusAnalise = "EM_ANALISE";
    String StatusAprovado = "APROVADO";
    String StatusRejeitado = "REJEITADO";

    public LoteSementes(String codigoLote, String cultura, double quilosDisponiveis) {
        this.codigoLote = codigoLote;
        this.cultura = cultura;
        this.quilosDisponiveis = quilosDisponiveis;
        this.taxaGerminacaoPercentual = 0;
        this.statusCertificacao = StatusAnalise; // Inicialmente, o status é "EM_ANALISE"
    }

    public String GetCodigoLote() {
        return codigoLote;
    }

    public String GetCultura() {
        return cultura;
    }

    public double GetQuilosDisponiveis() {
        return quilosDisponiveis;
    }

    public double GetTaxaGerminacaoPercentual() {
        return taxaGerminacaoPercentual;
    }

    public String GetStatusCertificacao() {
        return statusCertificacao;
    }
    
    private void SetTaxaGerminacaoPercentual(double taxaGerminacaoPercentual) {
        this.taxaGerminacaoPercentual = taxaGerminacaoPercentual;
    }

    private void SetQuilosDisponiveis(double quilosDisponiveis) {
        this.quilosDisponiveis = quilosDisponiveis;
    }

    private void SetStatusCertificacao(String statusCertificacao) {
        this.statusCertificacao = statusCertificacao;
    }
    
    public void RegistrarLaudoGerminacao(double taxa) {
        if(!this.statusCertificacao.equals(StatusAnalise)) {
            System.err.println(">> ERRO: laudo não é permitido nesse status.\n");
            return;
        }

        if(taxa < 0 || taxa > 100) {
            System.err.println(">> ERRO: taxa de germinação inválida. Deve estar entre 0 e 100.\n");
            return;
        }
        this.SetTaxaGerminacaoPercentual(taxa);

        if(taxa >= 85) {
            this.SetStatusCertificacao(StatusAprovado);
        } else {
            this.SetStatusCertificacao(StatusRejeitado);
        }
    }

    public boolean FracionarParaPlantio(double quilosRequisitados) {
        if(this.statusCertificacao != StatusAprovado) {
            System.err.println(">> ERRO: fracionamento não é permitido nesse status.\n");
            return false;
        }

        if(quilosRequisitados <= 0) {
            System.err.println(">> ERRO: quantidade de quilos requisitada inválida.\n");
            return false;
        }

        if(quilosRequisitados > this.quilosDisponiveis) {
            System.err.println(">> ERRO: quantidade de quilos requisitada maior que a disponível.\n");
            return false;
        }

        this.SetQuilosDisponiveis(this.quilosDisponiveis - quilosRequisitados);
        return true;
    }

}

