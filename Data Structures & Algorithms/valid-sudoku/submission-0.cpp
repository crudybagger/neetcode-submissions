class Solution {
public:
    bool isValidBlock(vector<char> block) {
        int nums[9] = {0};
        for(char c : block) {
            if(c != '.') {
                nums[c - '1']++;
            }
        }
        for(int i = 0; i < 9; i++) {
            if(nums[i] > 1) return false;
        }
        return true;
    }
    bool validRows(vector<vector<char>>& board) {
        bool isValid = true;
        for(int i = 0; i < 9; i++) {
            //each row must have unique digits and no duplicates
            isValid = isValid && isValidBlock(board[i]);
        }
        return isValid;
    }
    bool validColumns(vector<vector<char>>& board) {
        bool isValid = true;
        for(int i = 0; i < 9; i++) {
            vector<char> tmp(9);
            for(int j = 0; j < 9; j++) {
                tmp[j] = board[j][i];
            }
            isValid = isValid && isValidBlock(tmp);
        }
        return isValid;
    }
    bool validBlocks(vector<vector<char>>& board) {
        bool isValid = true;
        for(int row = 0; row < 9; row += 3) {
            for(int col = 0; col < 9; col += 3) {
                vector<char> tmp;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        tmp.push_back(board[row+i][col+j]);
                    }
                }
                isValid = isValid && isValidBlock(tmp);
            }
        }
        return isValid;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return (validRows(board) && validColumns(board) && validBlocks(board));
    }
};
