#include <stdlib.h>
#include <string.h>

void* newcalloc(size_t num, size_t size) {
    // Aloca memória suficiente para armazenar num elementos de tamanho size
    void* ptr = malloc(num * size);
    if (ptr == NULL) {
        // Retorna NULL se a alocação falhar
        return NULL;
    }
    // Inicializa a memória alocada com 1
    memset(ptr, 1, num * size);
    return ptr;
}