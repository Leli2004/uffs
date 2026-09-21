
public class Gerente extends Funcionario {
    private double bonus;

    public Gerente(String nome, String cpf, double salarioBase, double bonus) {
        super(nome, cpf, salarioBase);
        this.bonus = bonus;
    }

    public double GetBonus() {
        return this.bonus;
    }

    public void SetBonus(double bonus) {
        this.bonus = bonus;
    }

    // public double CalcularSalario() {
    //     return this.salarioBase + this.bonus;
    // }

    @Override 
    public double CalcularSalario() {
        return super.CalcularSalario() + this.bonus;
    }

    @Override 
    public String toString() {
        return super.toString() + " | Bônus: " + this.bonus + " | Salário final: R$" + this.CalcularSalario();
    }
}
