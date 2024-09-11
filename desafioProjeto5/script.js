// Função para calcular o saldo de vitórias
function saldo(vitorias, derrotas) {
  let saldoVitorias = vitorias - derrotas;
  return saldoVitorias;
}

// Função para exibir a mensagem com o saldo e o nível
function mensagem(saldoVitorias, nivel) {
  console.log(
    `O Herói possui um saldo de ${saldoVitorias} vitórias e está no nível ${nivel}.`
  );
}

// Função para determinar o nível baseado na quantidade de vitórias
function determinarNivel(vitorias) {
  if (vitorias < 10) {
    return "Ferro";
  } else if (vitorias >= 11 && vitorias <= 20) {
    return "Bronze";
  } else if (vitorias >= 21 && vitorias <= 50) {
    return "Prata";
  } else if (vitorias >= 51 && vitorias <= 80) {
    return "Ouro";
  } else if (vitorias >= 81 && vitorias <= 90) {
    return "Diamante";
  } else if (vitorias >= 91 && vitorias <= 100) {
    return "Lendário";
  } else if (vitorias >= 101) {
    return "Imortal";
  }
}

// Definindo as vitórias e derrotas
let vitorias = 87;
let derrotas = 43;

// Calculando o saldo de vitórias
let saldoVitorias = saldo(vitorias, derrotas);

// Determinando o nível do jogador com base no número de vitórias
let nivel = determinarNivel(vitorias);

// Exibindo a mensagem final
mensagem(saldoVitorias, nivel);
