#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

#define MAX_LEN     (150)

typedef pair<int, int> ii;

int main(int argc, char **argv) {
    char line[MAX_LEN];
    int count = 0;
    while(gets(line)) {
        vector<ii> light;
        
        char *token = strtok(line, " ");
        int cycle = INT_MAX;
        while(token) {
            ii signal;
            int value = atoi(token);
            signal.first = value - 5;
            signal.second = value * 2;
            light.push_back(signal);
            
            cycle = min(cycle, value * 2);
            token = strtok(NULL, " ");   
        }

        int time = cycle;
        while(time <= 3600) {
            bool result = true;
            for (int i = 0; result && i < light.size(); i++) {
                int modulo = time % light[i].second;
                if (modulo >= light[i].first) {
                    result = false;
                }
            }
            
            if (result == true) {
                break;
            }
            time++;
        }

        if (time <= 3600) {
            int min = time / 60;
            int sec = time % 60;
            printf("Set %d synchs again at %d minute(s) and %d second(s) "
                   "after all turning green.\n", ++count, min, sec);
        } else {
            printf("Set %d is unable to synch after one hour.\n", ++count);
        }
    }

    return 0;
}