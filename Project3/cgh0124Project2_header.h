//#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int numTests = 5;
enum choices {
    Add = 1,
    Remove = 2,
    Display = 3,
    Search = 4,
    Results = 5,
    Quit = 6
};
struct Student {
    string name;
    int id;
    int testsTaken;
    int* scores;
    double avg;
};

int getNumber();
void add_Student();
void remove_Student(int removeID);
void display();
void search(int findID);
int findMinimum(int* allScores, int arrSize);
void exportResults();