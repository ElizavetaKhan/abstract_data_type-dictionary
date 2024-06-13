#include <iostream>
#include <fstream>
#include "openedHash.h"
#include "closedHash.h"
typedef openedHash package;


namespace lab_6
{
    static package GOOD_PEOPLE;
    static package BAD_PEOPLE;
}
using namespace lab_6;


// изначальное заполнение списка хороших из файла
void fillFromFile(std::ifstream& in)
{
    char str[10];
    while (in >> str) {
        GOOD_PEOPLE.insert(str);
    }
}

/*

john, mary, jacob, mia, william,
noah,
michael,
olivia, anna,
emma,
james, ethan,
ben, diana, isabella, liam,

*/

int main()
{
    std::ifstream in("input.txt");
    fillFromFile(in);

    char key;
    char name[10];
    std::cin >> key;

    while (key != 'E') {
        std::cin >> name;

        switch (key) {
            // перемещение из хороших в плохие
            case 'U':
                GOOD_PEOPLE.deletE(name);
                BAD_PEOPLE.insert(name);
                break;

            // перемещение из плохих в хорошие
            case 'F':
                BAD_PEOPLE.deletE(name);
                GOOD_PEOPLE.insert(name);
                break;

            case 'E':
                if (GOOD_PEOPLE.member(name)) {
                    std::cout << "in GOOD PEOPLE" << std::endl;
                    break;
                }
                if (BAD_PEOPLE.member(name))
                    std::cout << "in BAD PEOPLE" << std::endl;
                break;
        }

        std::cin >> key;
    }

    std::cout << std::endl << "GOOD PEOPLE:";
    GOOD_PEOPLE.print();
    std::cout << std::endl << "BAD PEOPLE:";
    BAD_PEOPLE.print();

    return 0;
}
