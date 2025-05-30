/*
*   author: denimflame12
*   created: 30.05.2025 22:55:35
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int N, M;
char G[1001][1001];
bool V[1001][1001];
int Cnt = 0;

int dX[] = {0, 1, 0, -1};
int dY[] = {1, 0, -1, 0};

bool Valid(int X, int Y) {
    return (X >= 1 && X <= N && Y >= 1 && Y <= M && G[X][Y] == '#' && !V[X][Y]);
}

void Dfs(int X, int Y) {
    V[X][Y] = true;
    for(int _ = 0; _ < 4; _++) {
        if(Valid(X + dX[_], Y + dY[_])) {
            Dfs(X + dX[_], Y + dY[_]);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> G[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(Valid(i, j)) {
                Dfs(i, j);
                Cnt++;
            }
        }
    }
    cout << Cnt << endl;
    return 0;
}
