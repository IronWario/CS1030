#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    srand(time(NULL));

    int numberPoints = 100;
    enum values {
        displayLeft = 1,
        displayRight = 2,
        Guess = 3,
        Change = 4,
        Exit = 5
    };
    string playerName;

    bool valid = false;
    bool playing = true;
    int userSelect;
    values userSelected;
    int userGuess;

    while (!valid) {
        cout << "Please enter your name\n";
        getline(cin, playerName);
        for (int i = 0; i < playerName.size(); i++) {
            if (!isalpha(playerName[i]) && !isspace(playerName[i])) {
                valid = false;
                cout << "Your name can only have alphabets or spaces. Enter Again\n";
                break;
            }
            else {
                //cout << "Your name is valid\n";
                valid = true;
                //break;
            }
        }
        if (valid) {
            cout << "Your name is valid\n";
        }

    }
    int randNumberOne;
    int randNumberTwo;
    do {
        randNumberOne = rand() % 101 + 100;
        randNumberTwo = rand() % 101 + 100;
    } while (randNumberOne > randNumberTwo);
    
    int shownNumOne = -1;
    int shownNumTwo = -1;

    bool showingOne = false;
    
    while (playing) {
        cout << "--------------------------\n";
        cout << "Numbers: " << shownNumOne << "\t" << shownNumTwo << endl;
        cout << "Please select an option:\n";
        cout << "1: Display Number on Left\n";
        cout << "2: Display Number on Right\n";
        cout << "3: Make a Guess\n";
        cout << "4: Change Numbers\n";
        cout << "5: Exit Program\n";
        cout << "--------------------------\n";

        cin >> userSelect;
        userSelected = static_cast<values>(userSelect);

        switch (userSelected) {
        case 1:
            if (!showingOne) {
                cout << "From now on, you will only receive 1 point for a correct guess, and lose 10 for an incorrect guess.\n";
                shownNumOne = randNumberOne;
                showingOne = true;
            }
            else {
                cout << "One number already revealed. Cannot reveal another\n";
            }
            break;
        case 2:
            if (!showingOne) {
                cout << "From now on, you will only receive 1 point for a correct guess, and lose 10 for an incorrect guess.\n";
                shownNumTwo = randNumberTwo;
                showingOne = true;
            }
            else {
                cout << "One number already revealed. Cannot reveal another\n";
            }
            break;
        case 3:
            cout << "Enter your Guess: ";
            cin >> userGuess;
            if (userGuess > randNumberOne && userGuess < randNumberTwo) {
                if (showingOne) {
                    cout << "You guessed correctly! Awarded 1 Point!\n";
                    numberPoints += 1;
                }
                else {
                    cout << "You guessed correctly! Awarded 5 Points!\n";
                    numberPoints += 5;
                }
            }
            else {
                if (showingOne) {
                    cout << "You guessed Incorrectly. You Lose 10 Points.\n";
                    numberPoints += -10;
                }
                else {
                    cout << "You guessed Incorrectly. You Lose 5 Points.\n";
                    numberPoints += -5;
                }
            }
            cout << "Your Remaining Points: " << numberPoints << endl;
            break;
        case 4:
            numberPoints += -1;
            cout << "Your Remaining Points = " << numberPoints << endl;
            cout << "Generating new Boundaries.\n";
            do {
                randNumberOne = rand() % 101 + 100;
                randNumberTwo = rand() % 101 + 100;
            } while (randNumberOne > randNumberTwo);
            showingOne = false;
            shownNumOne = -1;
            shownNumTwo = -1;
            break;
        case 5:
            cout << "Goodbye " << playerName << "! Quitting Program...\n";
            playing = false;
            break;
        default:
            cout << "Not a valid selection. Try again\n";
            break;
        }
    }

    //return 0;
}