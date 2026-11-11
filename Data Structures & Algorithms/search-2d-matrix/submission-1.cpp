class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i,j,l,r,mid,n,m;
        m = matrix.size();
        n = matrix[0].size();

        l = 0;
        r = n*m -1;
        i=0;
        j=0;
        while (l<=r){
            mid = l+(r-l)/2;
            i = mid/n;
            j = mid%n;
            if(matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
