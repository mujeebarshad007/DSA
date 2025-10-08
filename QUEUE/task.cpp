#include <iostream>
#include "header.h"
int main()
{
    std::cout << " Welcome to Lab Task 08 October 2025" << std::endl;
    queue q;
    q.push(10); // Pushing The Values
    q.push(20);
    q.push(60);
    q.push(78);
    q.push(65);
    q.push(39);

    std::cout << " The Values Pushed Are 10 20 60 78 65 39 \n";
    try
    {
        std::cout << " The Front Value Of this Queue is :" << q.front() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    try
    {
        std::cout << " The Back Value Of this Queue is :" << q.back() << std ::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    // Size OF QUEUE
    std::cout << " The  Size of this Queue is " << q.size() << std::endl;

    // Popping The Value From the Queue
    q.pop();

    std::cout << " Value is Popped " << std::endl;

    // Updated Values Display
    std::cout << " The Updated Values are Now " << std::endl;
    try
    {
        std::cout << " The Front Value Of this Queue is :" << q.front() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    try
    {
        std::cout << " The Back Value Of this Queue is :" << q.back() << std ::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    // Updated Size OF QUEUE
    std::cout << " The Updated Size of this Queue is " << q.size() << std::endl;

    return 0;
}