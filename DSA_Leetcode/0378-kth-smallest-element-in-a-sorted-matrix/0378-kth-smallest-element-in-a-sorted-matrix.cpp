class Solution {
public:
    int helperFunction(vector<vector<int>>& matrix, int mid)
    {
        int cnt = 0;

        for(int i = 0 ; i<matrix.size() ; i++)
        {
            cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin());
        }

        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            int cnt = helperFunction(matrix,mid);

            if(cnt>=k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};