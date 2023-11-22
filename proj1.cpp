#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
typedef vector<vector<int> > matrix;

// STRUCTS
enum Orientation{
    HORIZONTAL,
    VERTICAL,
};

typedef struct {
    int x;
    int y;
    int profit;
} Piece;

// GLOBAL VARIABLES
vector<Piece> pieces;
matrix memoization;

bool canConvertToPiece(int slab_x, int slab_y) {
    for (const Piece& piece : pieces) {
        // Check if the dimensions of the rectangle are greater than or equal to the piece
        if ((slab_x >= piece.x && slab_y >= piece.y) ||
            (slab_x >= piece.y && slab_y >= piece.x)) {
            return true; // Rectangle can be converted into this piece
        }
    }
    return false; // Rectangle cannot be converted into any of the pieces
}

Piece* matches_piece(int slab_x, int slab_y) {
    for (auto& piece : pieces) {
        // Checks if the rectangle dimensions match the dimensions of a piece (and its rotated counterpart)
        if ((piece.x == slab_x && piece.y == slab_y) || (piece.x == slab_y && piece.y == slab_x)) {
            return &piece;
        }
    }
    return nullptr; 
}


int maximize_profit(int slab_x, int slab_y){
    
    // Returns value from memoization matrix if already determined
    if(memoization[slab_x-1][slab_y-1] != 0){
        return memoization[slab_x-1][slab_y-1];
    }

    // If there's a matching piece
    if(matches_piece(slab_x,slab_y) != nullptr){
        
        // Gets piece profit
        Piece* p = matches_piece(slab_x,slab_y);
         
        // Checking if continue cutting gives us increased profit
        int max_profit = p->profit;

        // Vertical cuts
        for (int i = 1; i < slab_x; ++i) {
            int potential_profit = maximize_profit(i, slab_y) + maximize_profit(slab_x - i, slab_y);
            max_profit = max(max_profit, potential_profit);
        }

        // Horizontal cuts
        for (int i = 1; i < slab_y; ++i) {
            int potential_profit = maximize_profit(slab_x, i) + maximize_profit(slab_x, slab_y - i);
            max_profit = max(max_profit, potential_profit);
        }

        //if(slab_x == slab_y){
        //  memoization[slab_y-1][slab_x-1] = max(p->profit, max_profit);
        //}

        memoization[slab_x-1][slab_y-1] = max(p->profit, max_profit);

        return max_profit;
    }

    if(!canConvertToPiece(slab_x,slab_y)){
        return 0;
    }

    // There is no matching piece, we access all cutting possibilities
    int max_profit = 0;

    // Vertical cuts
    for (int i = 1; i < slab_x; ++i) {
        int current_profit = maximize_profit(i, slab_y) + maximize_profit(slab_x - i, slab_y);
        max_profit = max(max_profit, current_profit);
    }

    // Horizontal cuts
    for (int i = 1; i < slab_y; ++i) {
        int current_profit = maximize_profit(slab_x, i) + maximize_profit(slab_x, slab_y - i);
        max_profit = max(max_profit, current_profit);
    }

    memoization[slab_x-1][slab_y-1] = max_profit;

    return max_profit;
}


int main(){

    int slab_x, slab_y;    
    scanf("%d %d", &slab_x, &slab_y);
    
    int num_pieces;
    scanf("%d", &num_pieces);

    pieces.resize(num_pieces);

    for(int i = 0; i < num_pieces; i++){
        int piece_x, piece_y, piece_profit;
        scanf("%d %d %d", &piece_x, &piece_y, &piece_profit);
        pieces[i] = {piece_x, piece_y, piece_profit};
    }

    memoization.resize(slab_x, vector<int>(slab_y, 0));

    int result = maximize_profit(slab_x,slab_y);

    printf("%d\n",result);

}   