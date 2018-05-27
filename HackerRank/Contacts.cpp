#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> table;

void add(const string &s) {
    for (int i = 1; i <= s.length(); i++) {
        table[s.substr(0, i)]++;
    }
}

int find(const string &s) {
    return table[s];
}

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
    /*
     * Write your code here.
     */
    vector<int> result;
    for (int i = 0; i < queries.size(); i++) {
        string cmd  = queries[i][0];
        string data = queries[i][1];
        
        cout << cmd << " " << data;
        if (cmd == "add") {
            add(data);
        } else {
            int count = find(data);
            result.push_back(count);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
