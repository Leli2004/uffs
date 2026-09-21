
public class Vendedor extends Funcionario {
    private double comissao;

    public Vendedor(String nome, String cpf, double salarioBase, double comissao) {
        super(nome, cpf, salarioBase);
        this.comissao = comissao;
    }

    public double GetComissao() {
        return this.comissao;
    }

    public void SetComissao(double comissao) {
        this.comissao = comissao;
    }

    public void RegistrarVenda(double valorComissao) {
        this.comissao += valorComissao;
    }

    @Override 
    public double CalcularSalario() {
        return super.CalcularSalario() + this.comissao;
    }

    @Override 
    public String toString() {
        return super.toString() + " | Comissão: " + this.comissao + " | Salário final: R$" + this.CalcularSalario();
    }
}
