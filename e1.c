// Escreva um programa que solicita ao usuário a quantidade de alunos de uma turma e aloca um
// vetor de notas (números reais). Depois de ler as notas, imprime a média aritmética. Obs: não deve
// ocorrer desperdício de memória; e após ser utilizada a memória deve ser devolvida
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numAlunos;
    float *notas, soma = 0.0, media;

    // Solicita a quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &numAlunos);

    // Verifica se o número de alunos é válido
    if (numAlunos <= 0) {
        printf("O número de alunos deve ser maior que zero.\n");
        return 1;
    }

    // Aloca memória para o vetor de notas
    notas = (float *)malloc(numAlunos * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memória.\n");
    }

    // Lê as notas dos alunos e calcula a soma
    for (int i = 0; i < numAlunos; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        while (scanf("%f", &notas[i]) != 1) {
            printf("Entrada inválida. Por favor, insira um número válido para a nota do aluno %d: ", i + 1);
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
        soma += notas[i];
    }

    // Calcula e imprime a média aritmética
    media = soma / numAlunos;
    printf("A média aritmética da turma é: %.2f\n", media);

    // Libera a memória alocada
    free(notas);
    notas = NULL;

    return 0;
}