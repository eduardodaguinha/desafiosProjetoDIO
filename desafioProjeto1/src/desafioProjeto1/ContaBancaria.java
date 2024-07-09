package desafioProjeto1;

public abstract class ContaBancaria {
    protected double saldo;

    public ContaBancaria(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    public abstract void sacar(double valor);
    
    public double getSaldo() {
        return saldo;
    }

    protected void debitar(double valor) {
        if (saldo >= valor) {
            saldo -= valor;
            System.out.println("Saque de " + valor + " realizado com sucesso. Saldo restante: " + saldo);
        } else {
            System.out.println("Saldo insuficiente para saque de " + valor + ". Saldo atual: " + saldo);
        }
    }
}