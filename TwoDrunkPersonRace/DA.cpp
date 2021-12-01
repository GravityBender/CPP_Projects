#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

void animate(char c1, char c2)
{
    srand(time(0));
    int position1, position2;
    int distance = 60;
    position1 = position2 = distance / 2;

    while (true)
    {
        std::cout << "|_START_|";
        for (int i = 0; i < distance; i++)
        {
            if (position1 == i)
                std::cout << c1;
            else if (position2 == i)
            {
                std::cout << c2;
            }

            else
                std::cout << " ";
        }
        std::cout << "|_FINISH_|" << std::endl;

        int step1 = rand() % 3 - 1;
        position1 += step1;
        int step2 = rand() % 3 - 1;
        position2 += step2;

        if (position1 > distance - 1)
        {
            std::cout << "Player " << c1 << " won :)";
            break;
        }
        if (position2 > distance - 1)
        {
            std::cout << "Player " << c2 << " won :)";
            break;
        }
        for (int sleep = 0; sleep < 10000000; ++sleep)
            ;
    }
}

int main()
{
    std::cout << "Enter first player name(any letter from the alphabet)" << std::endl;
    char c1;
    std::cin >> c1;
    std::cout << "Enter second player name(any letter from the alphabet)" << std::endl;
    char c2;
    std::cin >> c2;
    animate(c1, c2);
    return 0;
}