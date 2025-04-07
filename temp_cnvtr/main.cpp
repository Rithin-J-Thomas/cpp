#include <iostream>
#include <vector>
using namespace std;

class Temperature
{
public:
    double C_F(double C) { return (C * 9 / 5) + 32; }
    double C_K(double C) { return C + 273.15; }

    double F_C(double F) { return (F - 32) * 5 / 9; }
    double F_K(double F) { return (F - 32) * 5 / 9 + 273.15; }

    double K_C(double K) { return K - 273.15; }
    double K_F(double K) { return (K - 273.15) * 9 / 5 + 32; }
};

void display_history(const vector<double>& hist){//hist is alias for history & means refference
    cout <<"History\n";
    for(double i:hist)
    {
        cout<<"\t"<<i<<"\n";
    }
}

int main()
{
    char unit_choice, tem_choice;
    double user_input ,val;

    vector<double> history;
    // //Create an object of My each Classes
    Temperature tempConverter;
    while (true)
    {
        cout << "\nUNIT CONVERTOR \n1:TEMPERATURE \nh:History \nq: Quit\n";
        cin >> unit_choice;
        switch (unit_choice)
        {
        case '1':
            cout << "TEMPERATURE \n1: Celsius to Fahrenheit \n2: Celsius to Kelvin \n3: Fahrenheit to Celsius \n4: Fahrenheit to Kelvin \n5: Kelvin to Celsius \n6: Kelvin to Fahrenheit \n";
            cin >> tem_choice;
            cout << "Enter Temperature \t";
            cin >> user_input;

            // //switch for TEMPERATURE
            switch (tem_choice)
            {
            case '1':
                val = tempConverter.C_F(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            case '2':
                val = tempConverter.C_K(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            case '3':
                val = tempConverter.F_C(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            case '4':
                val = tempConverter.F_K(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            case '5':
                val = tempConverter.K_C(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            case '6':
                val = tempConverter.K_F(user_input);
                cout << val;
                history.emplace_back(val);
                break;
            }
            break;
            
        case 'q':
            return 0;
            break;
        case 'h':
            display_history(history);
            break; 
        default:
            cout << "Invalid choice! Try again.\n";
            break;

        }
    }
    return 0;
}