// Problema: Achar a maior quantidade de objetos com peso e valor que possa ser colocado em uma mochila 
// com capacidade x de modo que seus valores seja máximo (maximo de lucro).

#include <bits/stdc++.h>

using namespace std;

int mochila_binaria(vector<int> &pesos, vector<int> &valores, int qntd_objetos, int capacidade){
    int pd[qntd_objetos + 1][capacidade + 1];

    for(int i = 0; i < qntd_objetos + 1; i++) pd[i][0] = 0;
    for(int j = 0; j < capacidade + 1; j++) pd[0][j] = 0;

    for(int i = 1; i <= qntd_objetos; i++){
        for(int j = 1; j <= capacidade; j++){
            if(pesos[i] > j)
                pd[i][j] = pd[i - 1][j];
            else
                pd[i][j] = max(valores[i] + pd[i - 1][j - pesos[i]], pd[i - 1][j]);
        }
    }

    for(int i = 0; i < qntd_objetos + 1; i++){
        for(int j = 0; j < capacidade + 1; j++){
            cout << pd[i][j] << " ";
        }
        cout << endl;
    }

    return pd[qntd_objetos][capacidade];
}

int main(void){
    vector<int> pesos = { 0, 12, 4 };
    vector<int> valores = { 0, 47, 39 };

    cout << mochila_binaria(pesos, valores, 2, 15) << endl;

    return 0;
}