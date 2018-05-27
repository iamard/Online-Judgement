class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> table;
        for (int i = 0; i < cpdomains.size(); i++) {
            string domain = cpdomains[i];
                        
            int pos = 0;
            while(pos < domain.length() && domain[pos] != ' ') {
                pos++;
            }
            int value = stoi(domain.substr(0, pos));
            pos++;
            
            while(pos < domain.length()) {
                string curr = domain.substr(pos);
                if (table.find(curr) == table.end()) {
                    table[curr] = value;
                } else {
                    table[curr] += value;
                }

                while(pos < domain.length() && domain[pos] != '.') {
                    pos++;
                }
                pos++;
            }
        }
        
        vector<string> result;
        for (auto &itor: table) {
            string value = to_string(itor.second) + " " + itor.first;
            result.push_back(value);
        }
        return result;
    }
};