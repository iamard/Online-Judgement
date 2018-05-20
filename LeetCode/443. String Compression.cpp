class Solution {
public:
    int compress(vector<char>& chars) {
        int curPos = 0;
        int start = 0;
        while(curPos < chars.size()) {
            int count = 1;
            while((curPos < (chars.size() - 1)) && (chars[curPos] == chars[curPos + 1])) {
                count++;
                curPos++;
            }

            chars[start++] = chars[curPos];
            if (count > 1) {
                string value = to_string(count);
                for (int i = 0; i < value.length(); i++) {
                    chars[start++] = value[i];
                }
            }
            curPos++;
        }
        return start;
    }
};