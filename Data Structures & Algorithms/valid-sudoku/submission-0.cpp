class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> distincts;
        unordered_map<int, unordered_set<char>> distincts_squares;
        // verify rows
        for(int i=0; i<9; i++){ 
            for(int j=0; j<9; j++){
                char current = board[i][j];
                if (current == '.') continue;
                if (distincts.contains(current)) return false;
                distincts.insert(current);
            }
            distincts.clear();
        }
        // verify columns
        for(int i=0; i<9; i++){ 
            for(int j=0; j<9; j++){
                char current = board[j][i];
                if (current == '.') continue;
                if (distincts.contains(current)) return false;
                distincts.insert(current);
            }
            distincts.clear();
        }
        //verify squares (row/3) *3 + col/3
        
        for(int i=0; i<9; i++){ 
            for(int j=0; j<9; j++){
                char current = board[j][i];
                int square_position = (i/3) *3 + j/3;
                if (current == '.') continue;
                if (distincts_squares[square_position].contains(current)) return false;
                distincts_squares[square_position].insert(current);
            }
            
        }
        return true;
    }
};
