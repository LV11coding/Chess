#include <iostream>
using namespace std;

int main(){
    int playerx = 0;
    int playery = 0;
    int nplayerx = 0;
    int nplayery = 0;
    int pawnmove = 0;
    bool check = true;
    char board [8][8] = {{'O','O','O','O','O','O','O','O'}, 
                        {'O','O','O','O','O','O','O','O'},
                        {'O','O','O','O','O','O','O','O'},
                        {'O','O','O','O','O','O','O','O'},
                        {'O','O','O','O','O','O','O','O'},
                        {'O','O','O','O','O','O','O','O'},
                        {'p','p','p','p','p','p','p','p'},
                        {'r','O','O','O','O','O','O','r'}};
    cout << "Y and X coordinates are 0-7 (0 the highest or the most left and 7 the lowest or the most right)" << endl;
    cout << "O - empty space" << endl;
    cout << "p - pawn" << endl;
    cout << "r - rook" << endl;
    while(true){
        do {
            cout << "Enter y for the thing you want to move" << endl;
            cin >> playerx;
            cout << "Enter x for the thing you want to move" << endl;
            cin >> playery;
            if (board[playerx][playery] == 'O' || playerx > 7 || playery > 7 || playerx < 0 || playery < 0){
                cout << "There is no piece on this square" << endl;
            }
        }
        while (board[playerx][playery] == 'O' || playerx > 7 || playery > 7 || playerx < 0 || playery < 0);

        if (board[playerx][playery] == 'p' && playerx == 6){ //pawn for first move
            do {
                cout << "With how much do you want to move this pawn (1 or 2)" << endl;
                cin >> pawnmove;
                if(pawnmove != 1 && pawnmove != 2){
                    cout << "Enter 1 or 2" << endl;
                }
            }
            while (pawnmove != 1 && pawnmove != 2);
            board[playerx][playery] = 'O';
            board[playerx - pawnmove][playery] = 'p';
        }

        if (board[playerx][playery] == 'p' && playerx != 6){ //pawn for not first move
            board[playerx][playery] = 'O';
            board[playerx - 1][playery] = 'p';
        }

        if (board[playerx][playery] == 'r'){ //rook
            cout << "Enter the y of the square you want to put this rook on" << endl;
            cin >> nplayerx;
            cout << "Enter the x of the square you want to put this rook on" << endl;
            cin >> nplayery;
            check = true;
            if (nplayerx < 0 || nplayerx > 7 || nplayery < 0 || nplayery > 7) {
                cout << "This square doesn't exist" << endl;
            }
            else {
                if (board[nplayerx][nplayery] == 'O' && (playerx - nplayerx == 0 || playery - nplayery == 0)){
                    if (playerx == nplayerx) {
                        if (nplayery > playery) {
                            for (int y2 = playery + 1; y2 < nplayery; y2++) {
                                if (board[playerx][y2] != 'O') {
                                    check = false;
                                    break;
                                }
                            }
                        } else {
                            for (int y2 = playery - 1; y2 > nplayery; y2--) {
                                if (board[playerx][y2] != 'O') {
                                    check = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if (playery == nplayery) {
                        if (nplayerx > playerx) {
                            for (int x2 = playerx + 1; x2 < nplayerx; x2++) {
                                if (board[x2][playery] != 'O') {
                                    check = false;
                                    break;
                                }
                            }
                        } else {
                            for (int x2 = playerx - 1; x2 > nplayerx; x2--) {
                                if (board[x2][playery] != 'O') {
                                    check = false;
                                    break;
                                }
                            }
                        }
                    }
                    if (check){
                        board[nplayerx][nplayery] = 'r';
                        board[playerx][playery] = 'O';
                    }
                    else {
                        cout << "There is a piece blocking your move" << endl;
                    }
                }
            }
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