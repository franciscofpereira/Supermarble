#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix;
 
int maximize_profit(int slab_x, int slab_y, matrix profits){
    
    // Initializing memoization matrix 
    matrix memoization(slab_x + 1, vector<int>(slab_y + 1, 0));

    // For each rectangle width
    for (int i = 1; i <= slab_x; ++i) {

        int num_vertical_cuts = (i % 2 == 0) ? i/2 : (i - 1) / 2;
        
        // For each rectangle height
        for (int j = 1; j <= slab_y; ++j) {

            int num_horizontal_cuts = (j % 2 == 0) ? j/ 2 : (j - 1) / 2;
            
            // Use direct indexing for profits vector with size checks
            int profit1 = (i < static_cast<int>(profits.size()) && j < static_cast<int>(profits[i].size())) ? profits[i][j] : 0;
            int profit2 = (j < static_cast<int>(profits.size()) && i < static_cast<int>(profits[j].size())) ? profits[j][i] : 0;

            int matched_piece_profit = max(profit1, profit2);

            // Check whether using the matching piece directly is more profitable
            memoization[i][j] = max(memoization[i][j], matched_piece_profit);
            
            // If no matching piece, consider all possible cuts
            for (int k = 1; k <= num_vertical_cuts; ++k) {
                // For each vertical cut position, compares stored result in matrix with the sum of the results for the sub-rectangles
                memoization[i][j] = max(memoization[i][j], memoization[k][j] + memoization[i - k][j]);
            }
            for (int k = 1; k <= num_horizontal_cuts; ++k) {
                // For each horizontal cut position, compares stored result in matrix with the sum of the results of the sub-rectangles
                memoization[i][j] = max(memoization[i][j], memoization[i][k] + memoization[i][j - k]);
            }
        }
    }
    return memoization[slab_x][slab_y];
}


int main() {
    int input;
    int slab_x, slab_y;
    input = scanf("%d %d", &slab_x, &slab_y);

    int num_pieces;
    input = scanf("%d", &num_pieces);

     // Initialize profits vector
    matrix profits(slab_x + 1, vector<int>(slab_y + 1, 0));

    int piece_x, piece_y, piece_profit;
    for (int i = 0; i < num_pieces; i++) {
        input = scanf("%d %d %d", &piece_x, &piece_y, &piece_profit);
        if (piece_x <= slab_x && piece_y <= slab_y) {
            profits[piece_x][piece_y] = piece_profit;
        }
    }

    int result = maximize_profit(slab_x, slab_y, profits);
    (void)input;
    printf("%d\n", result);

    return 0;
}   