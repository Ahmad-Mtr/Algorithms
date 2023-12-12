#include <iostream>

using namespace std;
const int n = 5;
int X[n] = {10, 50, 12, 3, 1};

// Helper Functions
int getLeft(int index) {
    return index * 2 + 1;
}

int getRight(int index) {
    return index * 2 + 2;
}

void Swap(int indexA, int indexB) {
    int temp = X[indexA];
    X[indexA] = X[indexB];
    X[indexB] = temp;
}

//Sorting Algorithms
void selectionSort(int A[n]) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            c++;
            if (A[j] > A[i]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}


void bubbleSort(int A[n]) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            c++;
            if (A[j + 1] < A[i]) {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void insertionSort(int A[n]) {
    for (int i = 1; i < n; ++i) {
        int x = A[i];
        int j = i - 1;
        while (x < A[j] && j > 0) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = x;
    }
}

void quickSort(int A[n]) {

}
void Heapify(int A[n]) {
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0) {
            if (A[j] > A[j / 2]) {
                Swap(j, j / 2);
                j = j / 2;
            } else {
                break;
            }
        }
    }
}

void HeapSort(int A[n]) {
    Heapify(A);
    for (int i = n - 1; i > 0; --i) {
        Swap(0, i);
        int j = 0;
        while (getLeft(j) < i) {
            int maxChild = getLeft(j);
            if (getRight(j) < i && A[getRight(j)] > A[maxChild]) {
                maxChild = getRight(j);
            }
            if (A[maxChild] > A[j]) {
                Swap(maxChild, j);
                j = maxChild;
            } else {
                break;
            }
        }
    }
}



int main() {
    //selectionSort(X);
    bubbleSort(X);
    insertionSort(X);
    HeapSort(X);
    for (int i : X) {
        cout << i << "\t";
    }
    return 0;
}

