#include <iostream>
#include <vector>
using namespace std;

class Initial_Phase
{
private:
    // //game score
    int score;
    // //playing board
    vector<vector<char>> board;

public:
    // //2D Vector 3x3
    Initial_Phase() : board(3, vector<char>(3))
    {
        cout << "\n\nEnter the position's number to enter you input \n\n";
        // // count= helps to add char 1 to 9 for printing in board position
        int count = 1;
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                board[i][j] = '0' + count;
                cout << board[i][j] << "\t";
                count++;
            }
            cout << "\n\n";
        }
    }

    // //method just to display or print board (lastest board)
    void display_board()
    {
        cout << "\n\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << "\n\n";
        }
    }

    // //asking user to exit game or not
    char continue_game(char exit)
    {
        // //'y' will take as YES from user to continue game and return 'n' as NO
        if (exit == 'y')
        {
            return 'n';
        }
        else
        {
            return 'y';
        }
    }

    // //get the input from user
    void game_started()
    {
        // //board_position= to enter the symbol in desired position,  player_symbol = Choose X or O
        char board_position, player_symbol;
        // //turn=keep track of whose turn is now (just a indicator)
        int turn =1;

        // //loop for game to keep going until someone wins
        while(true)
        {
            // //found=flag for position found in board or not
            int found = 1;
            
            if (turn %2==0)// //even numb for Player 2
            {
                cout << "\n\nPlayer 2's turn \tSymbol=O\n\n";

            }
            else
            {
                cout << "\n\nPlayer 1's \tSymbol=X turn\n\n";
            }

            cout << "ENTER X or O \t";
            cin >> player_symbol;

            cout << "Enter the position\'s number to enter your input \t";
            cin >> board_position;



            for (int i = 0; i <= 2; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    if (board[i][j] == board_position)
                    {
                        board[i][j] = player_symbol;
                        found++;
                        turn++;

                    }
                }
            }

            while (found == 1)
            {
                cout << "\nThis position is already marked. Please choose a different one.\n";
                game_started();
            }
            display_board();
            bool win = win_or_lose();
            if (win == false)
            {
                break;
            }
        }
    }
    bool win_or_lose()
    {
        int k=0;
        for(int i =0; i <=2 ; i++)
        {
            int j=0;
            if(board[i][j]==board[i][j+1] && board[i][j+1]==board[i][j+2])
            {
                cout<<"\n\n\n**********Win**********\n\n\n";
                return false;
            }
            else if(board[j][k]==board[j+1][k] && board[j+1][k]==board[j+2][k])
            {
                cout<<"\n\n\n**********Win**********\n\n\n";
                return false;
            }
            else if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
            {
                cout<<"\n\n\n**********Win**********\n\n\n";
                return false;
            }
            else if(board[2][0]==board[1][1] && board[1][1]==board[0][2])
            {
                cout<<"\n\n\n**********Win**********\n\n\n";
                return false;
            }
            k++;
        }
        return true;
    }
};

int main()
{
    char exit = 'n';
    while (exit == 'n')
    {
        // //sets up the game board
        Initial_Phase game;


        game.game_started();

        // // asking user to exit the game after finishing
        cout << "\npress \'y\' to continue or press any key to exit\n";
        cin >> exit;
        exit = game.continue_game(exit);
        
    }

    return 0;
}
