#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN (30)

int main(int argc, char **argv) {
    while(1) {
        int N;
        scanf("%d\n", &N);
        if (N == 0)
            break;
        
        int maxOfX = 0;
        int lineOfX[N];
        for (int i = 0; i < N; i ++) {
            char line[MAX_LEN];
            gets(line);
            
            int XCount = 0;
            for (int j = 0; j < strlen(line); j++) {
                if (line[j] == 'X') {
                    XCount++;
                }     
            }
            lineOfX[i] = XCount;

            maxOfX = max(maxOfX, XCount);
        }
        
        int diff = 0;
        for (int i = 0; i < N; i++) {
            diff += maxOfX - lineOfX[i];
        }
        printf("%d\n", diff);
    }
    
    return 0;
}