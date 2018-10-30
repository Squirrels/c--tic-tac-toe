#include <iostream>
#include <vector>

using namespace std;
char squares[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
int used_spaces = 0;
int checkWin();
void board();

int main(int argc, const char * argv[]) {
    int current_player = 1, current_play = 0, winner = checkWin();
    while(winner == 0 && used_spaces != 9){
        board();
        // Ask for input
        printf("Player %d\n", current_player);
        cout << "Select box to play" << endl;
        cin >> current_play;
        // Check play
        while (squares[current_play] == 'X' ||  squares[current_play] == 'O'){
            board();
            cout << "Invalid play, pick a different one" << endl;
            cin >> current_play;
        }
        squares[current_play] = (current_player == 1) ? 'X' : 'O';
        // Change player
        current_player = (current_player == 1)  ? 2 : 1;
        winner = checkWin();
        used_spaces++;
    }
    if(winner == 0){
        cout << "Tie! Nobody wins!\n" << endl;
    } else {
        printf("Winner is Player %d\n", winner);
    }
    return 0;
}

int checkWin(){
    // Possible lines
    vector<vector<int>> lines{
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Horizontals
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Verticals
        {0, 4, 8}, {2, 4, 6} // Diagonals
    };
    for(int i=0; i<lines.size(); i++){
        // Check possible winner
        if(squares[lines[i][0]] == squares[lines[i][1]] && squares[lines[i][1]] == squares[lines[i][2]]){
            return squares[lines[i][0]] == 'X' ? 1 : 2;
        }
    }
    return 0;
}

void board(){
    // Draw the board
    cout << squares[0] << " | " << squares[1] << " | " << squares[2] << endl;
    cout << "-- --- --" << endl;
    cout << squares[3] << " | " << squares[4] << " | " << squares[5] << endl;
    cout << "-- --- --" << endl;
    cout << squares[6] << " | " << squares[7] << " | " << squares[8] << endl;
}
