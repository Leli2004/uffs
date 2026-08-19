
public class AuditoriaLote {
    public static void main(String[] args) {
        LoteSementes lote1 = new LoteSementes("L001", "Soja", 1000);
        LoteSementes lote2 = new LoteSementes("L002", "Milho", 500);

        System.out.println("\n*******************************");
        System.out.println("Código do lote 1: " + lote1.GetCodigoLote());
        System.out.println("Cultura do lote 1: " + lote1.GetCultura());
        System.out.println("Quilos disponíveis do lote 1: " + lote1.GetQuilosDisponiveis());
        System.out.println("Taxa de germinação do lote 1: " + lote1.GetTaxaGerminacaoPercentual());
        System.out.println("Status de certificação do lote 1: " + lote1.GetStatusCertificacao());

        System.out.println("\n*******************************");
        System.out.println("Código do lote 2: " + lote2.GetCodigoLote());
        System.out.println("Cultura do lote 2: " + lote2.GetCultura());
        System.out.println("Quilos disponíveis do lote 2: " + lote2.GetQuilosDisponiveis());
        System.out.println("Taxa de germinação do lote 2: " + lote2.GetTaxaGerminacaoPercentual());
        System.out.println("Status de certificação do lote 2: " + lote2.GetStatusCertificacao());
        
        // fracionar antes da análise
        System.out.println("\n*******************************");
        System.out.println("Tentando fracionar lote 1 antes da análise...");
        boolean fracionou1 = lote1.FracionarParaPlantio(100);
        System.out.println("Fracionamento realizado? " + fracionou1);
        System.out.println("Quilos disponíveis do lote 1: " + lote1.GetQuilosDisponiveis());

        // registra laudo válido para o lote 1 (APROVADO)
        System.out.println("\n*******************************");
        System.out.println("\nTentando registrar laudo com taxa válida (90) no lote 1...");
        lote1.RegistrarLaudoGerminacao(90);
        System.out.println("Status de certificação do lote 1: " + lote1.GetStatusCertificacao());

        // registra novo laudo após já ter sido avaliado
        System.out.println("\n*******************************");
        System.out.println("\nTentando registrar novo laudo com taxa (80) no lote 1 após já ter sido avaliado...");
        lote1.RegistrarLaudoGerminacao(80);
        System.out.println("Status de certificação do lote 1: " + lote1.GetStatusCertificacao());

        // fraciona após aprovação
        System.out.println("\n*******************************");
        System.out.println("\nTentando fracionar lote 1 após aprovação...");
        boolean fracionou2 = lote1.FracionarParaPlantio(200);
        System.out.println("Fracionamento realizado? " + fracionou2);
        System.out.println("Quilos disponíveis do lote 1: " + lote1.GetQuilosDisponiveis());

        // rejeitar laudo 2
        System.out.println("\n*******************************");
        System.out.println("\nTentando registrar laudo com taxa (70) no lote 2...");
        lote2.RegistrarLaudoGerminacao(70);
        System.out.println("Status de certificação do lote 2: " + lote2.GetStatusCertificacao());
        
        System.out.println("\nTentando fracionar lote 2 após rejeição...");
        boolean fracionou3 = lote2.FracionarParaPlantio(100);
        System.out.println("Fracionamento realizado? " + fracionou3);
        System.out.println("Quilos disponíveis do lote 2: " + lote2.GetQuilosDisponiveis());
    }
}
