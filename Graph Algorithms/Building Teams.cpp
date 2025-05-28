// Solution 1 [DFS]
/*
*   author: denimflame12
*   created: 28.05.2025 09:45:51
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m;
vector<vector<int>> adj;
vector<int> col;

bool dfs(int node, int color) {
    col[node] = color;
    bool t = true;
    for(auto child : adj[node]) {
        if(col[child] != -1 && col[child] == col[node]) {
            return false;
        }
        else if(col[child] == -1) {
            t &= dfs(child, color ^ 1);
        }
    }
    return t;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    col.resize(n + 1, -1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(col[i] == -1) {
            bool x = dfs(i, 0);
            if(!x) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << col[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}
