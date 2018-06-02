#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE 20000

void loadData(int* data);
void exchange(int* a, int* b);
void selectionSort(int* data);
void print(int* data);

int main(int argc, char** argv) {
    int data[INPUTSIZE]={};
    loadData(data);
    selectionSort(data);
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

void selectionSort(int* data) {
    for(int j=0; j<INPUTSIZE -2; ++j){
        int smallest = j;
        for(int i=j+1; i<INPUTSIZE-1; ++i){
            if(data[i]<data[smallest]){
                smallest = i;
            }
        }
        exchange(&data[j],&data[smallest]);
    }
}

void print(int* data) {
    for (int i = 0; i < INPUTSIZE; ++i)
        printf("%d\n", data[i]);
}
