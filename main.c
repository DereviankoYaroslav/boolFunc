#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // заголовочный файл, содержащий функции API

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *func, int size, int count);

int *anfRepresentation(int *func, int size);


int main(int args, char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 3;
    int size = raiseToPower(2, n);
    int *binElems = elemsForN(size);
    int f[] = {0, 0, 1, 1, 0, 1, 1, 0};


    for (int i = 0; i < size; ++i) {
        printf("%d ", binElems[i]);
    }
    printf("\nБулеві значення для змінних\n");
    int *ar = binaryElements(binElems, size, n);
    for (int i = 0; i < n; ++i) {
        printf("x%d = ", i + 1);
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar[i * size + j]);
        }
        printf("\n");
    }
/*
    int *x1 = malloc(size * sizeof(int));
    int *x2 = malloc(size * sizeof(int));
    int *x3 = malloc(size * sizeof(int));

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            for (int j = 0; j < size; ++j) {
                x1[j] = ar[i * size + j];
                printf("%d ", x1[j]);
            }
            printf("\n");
        } else if (i == 1) {
            for (int j = 0; j < size; ++j) {
                x2[j] = ar[i * size + j];
                printf("%d ", x2[j]);
            }
            printf("\n");
        } else if (i == 2) {
            for (int j = 0; j < size; ++j) {
                x3[j] = ar[i * size + j];
                printf("%d ", x3[j]);
            }
            printf("\n");
        }
    }
    /*

    int *ANF1 = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i) {
        if (x1[i] == 0) {
            ANF1[i] = '0';
        } else if (x1[i] == 1) {
            ANF1[i] = 'x';
        }
        printf("%c ", ANF1[i]);
    }
    printf("\n");

    int *ANF2 = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i) {
        if (x2[i] == 0) {
            ANF2[i] = '0';
        } else if (x2[i] == 1) {
            ANF2[i] = 'x';
        }
        printf("%c ", ANF2[i]);
    }
    printf("\n");

    int *ANF3 = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i) {
        if (x3[i] == 0) {
            ANF3[i] = '0';
        } else if (x3[i] == 1) {
            ANF3[i] = 'x';
        }
        printf("%c ", ANF3[i]);
    }
    printf("\n");*/

    /*int *func = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i) {
      func[i] = x2[i]^x3[i]^x1[i]*x3[i]^x2[i]*x3[i];
    }
    for (int i = size-1; i >= 0; --i) {
        printf("%d", func[i]);
    }*/

    int *func2 = anfRepresentation(f, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", func2[i]);
    }

    return 0;
}

int *binaryElements(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            result[j * size + i] = bin[k];
            //printf("%d\n",bin[j]);
        }
    }
    return result;
}

int *valueToBinary(int i, int rank) {
    int *res = calloc(rank, sizeof(int));
    for (int j = 0; j < rank; ++j) {
        res[rank - 1 - j] = i >> j & 1u;
    }
    return res;
}

int raiseToPower(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

int *elemsForN(int size) {
    int *result = calloc(size,sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }
    return result;
}

int *anfRepresentation(int *func, int size) {
    int *result = calloc(size, sizeof (int));
    int j;
    for (int i = 0; i < size; ++i) {
        if (func[i] != 0) {
            result[j] = i;
            j++;
        }
    }
    return result;
}

