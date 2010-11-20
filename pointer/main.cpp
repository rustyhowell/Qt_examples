#include <iostream>
using namespace std;

// Checking if Person* is reallocated during each iteration. It's not.

const int MAX = 100000000;

class Person
{
    public:
    private:
};

Person* getPerson()
{
    static Person p;
    return &p;
}

int main()
{

    /*
    for(int i = 0; i < MAX; ++i)
    {
        Person * p1 = getPerson();
    }
    */

    Person * p2 = NULL;
    for(int i = 0; i < MAX; ++i)
    {
        p2 = getPerson();
    }
}
