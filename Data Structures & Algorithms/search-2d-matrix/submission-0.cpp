class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = col - 1;
        int top = 0;

        while(top < row){
            if(target >= matrix[top][left] && target <= matrix[top][right]){
                while(left <= right){
                    int mid = left + (right-left)/2;
                    if(matrix[top][mid] == target) return true;
                    else if(matrix[top][mid] < target) left = mid + 1;
                    else right = mid - 1;
                }
                return false;
            }
            else{
                top++;
            }
            left = 0;
            right = col - 1;
        }

        return false;
    }
};