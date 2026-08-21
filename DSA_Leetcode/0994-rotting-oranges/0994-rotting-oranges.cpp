class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(int i,int j, int n ,int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0,fresh=0,i,j;
        queue<pair<int,int>>q;
        int n= grid.size();
        int m= grid[0].size();
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int s= q.size();
            while(s--){
                pair<int,int>p=q.front();
                q.pop();
                int r=p.first;
                int c=p.second;
                for(int k=0;k<4;k++){
                    int row= r + x[k];
                    int col= c + y[k];

                    if(valid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col]=-2;
                        fresh--;
                    }
                }
            }
        }
        
        if(fresh>0) return -1;
        return time;

    }
};