class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            set<int> st1;
            set<int> st2;

            // Check each row
            for (int j = 0; j < n; j++) {
                st1.insert(matrix[i][j]);
            }

            // Check each column
            for (int j = 0; j < n; j++) {
                st2.insert(matrix[j][i]);
            }
            if (st1.size() < n) return false;
            if (st2.size() < n) return false;
        }
        return true;
    }
};