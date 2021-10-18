/**
 * Given an integer n, return an array ans of length n + 1 such that for 
 * each i (0 <= i <= n), ans[i] is the number of 1's in the binary 
 * representation of i.
 * 
*/
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> A) {
    for (auto x : A) {
        cout << " " << x;
    }
    cout << endl;
}

class Solution {    
public:
    int numberOfOnes(int i) {
        auto count = 0;
        if (i == 0) {
            return 0;
        }
        while (i > 0) {
            if (i % 2 == 1) {
                count++;
            }
            i = i / 2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (auto i = 0; i <= n; i++) {
            ans.push_back(numberOfOnes(i));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> res;
    int n;
    cin >> n;
    res = s.countBits(n);
    print_vector(res);
    return 0;
}