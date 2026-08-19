
public class SensorClimatico {
    private String identificador;
    private double temperaturaCelsius;
    private boolean operacional;

    public SensorClimatico(String id) {
        this.identificador = id;
        this.temperaturaCelsius = 20;
        this.operacional = true;
    }

    public String GetIdentificador() {
        return this.identificador;
    }

    public double GetTemperaturaC() {
        return this.temperaturaCelsius;
    }

    public boolean GetOperacional() {
        return this.operacional;
    }
    
    public void setTemperaturaCelsius(double novaTemperatura) {
        if(novaTemperatura < -50 || novaTemperatura > 60) {
            System.err.println(">> ERRO: nova temperatura inválida.\n");
        } else {
            this.temperaturaCelsius = novaTemperatura;
        }
    }

    public void desativarSensor() {
        this.operacional = false;
    }

    public void ativarSensor() {
        this.operacional = true;
    }

    public void Imprime() {
        System.out.println("Imprimindo dados do sensor... \nId: " + this.identificador
            + "\nC°: " + this.temperaturaCelsius
            + "\nAtivo: " + this.operacional
        );
    }

}
