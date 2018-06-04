class Solution {
public:
    string pushDominoes(string dominoes) {
        int pos = 0;

        while(pos < dominoes.length()) {
            char left = '#';
            while(pos < dominoes.length() && (dominoes[pos] == 'L' || dominoes[pos] == 'R')) {
                left = dominoes[pos++];
            }

            int start = pos;
            int count = 0;
            while(pos < dominoes.length() && dominoes[pos] == '.') {
                count++;
                pos++;
            }

            if (count) {
                if ((left == '#' || left == 'L') && dominoes[pos] == 'L') {
                    while(count) {
                        dominoes[start++] = 'L';
                        count--;
                    }
                } else if (left == 'R' && (pos >= dominoes.length() || dominoes[pos] == 'R')) {
                    while(count) {
                        dominoes[start++] = 'R';
                        count--;
                    }
                } else if (left == 'R' && dominoes[pos] == 'L') {
                    int lindex = start;
                    int rindex = pos - 1;
                    while(lindex < rindex) {
                        dominoes[lindex++] = 'R';
                        dominoes[rindex--] = 'L';
                    }
                }
            }
        }
        return dominoes;
    }
};