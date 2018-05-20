class Solution {
public:
    bool judgeCircle(string moves) {
        int curY = 0;
        int curX = 0;
        
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U')
                curY--;
            else if (moves[i] == 'D')
                curY++;
            else if (moves[i] == 'L')
                curX--;
            else
                curX++;
        }
        
        return (curY == 0) && (curX == 0);
    }
};