#include<iostream>
#include<random>
#include<fstream>
#include<string>
using namespace std;

class NumberGuess
{
    private:
    // // trying Private Access Specifiers
    int make_random_num()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution <int> dist(1,10);

        return dist(gen);
    }


    public:

        int start_game(int numb)
        {
            int guessed ,chance = 3,found=0;

            while(chance >0)
            {
                // //getting user's input 
                guessed = get_user_input();

                // //checking if guess is correct or not
                if (numb == guessed){
                    cout<<"**********Your guessed is correct**********\n\n";
                    //return ++score;
                    found++;
                    break;
                }
                else if(numb > guessed)
                {
                    chance--;
                    cout<<"Your guess is low '"<<chance<<"' chance left to guess\n\n";
                }
                else
                {
                    chance--;
                    cout<<"Your guess is high '"<<chance<<"' chance left to guess\n\n";              
                }

            }

            // //looking for chances left to guess and found is for game_status to calculate or add score if found
            if (chance == 0)
            {
                cout<<"\tYou lost\n\n";
                return found;
            }
            else
            {
                return found;
            }



            
        }

        // //getting user's input 
        int get_user_input()
        {
            int user_input;

            cout<<"Enter your guess\n\n";
            cin>>user_input;
            return user_input;
        }

        // //for tracking and printing score 
        int track_score(int score)
        { 
            cout<<"\tYour Score = "<<score<<"\n";
            cout<<"\t--------------------\n\n";
            return score;
        }


        // //prints number
        int getting_random_number()
        {
            // //make_random_num() is a Private Access Specifier
            int num = make_random_num();
            cout<<num<<"\n";
            return num;
        }

        char exit_game()
        {
            char exit;
            cout<<"\nEnter 'N' to exit game or Enter any key to continue \t";
            cin>>exit;
            return tolower(exit);
        }

        // //save history in a file
        void save_history_file(int score)
        {
            string file_name ,name;

            // //asking file's name to save
            cout<<"\nEnter the file name to save \t";
            cin>>file_name;

            cin.ignore();

            cout<<"\nEnter User Name \t";
            // // gets entire name using getline()
            getline(cin,name);

            // // Create and open a text file
            ofstream File(file_name);
            File <<name<<" Scored "<<score<<" points";

            File.close();
            cout<<"\nFile Saved";
        }
};

int main()
{
    int score = 0 ;
    char exit;

    NumberGuess game;
    
    // //game.getting_random_number();
    

    while(true)
    {
        int game_status=0;
        char save_history;
        
        int number_to_guess = game.getting_random_number();
        // //cout<<number_to_guess<<"hhhh";

        // //if user guess correct value of game_status will become 1 {"start_game() returns 1 or 0" and "found" variable is responsible for returning it}
        game_status = game.start_game(number_to_guess);


        // //keep track of score 
        if (game_status==1)
        {
            score++;
            score = game.track_score(score);
        }
        else
        {
            // //asking for save game score in a file
            cout<<"\nDo you want to save score in a file Enter 'Y' to save and 'N' to not save\t";
            cin>>save_history;
            if (save_history =='Y' || save_history == 'y')
            {
                game.save_history_file(score);
            }

            // //this will reset score back to 0 
            score = 0;

            // //asking user to continue game or not 
            exit=game.exit_game();
            if(exit=='n')
            {
                break;
            }
        }

    }

    return 0;
}
