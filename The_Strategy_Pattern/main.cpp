#include "Duck.h"

int main()
{
    Duck *duck = nullptr;
    cout << "\nDuck Simulator \n"
         << endl;
    for (int i = 1; i <= 4; i++)
    {
        duck = DuckFactory::createDuck(i);
        DuckSimulator::simulate(duck);
        cout << "-----------------------------" << endl;
        delete duck;
    }

    return 0;
}