#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE 20000

void bubbleSort(int* A);

int main(int argc, char** argv) {
    FILE* inFile = fopen("random.txt", "r");
    int data[INPUTSIZE] = {};
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        fscanf(inFile, "%d", &data[i]);
    }
    fclose(inFile);
    
    bubbleSort(data);
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}

void bubbleSort(int* A) {
    unsigned int i = 0, j = INPUTSIZE - 1;
    for (i = 0;i < INPUTSIZE; ++i) {
        for (j = INPUTSIZE - 1; j > i; --j) {
            if (A[j-1] >= A[j]) {
                unsigned int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
            }
        }
    }
}

