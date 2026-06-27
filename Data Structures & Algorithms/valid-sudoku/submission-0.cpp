class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> st;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (st.count(board[i][j]) && board[i][j] != '.') {
                    return false;
                }
                st.insert(board[i][j]);
            }
            st.clear();
        }

        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (st.count(board[i][j]) && board[i][j] != '.') {
                    return false;
                }
                st.insert(board[i][j]);
            }
            st.clear();
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                set<char> setBox;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int r = i * 3 + x;
                        int c = j * 3 + y;
                        if (board[r][c] != '.' && setBox.count(board[r][c]))
                            return false;

                        setBox.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};