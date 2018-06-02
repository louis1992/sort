#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE 20000

void loadData(int* data);
void exchange(int* a, int* b);
void insertionSort(int* data);
void print(int* data);

int main(int argc, char** argv) {
    int data[INPUTSIZE]={};
    loadData(data);
    insertionSort(data);
    print(data);
    return 0;
}

void loadData(int* data) {
    FILE *inFile = fopen("random.txt", "r");
    for (int i = 0; i < INPUTSIZE; ++i)
        fscanf(inFile, "%d", &data[i]);
    fclose(inFile);
}

void exchange(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int* data) {
    for(int i=0; i<INPUTSIZE;++i){
        int j = i;
        while(j>0 && data[j-1]>data[j]){
            exchange(&data[j],&data[j-1]);
            --j;
        }
    }
}

void print(int* data) {
    for (int i = 0; i < INPUTSIZE; ++i)
        printf("%d\n", data[i]);
}
