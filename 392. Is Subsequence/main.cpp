/** Creato da Vincenzo Iannucci in data 02/03/2021 
 * Date due stringhe set, controlla se s è una sottosequenza di t. Una sottosequenza di una stringa 
 * è una nuova stringa che viene formata dalla stringa originale eliminando alcuni (non può essere nessuno) 
 * dei caratteri senza disturbare le posizioni relative dei caratteri rimanenti. (cioè, "ace" è una 
 * sottosequenza di "abcde" mentre "aec" non lo è).
 * **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto count = 0;
        auto j = 0;
        for (auto i = 0; i < t.length(); i++) {
            if (t[i] == s[j]) {
                count++;
                j++;
            }
        }
        return (count == s.length()) ? true : false; 
    }
};

int main() {
    string s("abc");
    string t("ahbgdc");
    Solution a;
    cout << a.isSubsequence(s, t) << endl;
    return 0;
}