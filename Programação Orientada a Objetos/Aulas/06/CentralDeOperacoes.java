public class CentralDeOperacoes {

    public static void main(String[] args) {

        Veiculo[] frota = new Veiculo[3];
        frota[0] = new Veiculo("CAR-01", new Motor(1.0, "flex"));
        frota[1] = new Veiculo("AVI-01", new Motor(3.0, "querosene"));


        int[] alvo = {0, 1, 2, 7, 0};
        String[] quantidades = {"40", "180", "30", "50", "quarenta"};

        for (int i = 0; i < alvo.length; i++) {
            try {
                double litros = Double.parseDouble(quantidades[i]);
                frota[alvo[i]].abastecer(litros, "gasolina");
                System.out.println("OK: " + frota[alvo[i]].getPrefixo()
                                   + " recebeu " + litros + " L de gasolina");
            } catch (OperacaoInvalidaException e) {
                System.out.println("RECUSADO [" + e.getClass().getSimpleName() + "]: "
                                   + e.getMessage());
            } catch (NumberFormatException e) {
                System.out.println("RECUSADO: quantidade invalida -> " + e.getMessage());
            } catch (IllegalArgumentException e) {
                System.out.println("RECUSADO: " + e.getMessage());
            } catch (NullPointerException e) {
                System.out.println("RECUSADO: nao existe veiculo na posicao " + alvo[i]);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("RECUSADO: a frota nao tem a posicao " + alvo[i]);
            } finally {
                System.out.println("-- pedido " + i + " registrado no diario de bordo");
            }
        }

        System.out.println("Fim do turno.");
    }
}