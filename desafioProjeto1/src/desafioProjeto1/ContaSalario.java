package desafioProjeto1;

public class ContaSalario extends ContaBancaria {
    public ContaSalario(double saldoInicial) {
        super(saldoInicial);
    }

    @Override
    public void sacar(double valor) {
        debitar(valor);
    }
}