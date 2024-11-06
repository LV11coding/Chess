#include <iostream>
using namespace std;

int main(){
    int playerx = 0;
    int playery = 0;
    int pawnmove = 0;
    int board [8][8] = {{0,0,0,0,0,0,0,0}, 
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0}};
    cout << "Y and X coordinates are 0-7 (0 the highest or the most left and 7 the lowest or the most right)" << endl;
    cout << "0 - empty space" << endl;
    cout << "1 - pawn" << endl;
    while(true){
        do {
            cout << "Enter y for the thing you want to move" << endl;
            cin >> playerx;
            cout << "Enter x for the thing you want to move" << endl;
            cin >> playery;
            if (board[playerx][playery] == 0 || playerx > 7 || playery > 7 || playerx < 0 || playery < 0){
                cout << "There is no piece on this square" << endl;
            }
        }
        while (board[playerx][playery] == 0 || playerx > 7 || playery > 7 || playerx < 0 || playery < 0);

        if (board[playerx][playery] == 1 && playerx == 6){
            do {
                cout << "With how much do you want to move this pawn (1 or 2)" << endl;
                cin >> pawnmove;
                if(pawnmove != 1 && pawnmove != 2){
                    cout << "Enter 1 or 2" << endl;
                }
            }
            while (pawnmove != 1 && pawnmove != 2);
            board[playerx][playery] = 0;
            board[playerx - pawnmove][playery] = 1;
        }

        if (board[playerx][playery] == 1 && playerx != 6){
            board[playerx][playery] = 0;
            board[playerx - 1][playery] = 1;
        }

        for (int x = 0; x < 8; x++){
            for (int y = 0; y < 8; y++){
                cout << board[x][y] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
