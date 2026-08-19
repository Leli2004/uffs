
public class TesteSensor {

    public static void main(String[] args) {
        SensorClimatico sensor = new SensorClimatico("123");

        System.out.println("Id: " + sensor.GetIdentificador()
            + "\nC°: " + sensor.GetTemperaturaC()
            + "\nAtivo: " + sensor.GetOperacional()
        );

        System.out.println();
        sensor.desativarSensor();
        sensor.Imprime();

        System.out.println();
        sensor.setTemperaturaCelsius(71);
        sensor.Imprime();

        System.out.println();
        sensor.setTemperaturaCelsius(32);
        sensor.Imprime();

        System.out.println();
        sensor.setTemperaturaCelsius(-100);
        sensor.Imprime();

        System.out.println();
        sensor.ativarSensor();
        sensor.Imprime();
    }
}
