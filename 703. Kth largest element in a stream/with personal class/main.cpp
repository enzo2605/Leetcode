/** Creato da Vincenzo Iannucci in data 30/01/2021 
 * Progetta una classe per trovare il k-esimo elemento più grande in un flusso. Nota che è il k-esimo 
 * elemento più grande nell'insieme ordinato, non il k-esimo elemento distinto.
 * Implementa la classe KthLargest:
 * - KthLargest (int k, int[] nums) Inizializza l'oggetto con il numero intero k e il flusso 
 *   di numeri interi num.
 * - int add (int val) Restituisce l'elemento che rappresenta il k-esimo elemento più grande nel flusso.
 * **/
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> A) {
    for (auto x : A) {
        cout << " " << x;
    }
    cout << endl;
}

template <class T>
class MaxHeap {
    protected:
        vector<int> A;
        int heapsize;
    public:
        MaxHeap(vector<int> B) : A(B), heapsize(B.size()) {};
        MaxHeap() {};
        ~MaxHeap() {};
        void MaxHeapify(int i) {
            auto max = i;
            auto left = 2 * i + 1;
            auto right = 2 * i + 2;
            if (left < heapsize && A[left] > A[max]) {
                max = left;
            }
            if (right < heapsize && A[right] > A[max]) {
                max = right;
            }
            if (max != i) {
                swap(A[i], A[max]);
                MaxHeapify(max);
            }
        }
        void BuildMaxHeap() {
            for (int i = heapsize / 2 - 1; i >= 0; i--) {
                MaxHeapify(i);
            }
        }
};

template <class T>
class MaxPriorityQueue : private MaxHeap<T> {
    public:
        MaxPriorityQueue() { this->heapsize = 0; };
        MaxPriorityQueue(vector<int> A) : MaxHeap<T>(A) {
            this->BuildMaxHeap();
        };
        void printArray() {
            for (auto x : this->A) {
                cout << " " << x;
            }
            cout << endl;
        }
        T ExtractMax() {
            if (this->heapsize < 1) {
                exit(0);
            }
            auto max = this->A[0];
            swap(this->A[0], this->A[this->heapsize - 1]);
            this->heapsize--;
            this->A.pop_back();
            this->MaxHeapify(0);
            return max;
        }
        void IncreaseKey(int i, T key) {
            if (key < this->A[i]) {
                exit(0);
            }
            this->A[i] = key;
            while (i > 0 && this->A[(i - 1) / 2] < this->A[i]) {
                swap(this->A[(i - 1) / 2], this->A[i]);
                i = (i - 1) / 2;
            }
        }
        void Insert(T key) {
            this->heapsize++;
            this->A.push_back(key);
            IncreaseKey(this->heapsize - 1, key);
        }
};

class KthLargest {
    private:
        MaxPriorityQueue<int> maxHeap;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (auto i = 0; i < nums.size(); i++) {
                maxHeap.Insert(nums[i]);
            }
        }
        int add(int val) {
            vector<int> save;
            auto max = 0;
            maxHeap.Insert(val);
            for (auto i = 0; i < k; i++) {
                max = maxHeap.ExtractMax();
                save.push_back(max);
            }
            for (auto i = 0; i < k; i++) {
                maxHeap.Insert(save[i]);
            }
            return max;
        }
};

int main() {
    vector<int> A = { 4, 5, 8, 2 };
    KthLargest kthLargest(3, A);
    cout << kthLargest.add(3) << endl;   // return 4
    cout << kthLargest.add(5) << endl;   // return 5
    cout << kthLargest.add(10) << endl;  // return 5
    cout << kthLargest.add(9) << endl;   // return 8
    cout << kthLargest.add(4) << endl;   // return 8
    return 0;
}