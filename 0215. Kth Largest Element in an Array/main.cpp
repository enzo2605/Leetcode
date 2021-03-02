/** Creato da Vincenzo Iannucci in data 31/01/2021 
 * Trova il k-esimo elemento più grande dell'array
 * **/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> maxHeap;
            auto max = 0;
            for (auto num : nums) {
                maxHeap.push(num);
            }
            for (auto i = 0; i < k - 1; i++) {
                maxHeap.pop();
            }
            return maxHeap.top();
        }
};

int main() {
    vector<int> A = { 4, 5, 8, 2 };
    Solution s;
    auto k = 3;
    cout << k << "th largest element is " << s.findKthLargest(A, k) << endl;
    return 0;
}