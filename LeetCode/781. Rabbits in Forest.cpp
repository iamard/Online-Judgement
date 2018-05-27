class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0)
            return 0;

        sort(answers.begin(), answers.end());
        
        int group  = answers[0];
        int remain = group;
        int total  = group + 1;
        for (int i = 1; i < answers.size(); i++) {
            if (answers[i] == group) {
                if (remain > 0) {
                    remain--;
                } else {
                    remain = group;
                    total += (group + 1);
                }
            } else {
                group  = answers[i];
                remain = group;
                total += (group + 1); 
            }
        }
        return total;
    }
};