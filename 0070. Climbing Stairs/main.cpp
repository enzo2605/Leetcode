/** Creato da Vincenzo Iannucci in data 02/03/2021 
 * Stai salendo una scala. Sono necessari n passaggi per raggiungere la cima. 
 * Ogni volta puoi salire 1 o 2 gradini. In quanti modi distinti puoi salire in cima?
 * **/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        auto a = 0;
        auto b = 1;
        for (auto i = 0; i < n; i++) {
            auto tmp = a;
            a = b;
            b = a + tmp;
        }
        return b;
    }
};

int main() {
    srand((unsigned)time(NULL));
    int n;
    Solution s;
    cout << "n: ";
    cin >> n;
    cout << "In quanti modi possibili posso salire " << n << " gradini? " << s.climbStairs(n) << endl;
    return 0;
}