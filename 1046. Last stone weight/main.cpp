/** Creato da Vincenzo Iannucci in data 29/01/2021
* Abbiamo una collezione di pietre, ogni pietra ha un peso intero positivo.
  Ad ogni turno, scegliamo le due pietre pi� pesanti e le rompiamo insieme. Supponiamo che le pietre abbiano pesi x e y 
  con x <= y. Il risultato di questo successo �:
    - Se x == y, entrambe le pietre vengono completamente distrutte;
    - Se x != y, la pietra di peso x � completamente distrutta e la pietra di peso y ha un nuovo peso y - x.
  Alla fine, rimane al massimo 1 pietra. Restituisci il peso di questa pietra (o 0 se non sono rimaste pietre).
**/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> A) {
    for (auto x : A) {
        cout << " " << x;
    }
    cout << endl;
}

void MaxHeapify(vector<int>& A, int i) {
    auto max = i;
    auto left = 2 * i + 1;
    auto right = 2 * i + 2;
    if (left < A.size() && A[left] > A[max]) {
        max = left;
    }
    if (right < A.size() && A[right] > A[max]) {
        max = right;
    }
    if (max != i) {
        swap(A[i], A[max]);
        MaxHeapify(A, max);
    }
}

void BuildMaxHeap(vector<int>& A) {
    for (int i = A.size() / 2 - 1; i >= 0; i--)
        MaxHeapify(A, i);
}

int HeapExtractMax(vector<int>& A) {
    if (A.size() < 1) {
        exit(0);
    }
    auto max = A[0];
    A[0] = A[A.size() - 1];
    A.pop_back();
    MaxHeapify(A, 0);
    return max;
}

void HeapIncreaseKey(vector<int>& A, int i, int key) {
    if (key < A[i]) {
        exit(0);
    }
    A[i] = key;
    while (i > 0 && A[(i - 1) / 2] < A[i]) {
        swap(A[(i - 1) / 2], A[i]);
        i = (i - 1) / 2;
    }
}

void MaxHeapInsert(vector<int>& A, int key) {
    A.push_back(key);
    HeapIncreaseKey(A, A.size() - 1, key);
}

int lastStoneWeight(vector<int>& stones) {
    BuildMaxHeap(stones);
    while (stones.size() > 1) {
        auto y = HeapExtractMax(stones);
        auto x = HeapExtractMax(stones);
        if (x != y) {
            y = y - x;
            if (y != 0) {
                MaxHeapInsert(stones, y);
            }
        }
    }
    if (stones.size() == 1) {
        return stones[0];
    }
    else {
        return 0;
    }
}

int main() {
    vector<int> A = { 2,7,4,1,8,1 };
    cout << lastStoneWeight(A) << endl;
    return 0;
}
