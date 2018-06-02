#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE   20000

void mergeSort(int* data, int p, int r);
void merge(int* data, int p, int q, int r);

int main() {
    FILE* in_file = fopen("random.txt", "r");
    int data[INPUTSIZE] = {};
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        fscanf(in_file, "%d", &data[i]);
    }
    mergeSort(data, 0, INPUTSIZE-1);
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        printf("%d\n", data[i]);
    }
    
    fclose(in_file);
    return 0;
}

void mergeSort(int* data, int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        mergeSort(data, p, q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}

void merge(int* data, int p, int q, int r) {
    int n = q - p + 1; // p to q.
    int m = r - q;     // q+1 to r.
    int left[n];
    int right[m];

    for (int i = 0; i < n; ++i) {
        left[i] = data[p + i];
    }
    for (int j = 0; j < m; ++j) {
        right[j] = data[q + j + 1];
    }

    int i = 0, j = 0, k = 0;
    // 수도 코드와 실제 구현상의 괴리가 있다.
    while (i < n && j < m) {
        if (left[i] <= right[j]) {
            data[p + k] = left[i];
            ++i;
            ++k;
        } else {
            data[p + k] = right[j];
            ++j;
            ++k;
        }
    }
}