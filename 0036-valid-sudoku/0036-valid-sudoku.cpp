class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows
        for(int i = 0; i < 9; i++){
            unordered_set<int> row;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && row.count(board[i][j]) > 0){
                    return false;
                }
                row.insert(board[i][j]);
            }
        }
        
        // check columns
        for(int i = 0; i < 9; i++){
            unordered_set<int> col;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.' && col.count(board[j][i]) > 0){
                    return false;
                }
                col.insert(board[j][i]);
            }
        }
        
        
        // check each box
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                unordered_set<int> box;
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        char c = board[i+x][j+y];
                        if(c != '.' && box.count(c) > 0){
                            return false;
                        }
                        box.insert(c);
                    }
                }
            }
        }
            
            
        return true;
    }
};