class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix[0].size()-1;
        while(l<matrix.size()&&h>=0)
        {
            if(target==matrix[l][h])
                return true;
            else if(target<matrix[l][h])
                h--;
            else
                l++;
        }
        return false;
        }
       
};