/** Creato da Vincenzo Iannucci in data 03/03/2021 
 * Un robot si trova nell'angolo in alto a sinistra di una griglia $m \times n$ (contrassegnata con "Start"
 * nel diagramma sottostante). Il robot può muoversi solo verso il basso o verso destra in qualsiasi momento. Il robot sta cercando 
 * di raggiungere l'angolo in basso a destra della griglia (contrassegnato con "Fine" nel diagramma
 * sottostante). Quanti possibili percorsi unici ci sono?
 * **/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        // Crea un array di puntatori ad array di size m
        unsigned int **paths = new unsigned int*[m];
        // Alloca dinamicamente gli array di size n
        for (auto i = 0; i < m; i++) {
            paths[i] = new unsigned int[n];
        }
        // Inizializza l'ultima riga e l'ultima colonna a 1
        // In quanto se ci troviamo sull'ultima riga possiamo solamente andare giù
        // Se ci troviamo sull'ultima colonna possiamo solamente andare a destra
        for (auto i = 0; i < m - 1; i++) {
            paths[i][n - 1] = 1;
        }
        for (auto j = 0; j < n - 1; j++) {
            paths[m - 1][j] = 1;
        }
        // Caclola tutti i possibili percorsi
        for (auto i = m - 2; i >= 0; i--) {
            for (auto j = n - 2; j >= 0; j--) {
                paths[i][j] = paths[i + 1][j] + paths[i][j + 1];
            }
        }
        return paths[0][0];
    }
};

int main() {
    srand((unsigned)time(NULL));
    Solution s;
    int m = 1 + rand() % 100, n = 1 + rand() % 100;
    cout << "Input: m = " << m << ", n = " <<  n << endl; 
    cout << "Output: " << s.uniquePaths(m, n) << endl;
    return 0;
}