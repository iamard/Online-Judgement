class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.length();
        int n = magazine.length();
        if (n < m)
            return false;

        unordered_map<int, int> letter;
        for (int i = 0; i < magazine.length(); i++) {
            letter[magazine[i]]++;
        }
        
        for (int i = 0; i < ransomNote.length(); i++) {
            int value = ransomNote[i];
            if (letter.find(value) == letter.end())
                return false;
            else if (letter[value] > 0) {
                letter[value]--;
                if (letter[value] == 0)
                    letter.erase(value);
            }
        }
        return true;
    }
};