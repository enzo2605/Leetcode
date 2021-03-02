/** Creato da Vincenzo Iannucci in data 14/02/2021 
 * Abbiamo una lista di punti sul piano. Trova i punti K più vicini all'origine (0, 0). 
 * (Qui, la distanza tra due punti su un piano è la distanza euclidea). 
 * Puoi restituire la risposta in qualsiasi ordine. La risposta è garantita per essere 
 * unica (tranne per l'ordine in cui si trova).
 * **/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

void printMap(multimap<double, vector<int>> map) {
    cout << endl;
    for (auto it = map.begin(); it != map.end(); it++) {
        cout << it->first << " "; 
        for (auto i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

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
        multimap<double, vector<int>> map;
        // Crea una mappa contenente i punti e la loro distanza
        for (auto point : points) {
            map.insert(make_pair(distance(point), point));
        }
        auto i = 0;
        // Inserisci i primi k punti nell'array di output
        for (auto x : map) {
            if (i >= K)
                break;
            result.push_back(x.second);
            i++;
        }
        return result;
    }
    // T(n) = O(nlogn) 
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