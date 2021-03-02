/** Creato da Vincenzo Iannucci in data 01/03/2021 
 * Ti viene fornito un array di prezzi dove i prezzi [i] è il prezzo di un dato titolo 
 * nell'i esimo giorno. Vuoi massimizzare il tuo profitto scegliendo un solo giorno per 
 * acquistare un'azione e scegliendo un giorno diverso in futuro per vendere quella azione. 
 * Restituisci il massimo profitto che puoi ottenere da questa transazione. Se non puoi ottenere 
 * alcun profitto, restituisci 0.
 * **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto it = begin; it != end; it++) {
        cout << " " << *it;
    }
    cout << endl;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto i = 1;
        auto profit = 0;
        for (auto price : prices) {
            auto max = (prices.begin() + i < prices.end()) ? *max_element(prices.begin() + i, prices.end()) : prices[i - 1];
            auto q = max - price;
            if (q > profit) 
                profit = q;
            i++;
        }
        return profit;
    }
    int efficientMaxProfit(vector<int>& prices) {
        auto profit = 0;
        auto min = INT_MAX;
        auto max = 0;
        for (auto i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < min) 
                min = prices[i];
            profit = prices[i + 1] - min;
            if (profit > max)
                max = profit;
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> prices = { 6, 5, 4, 3, 2, 1, 10, 20, 30, 40, 50, 60 };
    cout << s.efficientMaxProfit(prices) << endl; 
    return 0;
}