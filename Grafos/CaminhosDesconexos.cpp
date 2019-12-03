// EC20 03/12	Implementar em C++ o programa para resolver o problema “Caminhos Desconexos”.

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define INF 0x3f3f3f3f
#define NVM 1200

using namespace std;

int C[NVM][NVM], CC[NVM][NVM], F[NVM][NVM], n, n2, m, m2, nh, nm, np, fmax;
bool V[NVM];
vector<int> G[100];

void Imprime(){
    cout<<"Fluxo:"<<endl;
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
        }        
    }     
}
void ImprimeC(){
    cout<<"Rede:"<<endl;
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            if (CC[i][j] > 0) cout << i << " " << j << "  "<<CC[i][j]<<endl;
        }        
    }     
}

int ExisteCaminho(int v, int s, int mincap) {
    V[v] = true; 
    if (v==s) return mincap;
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[v][i] > 0) {
            if (int fm = ExisteCaminho(i, s, min(mincap, C[v][i]))) {
                C[v][i] -= fm;  C[i][v] += fm;
                F[v][i] += fm;  F[i][v] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}

void CriaRede(){
    int i, j;
    n2 = n; // COPIAS:  n2 até n - 1
    m2 = m;
    n = ((n - 2) * 2) + 2;
    m = m + (2 * n);

	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }

    // 1 PARA OS VERTICES QUE OS CONECTAM
    for(int i = 0; i < G[1].size(); i++) CC[1][G[1][i]] = 3; 
    
    // VERTICES PARA SUAS RESPECTIVAS "COPIAS"
    int aux = n2;
    for(int i = 2; i <= n2 - 1; i++) CC[i][aux++] = 1; 
    
    // CONECTANDO AS COPIAS PARA OS VERTICES REAIS, COM OBSERVAÇÃO PARA O SUMIDOURO (PRIMEIRO IF)
    int tmp = 2;
    for(int i = n2; i <= n - 1; i++){
        for(int j = 0; j < G[tmp].size(); j++){
            if(G[tmp][j] == n2) CC[i][n] = 1;
            else CC[i][G[tmp][j]] = 1;
        }
        tmp++;
    }
}

int main(void){
    freopen("input", "r", stdin);

    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        G[u].push_back(v);
    }

    CriaRede();

    cout << " n= " << n << " m= " << m << endl;

    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) C[i][j]=CC[i][j];

    fmax = 0;
    memset(V, 0, sizeof(V));      
    while(int fm = ExisteCaminho(1, n, INF)) {
        fmax += fm;
        memset(V, 0, sizeof(V));
    }         

    Imprime();
    ImprimeC();

    cout << "Fluxo Máximo: " << fmax << endl;
    if(fmax == 3) cout << "É POSSIVEL" << endl;
    else cout << "NÃO É POSSIVEL" << endl;
}
