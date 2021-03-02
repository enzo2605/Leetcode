/** Creato da Vincenzo Iannucci in data 01/02/2021 
 * Data una stringa s e un array di numeri interi della stessa lunghezza. 
 * La stringa s sarà mescolata in modo tale che il carattere nella iesima posizione
 * si sposti sugli indici [i] nella stringa mescolata. Restituisce la stringa mescolata.
 * **/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void print(vector<int> A) {
    for (auto x : A) {
        cout << " " << x;
    }
    cout << endl;
}

class Solution {
    public:
        string restoreString(string s, vector<int>& indices) {
            string x = s;
            auto j = 0;
            for (auto i : indices) {
                x[i] = s[j];
                j++;
            }
            return x;
        }
};

int main() {
    vector<int> A = { 4, 0, 2, 6, 7, 3, 1, 5};
    string a("aaiougrt");
    Solution s;
    cout << s.restoreString(a, A);
    return 0;
}