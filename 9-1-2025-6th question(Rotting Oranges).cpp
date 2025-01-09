6th question of the day
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int fresh=0;
       vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                    visited[i][j]=0;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        if(fresh==0)return 0;
        vector<int> x={1,0,-1,0};
        vector<int> y={0,1,0,-1};
        int maxi=-1;
        while(!q.empty()){
            pair<int,pair<int,int>> tp=q.front();
            int days=tp.first;
            maxi=max(maxi,days);
            int x1=tp.second.first;
            int y1=tp.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int x2=x1+x[i];
                int y2=y1+y[i];
                if(x2>=0 && x2<n && y2>=0 && y2<m){
                    if(grid[x2][y2] == 1 && visited[x2][y2] == 0){
                        q.push({days+1,{x2,y2}});
                        visited[x2][y2]=2;
                        fresh--;
                       
                    }
                }
            }
        }
        if(fresh==0)return maxi;
        return -1;
    }
};
