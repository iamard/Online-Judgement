#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define MAX_LEN     (5000)
#define MAX_SIZE    (3000)

char   line[MAX_LEN];
int    pos[MAX_SIZE];
string val[MAX_SIZE];

int main(int argc, char **argv) {
    int T;
    scanf("%d\n", &T);
    while(T-- > 0) {
        scanf(" ");
        
        string input;
        getline(cin, input);

        vector<int> pos;
        istringstream ss(input);
        int x;
        while(ss >> x) {
            pos.push_back(x);
        }
        
        getline(cin, input);
        vector<string> val(pos.size() + 1);
        ss.clear();
        ss.str(input);
        for (int i = 0; i < pos.size(); i++) {
            ss >> val[pos[i]];
        }
      
        for (int i = 1; i <= pos.size(); i++) {
            printf("%s\n", val[i].c_str());
        }
        if (T > 0)
            printf("\n");
    }
    return 0;
}