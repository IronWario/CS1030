#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string getName() {
    string playerName;
    bool valid = false;
    bool nextUpper = true;
    while (!valid) {
        cout << "Please enter your name\n";
        getline(cin, playerName);
        nextUpper = true;
        for (int i = 0; i < playerName.size(); i++) {
            if (!isalpha(playerName[i]) && !isspace(playerName[i])) {
                valid = false;
                cout << "Your name can only have alphabets or spaces. Enter Again\n";
                break;
            }
            else {
                valid = true;
                if (isspace(playerName[i])) { // Makes each new word start with uppercase
                    nextUpper = true;
                }
                else if (nextUpper && isalpha(playerName[i])) {
                    playerName[i] = toupper(playerName[i]);
                    nextUpper = false;
                }
                else {
                    playerName[i] = tolower(playerName[i]);
                }
            }
        }
        if (valid) {
            cout << "Your name is valid\n";
            return playerName;
        }

    }
}

void genShowMatrix(int(&shownMatrix)[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            shownMatrix[i][j] = -1;
        }
    }
}

void genHideMatrix(int(&numMatrix)[5][5], int randOne, int randTwo) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            do {
                numMatrix[i][j] = rand() % 101 + 100;
            } while (numMatrix[i][j] < randOne || numMatrix[i][j] > randTwo);
        }
    }
}

void showMatrix(int shownMatrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != 4) {
                cout << shownMatrix[i][j] << "\t";
            }
            else {
                cout << shownMatrix[i][j];
            }
        }
        cout << endl;
    }
}

void setDisplayLeft(int randNumberOne, int &shownNumOne, bool &showingOne) {
    if (!showingOne) {
        cout << "From now on, you will only receive 1 point for a correct guess, and lose 10 for an incorrect guess.\n";
        shownNumOne = randNumberOne;
        showingOne = true;
    }
    else {
        cout << "One number already revealed. Cannot reveal another\n";
    }
}

void setDisplayRight(int randNumberTwo, int& shownNumTwo, bool& showingOne) {
    if (!showingOne) {
        cout << "From now on, you will only receive 1 point for a correct guess, and lose 10 for an incorrect guess.\n";
        shownNumTwo = randNumberTwo;
        showingOne = true;
    }
    else {
        cout << "One number already revealed. Cannot reveal another\n";
    }
}

void eliminate(int(&shownMatrix)[5][5], int(&numMatrix)[5][5], int row, int column) {
    for (int i = 0; i < 5; i++) {
        shownMatrix[row][i] = 0;
        numMatrix[row][i] = 0;
        shownMatrix[i][column] = 0;
        shownMatrix[i][column] = 0;
    }
}

bool allZeros(int(&shownMatrix)[5][5]) {
    bool zeros = true;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (shownMatrix[i][j] != 0) {
                zeros = false;
            }
        }
    }
    return zeros;
}

void guess(int(&shownMatrix)[5][5], int(&numMatrix)[5][5], int userGuess, bool showingOne, int &numberPoints) {
    bool match = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (numMatrix[i][j] == userGuess) {
                match = true;
                eliminate(shownMatrix, numMatrix, i, j);
            }
        }
    }
    if (match) {
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
}

void initialize(int &randNumberOne, int &randNumberTwo, int &shownNumOne, int &shownNumTwo, int(&shownMatrix)[5][5], int(&numMatrix)[5][5], bool &showingOne) {
    do { // Makes random numbers until randNumberOne is less than or equal to randNumberTwo
        randNumberOne = rand() % 100 + 100;
        randNumberTwo = rand() % 100 + 200;
    } while (randNumberOne >= randNumberTwo);
    shownNumOne = -1;
    shownNumTwo = -1;
    genHideMatrix(numMatrix, randNumberOne, randNumberTwo);
    genShowMatrix(shownMatrix);
    showingOne = false;
}

int main()
{
    srand(time(NULL));

    cout << " +----------------------------------------------------+\n";
    cout << " |        Computer Science and Engineering            |\n";
    cout << " |         CSCE 1030 - Computer Science I             |\n";
    cout << " |       Coleman Hicks cgh0124 cgh0124@my.unt.edu     |\n";
    cout << " +----------------------------------------------------+\n";


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
    bool nextUpper = true;

    playerName = getName();

    int randNumberOne;
    int randNumberTwo;
    int numMatrix[5][5];
    int shownNumOne;
    int shownNumTwo;
    int shownMatrix[5][5];
    bool showingOne;

    initialize(randNumberOne, randNumberTwo, shownNumOne, shownNumTwo, shownMatrix, numMatrix, showingOne);


     // Used to check if one of the numbers is revealed

    while (playing && numberPoints > 0) {
        cout << "--------------------------\n"; // Prompts for user input
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
        case 1: // Show the first number
            setDisplayLeft(randNumberOne, shownNumOne, showingOne);
            break;
        case 2: // Show the second number
            setDisplayRight(randNumberTwo, shownNumTwo, showingOne);
            break;
        case 3: // Allow user to guess the number
            showMatrix(shownMatrix);
            cout << "Enter your Guess: ";
            cin >> userGuess;
            guess(shownMatrix, numMatrix, userGuess, showingOne, numberPoints);

            cout << "Your Remaining Points: " << numberPoints << endl;
            showMatrix(shownMatrix);
            break;
        case 4: // Generate new numbers
            numberPoints += -1;
            cout << "Your Remaining Points = " << numberPoints << endl;
            cout << "Generating new Boundaries.\n";
            initialize(randNumberOne, randNumberTwo, shownNumOne, shownNumTwo, shownMatrix, numMatrix, showingOne);
            break;
        case 5: // Exit program
            cout << "Goodbye " << playerName << "! Quitting Program...\n";
            playing = false;
            break;
        default:
            cout << "Not a valid selection. Try again\n";
            break;
        }
    }

    if (numberPoints > 0) { // Checks if it needs to give a different exit message

    }
    else {
        cout << "You are out of points!\n Bye " << playerName << "!\n";
    }

}