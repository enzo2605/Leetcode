/** Creato da Vincenzo Iannucci in data 30/01/2021 **/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T> void printQueue(T q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

class KthLargest {
    private:
        priority_queue<int> maxHeap;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (auto i = 0; i < nums.size(); i++) {
                maxHeap.push(nums[i]);
            }
        }
        int add(int val) {
            vector<int> save;
            auto max = 0;
            maxHeap.push(val);
            for (auto i = 0; i < k; i++) {
                max = maxHeap.top();
                maxHeap.pop();
                save.push_back(max);
            }
            for (auto i = 0; i < k; i++) {
                maxHeap.push(save[i]);
            }
            return max;
        }
};

int main() {
    vector<int> A = { 4, 5, 8, 2 };
    KthLargest *kthLargest = new KthLargest(3, A);
    cout << kthLargest->add(3) << endl;   // return 4
    cout << kthLargest->add(5) << endl;   // return 5
    cout << kthLargest->add(10) << endl;  // return 5
    cout << kthLargest->add(9) << endl;   // return 8
    cout << kthLargest->add(4) << endl;   // return 8
    return 0;
}