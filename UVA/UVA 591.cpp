#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int T = 0;
    while(1) {
        int N;
        scanf("%d\n", &N);
        if (N == 0)
            break;
            
        int A[N];
        int S = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            S += A[i];
        }
        S /= N;

        int D = 0;
        for (int i = 0; i < N; i++) {
            if (S < A[i]) {
                D += A[i] - S;
            }
        }
        printf("Set #%d\n", ++T);
        printf("The minimum number of moves is %d.\n\n", D);
    }

    return 0;
}