#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX_LEN         (15)

typedef pair<int, int>  ii;

class Array {
public:
    Array() {
        
    }

    Array(int baseAddr, 
          int elemBytes,
          int dimension,
          vector<ii> &bounds) {
        mBase = baseAddr;
        mBytes = elemBytes;
        mDims = dimension;
        mBounds = bounds;

        mCoeffs = vector<int>(mDims + 1);
        mCoeffs[mDims] = mBytes;

        int sumVal = mCoeffs[mDims] * bounds[mDims].first;
        for (int i = mDims - 1; i >= 1; i--) {
            mCoeffs[i] = mCoeffs[i + 1] * (bounds[i + 1].second - bounds[i + 1].first + 1);
            sumVal += mCoeffs[i] * bounds[i].first;
        }
        mCoeffs[0] = baseAddr - sumVal;
    }

    ~Array() {
    }

    int dimension() {
        return mDims;
    }

    int queryBase(const vector<int> &index) {
        int dim = mDims;
        int sum = mCoeffs[0];
        for (int i = 1; i <= dim; i++) {
            sum += mCoeffs[i] * index[i];
        }
        return sum;
    }
    
private:
    int mBase;
    int mBytes;
    int mDims;
    vector<ii> mBounds;
    vector<int> mCoeffs;
};

int main(int argc, char **argv) {
    int N, R;
    scanf("%d %d\n", &N, &R);
    
    unordered_map<string, Array> table;
    for (int i = 0; i < N; i++) {
        char name[MAX_LEN];
        scanf("%s", name);
        int base, size, dim;
        scanf("%d %d %d", &base, &size, &dim);
        vector<ii> bounds(dim + 1);
        for (int j = 1; j <= dim; j++) {
            int lower, upper;
            scanf("%d %d", &lower, &upper);
            bounds[j].first = lower;
            bounds[j].second = upper;
        }
        table[name] = Array(base, size, dim, bounds);
    }
    
    for (int i = 0; i < R; i++) {
        char name[MAX_LEN];
        scanf("%s", name);
        
        Array &array = table[name];
        int dim = array.dimension();
        vector<int> query(dim + 1);
        cout << name << "[";
        for (int j = 1; j <= dim; j++) {
            int index;
            scanf("%d", &index);
            
            cout << index;
            if (j != dim)
                cout << ", ";
            
            query[j] = index;
        }
        cout << "] = " << array.queryBase(query) << endl;
    }
    
    return 0;
}