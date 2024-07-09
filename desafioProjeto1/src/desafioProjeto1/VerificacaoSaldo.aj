package desafioProjeto1;

public aspect VerificacaoSaldo {
    before(double valor): execution(* desafioProjeto1.ContaBancaria.sacar(..)) && args(valor) {
        System.out.println("Verificando saldo para saque de: " + valor);
    }
}