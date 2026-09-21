
public class Departamento {
    private final String nome;
    private final Funcionario []equipe;
    private int quantidade;

    public Departamento(String nome, int capacidade) {
        this.nome = nome;
        this.equipe = new Funcionario[capacidade];
        this.quantidade = 0;
    }

    public String GetNome() {
        return this.nome;
    }

    public int GetQuantidade() {
        return this.quantidade;
    }

    public void Contratar(Funcionario funcionario) {
        if(this.quantidade < equipe.length) {
            this.equipe[this.quantidade] = funcionario;
            this.quantidade++;
        }
    }

    public double CalculaFolhaBase() {
        double total = 0.0;
        for(int i=0; i<this.quantidade; i++) {
            total += this.equipe[i].CalcularSalario();
        }
        return total;
    }

    public void ListaNomes() {
        for(int i=0; i<this.quantidade; i++) {
            System.out.print(this.equipe[i].GetNome() + "; ");
        }
    }
}

