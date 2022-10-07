#include <iostream>
using namespace std; 
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <string>
//fart

int main(){
// just variables
    int maxValue = 10;
    int secretNumber = -1;
    int guessNumber;
    int allowedGuesses = 10;
    int guessesLeft = 10;
    string userInput = "";

// secret number gen
    srand(time(NULL)); 
    secretNumber = (rand() % maxValue) + 1;

// basic instructions/beginning
    cout << "****************************************************************************" << endl;
    cout << "-----------------------Welcome to the Over Under Game-----------------------" << endl;
    cout << "****************************************************************************" << endl;    
    cout << "In this game, you have to guess the number I have secretly chosen." << '\n' << "If your guess is wrong, I will tell you if it is lower or higher." << endl;
    cout << "Use the hint get closer to the real answer!" << '\n' << "If you get it correctly, you win!" << endl;
    cout << "You also only have 10 guesses, so try your best to not run out!" << endl;
    cout << "****************************************************************************" << endl;
    cout << "Lets begin! Enter your guess: ";
    cin >> guessNumber;
    cout << "You guessed: " << guessNumber << endl;
    cout << "You have " << guessesLeft << " guesses left." << endl;

// cheats
    cout << "Enter a guess: ";
    cin >> userInput;
    if (userInput == "S"){
        cout << "They entered S!" << endl;
        cout << "The secret number is: " << secretNumber << endl;
        cout << "You have " << guessesLeft << " guesses left." << endl;
        cout << "Enter a guess: ";
        cin >> userInput;
    } else {
         guessNumber = stoi(userInput);
    }
    if (userInput == "H"){
        cout << "They entered H!" << endl;
        cout << "Lets give a hint!" << endl;
        if (secretNumber >= 1 && secretNumber <= 3){
            cout << "The secret number is a low number." << endl;
        } else if (secretNumber >= 4 && secretNumber <= 7){
            cout << "The secret number is a middle number." << endl;
        } else if (secretNumber >= 8 && secretNumber <= 10){
            cout << "The secret number is a high number." << endl;
        }
        cout << "You have " << guessesLeft << " guesses left." << endl;
        cout << "Enter a guess: ";
        cin >> userInput;
    } else{
        guessNumber = stoi(userInput);
    }

// guessing game
    while (guessNumber != secretNumber && guessesLeft > 0){
        if (guessNumber <= secretNumber){
            cout << "Your number is less than the secret number, guess again: ";
            cin >> guessNumber;
            guessesLeft --;
            cout << "You have " << guessesLeft << " guesses left." << endl;
        }
        else if (guessNumber >= secretNumber){
            cout << "Your number is greater than the secret number, guess again: ";
            cin >> guessNumber;
            guessesLeft --;
            cout << "You have " << guessesLeft << " guesses left." << endl;
        }
    }

// endings
    if (guessNumber == secretNumber){
        cout << "You guessed the correct number!\n" << "The secret number was " << secretNumber << '\n' << "Congratulations! You Won!" << endl;
    }
    if (guessesLeft == 0)
        cout << "Sorry! You lost! You ran out of guesses!" << endl;
}
