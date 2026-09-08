
public class ContaBancaria {
    private String numeroConta;
    private double saldo;
    private Registro[] registros;

    public ContaBancaria(String numeroConta) {
        this.numeroConta = numeroConta;
        this.saldo = 0.0;
        this.registros = new Registro[50]; 

        this.registros[0] = new Registro("08/09/2026", "Conta criada");
    }

    public void ImprimeRegistros() {
        System.out.println("\nRegistros da conta " + numeroConta + ":");
        for (Registro registro : registros) {
            if (registro != null) {
                registro.ImprimirRegistro();
            }
        }
    }

    public void AdicionaRegistro(String data, String operacao) {
        for (int i = 0; i < registros.length; i++) {
            if (registros[i] == null) {
                registros[i] = new Registro(data, operacao);
                return;
            }
        }
        System.out.println("\nNão é possível adicionar mais registros. Limite atingido.");
    }
 
    public static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria("12345-6");
        conta.ImprimeRegistros();
        
        conta.AdicionaRegistro("09/09/2026", "Depósito de R$ 1000,00");
        conta.ImprimeRegistros();
    }
}
