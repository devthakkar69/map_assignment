class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<char, bool>> row_map, col_map, box_map;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue;

                int box_id =(i/3)*3+(j/3);

                if (row_map[i][num] || col_map[j][num] || box_map[box_id][num]) {
                    return false;
                }
                row_map[i][num]=true;
                col_map[j][num]=true;
                box_map[box_id][num]=true;
            }
        }

        return true;
    }
};
