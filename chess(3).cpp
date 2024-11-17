#include <iostream>
using namespace std;

int playerx = 0;
int playery = 0;
int nplayerx = 0;
int nplayery = 0;
int pawnmove = 0;
bool check = true;
bool check2 = true;
int x3 = 0;
int y3 = 0;
int dx = 0;
int dy = 0;
int x = 0;
int y = 0;
char board [8][8] = {{'O','O','O','O','O','O','O','O'}, 
                    {'P','P','P','P','P','P','P','P'},
                    {'O','O','O','O','O','O','O','O'},
                    {'O','O','O','O','O','O','O','O'},
                    {'O','O','O','O','O','O','O','O'},
                    {'O','O','O','O','O','O','O','O'},
                    {'p','p','p','p','p','p','p','p'},
                    {'r','k','b','q','m','b','k','r'}};

void printboard(){
    cout << "  ";
    for (int dumb = 0; dumb < 8; dumb++){
        cout << dumb << " ";
    }
    cout << endl;
    for (x = 0; x < 8; x++){
        cout << x << " ";
        for (y = 0; y < 8; y++){
            cout << board[x][y] << ' ';
        }
        cout << endl;
    }
}


int main(){
    cout << "Y and X coordinates are 0-7 (0 the highest or the most left and 7 the lowest or the most right)" << endl;
    cout << "O - empty space" << endl;
    cout << "p - white pawn" << endl;
    cout << "r - white rook" << endl;
    cout << "k - white knight" << endl;
    cout << "b - white bishop" << endl;
    cout << "q - white queen" << endl;
    cout << "m - white king" << endl;
    cout << "P - black pawn" << endl;
    printboard();
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
            if (board[playerx - pawnmove][playery] == 'O'){
                if (pawnmove == 2){
                    if (board[playerx - 1][playery] == 'O'){
                        board[playerx][playery] = 'O';
                        board[playerx - pawnmove][playery] = 'p';
                    }
                    else {
                        cout << "There is a piece blocking your move" << endl;
                    }
                }
                else {
                    board[playerx][playery] = 'O';
                    board[playerx - pawnmove][playery] = 'p';
                }
            }
            else {
                cout << "There is another piece on this square" << endl;
            }
        }

        if (board[playerx][playery] == 'p' && playerx != 6){ //pawn for not first move
            if (board[playerx - 1][playery] == 'O'){
                board[playerx][playery] = 'O';
                board[playerx - 1][playery] = 'p';
            }
            else {
                cout << "There is another piece on this square" << endl;
            }
            
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
            if (board[nplayerx][nplayery] != 'O'){
                cout << "There is another piece on this square" << endl;
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
                else {
                    cout << "Unavailable square" << endl;
                }
            }
        }

        if (board[playerx][playery] == 'k'){ //knight
            cout << "Enter the y of the square you want to put this knight on" << endl;
            cin >> nplayerx;
            cout << "Enter the x of the square you want to put this knight on" << endl;
            cin >> nplayery;
            if (nplayerx < 0 || nplayerx > 7 || nplayery < 0 || nplayery > 7) {
                cout << "This square doesn't exist" << endl;
            }
            else if (board[nplayerx][nplayery] == 'O' &&
                     ((abs(playerx - nplayerx) == 2 && abs(playery - nplayery) == 1) ||
                      (abs(playerx - nplayerx) == 1 && abs(playery - nplayery) == 2))) {
                board[playerx][playery] = 'O';
                board[nplayerx][nplayery] = 'k';
            }
            else {
                cout << "Unavailable square" << endl;
            }
        }

        if (board[playerx][playery] == 'b'){ //bishop
            cout << "Enter the y of the square you want to put this bishop on" << endl;
            cin >> nplayerx;
            cout << "Enter the x of the square you want to put this bishop on" << endl;
            cin >> nplayery;
            check2 = true;
            if (nplayerx < 0 || nplayerx > 7 || nplayery < 0 || nplayery > 7) {
                cout << "This square doesn't exist" << endl;
            }
            else {
                if (board[nplayerx][nplayery] != 'O'){
                    cout << "There is another piece on this square" << endl;
                }
                else {
                    if (abs(playerx - nplayerx) == abs(playery - nplayery)){
                        if (nplayerx > playerx){
                            dx = 1;
                        }
                        else {
                            dx = -1;
                        }
                        if (nplayery > playery){
                            dy = 1;
                        }
                        else {
                            dy = -1;
                        }
                        x3 = playerx + dx;
                        y3 = playery + dy;
                        while (x3 != nplayerx && y3 != nplayery) {
                            if (board[x3][y3] != 'O') {
                                check2 = false;
                                break;
                            }
                            x3 += dx;
                            y3 += dy;
                        }
                        if (check2){
                            board[playerx][playery] = 'O';
                            board[nplayerx][nplayery] = 'b';
                        }
                        else {
                            cout << "There is a piece blocking your move" << endl;
                        }
                    }
                    else {
                        cout << "Unavailable square" << endl;
                    }
                }
            }
        }

        if (board[playerx][playery] == 'q'){ //queen
            cout << "Enter the y of the square you want to put this queen on" << endl;
            cin >> nplayerx;
            cout << "Enter the x of the square you want to put this queen on" << endl;
            cin >> nplayery;
            check = true;
            check2 = true;
            if (nplayerx < 0 || nplayerx > 7 || nplayery < 0 || nplayery > 7) {
                cout << "This square doesn't exist" << endl;
            }
            else{
                if (board[nplayerx][nplayery] != 'O'){
                    cout << "There is another piece on this square" << endl;
                }
                else {
                    if (playerx - nplayerx == 0 || playery - nplayery == 0){
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
                    }

                    if (abs(playerx - nplayerx) == abs(playery - nplayery)){
                        if (nplayerx > playerx){
                            dx = 1;
                        }
                        else {
                            dx = -1;
                        }
                        if (nplayery > playery){
                            dy = 1;
                        }
                        else {
                            dy = -1;
                        }
                        x3 = playerx + dx;
                        y3 = playery + dy;
                        while (x3 != nplayerx && y3 != nplayery) {
                            if (board[x3][y3] != 'O') {
                                check2 = false;
                                break;
                            }
                            x3 += dx;
                            y3 += dy;
                        }
                    }

                    if (check && check2){
                        board[nplayerx][nplayery] = 'q';
                        board[playerx][playery] = 'O';
                    }
                    else {
                        cout << "Unavailable square" << endl;
                    }
                }
            }
        }

        if (board[playerx][playery] == 'm'){ //king
            cout << "Enter the y of the square you want to put this king on" << endl;
            cin >> nplayerx;
            cout << "Enter the x of the square you want to put this king on" << endl;
            cin >> nplayery;
            if (nplayerx < 0 || nplayerx > 7 || nplayery < 0 || nplayery > 7) {
              cout << "This square doesn't exist" << endl;
            }
            else {
                if (board[nplayerx][nplayery] != 'O') {
                    cout << "There is another piece on this square" << endl;
                }
                else {
                    if ((abs(playerx - nplayerx) == 1 && abs(playery - nplayery) <= 1) || (abs(playery - nplayery) == 1 && abs(playerx - nplayerx) <= 1)) {
                      board[nplayerx][nplayery] = 'm';
                      board[playerx][playery] = 'O';
                    } else {
                      cout << "Unavailable square" << endl;
                    }
                }
            }
        }

        if (board[playerx][playery] == 'P' && playerx == 1){ //black pawn for first move
            do {
                cout << "With how much do you want to move this pawn (1 or 2)" << endl;
                cin >> pawnmove;
                if(pawnmove != 1 && pawnmove != 2){
                    cout << "Enter 1 or 2" << endl;
                }
            }
            while (pawnmove != 1 && pawnmove != 2);
            if (board[playerx + pawnmove][playery] == 'O'){
                if (pawnmove == 2){
                    if (board[playerx + 1][playery] == 'O'){
                        board[playerx][playery] = 'O';
                        board[playerx + pawnmove][playery] = 'P';
                    }
                    else {
                        cout << "There is a piece blocking your move" << endl;
                    }
                }
                else {
                    board[playerx][playery] = 'O';
                    board[playerx + pawnmove][playery] = 'P';
                }
            }
            else {
                cout << "There is another piece on this square" << endl;
            }
        }

        if (board[playerx][playery] == 'P' && playerx != 1){
            if (board[playerx + 1][playery] == 'O'){
                board[playerx][playery] = 'O';
                board[playerx + 1][playery] = 'P';
            }
            else {
                cout << "There is another piece on this square" << endl;
            }
        }
        
        printboard();
    }
    return 0;
}