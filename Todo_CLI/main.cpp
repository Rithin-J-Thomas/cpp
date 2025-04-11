#include <iostream>
#include <string>
#include <map>
#include <vector>


using std::cout ,std::cin;

// //this struct is to hold one task
struct Task
{
    std::string task_name ,task_done  , description;
    std::map<std::string ,std::string>Time;
};

// //map to store every tasks from user
std::map<std::string ,std::vector<std::string>>Todo_menu;

// //function for taking input from user
void taking_task(Task& app)
{
    // //declares variables 
    std::string time , date;

    cout<<"Task Name\t\t";
    cin>>app.task_name;

    cin.ignore();   // //to use getline after using cin;

    cout<<"Task Description\t";
    std::getline(cin,app.description);


    cout << "Time\t\t\t";
    cin>>time;
    app.Time["time"]=time;
    cout << "Date\t\t\t";
    cin>>date;
    app.Time["date"]=date;

    cout << "Task Status\t\t";
    cin>>app.task_done;

    
    std::vector<std::string> task_details = {app.task_name,app.description,time,date,app.task_done};

    Todo_menu[app.task_name]=task_details;

}

// //function for printing task
void display_task(Task app)
{

    if(Todo_menu.empty())
    {
        cout<<"\n\u001b[103m \u001b[30mNo task to display \u001b[0m\n";
    }
    else
    {
        int j=1 ,task_found =0 ,user_task_request;
        cout<<"\nList of tasks";
        cout << "\n============================\n";
    
        for(auto i :Todo_menu)
        {
            cout<<"Press '"<<j<<"' : "<<i.first<<"\n";
    
            ++j;
        }

        cout << "\nTask number to display\t";
        cin>>user_task_request;

        j = 1;
        for(auto i :Todo_menu)
        {
            if(user_task_request == j)
            {
                auto test = Todo_menu[i.first];
                task_found = 1;
                cout << "\n============================\n";
                cout << "Task:        " << test[0] << "\n";
                cout << "Description: " << test[1] << "\n";
                cout << "Time:        " << test[2] << "\n";
                cout << "Date:        " << test[3] << "\n";
                cout << "Status:      " << test[4] << "\n";
                cout << "============================\n";
            }
            j++;
        }
        if(task_found==0)
        {
            cout<<"\n\u001b[41m Invalid Choice \u001b[0m\n";
        }
    }
}

// //function for make changes to tasks
void update_task(Task& app)
{
    int task_choice;
    int j=1,task_found = 0 ;    // //j counts how many elements in Todo_menu map to print

    cout<<"\nList of tasks to edit";
    cout << "\n============================\n";

    for(auto i :Todo_menu)
    {
        cout<<"Press '"<<j<<"' : "<<i.first<<"\n";
        ++j;
    }

    cin>>task_choice;
    j = 1;
    for(auto i :Todo_menu)
    {
        if(task_choice == j)
        {
            taking_task(app);
            task_found = 1;
        }
        j++;
    }
    if(task_found==0)
    {
        cout<<"\n\u001b[41m Invalid Choice \u001b[0m\n";
    }    
}

int main()
{

    Task app;

    while(true)
    {
        cout<<"\n1 : to add task\n";
        cout<<"2 : to display task\n";
        cout<<"3 : to update task\n";
        cout<<"0 : to quit\n\n";

        char choice ;
        cin>>choice;

        switch(choice)
        {
            case '1':
                taking_task(app);
                break;
            
            case '2':
                display_task(app);
                break;   

            case '3':
                update_task(app);
                break;

            case '0':
                return false;

            default:
                cout<<"\n\u001b[41m Invalid Choice \u001b[0m\n";
                break;        
        }
    }
    return 0;
}

