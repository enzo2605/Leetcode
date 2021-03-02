/** Creato da Vincenzo Iannucci in data 01/03/2021 
 * Su una scala, l'i-esimo gradino ha un costo di costo non negativo [i] assegnato (0 indicizzato). 
 * Una volta pagato il costo, puoi salire uno o due gradini. Devi trovare il costo minimo per raggiungere
 * la parte superiore del pavimento e puoi iniziare dal passaggio con indice 0 o dal passaggio con 
 * indice 1.
 * **/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> A) {
    for (auto elem : A) {
        cout << elem << " ";
    }
    cout << endl;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (auto i = 2; i < n; i++) {
            dp[i] = min(cost[i] + dp[i - 1], cost[i] + dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
int main() {
    vector<int> stairs = { 10, 15, 20 };
    vector<int> stairs2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    Solution s;
    cout << s.minCostClimbingStairs(stairs2) << endl;
    return 0;
}