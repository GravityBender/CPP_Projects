#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

void displayRules(std::string pName)
{

    std::cout << "\n\t\t\t\t\t\t\t\t\tWelcome to the Gambling Game!!\t\t\t\t\t\t\t\t\t";
    std::cout << "\n\t\t\t\t\t\t\t\t\tSo, Mr./Mrs./Mis. " << pName << " here are the rules of the game: \t\t\t\t\t\t\t\t\t";
    std::cout << "\n\t\t\t\t\t\t\t\t\t\t1.You would be getting an initial amount of 1000 coins;"
              << "which you would be using for in game gambling.";
    std::cout << "\n\t\t\t\t\t\t\t\t\t\t2.If you loose all the coins then you would loose the game.";
}

void playGame()
{

    int balanceCoins = 1000;
    int bettingCoins = 0;
    int guess = 0;
    int gamble = 0;
    std::cout << "Your current balance is: " << balanceCoins << std::endl;

    char choice;
    do
    {
        system("cls");

        do
        {
            std::cout << "Enter the betting amount" << std::endl;
            std::cin >> bettingCoins;

            if (bettingCoins > balanceCoins)
                std::cout << "\nAmount entered exceeds the available balance"
                          << "\nEnter the amount again." << std::endl;

        } while (bettingCoins > balanceCoins);

        do
        {
            std::cout << "\nGuess any number between 1 and 10.";
            std::cin >> guess;

            if (guess <= 0 || guess > 10)
                std::cout << "\nThe number entered should be within 1 and 10"
                          << "\nPlease, re-enter the amount again" << std::endl;

        } while (guess <= 0 || guess > 10);

        gamble = rand() % 10 + 1;
        std::cout << "\nThe winning number was: " << gamble;
        if (gamble == guess)
        {
            std::cout << "\nYou won this bet!!"
                      << "\nYou are credited with " << bettingCoins * 10 << " credits!" << std::endl;
            balanceCoins += bettingCoins * 10;
        }
        else
        {
            std::cout << "Oops, you lost the bet."
                      << "\nYou lost " << bettingCoins << " coins!" << std::endl;
            balanceCoins -= bettingCoins;
        }

        std::cout << "\nYour balance is: " << balanceCoins << std::endl;

        if (balanceCoins == 0)
        {
            std::cout << "Sorry, you are out of coins to play." << std::endl;
            break;
        }

        std::cout << "\nDo you wish to continue?(y\n)" << std::endl;
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nThanks for playing this game!"
              << "\nYour balance at the end of this game is " << balanceCoins;
}

int main()
{
    std::string pName;
    srand(time(0));

    std::cout << "Enter the name of the player" << std::endl;
    std::getline(std::cin, pName);
    std::cout << "The player name is: " << pName << std::endl;

    std::cout << "Are you familiar with the rules of the game?(y/n)" << std::endl;
    char ch;
    std::cin >> ch;

    if (ch == 'n')
        displayRules(pName);

    std::cout << "\nLet the Game begin then!!" << std::endl;
    playGame();

    return 0;
}