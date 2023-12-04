#include "cgh0124Project2_header.h"

void add_Student() {
    Student stu;
    string holding;
    cout << "Please enter the student's last name: ";
    cin >> holding;
    cout << "Please enter the student's first name: ";
    cin >> stu.name;
    cout << "Please enter the student ID: ";
    cin >> stu.id;
    cout << "Please enter the number of tests taken: ";
    cin >> stu.testsTaken;
    stu.scores = new int(stu.testsTaken);
    for (int i = 0; i < stu.testsTaken; i++) {
        cout << "Please enter score #" << i + 1 << ":";
        cin >> stu.scores[i];
    }

    ofstream outputter;
    outputter.open("student.dat", ios_base::app);
    outputter << holding << "," << stu.name << "," << stu.id << "," << stu.testsTaken << ",";
    for (int i = 0; i < stu.testsTaken; i++) {
        outputter << stu.scores[i] << ",";
    }
    outputter << endl;

    outputter.close();
}

void remove_Student(int removeID) {
    int numStudents = getNumber();
    Student* allStudents = new Student[numStudents];
    string* lastNames = new string[numStudents];
    ifstream readIn;
    readIn.open("student.dat");
    string holdMe;
    bool foundMatch = false;
    for (int i = 0; i < numStudents; i++) {
        getline(readIn, lastNames[i], ',');
        getline(readIn, allStudents[i].name, ',');
        getline(readIn, holdMe, ',');
        allStudents[i].id = stoi(holdMe);
        if (allStudents[i].id == removeID) {
            foundMatch = true;
        }
        getline(readIn, holdMe, ',');
        allStudents[i].testsTaken = stoi(holdMe);
        allStudents[i].scores = new int(allStudents[i].testsTaken);
        for (int j = 0; j < allStudents[i].testsTaken; i++) {
            getline(readIn, holdMe, ',');
            allStudents[i].scores[j] = stoi(holdMe);
        }
    }
    readIn.close();
    if (foundMatch) {
        ofstream outputter;
        outputter.open("student.dat");
        for (int i = 0; i < numStudents; i++) {
            if (allStudents[i].id != removeID) {
                outputter << lastNames[i] << "," << allStudents[i].name << "," << allStudents[i].id << "," << allStudents[i].testsTaken << ",";
                for (int j = 0; i < allStudents[i].testsTaken; j++) {
                    outputter << allStudents[i].scores[j] << ",";
                }
                outputter << endl;
            }
        }
        outputter.close();
    }
    else {
        cout << "No match found!" << endl;
    }
}

void display() {
    int numStudents = getNumber();
    Student* allStudents = new Student[numStudents];
    string* lastNames = new string[numStudents];
    ifstream readIn;
    readIn.open("student.dat");
    string holdMe;
    for (int i = 0; i < numStudents; i++) {
        getline(readIn, lastNames[i], ',');
        getline(readIn, allStudents[i].name, ',');
        getline(readIn, holdMe, ',');
        allStudents[i].id = stoi(holdMe);
        getline(readIn, holdMe, ',');
        allStudents[i].testsTaken = stoi(holdMe);
        allStudents[i].scores = new int(allStudents[i].testsTaken);
        for (int j = 0; j < allStudents[i].testsTaken; i++) {
            getline(readIn, holdMe, ',');
            allStudents[i].scores[j] = stoi(holdMe);
        }
    }
    readIn.close();

    for (int i = 0; i < numStudents; i++) {
        string fullName = lastNames[i] + "," + allStudents[i].name;
        printf("%30s", fullName);
        printf("%15d", allStudents[i].id);
        for (int j = 0; j < allStudents[i].testsTaken; j++) {
            printf("%5d", allStudents[i].scores[j]);
        }
        cout << endl;
    }
}

void search(int findID) {
    int numStudents = getNumber();
    Student* allStudents = new Student[numStudents];
    string* lastNames = new string[numStudents];
    ifstream readIn;
    readIn.open("student.dat");
    string holdMe;
    bool foundMatch = false;
    for (int i = 0; i < numStudents; i++) {
        getline(readIn, lastNames[i], ',');
        getline(readIn, allStudents[i].name, ',');
        getline(readIn, holdMe, ',');
        allStudents[i].id = stoi(holdMe);
        if (allStudents[i].id == findID) {
            foundMatch = true;
        }
        getline(readIn, holdMe, ',');
        allStudents[i].testsTaken = stoi(holdMe);
        allStudents[i].scores = new int(allStudents[i].testsTaken);
        for (int j = 0; j < allStudents[i].testsTaken; i++) {
            getline(readIn, holdMe, ',');
            allStudents[i].scores[j] = stoi(holdMe);
        }
    }
    readIn.close();
    if (foundMatch) {
        for (int i = 0; i < numStudents; i++) {
            if (allStudents[i].id == findID) {
                string fullName = lastNames[i] + "," + allStudents[i].name;
                printf("%30s", fullName);
                printf("%15d", allStudents[i].id);
                for (int j = 0; j < allStudents[i].testsTaken; j++) {
                    printf("%5d", allStudents[i].scores[j]);
                }
                cout << endl;
            }
        }
    }
    else {
        cout << "No match found!" << endl;
    }
}

int findMinimum(int* allScores, int arrSize) {
    int lowest = 100;
    if (arrSize < numTests) {
        lowest = 0;
    }
    else {
        for (int i = 0; i < arrSize; i++) {
            if (lowest > allScores[i]) {
                lowest = allScores[i];
            }
        }
    }
    return lowest;
}

void exportResults() {
    ofstream outputter;
    outputter.open("averages.dat");
    int numStudents = getNumber();
    Student* allStudents = new Student[numStudents];
    string* lastNames = new string[numStudents];
    ifstream readIn;
    string holdMe;
    readIn.open("student.dat");

    for (int i = 0; i < numStudents; i++) {
        getline(readIn, lastNames[i], ',');
        getline(readIn, allStudents[i].name, ',');
        getline(readIn, holdMe, ',');
        allStudents[i].id = stoi(holdMe);
        getline(readIn, holdMe, ',');
        allStudents[i].testsTaken = stoi(holdMe);
        allStudents[i].scores = new int(allStudents[i].testsTaken);
        for (int j = 0; j < allStudents[i].testsTaken; i++) {
            getline(readIn, holdMe, ',');
            allStudents[i].scores[j] = stoi(holdMe);
        }
    }
    readIn.close();

    for (int i = 0; i < numStudents; i++) {
        allStudents[i].avg = 0;
        for (int j = 0; j < allStudents[i].testsTaken; j++) {
            allStudents[i].avg += allStudents[i].scores[j];
        }
        allStudents[i].avg -= findMinimum(allStudents[i].scores, numStudents);
        allStudents[i].avg = allStudents[i].avg / numTests - 1;
        outputter << allStudents[i].id << "\t" << fixed << setprecision(1) << allStudents[i].avg << endl;
    }
    outputter.close();
}