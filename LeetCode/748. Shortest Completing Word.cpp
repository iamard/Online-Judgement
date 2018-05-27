class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> table;
        for (int i = 0; i < licensePlate.length(); i++) {
            if (isalpha(licensePlate[i]))
                table[tolower(licensePlate[i])]++;
        }

        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        
        for (string &word: words) {
            unordered_map<char, int> dict = table;
            for (char c: word) {
                c = tolower(c);
                if (dict.count(c) == 0)
                    continue;

                dict[c]--;
                if (dict[c] == 0)
                    dict.erase(c);
            }
            
            if (dict.empty())
                return word;
        }
        return "";
    }
};