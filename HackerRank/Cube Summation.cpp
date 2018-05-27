#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long bit[101][101][101];

void update(int n, int x, int y, int z, long diff) {
    int ze = z;
    while(ze <= n) {
        int ye = y;
        while(ye <= n) {
            int xe = x;
            while(xe <= n) {
                bit[ze][ye][xe] += diff;
                xe += (xe & -xe);
            }
            ye += (ye & -ye);
        }
        ze += (ze & -ze);
    }
}

long query(int x, int y, int z) {
    long sum = 0;
    int ze = z;
    while(ze > 0) {
        int ye = y;
        while(ye > 0) {
            int xe = x;
            while(xe > 0) {
                sum += bit[ze][ye][xe];
                xe -= (xe & -xe);
            }
            ye -= (ye & -ye);
        }
        ze -= (ze & -ze);
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        memset(bit, 0, sizeof(bit));
        
        for (int j = 0; j < M; j++) {
            string Q;
            cin >> Q;
            if (Q == "UPDATE") {
                int x, y, z;
                long w;
                cin >> x >> y >> z >> w;

                long val1 = query(x, y, z) -
                           query(x - 1, y, z) -
                           query(x, y - 1, z) +
                           query(x - 1, y - 1, z);
                long val2 = query(x, y, z - 1) -
                           query(x - 1, y, z - 1) -
                           query(x, y - 1, z - 1) +
                           query(x - 1, y - 1, z - 1);
                long diff = w - (val1 - val2);
                update(N, x, y, z, diff);
            } else if (Q == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                
                long val1 = query(x2, y2, z2) -
                           query(x1 - 1, y2, z2) -
                           query(x2, y1 - 1, z2) +
                           query(x1 - 1, y1 - 1, z2);
                long val2 = query(x2, y2, z1 - 1) -
                           query(x1 - 1, y2, z1 - 1) -
                           query(x2, y1 - 1, z1 - 1) +
                           query(x1 - 1, y1 - 1, z1 - 1);
                cout << (val1 - val2) << endl;
            }
        }
    }

    return 0;
}
