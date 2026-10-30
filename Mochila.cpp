#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mochila(const vector<int>& p, const vector<int>& b, int m, vector<int>& s) {
    int n = p.size();
    s.assign(n, 0);

    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= n; ++i) {
        int peso_actual = p[i - 1];
        int benef_actual = b[i - 1];

        for (int c = 1; c <= m; ++c) {
            if (peso_actual > c) {
                g[i][c] = g[i - 1][c];
            } else {
                g[i][c] = max(g[i - 1][c], g[i - 1][c - peso_actual] + benef_actual);
            }
        }
    }

    
    int c = m;
    for (int i = n; i >= 1; --i) {
        if (g[i][c] != g[i - 1][c]) {
            s[i - 1] = 1;             
            c -= p[i - 1];
        }
    }

    return g[n][m];
}