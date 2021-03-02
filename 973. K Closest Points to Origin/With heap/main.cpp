/** Creato da Vincenzo Iannucci in data 14/02/2021 
 * Abbiamo una lista di punti sul piano. Trova i punti K più vicini all'origine (0, 0). 
 * (Qui, la distanza tra due punti su un piano è la distanza euclidea). 
 * Puoi restituire la risposta in qualsiasi ordine. La risposta è garantita per essere 
 * unica (tranne per l'ordine in cui si trova).
 * **/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void printMatrix(vector<vector<int>> A) {
    for (auto row : A) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

void printVector(vector<int> A) {
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    double distance(vector<int> point) {
        double x = pow(point[0], 2);
        double y = pow(point[1], 2);
        double sum = sqrt(x + y);
        return sum;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<pair<double, vector<int>>> maxHeap;
        for (auto point : points) {
            maxHeap.push(make_pair(distance(point), point));
            if (maxHeap.size() > K)
                maxHeap.pop();
        }
        auto i = 0;
        while (i < K) {
            pair<double, vector<int>> a = maxHeap.top();
            result.push_back(a.second);
            maxHeap.pop();
            i++;
        }
        return result;
    }
    // T(n) = O(nlogK) 
    // S(n) = O(n)
};

int main() {
    vector<vector<int>> vec{ {-5, 4}, {4, 6}, {-6, -5} };
    Solution s;
    vector<vector<int>> ris = s.kClosest(vec, 2);
    cout << "\nRisultato: " << endl;
    printMatrix(ris);
    return 0;
}