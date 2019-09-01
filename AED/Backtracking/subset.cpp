// Gerando subconjuntos de um conjunto de n elementos

#include <bits/stdc++.h>

using namespace std;

vector<int> conjunto = { 1, 2, 3 };
vector<int> subconjuntos;

void GeraSubset(int p){
    if(p == conjunto.size()){
        for(int i = 0; i < subconjuntos.size(); i++)
            cout << subconjuntos[i] << " ";
        cout << endl;
    }else{
        GeraSubset(p+1);
        subconjuntos.push_back(conjunto[p]);
        GeraSubset(p+1);
        subconjuntos.pop_back();
    }
}

int main(void){
    // GeraSubset(0);
    cout << (9 << 2) << endl;
    return 0;
}