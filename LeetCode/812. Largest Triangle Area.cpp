class Solution {
    double crossProduct(pair<float, float> a, pair<float, float> b) {
        return fabs(a.first * b.second - b.first * a.second);
    }
    
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int count = points.size();
        double result = 0.0;
        for (int i = 0; i < (count - 2); i++) {
            for (int j = i + 1; j < (count - 1); j++) {
                for (int k = j + 1; k < count; k++) {
                    double area = 0.5 * crossProduct(make_pair(points[j][0] - points[i][0], 
                                                               points[j][1] - points[i][1]),
                                                     make_pair(points[k][0] - points[i][0], 
                                                               points[k][1] - points[i][1]));
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};