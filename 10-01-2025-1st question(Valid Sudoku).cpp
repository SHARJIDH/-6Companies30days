class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> box[9];
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int x=board[i][j];
                if(x=='.')continue;
                int k= (i/3)*3 + j/3;
                if(row[i].find(x)!=row[i].end() || col[j].find(x)!=col[j].end() ||box[k].find(x)!=box[k].end( )){
                    return false;
                }
                row[i].insert(x);
                col[j].insert(x);
                box[k].insert(x);
            }
        }
        return true;
    }
};
