/** Creato da Vincenzo Iannucci in data 02/02/2021 
 * Dato un numero intero di array nums, trova il sottoarray contiguo (contenente almeno un numero) 
 * che ha la somma più grande e restituisci la sua somma.
 * **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayDI(nums, 0, nums.size() - 1);
    }
    int maxCrossingSubarray(vector<int>& A, int low, int mid, int high) {
        int left_sum = INT_MIN;
        auto sum = 0;
        for (auto i = mid; i >= low; i--) {
            sum += A[i];
            if (sum >= left_sum) {
                left_sum = sum;
            }
        }
        int right_sum = INT_MIN;
        sum = 0;
        for (auto j = mid + 1; j <= high; j++) {
            sum += A[j];
            if (sum >= right_sum) {
                right_sum = sum;
            }
        }
        return left_sum + right_sum;
    }
    int maxSubArrayDI(vector<int>& A, int low, int high) {
        if (high == low) {
            return A[high];
        }
        else {
            auto mid = (low + high) / 2;
            auto left_sum = maxSubArrayDI(A, low, mid);
            auto right_sum = maxSubArrayDI(A, mid + 1, high);
            auto cross_sum = maxCrossingSubarray(A, low, mid, high);
            if (left_sum >= right_sum && left_sum >= cross_sum) {
                return left_sum;
            }
            else if (right_sum >= left_sum && right_sum >= cross_sum) {
                return right_sum;
            }
            else {
                return cross_sum;
            }
        }
    }
};

int main() {
    vector<int> A = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution s;
    cout << s.maxSubArray(A) << endl;
    return 0;
}