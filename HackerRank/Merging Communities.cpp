#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int find(vector<ii> &V, int C) {
    if (V[C].first != C) {
        V[C].first = find(V, V[C].first);
    }
    return V[C].first;
}

void merge(vector<ii> &V, int I, int J) {
    int P1 = find(V, I);
    int P2 = find(V, J);
    if (P1 == P2)
        return;

    if (V[P1].second >= V[P2].second) {
        V[P2].first = P1;
        V[P1].second += V[P2].second;
    } else {
        V[P1].first = P2;
        V[P2].second += V[P1].second;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, Q;
    cin >> N >> Q;
    
    vector<ii> V(N + 1);
    for (int i = 1; i <= N; i++) {
        V[i].first = i;
        V[i].second = 1;
    }
 
    for (int i = 0; i < Q; i++) {
        char T;
        cin >> T;
        if (T == 'Q') {
            int C;
            cin >> C;
            int P = find(V, C);
            cout << V[P].second << endl;
        } else if (T == 'M') {
            int I, J;
            cin >> I >> J;
            merge(V, I, J);
        }
    }

    return 0;
}
