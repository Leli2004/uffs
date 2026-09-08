
public class ServidorCloud {
    private String nome;
    private String host;
    private String usuario;
    private String senha;
    private MemoriaRAM memoriaRAM;
    private CPU cpu;
    private DiscoRigido discoRigido;
    
    public ServidorCloud(String nome, String host, String usuario, String senha) {
        this.nome = nome;
        this.host = host;
        this.usuario = usuario;
        this.senha = senha;
        this.memoriaRAM = new MemoriaRAM();
        this.cpu = new CPU();
        this.discoRigido = new DiscoRigido();
    }

    public boolean boot() {
        boolean memoriaStatus = memoriaRAM.Iniciar();
        boolean cpuStatus = cpu.Iniciar();
        boolean discoStatus = discoRigido.Iniciar();

        return memoriaStatus && cpuStatus && discoStatus;
    }

    public static void main(String[] args) {
        ServidorCloud servidor = new ServidorCloud("Servidor1", "192.168.1.1", "admin", "password");
        
        boolean bootResult = servidor.boot();
        System.out.println("Servidor inicializado: " + bootResult);
    }
}
