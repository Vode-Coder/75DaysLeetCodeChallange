class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rowIDX = searchPotentialRow(matrix, target);
        if (rowIDX != -1) return binarySearchOverRow(rowIDX, matrix, target);
        return false;
    }

private:
    // In C++, private is a section, not a per-method prefix
    int searchPotentialRow(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1; // Added ()
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Accessing first and last element of the row
            if (matrix[mid][0] <= target && target <= matrix[mid][matrix[0].size() - 1]) {
                return mid;
            } else if (matrix[mid][0] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    bool binarySearchOverRow(int rowIDX, vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix[rowIDX].size() - 1; // Binary search the columns
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[rowIDX][mid] == target) return true;
            else if (matrix[rowIDX][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};