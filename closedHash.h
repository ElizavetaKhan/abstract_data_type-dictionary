#ifndef INC_6_LAB_CLOSEDHASH_H
#define INC_6_LAB_CLOSEDHASH_H
#include <iostream>
#include <cstring>

class closedHash {
private:
    char* array[20]{}; // хранит имя

    int amountOfArrayElements{};
    char used[10]{}; // если элемент массива равен данному, то он использовался

private:
    int hash_function(int hash) const;

    // считаем сумму кодов символов – HASH
    static int calcHash(const char name[10]);

    void destructor();

public:
    closedHash();

    ~closedHash();

    // вставка имени в словарь
    void insert(char name[10]);

    // удаление имени из словаря
    void deletE(char name[10]);

    // есть ли имя в словаре?
    bool member(char name[10]);

    void makeNull();

    void print();
};


#endif //INC_6_LAB_CLOSEDHASH_H
