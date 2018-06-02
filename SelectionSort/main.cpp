#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadData(vector<int>& source);
void selectionSort(vector<int>& source);
void print(vector<int>& source);

int main(int argc, char** argv) {
    vector<int> in_data;
    loadData(in_data);
    selectionSort(in_data);
    print(in_data);
    return 0;
}

void loadData(vector<int>& source) {
    ifstream inFile("random.txt");
    int buf;
    while (!inFile.eof()) {
        inFile >> buf;
        source.push_back(buf);
    }
    inFile.close();
}

void selectionSort(vector<int>& source) {
    //TODO.
}

void print(vector<int>& source) {
    for (int itr = 0; itr < source.size(); ++itr)
        cout << source[itr] << endl;
}