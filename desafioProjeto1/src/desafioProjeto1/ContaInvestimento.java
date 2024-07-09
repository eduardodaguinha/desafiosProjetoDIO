package desafioProjeto1;

public class ContaInvestimento extends ContaBancaria {
    public ContaInvestimento(double saldoInicial) {
        super(saldoInicial);
    }

    @Override
    public void sacar(double valor) {
        debitar(valor);
    }
}