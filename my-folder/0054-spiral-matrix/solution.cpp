class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rmin = 0;
        int cmin = 0;
        int rmax = n-1;
        int cmax = m-1;
        int x = n*m;
        vector<int>res;
        while(true)
        {
            if(rmin>rmax || cmin>cmax) break;
            for(int i=cmin;i<=cmax;i++)
            {
                res.push_back(matrix[rmin][i]);
                
            }
            rmin++;
            if(rmin>rmax || cmin>cmax) break;
            for(int i=rmin;i<=rmax;i++)
            {
                res.push_back(matrix[i][cmax]);
                
            }
            cmax--;
            if(rmin>rmax || cmin>cmax) break;
            for(int i=cmax;i>=cmin;i--)
            {
                res.push_back(matrix[rmax][i]);
                
            }
            rmax--;
            if(rmin>rmax || cmin>cmax) break;
            for(int i=rmax;i>=rmin;i--)
            {
                res.push_back(matrix[i][cmin]);
                
            }
            cmin++;
        }
        return res;
    }
};
