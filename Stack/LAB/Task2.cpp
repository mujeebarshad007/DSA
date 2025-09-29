#include <iostream>
#include "conio.h"
#include <fstream>
class stack
{
    int top_i;
    int arr[1000];

public:
    stack()
    {
        top_i = -1;
    }
    void push(char c)
    {
        arr[++top_i] = c;
    }

    void pop()
    {
        if (!empty())
        {
            top_i--;
        }
    }
    bool empty()
    {
        return top_i == -1;
    }

    int top_value()
    {
        return arr[top_i];
    }
};
bool read_file(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << " File not Found " << std::endl;
        return false;
    }
    stack s;
    char ch;
    while (file.get(ch))
    {
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (ch == '}')
            {
                if (s.empty())
                {
                    return false;
                }
                s.pop();
            }
        }
    }
    file.close();
    return s.empty();
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout << "File name not given!\n";
        return 1;
    }

    if (read_file(argv[1]))
    {
        std::cout << " Balanced \n";
    }
    else
    {
        std::cout << " Not Balanced \n";
    }
}