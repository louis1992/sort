#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadData(vector<int>& source);
int getMax(vector<int>& source);
void countSort(vector<int>& source, int exp);
void radixSort(vector<int>& source);
void print(vector<int>& source);

int main(int argc, char** argv) {
    vector<int> in_data;
    loadData(in_data);
    radixSort(in_data);
    print(in_data);
    
    return 0;
}

void loadData(vector<int>& source) {
    // TODO.
    ifstream inFile("random.txt");
    int buf;
    while (!inFile.eof()) {
        inFile >> buf;
        source.push_back(buf);
    }
    inFile.close();
}

int getMax(vector<int>& source) {
    int max = source[0];
    for (int itr = 0; itr < source.size(); ++itr) {
        if (source[itr] > max)
            max = source[itr];
    }
    return max;
}

void countSort(vector<int>& source, int exp) {
    // TODO.
    int count[10] = {0};
    int n = source.size();
    int output[n];
    
    for (int i = 0; i < n; ++i) {
        count[(source[i]/exp)%10]++;
    }

    for (int i = 1; i < 10; ++i)
        count[i] += count[i-1];
    
    for (int i = n-1; i >= 0; --i) {
        output[count[(source[i]/exp)%10] -1] = source[i];
        count[(source[i]/exp)%10]--;
    }

    for (int i = 0; i < n; ++i)
        source[i] = output[i];
}

void radixSort(vector<int>& source) {
    // TODO.
    int max = getMax(source);
    for (int exp = 1; max/exp > 0; exp *= 10) {
        countSort(source, exp);
    }
}

void print(vector<int>& source) {
    for (int itr = 0; itr < source.size(); ++itr)
        cout << source[itr] << endl;
}
