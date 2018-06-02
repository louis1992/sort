//
//  main.c
//  QuickSort_
//
//  Created by louis on 2018. 5. 26..
//  Copyright © 2018년 louis. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define INPUTSIZE   20000

void quickSort(int *A, int p, int r);
int partition(int *A, int p, int r);

int main(int argc, char** argv) {
    FILE* in_file = fopen("random.txt", "r");
    int data[INPUTSIZE] = {};
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        fscanf(in_file, "%d", &data[i]);
    }
    fclose(in_file);
    
    quickSort(data, 0, INPUTSIZE-1);
    
    for (int i = 0; i < INPUTSIZE; ++i) {
        printf("%d\n", data[i]);
    }
    
    return 0;
}

void quickSort(int *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int partition(int *A, int p, int r) {
    int pivot = A[r];
    int i = p-1;
    
    for (int j = p; j <= r-1; ++j) {
        if (A[j] <= pivot) {
            ++i;
            // swap A[i] and A[j].
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    
    int tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    
    return i+1;
}
