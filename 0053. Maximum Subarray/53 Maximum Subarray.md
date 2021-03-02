<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script> 
# 53. Maximum Subarray

Date: 02/02/2021
Status: Easy
Tags: Completed
Topic: Dynamic programming

## Prompt

Dato un numero intero di array nums, trova il sottoarray contiguo (contenente almeno un numero) che ha la somma più grande e restituisci la sua somma.

## Idea di base

Da un'attenta analisi, possiamo notare che il problema non sussiste se:

- L'array è costituito da tutti numeri positivi: in quanto il massimo sottoarray è il sottoarray stesso;
- L'array è costituito da tutti numeri negativi: il problema del massimo sottoarray coincide con il problema di ricerca del massimo valore nell'array.

Si potrebbe pensare ad un approccio forza bruta, cercando tutte le possibili combinazioni di sottoarray. Ma ciò richiederebbe una complessità polinomiale $\Theta(n^2)$ e dunque poco efficiente.

Sfruttiamo l'approccio divide et impera. Prendiamo un array $A[low \ldots high]$. Se lo dividiamo a metà, il nostro massimo sottoarray contiguo $A[i \ldots j]$ può trovarsi in una delle tre parti in cui l'array può essere idealmente diviso:

- $A[low \ldots mid]$ con $low \leq i \leq j\leq mid$, ovvero si trova nella porzione sinistra;
- $A[mid+1 \ldots high]$ con $mid < i \leq j\leq high$, ovvero si trova nella porzione destra;
- Attraversa la porzione sinistra e destra, dunque $low \leq i \leq mid < j \leq high$.

Sebbene i primi due casi possono essere risolti in maniera ricorsiva in quanto sono istanze più piccole del problema generale, la ricerca del sottoarray che attraversa le due porzioni richiede una procedura ulteriore. 

La procedura **FIND-MAX-CROSSING-SUBARRAY** ha il compito di trovare il massimo sottoarray contiguo $A[i \ldots j]$ che attraversa i due array. Per fare ciò riceve in input **low, mid** e **high**. Parte a considerare tutti gli array del tipo $A[i \ldots mid]$ dove $i \leq low$. La somma viene memorizzata in **left-sum**. La stessa cosa viene fatta per tutti gli array del tipo $A[mid+1 \ldots j]$ calcolando la **right-sum**. Alla fine ritorna la somma di **right-sum** e **left-sum**.

## Codice

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayDI(nums, 0, nums.size() - 1);
    }
    int maxCrossingSubarray(vector<int>& A, int low, int mid, int high) {
        int left_sum = INT_MIN;
        auto sum = 0;
        for (auto i = mid; i >= low; i--) {
            sum += A[i];
            if (sum >= left_sum) {
                left_sum = sum;
            }
        }
        int right_sum = INT_MIN;
        sum = 0;
        for (auto j = mid + 1; j <= high; j++) {
            sum += A[j];
            if (sum >= right_sum) {
                right_sum = sum;
            }
        }
        return left_sum + right_sum;
    }
    int maxSubArrayDI(vector<int>& A, int low, int high) {
        if (high == low) {
            return A[high];
        }
        else {
            auto mid = (low + high) / 2;
            auto left_sum = maxSubArrayDI(A, low, mid);
            auto right_sum = maxSubArrayDI(A, mid + 1, high);
            auto cross_sum = maxCrossingSubarray(A, low, mid, high);
            if (left_sum >= right_sum && left_sum >= cross_sum) {
                return left_sum;
            }
            else if (right_sum >= left_sum && right_sum >= cross_sum) {
                return right_sum;
            }
            else {
                return cross_sum;
            }
        }
    }
};
```

## Complessità computazionale

La ricorrenza che ne deriva è la ricorrenza del merge-sort. Ogni volta l'algoritmo genera due chiamate ricorsive ciascuna delle quali di size dimezzato e la fase divide e combina impiegano complessivamente un tempo $\Theta(n)$ derivante dalla complessità di **FIND-MAX-CROSSING-SUBARRAY.** 

$T(n)=2T\Big(\frac{n}{2}\Big)+\Theta(n)$

Risolta con il secondo caso del master theoreme:

$$T(n)=\Theta(n\log n)$$

