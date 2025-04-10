NOT A COMPLETE CODE BUT BARELY WORKS 

NO VALIDATIONS FOR INPUTS FROM USER



codes for future
====================
methods
========
// //this is for checking the char is in between 1 to 9 or char 49 to 57(ASCII values)
        while (true)
        {
            if(int(board_position) >= '49' && int(board_position) <='57')
            {
                break;
            }
            else
            {
                cout<<"Enter position number inside 1-9";
                cin>>board_position;
            }
        }
        


// //user choose X OR O
    char choose_X_OR_O()
    {
        char player_1, player_2;
        cout << "choose X or O \t";
        char x_or_o;
        cin >> x_or_o;
        if (x_or_o == 'x' || x_or_o == 'X')
        {
            return player_1 = 'X', player_2 = 'O';
        }
        else
        {
            return player_1 = 'O', player_2 = 'X';
        }
    }

