#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int pre[MAXN], low[MAXN], vis[MAXN], cpre, n, m, a, b, cont;
vector<int> g[MAXN];
stack<pair<int,int>> s;

void DFS(int p, int v){
    pre[v] = low[v] = ++cpre;
    int filhos = 0;
    for(auto u : g[v]){
        if(!pre[u]){
            filhos++;
            s.push({ u, v });
            DFS(v, u);
            if(pre[v] <= low[u]){
                cout << "Componente " << ++cont << ": " << endl;
                while(s.top().first != u || s.top().second != v){
                    cout << s.top().first << "-" << s.top().second << " ";
                    s.pop();
                }
                cout << s.top().first << "-" << s.top().second << " ";
                s.pop();
                cout << endl;
            }
            low[v] = min(low[v], low[u]);
        }else if(u != p){
            low[v] = min(low[v], pre[u]);
            if(pre[u] < pre[v]) s.push({ u, v });
        }
    }
}

void init(){
    cpre = 0;
    cont = 0;
    memset(g, 0, sizeof(0));
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
}

int main(void){
    freopen("grafo.txt", "r", stdin);
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 1);
    if(!s.empty()) cout << "Componente " << ++cont << ": " << endl;
    while(!s.empty()){
        cout << s.top().first << "-" << s.top().second << " ";
        s.pop();
    }
    return 0;
}