#ifndef INC_6_LAB_OPENEDHASH_H
#define INC_6_LAB_OPENEDHASH_H
#include <iostream>
#include <string>


class openedHash {
    struct Node
    {
        Node* next{};
        char name[10]{};

        // конструктор-присваивание имени name
        explicit Node(char name[10])
        {
            strcpy(this->name, name);
        }
    };

private:
    int amountOfArrayElements;
    Node* array[10]{};

private:
    // хэш-функция, возвращающая номер элемента массива, в котором находится имя
    int hash(const char name[10]) const;

    // поиск имени в списке от головы head
    // если найдено – возврат prev
    // если не найдено – возврат nullptr
    static Node* findName(Node* head, const char name[10]);

    void destructor();

public:
    openedHash();

    ~openedHash();

    // вставка имени в словарь
    void insert(char name[10]);

    // удаление имени из словаря
    void deletE(char name[10]);

    // есть ли имя в словаре?
    bool member(char name[10]);

    void makeNull();

    void print();

};


#endif //INC_6_LAB_OPENEDHASH_H
