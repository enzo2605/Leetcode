/**
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        int i, j;
        dp.push_back({ 1 });
        // First base case
        if (rowIndex == 0) {
            return dp[rowIndex];
        }
        // Second base case
        dp.push_back({ 1, 1 });
        if (rowIndex == 1) {
            return dp[rowIndex];
        }
        for (i = 2; i <= rowIndex; i++) {
            vector<int> aux;
            aux.push_back(1);
            for (j = 1; j < i; j++) {
                aux.push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            aux.push_back(1);
            dp.push_back(aux);
        }
        return dp[rowIndex];
    }
};

int main() {
    vector<int> A;
    Solution s;
    int n;
    cin >> n;
    A = s.getRow(n);
    print_vector(A);
    return 0;
}