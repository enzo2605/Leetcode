/** Creato da Vincenzo Iannucci in data 27/02/2021 
 * Alice e Bob giocano a turno, con Alice che inizia per prima. 
 * Inizialmente, c'è un numero N sulla lavagna. Nel turno di ogni giocatore, quel giocatore fa 
 * una mossa composta da:
 * - Scegliere qualsiasi x con 0 < x < N e N % x == 0.
 * - Sostituendo il numero N sulla lavagna con N - x.
 * Inoltre, se un giocatore non può fare una mossa, perde la partita.
 * Restituisce True se e solo se Alice vince la partita, assumendo che entrambi i giocatori
 * giochino in modo ottimale.
 * **/
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

bool divisorGame(int N) {
    if (N == 1)
        return false;
    for (auto x = 1; x < N; x++) {
        if (N % x == 0 && !divisorGame(N - x)) {
            return true;
        }
    }
    return false;
}

void printVector(int memo[], int N) {
    for (auto i = 0; i <= N; i++) {
        cout << " " << memo[i];
    }
    cout << endl;
}

int memoizedDivisorGameAux(int N, int memo[]) {
    if (memo[N] == 0 || memo[N] == 1)
        return memo[N];
    if (N == 1) 
        return 0;
    else {
        for (auto x = 1; x < N; x++) {
            if (N % x == 0 && !memoizedDivisorGameAux(N - x, memo)) {
                memo[N] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int memoizedDivisorGame(int N) {
    int *memo = new int[N + 1];
    for (auto i = 0; i <= N; i++) {
        memo[i] = INT_MIN;
    }
    return memoizedDivisorGameAux(N, memo);
}

int bottomUpDivisorGame(int N) {
    int *dp = new int[N + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (auto i = 2; i <= N; i++) {
        for (auto j = 1; j < i; j++) {
            if (i % j == 0 && dp[i - j] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[N];
}

int main() {
    for (auto i = 1; i <= 10; i++) {
        cout << "N = " << i << endl;
        cout << "Divide et impera : " << divisorGame(i) << endl;
        cout << "Memoization      : " << memoizedDivisorGame(i) << endl;
        cout << "Bottom-up        : " << bottomUpDivisorGame(i) << endl << endl;
    }
    return 0;
}