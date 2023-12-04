#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "cgh0124Project2_header.h"
using namespace std;

int main()
{
    bool looping = true;
    while (looping) {
        cout << "1.Add\n2.Remove\n3.Display\n4.Search\n5.Results\n6.Quit\nEnter your choice: ";
        int userSelect;
        choices userSelected;
        cin >> userSelect;
        userSelected = static_cast<choices>(userSelect);
        int idHold;

        switch (userSelected) {
        case 1:
            add_Student();
            break;
        case 2:
            cout << "Please enter the student's id: ";
            cin >> idHold;
            remove_Student(idHold);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Please enter the student's id: ";
            cin >> idHold;
            search(idHold);
            break;
        case 5:
            exportResults();
            break;
        case 6:
            looping = false;
            cout << "Bye!!!" << endl;
            break;
        default:
            cout << "Incorrect choice. Please enter again." << endl;
            break;
        }
    }
    return 0;
}