#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadDate(vector<int>& source, int n);
int getMax(vector<int>& source, int n);
void countSort(vector<int>& source, int n, int exp);
void radixSort(vector<int>& source, int n);
void print(vector<int>& source, int n);

int main(int argc, char** argv) {
    vector<int> in_data;
    // LoadFile().
    radixSort(in_data, in_data.size());
    print(in_data, in_data.size());
    
    return 0;
}

void loadDate(vector<int>& source, int n) {
    // TODO.
}

int getMax(vector<int>& source, int n) {
    int max = source[0];
    // TODO.
    return max;
}

void countSort(vector<int>& source, int n, int exp) {
    // TODO.
    vector<int> output;
    int count[10] = {0};

    // Store count of occurrences in count[]
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
 
    // Build the output array
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
}

void radixSort(vector<int>& source, int n) {
    // TODO.
    int max = getMax(source, n);
    
}

void print(vector<int>& source, int n) {
    for (int itr = 0; itr < n; ++itr)
        cout << source[itr] << endl;
}

//////////////////////////////////////////////////////////
/*
void countSort(vector<int>& source, int n, int exp) {
    // TODO.
    vector<int> output;
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(source[i]/exp)%10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[ (source[i]/exp)%10 ] - 1] = source[i];
        count[ (source[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        source[i] = output[i];
}
*/
//////////////////////////////////////////////////////////
