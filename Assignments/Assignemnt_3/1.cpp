#include <iostream>
#include <queue>
#include <cstring>
struct Patient
{
    std::string name;
    int age;
    std::string disease;
};
void help()
{
    std::cout << "\t\t  ____________________________________________________________________________________________" << std::endl;
    std::cout << "\t\t |                                                                                            |" << std::endl;
    std::cout << "\t\t |                        ============================================                        |" << std::endl;
    std::cout << "\t\t |                          Welcome to the Hospital Managemnet System                         |" << std::endl;
    std::cout << "\t\t |                        ============================================                        |" << std::endl;
    std::cout << "\t\t |                                                                                            |" << std::endl;
    std::cout << "\t\t |                              Usage: ./a.out number of queues /help                         |" << std::endl;
    std::cout << "\t\t |                              Example ./a.out 3  or ./a.out help                            |" << std::endl;
    std::cout << "\t\t |                                                                                            |" << std::endl;
    std::cout << "\t\t |                                        About                                               |" << std::endl;
    std::cout << "\t\t |             This System Allows You to add Patient details by using Queue in Linear DS      |" << std::endl;
    std::cout << "\t\t |                            It Supports The Input OF QUeues Dynamically                     |" << std::endl;
    std::cout << "\t\t |                  It has a Good User INterface And A Menu To Handle Inputs                  |" << std::endl;
    std::cout << "\t\t |                                                                                            |" << std::endl;
    std::cout << "\t\t |                                    Interactive Mode                                        |" << std::endl;
    std::cout << "\t\t |               You can Add Patient Details Like its Name,Age and Disease                    |" << std::endl;
    std::cout << "\t\t |                                                                                            |" << std::endl;
    std::cout << "\t\t |                           Press any Key and Enter To exit Program                          |" << std::endl;
    std::cout << "\t\t |____________________________________________________________________________________________|" << std::endl;
}
void menu()
{
    std::cout << "\t\t  ______________________________________" << std::endl;
    std::cout << "\t\t |                                      |" << std::endl;
    std::cout << "\t\t |         ======================       |" << std::endl;
    std::cout << "\t\t |              Menu Options:           |" << std::endl;
    std::cout << "\t\t |         ======================       |" << std::endl;
    std::cout << "\t\t |                                      |" << std::endl;
    std::cout << "\t\t |       1.  Add Patient                |" << std::endl;
    std::cout << "\t\t |       2. Serve Patient (Remove)      |" << std::endl;
    std::cout << "\t\t |       3. Display All Queues          |" << std::endl;
    std::cout << "\t\t |       4. Check Number OF Queues      |" << std::endl;
    std::cout << "\t\t |       5. Exit                        |" << std::endl;
    std::cout << "\t\t |______________________________________|" << std::endl;
}
void display(std::queue<Patient> q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\nQueue " << i + 1 << ":\n";
        if (q[i].empty())
        {
            std::cout << "  No patients in this queue.\n";
        }
        else
        {
            std::queue<Patient> temp = q[i];
            int count = 1;
            while (!temp.empty())
            {
                Patient p = temp.front();
                temp.pop();
                std::cout << "  " << count++ << ". " << p.name
                          << " (Age: " << p.age
                          << ", Reason: " << p.disease << ")\n";
            }
        }
    }
}
int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "help") == 0)
    {
        help();
        return 0;
    }
    if (argc < 2)
    {
        std::cout << " Invalid Input! Please Enter Any Inputs \n";
        return 0;
    }

    int num_of_que = atoi(argv[1]);

    if (num_of_que <= 0)
    {
        std::cout << "Please Enter More Than One Queues Number \n";
        return 0;
    }

    std::queue<Patient> *q = new std::queue<Patient>[num_of_que];

    int choice;
    do
    {
        system("clear");
        menu();
        std::cin >> choice;

        if (choice == 1)
        {
            system("clear");
            Patient p;
            int qnum;
            std::cout << " Enter The Queue Number In which You want to Add Patient Data\n";
            std::cin >> qnum;
            if (qnum < 1 || qnum > num_of_que)
            {
                std::cout << " Error! Please Enter the Valid Number\n";
                continue;
            }

            std::cout << " Enter The Patient NAME : \n";
            std::cin.ignore();
            std::getline(std::cin, p.name);
            std::cout << " Enter The Patient Age : \n";
            std::cin >> p.age;
            std::cout << " Enter The Patient Disease : \n";
            std::cin >> p.disease;
            q[qnum - 1].push(p);
            std::cout << " The Record For this Patient Has been Added Successfully\n";
        }
        else if (choice == 2)
        {
            system("clear");
            int qnum;
            std::cout << " Enter The Queue Number In which You want to Remove Patient Data\n";
            std::cin >> qnum;
            if (qnum < 1 || qnum > num_of_que)
            {
                std::cout << " Error! Please Enter the Valid Number\n";
                continue;
            }

            if (q[qnum - 1].empty())
            {
                std::cout << " There is no Record For this Patient\n";
            }
            else
            {

                Patient p1 = q[qnum - 1].front();
                q[qnum - 1].pop();
                std::cout << " The Patient has Been Removed Who had details of \n";
                std::cout << "NAME" << "\t\t" << "AGE" << "\t\t" << "DISEASE" << std::endl;
                std::cout << p1.name << "\t\t" << p1.age << "\t\t" << p1.disease << std::endl;
            }
        }
        else if (choice == 3)
        {
            system("clear");
            display(q, num_of_que);
        }
        else if (choice == 4)
        {
            system("clear");
            std::cout << " The Total Number Of Queues are " << num_of_que << std::endl;
        }
        else if (choice == 5)
        {
            exit(0);
        }
        else
        {
            std::cout << " Enter The Valid Choice \n";
            continue;
        }
        std::cout << " Press Enter To continue\n";
        std::cin.ignore();
        std::cin.get();
    } while (choice != 0);
    return 0;
}