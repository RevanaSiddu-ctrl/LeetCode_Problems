/*
-------------------------------------------------------
Problem: 36. Valid Sudoku
Difficulty: Medium
Topic: Arrays, HashSet, Matrix

Pattern:
- Multiple HashSets for Duplicate Detection

Approach:
1. Maintain separate HashSets for every row, column, and 3x3 box.
2. Traverse every cell in the Sudoku board.
3. Ignore empty cells represented by '.'.
4. For each number, check whether it already exists in:
   - The current row
   - The current column
   - The corresponding 3x3 box
5. If it exists in any of them, the Sudoku is invalid.
6. Otherwise, insert the number into all three corresponding sets.
7. Calculate the box index using:
   (row / 3) * 3 + (col / 3)

Concepts Learned:
- Using HashSet for duplicate detection
- Maintaining multiple sets for different constraints
- Mapping a 2D position to one of nine 3x3 boxes
- Checking multiple conditions in a single traversal

Time Complexity: O(1)
Space Complexity: O(1)
// Board size is always fixed at 9x9
-------------------------------------------------------
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char c = board[i][j];
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i].count(c) ||
                    cols[j].count(c) ||
                    boxes[box].count(c)) {
                    return false;
                }

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }

        return true;
    }
};