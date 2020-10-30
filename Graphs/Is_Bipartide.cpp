#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

bool is_bipartite(int n){
    vector<int> side(n, -1);
    queue<int> q;

    for (int i=0; i<n; i++){
        if (side[i] != -1) continue;

        q.push(i);
        side[i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for (auto v: adj[u]){
                if (side[v] == side[u]) return false;
                if (side[v] == -1) q.push(v), side[v] = 1 - side[u];
            }
        }
    }
    return true;
}

int main(){

}