class Solution {
public:
    int compress(vector<char>& chars) {
        int curPos = 1;
        int count = 1;
        int start = 0;
        while(curPos < chars.size()) {
            while((curPos < chars.size()) && (chars[curPos - 1] == chars[curPos])) {
                count++;
                curPos++;
            }

            chars[start++] = chars[curPos - 1];
            if (count > 1) {
                string value = to_string(count);
                for (int i = 0; i < value.length(); i++) {
                    chars[start++] = value[i];
                }
            }
            curPos++;
            count = 1;
        }
        return start;
    }
};