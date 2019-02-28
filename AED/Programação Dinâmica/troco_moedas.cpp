// Problema: Determinar a quantidade minima de moedas necessárias para dar um troco de tal valor.

#include <bits/stdc++.h>

using namespace std;

int pd[1000002];

int main(void){
    int moedas[2] = { 1, 5 };
    int qntd_moedas = 2;
    int valor = 103;

    memset(pd, 999999, sizeof(pd));
    pd[0] = 0;

    for(int i = 0; i < qntd_moedas; i++){
        for(int j = moedas[i]; j <= valor; j++){
            pd[j] = min(pd[j], 1 + pd[j - moedas[i]]);
        }
    }
    cout << pd[valor] << endl;

    return 0;
}