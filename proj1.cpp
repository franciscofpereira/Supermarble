#include <iostream>
#include <vector>
#include <cstdio>

typedef struct {
    int x;
    int y;
    int profit;
} Piece;

typedef struct {
    int x;
    int y;
} MarbleSlab;


int main(){

    int slab_x, slab_y;    
    scanf("%d %d", &slab_x, &slab_y);
    MarbleSlab slab = {slab_x,slab_y};

    int num_pieces;
    scanf("%d", &num_pieces);

    Piece pieces[num_pieces];

    for(int i = 0; i < num_pieces; i++){
        int piece_x, piece_y, piece_profit;
        scanf("%d %d %d", &piece_x, &piece_y, &piece_profit);
        pieces[i] = {piece_x, piece_y, piece_x};
    }

}   