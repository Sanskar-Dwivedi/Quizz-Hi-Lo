#include <iostream>
#include "Random.h"

int randomOutput()
{
    return {Random::get(1, 100)};
}

void hiLo(int answer, int input)
{
    if (input > answer)
    {
        std::cout << "Your guess is too high.\n";
    }
    else if (input < answer)
    {
        std::cout << "Your guess is too low.\n";
    }
}

void guesser()
{
    int answer{randomOutput()};
    bool hasWon{false};
    for (int guess{1}, input{}; guess <= 7; ++guess)
    {
        std::cout << "Guess #" << guess << " ";
        std::cin >> input;
        hiLo(answer, input);

        if (guess == 7 || answer == input)
        {
            if (answer == input)
                hasWon = true;
            if (hasWon)
                std::cout << "Correct! You win!\n";
            if (!hasWon)
                std::cout << "Sorry, you lose. The correct number was " << answer << ".\n";

            while (true)
            {
                std::cout << "Would you like to play again (y/n)? ";
                char re{};
                std::cin >> re;

                if (re == 'y' || re == 'Y')
                {
                    guess = 0;
                    answer = randomOutput();
                    hasWon=false;
                    break;
                }
                else if (re == 'n' || re == 'N')
                {
                    std::cout << "Thank you for playing <3";
                    std::exit(0);
                }
                
            }
        }
    }
}

int main()
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.  \n";
    guesser();
    return 0;
}