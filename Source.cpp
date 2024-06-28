#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to set the console text color using ANSI escape
void SetColor(int textColor)
{
    cout << "\033[" << textColor << "m";
}

void displayStart() 
{
    SetColor(33);
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "                           Welcome to the Number Guessing Game!\n";
    cout << "------------------------------------------------------------------------------------------------\n\n";

    SetColor(34);
    cout << "I have picked a number between 1 and 100.\n";
    cout << "Can you guess what it is?\n\n";
}

int getRandomNumber() 
{
    srand(time(0));                                                // Seed the random number generator
    int randomNumber = rand() % 100 + 1;                          // Generate a random number between 1 and 100
    return randomNumber;
}

void playGame(int sn) 
{
    int playerGuess = 0;
    int guessCount = 0;

    while (true) 
    {
        SetColor(35);
        cout << "Enter your guess: ";
        cin >> playerGuess;
        guessCount++;

        if (playerGuess > sn) 
        {
            SetColor(32);
            cout << "Your guess is too high!\n\n";
        }
        else if (playerGuess < sn) 
        {
            SetColor(31);
            cout << "Your guess is too low!\n\n";
        }
        else 
        {
            SetColor(34);
            cout << "Congratulations! You've guessed the number in " << guessCount << " tries.\n\n";
            break;
        }
    }
}

int main() 
{
    displayStart();
    int SecretNumber = getRandomNumber();
    playGame(SecretNumber);

    SetColor(31);
    cout << "Thanks for playing!\n\n";

    SetColor(37);
    system("pause");
    return 0;
}
