#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int, int> ii;

int find(vector<ii> &V, int C) {
    if (V[C].first != C) {
        V[C].first = find(V, V[C].first);
    }
    return V[C].first;
}

void merge(vector<ii> &V, int A, int B) {
    int P1 = find(V, A);
    int P2 = find(V, B);
    if (P1 == P2)
        return;

    if (V[P1].second <= V[P2].second) {
        V[P1].first = P2;
        V[P2].second += V[P1].second;
        V[P1].second = 1;
    } else {
        V[P2].first = P1;
        V[P1].second += V[P2].second;
        V[P2].second = 1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d", &N);
    
    vector<ii> V(2 * N + 1);
    for (int i = 1; i <= (2 * N); i++) {
        V[i].first = i;
        V[i].second = 1;
    }
    
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        merge(V, A, B);
    }
    
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 1; i <= (2 * N); i++) {
        if (V[i].second == 1)
            continue;
        
        minVal = min(minVal, V[i].second);
        maxVal = max(maxVal, V[i].second);
    }

    cout << minVal << " " << maxVal << endl;
    
    return 0;
}
