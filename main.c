#include <stdio.h>
#include <locale.h>

// ESTRUTURAS DOS DADOS
typedef struct {
  float notaP1; // nota P1
  float notaP2; // nota p2
  float notaE1; // nota exercício1
  float notaE2; // nota exercício2
  float notaTF; // nota trabalho final
  float media;  // média do aluno
} Notas;
Notas notas; // definindo notas do aluno

typedef struct {
  char nome[30]; // nome de cada aluno
  char matricula[12]; // matrícula do aluno
  float frequencia; // frequência do aluno
  int situacao; // situação do aluno APROVADO ou REPROVADO
  Notas notas; // solicitando typedef de notas do aluno
} Alunos;
Alunos aluno[150]; // definindo typedef como aluno

typedef struct {
  char nome_sala[20]; // nome da sala
  int quantidade_de_alunos_sala; // quantidade de alunos da sala
  Alunos aluno[150]; //solicitando typedef de alunos
} Turma;
Turma sala[10]; // definir typedef das salas

// DECLARAÇÃO DE FUNÇÕES
void inicio(); // função que define o que irá fazer no programa
void quantidade_de_turma(); // função para saber quantas turmas serão cadastradas
void cadastro_aluno(); // cadastrar os dados de cada aluno de cada turma
void cadastro_notas_alunos(); // cadastrar notas de cada aluno
void aprovados(); // lista de aprovados
void reprovados(); // lista de reprovados
void todos_alunos(); // lista de todos alunos em suas turmas

// VARIÁVEIS GLOBAIS
int qtd_sala, escolha;

// BLOCO MAIN
int main() {
  setlocale(LC_ALL, "Portuguese"); // Habilitação de símbolos em língua portuguesa
  do {
    inicio();
    switch (escolha) {
    case 1:
      system("cls");
      quantidade_de_turma();
      break;
    case 2:
      system("cls");
      aprovados();
      break;
    case 3:
      system("cls");
      reprovados();
      break;
    case 4:
      system("cls");
      todos_alunos();
      break;
    case 5:
      break;
    default:
      printf("CÓDIGO INVÁLIDO!");
      break;
    }
  } while (escolha != 5);
  printf("\nAté logo!");
  return 0;
}

// FUNÇÕES
void inicio() {

  printf("\n\n=== BEM VINDO AO GERENCIAMENTO DOS ALUNOS ===\n");
  printf("\n 1. Cadastro de turmas e alunos\n 2. Lista de aprovados\n 3. Lista "
         "de reprovados\n 4. Lista de todos alunos\n 5. Sair");
  printf("\nDigite o código do que deseja: ");
  scanf("%d", &escolha);
}

void quantidade_de_turma() {

  printf("\nQuantas turmas serão gerenciadas? "); // saber quantas turmas serão necessárias

  scanf("%d", &qtd_sala);
  if (qtd_sala <= 10) {
    for (int i = 0; i < qtd_sala; i++) { // saber o nome de cada turma
      printf("\n\nQual o nome da sala %d? ", i + 1);
      fseek(stdin, 0, SEEK_END);
      gets(&sala[i].nome_sala);

      printf("\nQuantos alunos tem a sala %s? ", sala[i].nome_sala); // saber o número de alunos
      fseek(stdin, 0, SEEK_END);
      scanf("%d", &sala[i].quantidade_de_alunos_sala);
      if (sala[i].quantidade_de_alunos_sala > 50) {
        printf("\nMUITOS ALUNOS, TENTE NOVAMENTE\n");
        printf("\nQuantos alunos tem a sala %s? ", sala[i].nome_sala); // saber o número de alunos
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &sala[i].quantidade_de_alunos_sala);

      } else{
      }
    }
    cadastro_aluno();
  } else {
    printf("\nMUITAS SALAS, TENTE NOVAMENTE\n");
    quantidade_de_turma();
  }
};

void cadastro_aluno() {
  int i, j; // i para sala e j para quantidade de alunos

  system("cls");
  printf("\n Salas:"); // lista todas salas cadastradas
  for (i = 0; i < qtd_sala; i++) {
    printf("\n  %d. %s: %d alunos.", i + 1, sala[i].nome_sala, sala[i].quantidade_de_alunos_sala); // printa listas cadastradas
  }
  printf("\n");
  for (i = 0; i < qtd_sala;
       i++) { // colocar nomes de alunos dentro de suas respectivas salas
    for (j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {
      printf("\nDigite o nome do %dº aluno, da sala %s: ", j + 1, &sala[i].nome_sala);
      fseek(stdin, 0, SEEK_END);
      gets(&sala[i].aluno[j].nome);
      printf("Digite a matrícula desse aluno: ");
      fseek(stdin, 0, SEEK_END);
      gets(&sala[i].aluno[j].matricula);
    }
  }
  system("cls");
  for (i = 0; i < qtd_sala; i++) { // imprimir alunos em suas devidas salas
    for (j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {
      printf("\nSala: %s , Nome: %s, Matrícula: %s", &sala[i].nome_sala, sala[i].aluno[j].nome, sala[i].aluno[j].matricula);
    }
    printf("\n");
  }
  cadastro_notas_alunos();
};

void cadastro_notas_alunos() {
  for (int i = 0; i < qtd_sala; i++) {
    for (int j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {

      printf("\n\nQuantas vezes %s estava presente na sala %s (Total=64): ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].frequencia);

      printf("Qual a nota P1 (Max= 30) de %s da sala %s: ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].notas.notaP1);

      printf("Qual a nota P2 (Max= 50) de %s da sala %s: ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].notas.notaP2);

      printf("Qual a nota E1 (Max = 5) de %s da sala %s: ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].notas.notaE1);

      printf("Qual a nota E2 (Max = 5) de %s da sala %s: ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].notas.notaE2);

      printf("Qual a nota TF (Max = 10) de %s da sala %s: ", sala[i].aluno[j].nome, &sala[i].nome_sala);
      scanf("%f", &sala[i].aluno[j].notas.notaTF);

      sala[i].aluno[j].notas.media =
          sala[i].aluno[j].notas.notaP1 + sala[i].aluno[j].notas.notaP2 +
          sala[i].aluno[j].notas.notaE1 + sala[i].aluno[j].notas.notaE2 +
          sala[i].aluno[j].notas.notaTF;
      printf("A NOTA FINAL de %s da sala %s: %.2f", sala[i].aluno[j].nome,
             &sala[i].nome_sala, sala[i].aluno[j].notas.media);

      if ((sala[i].aluno[j].notas.media >= 70) &&
          (sala[i].aluno[j].frequencia >= 40)) {
        sala[i].aluno[j].situacao = 1;
      } else {
        sala[i].aluno[j].situacao = 0;
      };
    }
  }
  system("cls");
};

void aprovados() {
  printf("\n\n LISTAGEM: APROVADOS\n");
  for (int i = 0; i < qtd_sala; i++) {
    for (int j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {
      if (sala[i].aluno[j].situacao == 1) {
        printf("\nSala: %s, Aluno: %s, Nota: %.2f, Frequência: %.2f%%: ", &sala[i].nome_sala, sala[i].aluno[j].nome, sala[i].aluno[j].notas.media, (sala[i].aluno[j].frequencia / 64) * 100);
      }
    }
  }
  printf("\n");
};

void reprovados() {
  printf("\n\n LISTAGEM: REPROVADOS\n");
  for (int i = 0; i < qtd_sala; i++) {
    for (int j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {
      if (sala[i].aluno[j].situacao == 0) {
        printf("\nSala: %s, Aluno: %s, Nota: %.2f, Frequência: %.2f%%: ", &sala[i].nome_sala, sala[i].aluno[j].nome, sala[i].aluno[j].notas.media, (sala[i].aluno[j].frequencia / 64) * 100);
      }
    }
  }
  printf("\n");
};

void todos_alunos() {
  printf("\n\n LISTAGEM: TODOS ALUNOS\n");
  for (int i = 0; i < qtd_sala; i++) {
    for (int j = 0; j < sala[i].quantidade_de_alunos_sala; j++) {
      printf("\nSala: %s, Aluno: %s, Nota: %.2f, Frequência: %.2f%%: ",
             &sala[i].nome_sala, sala[i].aluno[j].nome, sala[i].aluno[j].notas.media, (sala[i].aluno[j].frequencia / 64) * 100);
    }
  }
  printf("\n");
};
