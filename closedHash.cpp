#include "closedHash.h"

closedHash::closedHash()
{
    amountOfArrayElements = 20;

    for (int i = 0; i < amountOfArrayElements; ++i)
        array[i] = nullptr;
}

closedHash::~closedHash()
{
    destructor();
}

int closedHash::calcHash(const char name[10])
{
    int total = 0;

    for (int i = 0; name[i] != '\0'; ++i)
        total += name[i];
    return total;
}

int closedHash::hash_function(int hash) const
{
    return hash % amountOfArrayElements;
}

void closedHash::insert(char *name)
{
    // высчитываем хэш, далее в хэш-функции ищем первый свободный элемент, чтобы вставить туда
    int hash = calcHash(name);

    // если ранее использовался, то запоминаем номер этого элемента
    int freeButUsed = -1;
    int num = hash_function(hash);
    // запомнили элемент, с которого стартовали
    int start = num;

    // счетчик для повторного хэширования
    int i = 0;

    // пока не дошли до ранее не тронутого элемента
    while (array[num]) {

        // если прошли полный круг и не нашли пустых элементов
        if (start == num && (i != 0))
            std::cout << "!! МАССИВ ПЕРЕПОЛНЕН !!";

        // если оно уже лежит там – ничего не делаем
        if (strcmp(name, array[num]) == 0)
            return;

        // если элемент пустой, но ранее использовался
        if (strcmp(array[num],used) == 0)
            freeButUsed = num;

        ++i;
        num = hash_function(hash + i);
    }

    // если нашли пустой элемент и до этого не встретили опустошенных элементов – заполняем первый пустой
    if (!array[num] && freeButUsed == -1) {
        array[num] = new char[10];
        strcpy(array[num], name);

    } else if (!array[num] && freeButUsed != -1)
        strcpy(array[freeButUsed], name);
}

void closedHash::deletE(char *name)
{
    // высчитываем хэш, далее в хэш-функции ищем первый свободный элемент, чтобы вставить туда
    int hash = calcHash(name);

    int num = hash_function(hash);
    // запомнили элемент, с которого стартовали
    int start = num;

    // счетчик для повторного хэширования
    int i = 0;

    // пока не дошли до ранее не тронутого элемента
    while (array[num]) {

        // если прошли полный круг и не нашли пустых элементов
        if (start == num && (i != 0))
            return;

        // если оно уже лежит там – удаляем
        if (strcmp(name, array[num]) == 0){
            strcpy(array[num],used);
            return;
        }

        ++i;
        num = hash_function(hash + i);
    }
}

bool closedHash::member(char *name)
{
    // высчитываем хэш, далее в хэш-функции ищем первый свободный элемент, чтобы вставить туда
    int hash = calcHash(name);

    int num = hash_function(hash);
    // запомнили элемент, с которого стартовали
    int start = num;

    // счетчик для повторного хэширования
    int i = 0;

    // пока не дошли до ранее не тронутого элемента
    while (array[num]) {

        // если прошли полный круг и не нашли пустых элементов
        if (start == num && (i != 0))
            return false;

        // если оно уже лежит там – ничего не делаем
        if (strcmp(name, array[num]) == 0)
            return false;

        ++i;
        num = hash_function(hash + i);
    }

    return false;
}

void closedHash::makeNull()
{
    destructor();
}

void closedHash::print()
{
    std::cout << std::endl;

    for (int i = 0; i < amountOfArrayElements; ++i)
        if (array[i] && strcmp(array[i],used) != 0)
            std::cout << array[i] << std::endl;
}

void closedHash::destructor()
{
    for (int i = 0; i < amountOfArrayElements; ++i)
        delete array[i];
}