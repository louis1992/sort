#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE 20000

void loadData(int* data);
void maxHeapify(int* data, int n);
void heapSort(int* data);
void print(int* data);

int main(int argc, char** argv) {
    int data[INPUTSIZE]={};
    loadData(data);
    heapSort(data);
    print(data);
    return 0;
}

void loadData(int* data) {
    FILE *inFile = fopen("random.txt", "r");
    for (int i = 0; i < INPUTSIZE; ++i)
        fscanf(inFile, "%d", &data[i]);
    fclose(inFile);
}

void maxHeapify(int* data, int n) {
    for (int i = n; i >=0; --i) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest;
        if (left <= n && data[left] > data[i])
            largest = left;
        else
            largest = i;
        if (right <= n && data[right] > data[largest])
            largest = right;
        
        if (largest != i) {
            int tmp = data[i];
            data[i] = data[largest];
            data[largest] = tmp;
            maxHeapify(data, largest);
        }
    }
}

void heapSort(int* data) {
    maxHeapify(data, INPUTSIZE-1);
    for (int i = INPUTSIZE - 1; i > 0; --i) {
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        maxHeapify(data, i-1);
    }
}

void print(int* data) {
    for (int i = 0; i < INPUTSIZE; ++i)
        printf("%d\n", data[i]);
}
