#include <stdio.h>
#include <stdlib.h>

void swap(int* f, int* s) {
    *f ^= *s;
    *s ^= *f;
    *f ^= *s;
}

int main() {
    int size;
    scanf("%d", &size);

    int* numbers = calloc(size, sizeof(int));

    for (int index = 0; index < size; index++) {
        scanf("%d", &numbers[index]);
    }

    for (int index = 0; index < size / 2; index++) {
        swap(&numbers[index], &numbers[size - index - 1]);
    }

    for (int index = 0; index < size; index++) {
        printf("%d ", numbers[index]);
    }

    free(numbers);

    return 0;
}
