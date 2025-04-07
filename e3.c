// Escreva um programa que tenha inicialmente um vetor de 10 posições, onde o usuário pode inserir
// valores neste vetor quantas vezes ele quiser e quando ele decidir parar, os valores armazenados
// no vetor devem ser impressos. Sempre que o vetor estiver com mais de 70% das posições
// preenchidas, ele deve dobrar de tamanho. Dica: Faça um menu para o usuário poder escolher se
// insere um novo elemento ou finaliza a computação.

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define THRESHOLD 0.7

void printArray(int *array, int size) {
    printf("Valores armazenados no vetor:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array = (int *)malloc(INITIAL_SIZE * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int capacity = INITIAL_SIZE;
    int size = 0;
    int option, value;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo elemento\n");
        printf("2. Finalizar e imprimir vetor\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        if (option == 1) {
            if (size >= capacity * THRESHOLD) {
                capacity *= 2;
                int *newArray = (int *)realloc(array, capacity * sizeof(int));
                if (newArray == NULL) {
                    printf("Erro ao realocar memória.\n");
                    free(array);
                    return 1;
                }
                array = newArray;
                printf("Capacidade do vetor dobrada para %d.\n", capacity);
            }

            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            array[size++] = value;
        } else if (option != 2) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 2);

    printArray(array, size);
    free(array);
    return 0;
}