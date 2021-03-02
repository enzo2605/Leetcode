/** Creato da Vincenzo Iannucci il 03/02/2021
 * Data una griglia mxn in ordine decrescente sia per riga che per colonna, 
 * restituire il numero di numeri negativi.
**/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNegatives(vector<int> A, int begin, int end) {
        if (begin > end) {
            cout << A[begin] << endl;
            cout << begin << " " << end << endl;
            return 0;
        }
        if (begin == end) 
            return (A[begin] >= 0) ? 0 : 1;
        auto mid = (begin + end) / 2;
        if (A[mid] < 0) 
            return 1 + findNegatives(A, begin, mid - 1) + findNegatives(A, begin, mid + 1);
        else
            return findNegatives(A, mid + 1, end);
    } 
    int countNegatives(vector<vector<int>>& grid) {
        auto sum = 0;
        for (vector<int> array : grid) {
            sum += findNegatives(array, 0, array.size() - 1);
            cout << "\nsum: " << sum << endl;
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> grid = { { 4, 3, 2, -1 }, { 3, 2, 1, -1 }, {1, 1, -1, -2}, {-1, -1, -2, -3} };
    Solution s;
    cout << "\nRisultato: ";
    cout << s.countNegatives(grid) << endl;
    return 0;
}