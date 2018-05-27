class Solution {
    typedef pair<int, int> ii;
    
    int dist(ii &a, ii &b) {
        return (a.first - b.first) * (a.first - b.first)  +
               (a.second - b.second) * (a.second - b.second);
    }

    int dot(ii &a, ii &b) {
        return a.first * b.first + a.second * b.second;
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        ii coord[4] = { make_pair(p1[0], p1[1]),
                        make_pair(p2[0], p2[1]),
                        make_pair(p3[0], p3[1]),
                        make_pair(p4[0], p4[1]) };
        sort(coord, coord + 4);
        
        int edge1 = dist(coord[0], coord[1]);
        int edge2 = dist(coord[0], coord[2]);
        int edge3 = dist(coord[1], coord[3]);
        int edge4 = dist(coord[2], coord[3]);
        
        ii vec1 = make_pair((coord[1].first - coord[0].first), (coord[1].second - coord[0].second));
        ii vec2 = make_pair((coord[2].first - coord[0].first), (coord[2].second - coord[0].second));
        
        return (edge1 != 0) && 
               (edge1 == edge2) && 
               (edge1 == edge3) && 
               (edge1 == edge4) &&
               (dot(vec1, vec2) == 0);
    }
};