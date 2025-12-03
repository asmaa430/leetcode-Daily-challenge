class Solution {
public:
    int hashSlope(int a, int b) { return a * 4003 + b; }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, unordered_map<int, int>> m;
        unordered_map<int, unordered_map<int, map<int, int>>> m2;
        for (int i = 0; i < n; i++) {
            int x0 = points[i][0], y0 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0], y1 = points[j][1];
                int a = y1 - y0, b = x0 - x1;
                int len = a * a + b * b;
                int c = 0;
                if (a < 0)
                    a = -a, b = -b;
                if (a * b == 0) {
                    if (a == 0) {
                        b = 1;
                    } else {
                        a = 1;
                    }
                } else {
                    int g = gcd(abs(a), abs(b));
                    a /= g, b /= g;
                }
                c = a * x0 + b * y0;

                int hash = hashSlope(a, b);
                m[hash][c]++;
                m2[hash][c][len]++;
            }
        }
        int total = 0;
        for (auto& [slope, counts] : m) {
            int prev = 0;
            for (auto& [c, count] : counts) {
                total += count * prev;
                prev += count;
            }
        }
        int sameCount = 0;
        for (auto& [slope, counts] : m2) {
            map<int, int> prev;
            for (auto& [c, countLen] : counts) {
                for (auto& [len, count] : countLen) {
                    sameCount += count * prev[len];
                    prev[len] += count;
                }
            }
        }
        return total - sameCount / 2;
    }
};