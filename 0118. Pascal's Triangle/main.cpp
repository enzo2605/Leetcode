#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<vector<int>> A) {
    for (auto row : A) {
        for (auto col : row) {
            cout << " " << col;
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        int i, j;
        dp.push_back({ 1 });
        // First base case
        if (numRows == 1) {
            return dp;
        }
        // Second base case
        dp.push_back({ 1, 1 });
        if (numRows == 2) {
            return dp;
        }
        for (i = 2; i < numRows; i++) {
            vector<int> aux;
            aux.push_back(1);
            for (j = 1; j < i; j++) {
                aux.push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            aux.push_back(1);
            dp.push_back(aux);
        }
        return dp;
    }
};

int main() {
    vector<vector<int>> A;
    Solution s;
    int n;
    cin >> n;
    A = s.generate(n);
    print_vector(A);
    return 0;
}