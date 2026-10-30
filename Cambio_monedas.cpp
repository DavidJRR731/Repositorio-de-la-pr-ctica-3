#include <iostream>  
#include <vector>  
#include <limits>  
#include <algorithm> 
using namespace std;
void monedas(const vector<int>& m, int d, vector<int>& s) {
    int n = m.size();
    s.assign(n, 0); 

    if (d <= 0 || n == 0) return;

    
    vector<vector<int>> T(n, vector<int>(d + 1, INF));

    
    for (int i = 0; i < n; ++i) {
        T[i][0] = 0;
    }


    for (int j = 1; j <= d; ++j) {
        if (j >= m[0] && T[0][j - m[0]] != INF) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }

    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= d; ++j) {
            if (j < m[i] || T[i][j - m[i]] == INF) {
                T[i][j] = T[i - 1][j];
            } else if (T[i - 1][j] != INF) {
                T[i][j] = min(T[i - 1][j], 1 + T[i][j - m[i]]);
            } else {
                T[i][j] = 1 + T[i][j - m[i]];
            }
        }
    }

    
    if (T[n - 1][d] == INF) {
        cerr << "No hay combinacion posible para devolver " << d << "\n";
        return;
    }


    int i = n - 1;
    int j = d;
    while (j > 0 && i >= 0) {
        if (i == 0 || (j >= m[i] && T[i][j] != T[i - 1][j])) {
            s[i]++;
            j -= m[i];
        } else {
            i--;
        }
    }
}