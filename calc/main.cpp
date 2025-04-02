#include <iostream>
using namespace std;

class Calc
{
public:
    double add(double a, double b)
    {
        return a + b;
    }
    double sub(double a, double b){
        return a - b;
    }
    double div(double a, double b)
    {
        return a / b;
    }
    double mul(double a, double b){
        return a * b;
    }
};

int main()
{
    double num1, num2;
    char choice;


//making class's instance
    Calc myobj;

    while (true)
    {
        cout << "Enter numbers \n";
        cin >> num1 >> choice >> num2;
        switch (choice)
        {
        case '+':
            cout << myobj.add(num1, num2) << "\n";
            break;
        case '-':
            cout << myobj.sub(num1, num2) << "\n";
            break;
        case '/':
            cout << myobj.div(num1, num2) << "\n";
            break;
        case '*':
            cout << myobj.mul(num1, num2) << "\n";
            break;    

        default:
            cout << "Exiting\n";
            false;
            break;
        }
    }

    return 0;
}