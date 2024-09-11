// Classe para representar um herói de aventura
class Heroi {
  // Construtor para inicializar as propriedades do herói
  constructor(nome, idade, tipo) {
    this.nome = nome; // Nome do herói
    this.idade = idade; // Idade do herói
    this.tipo = tipo; // Tipo do herói (guerreiro, mago, monge, ninja)
  }

  // Método para o herói atacar com base no seu tipo
  atacar() {
    let ataque;

    // Determinando o tipo de ataque com base no tipo do herói
    switch (this.tipo.toLowerCase()) {
      case "mago":
        ataque = "usou magia."; // Ataque para o mago
        break;
      case "guerreiro":
        ataque = "utilizou sua espada."; // Ataque para o guerreiro
        break;
      case "monge":
        ataque = "praticou artes marciais."; // Ataque para o monge
        break;
      case "ninja":
        ataque = "lançou uma shuriken."; // Ataque para o ninja
        break;
      default:
        ataque = "realizou um ataque desconhecido."; // Caso o tipo seja desconhecido
        break;
    }

    // Exibindo a mensagem de ataque do herói
    console.log(
      `${this.tipo.charAt(0).toUpperCase() + this.tipo.slice(1)} ${ataque}`
    );
  }
}

// Criando instâncias dos heróis com diferentes tipos
const heroi1 = new Heroi("Gandalf", 150, "mago");
const heroi2 = new Heroi("Arthur", 30, "guerreiro");
const heroi3 = new Heroi("Dhalsim", 40, "monge");
const heroi4 = new Heroi("Hanzo", 25, "ninja");

// Chamando o método atacar para cada herói
heroi1.atacar(); // Mago usou magia
heroi2.atacar(); // Guerreiro utilizou sua espada
heroi3.atacar(); // Monge praticou artes marciais
heroi4.atacar(); // Ninja lançou uma shuriken
