
// sobrecarga => em tempo de compilação
// sobrescrita => JVM

public class Maior {
    // Exemplo de polimorfismo = printf, que trata cada tipo de modo específico 
    
    public int calcMaior(int x, int y) {
        return (x > y) ? x : y;
    }

    public float calcMaior(float x, float y) {
        return (x > y) ? x : y;
    }

    public double calcMaior(double x, double y) {
        return (x > y) ? x : y;
    }

    public double calcMaior(double x, double y, double z) {
        return calcMaior(calcMaior(x, y), z);
    }

    // Errado (não compila):
    // public int calcMaior(double x, double y) {...}
}
