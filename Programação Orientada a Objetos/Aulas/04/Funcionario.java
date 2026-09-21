
public class Funcionario {
    private final String nome;
    private final String cpf;
    protected double salarioBase;

    public Funcionario(String nome, String cpf, double salarioBase) {
        this.nome = nome;
        this.cpf = cpf;
        this.salarioBase = salarioBase;
    }

    public String GetNome() {
        return this.nome;
    } 

    public String GetCpf() {
        return this.cpf;
    }

    public double GetSalarioBase() {
        return this.salarioBase;
    }

    public void SetNome(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    public void Reajustar(double percentual) {
        if(percentual<0) percentual = 0;
        if(percentual>100) percentual = 100;
        this.salarioBase += percentual;
    }

    public double CalcularSalario() {
        return this.salarioBase;
    }

    @Override 
    public String toString() {
        return String.format("Nome: %s | CPF: %s | Salário base: R$%.2f", this.nome, this.cpf, this.salarioBase);
    }
}
