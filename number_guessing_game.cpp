//NUMBER GUESSING Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    const int maxAttempts = 10; // Maximum number of attempts allowed
    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100." << endl;

    while(attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << ": Enter your guess: ";
        cin >> guess;

        if(guess == randomNumber) {
            cout << "Congratulations You guessed the number correctly." << endl;
            break;
        } else if(guess < randomNumber) {
            cout << "Too low Try again." << endl;
        } else {
            cout << "Too high Try again." << endl;
        }

        attempts++;
    }

    if(attempts == maxAttempts) {
        cout << "Sorry, you didn't guess the number. The number was " << randomNumber << "." << endl;
    }

    return 0;
}
