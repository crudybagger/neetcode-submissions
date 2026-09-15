class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(matrix[mid][matrix[mid].size()-1] < target) l = mid+1;
            else if(matrix[mid][0] > target) r = mid-1;
            else break;
        }
        int row = mid;
        l = 0; 
        r = matrix[mid].size()-1;
        while(l <= r) {
            mid = l + (r - l)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
