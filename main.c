#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *func, int size, int count);

int *anfRepresentation(int *func, int size);

int *functionElems(int *arr, int *arr2, int size, int count);

int boolMassSize(int *arr, int *arr2, int size, int count);


int main(int args, char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 3;
    int size = raiseToPower(2, n);
    int *binElems = elemsForN(size);
    int f[] = {1, 0, 0, 1, 0, 1, 1, 0};
    int sizeOfF = sizeof(f) / sizeof(int);

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

    int *func2 = anfRepresentation(f, sizeOfF);
    for (int i = 0; i < sizeOfF; ++i) {
        printf("%d ", func2[i]);
    }

    printf("\n");
    printf("\n");

    int *ar3 = functionElems(func2, ar, size, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar3[i * size + j]);
        }
        printf("\n");
    }

    int newSize = boolMassSize(ar3,ar,size,n);
    printf("sum =%d",newSize);

    free(ar);
    free(func2);
    free(ar3);

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

int *functionElems(int *arr, int *arr2, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            int *bin = valueToBinary(arr[i], count);
            for (int j = 0, k = count - 1; j < count; ++j, k--) {
                /*if (bin[j] != 0) {
                    printf("nnn %d\n",j*size+i);
                    int calc = arr2[arr[i]*size];
                    //printf("%d\n",calc);
                    //printf("%d\n",bin[j]);
                } else{
                    printf("nnn %d\n",j*size+i);
                }*/
                result[j * size + i] = bin[k];
            }
        } else {
            for (int j = 0, k = count - 1; j < count; ++j, k--) {
                result[j * size + i] = -99;
            }
        }
    }
    return result;
}

int boolMassSize(int *arr, int *arr2, int size, int count){
    int newSize =0;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i*size+j]>0) {
                printf("%d ", arr[i * size + j]);
                printf("\n");
                printf("arr[i]= %d", arr2[i*size+j]);
                printf("index = %d", i*size+j);
                printf("\n");
                newSize = newSize+1;
                printf("size = %d",newSize);

            }
        }
        printf("\n");
    }
    return newSize;
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
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }
    return result;
}

int *anfRepresentation(int *func, int sizeOfF) {
    int newSize = sizeOfF;
    int *result = calloc(newSize, sizeof(int));
    int j;
    for (int i = 0; i < newSize; ++i) {
        if (func[i] != 0) {
            result[i] = i;
            ++j;
        } else if (func[i] == 0) {
            result[i] = -1;
        }
    }
    printf("\n");
    return result;
}

