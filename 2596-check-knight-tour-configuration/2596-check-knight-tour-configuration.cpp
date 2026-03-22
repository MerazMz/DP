class Solution {
public:
    // right side
    // row-2 col+1
    // row-1 col+2
    // row+1 col+2
    // row+2 col+1

    // left side
    // row-2 col-1
    // row-1 col-2
    // row+1 col-2
    // row+2 col-1
    bool isValid(vector<vector<int>>& grid, int r, int c,int expVal){
        int n=grid.size();
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expVal ){
            return false;
        }

        if(expVal==n*n-1){
            return true; //last cell
        }
        bool move1 = isValid(grid,r-2,c+1,expVal+1);
        bool move2 = isValid(grid,r-1,c+2,expVal+1);
        bool move3 = isValid(grid,r+1,c+2,expVal+1);
        bool move4 = isValid(grid,r+2,c+1,expVal+1);

        bool move5 = isValid(grid,r-2,c-1,expVal+1);
        bool move6 = isValid(grid,r-1,c-2,expVal+1);
        bool move7 = isValid(grid,r+1,c-2,expVal+1);
        bool move8 = isValid(grid,r+2,c-1,expVal+1);
       
        return move1 || move2 || move3 || move4 || move5 || move6 || move7 || move8;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid,0,0,0);
    }
};