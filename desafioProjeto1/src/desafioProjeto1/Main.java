package desafioProjeto1;

public class Main {
 public static void main(String[] args) {
     ContaBancaria contaCorrente = new ContaCorrente(1000);
     ContaBancaria contaSalario = new ContaSalario(500);
     ContaBancaria contaPoupanca = new ContaPoupanca(2000);
     ContaBancaria contaInvestimento = new ContaInvestimento(3000);

     contaCorrente.sacar(1200);
     contaSalario.sacar(600);
     contaPoupanca.sacar(1500);
     contaInvestimento.sacar(3500);
 }
}