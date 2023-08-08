#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int size, int& compCount, int& swapCount){
    int i, key, j;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
            compCount++;
            swapCount++;
        }
        arr[j + 1] = key;
        compCount++;
    }
}

int main(){
    srand(time(NULL));

    ofstream file;
    file.open("C:\\hm\\results.csv");

    for (int k = 0; k < 5; k++){
        int arr1[100];
        int arr2[500];
        int arr3[1000];
        int compCount = 0, swapCount = 0;
        for (int i = 0; i < 100; i++){
            arr1[i] = rand() % 100;
        }
        for (int i = 0; i < 500; i++){
            arr2[i] = rand() % 100;
        }for (int i = 0; i < 1000; i++){
            arr3[i] = rand() % 100;
        }

        insertionSort(arr1, 100, compCount, swapCount);
        insertionSort(arr2,500,compCount,swapCount);
        insertionSort(arr3,1000,compCount,swapCount);

        file << "100;" << compCount << ";" << swapCount << endl;
    }

    file.close();

    return 0;
}

