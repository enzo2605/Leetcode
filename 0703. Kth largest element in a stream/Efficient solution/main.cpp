/** Creato da Vincenzo Iannucci in data 31/01/2021 **/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class MinHeap {
    protected:
        vector<int> A;
        int heapsize;
    public:
        MinHeap(vector<int> B) : A(B), heapsize(B.size()) {};
        MinHeap() {};
        ~MinHeap() {};
        void MinHeapify(int i) {
            auto min = i;
            auto left = 2 * i + 1;
            auto right = 2 * i + 2;
            if (left < heapsize && A[left] < A[min]) {
                min = left;
            }
            if (right < heapsize && A[right] < A[min]) {
                min = right;
            }
            if (min != i) {
                swap(A[i], A[min]);
                MinHeapify(min);
            }
        }
        void BuildMinHeap() {
            for (int i = heapsize / 2 - 1; i >= 0; i--) {
                MinHeapify(i);
            }
        }
};

template <class T>
class MinPriorityQueue : private MinHeap<T> {
    public:
        MinPriorityQueue() { this->heapsize = 0; };
        MinPriorityQueue(vector<int> A) : MinHeap<T>(A) {
            this->BuildMinHeap();
        };
        void printArray() {
            for (auto x : this->A) {
                cout << " " << x;
            }
            cout << endl;
        }
        T extractMin() {
            if (this->heapsize < 1) {
                exit(0);
            }
            auto min = this->A[0];
            swap(this->A[0], this->A[this->heapsize - 1]);
            this->heapsize--;
            this->A.pop_back();
            this->MinHeapify(0);
            return min;
        }
        void increaseKey(int i, T key) {
            if (key < this->A[i]) {
                exit(0);
            }
            this->A[i] = key;
            while (i > 0 && this->A[(i - 1) / 2] > this->A[i]) {
                swap(this->A[(i - 1) / 2], this->A[i]);
                i = (i - 1) / 2;
            }
        }
        void insert(T key) {
            this->heapsize++;
            this->A.push_back(key);
            increaseKey(this->heapsize - 1, key);
        }
        int size() { return this->heapsize; }
        int minimum() { return this->A[0]; }
};

class KthLargest {
    private:
        MinPriorityQueue<int> minHeap;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) : k(k) {
            for (auto num : nums) {
                add(num);
            }
        }
    
        int add(int val) {
            minHeap.insert(val);
            if (minHeap.size() > k) {
                minHeap.extractMin();
            }      
            return minHeap.minimum();
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