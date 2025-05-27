// Solution 1 [DFS]
/*
*   author: denimflame12
*   created: 27.05.2025 20:39:35
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
vector<bool> vis;
vector<int> roots;

void dfs(int node) {
    vis[node] = true;
    for(auto child : adj[node]) {
        if(!vis[child]) {
            dfs(child);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            roots.push_back(i);
            dfs(i);
        }
    }
    int roads = roots.size();
    cout << roads - 1 << endl;
    for(int i = 1; i < roads; i++) {
        cout << roots[i - 1] << " " << roots[i] << endl;
    }
    return 0;
}

// Solution 2 [BFS]
/*
*   author: denimflame12
*   created: 27.05.2025 20:39:35
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
vector<bool> vis;
vector<int> roots;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto child : adj[curr]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            roots.push_back(i);
            bfs(i);
        }
    }
    int roads = roots.size();
    cout << roads - 1 << endl;
    for(int i = 1; i < roads; i++) {
        cout << roots[i - 1] << " " << roots[i] << endl;
    }
    return 0;
}
