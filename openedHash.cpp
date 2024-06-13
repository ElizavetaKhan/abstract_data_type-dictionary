#include "openedHash.h"

openedHash::openedHash()
{
    amountOfArrayElements = 10;
}

openedHash::~openedHash()
{
    destructor();
}

int openedHash::hash(const char *name) const
{
    int total = 0;
    int i = 0;
    while (name[i] != '\0') {
        total += name[i];
        ++i;
    }

    return total % amountOfArrayElements;
}

void openedHash::insert(char name[10])
{
    // находим номер элемента массива, в который положим name
    int num = hash(name);

    // если пока нет имен в данном элементе
    if (!array[num])
        array[num] = new Node(name);

    // голову проверяем – если в голове нашли, то ничего не делаем
    else if (strcmp(name, array[num]->name) == 0)
        return;

   // при возникновении коллизии и если нет еще этого имени
    else if (!findName(array[num], name))
    {
        Node* neW = new Node(name);

        Node* nexT = array[num]->next;
        array[num]->next = neW;
        neW->next = nexT;
    }
}

void openedHash::deletE(char name[10])
{
    // где должно быть это имя?
    int num = hash(name);

    // если этот элемент массива в целом пустой
    if (!array[num])
        return;

    // голову проверяем отдельно – если в голове нашли, то сдвигаем голову
    else if (strcmp(name, array[num]->name) == 0)
    {
        // и при этом есть еще элементы в списке
        Node* nexT = array[num]->next;
        if (nexT) {
            array[num] = new Node(nexT->name);
            array[num]->next = nexT->next;
            delete nexT;

        } else {
            delete array[num];
            array[num] = nullptr;
        }
        return;
    }

    Node* prev = findName(array[num],name);
    if (prev) {
        // если не первый элемент в списке коллизий – "вырезаем" элемент из списка
        Node* nexT = prev->next->next;
        delete prev->next;

        prev->next = nexT;
    }
}

bool openedHash::member(char name[10])
{
    // где должно быть это имя?
    int num = hash(name);

    // если элемент в принципе пустой
    if (!array[num])
        return false;

    // голову проверяем – если в голове нашли, то тру
    else if (strcmp(array[num]->name,name) == 0)
        return true;

    return findName(array[num],name);
}


// поиск имени в списке от головы head
// если найдено – возврат prev
// если не найдено – возврат nullptr
openedHash::Node* openedHash::findName(Node* head, const char name[10])
{
    Node* cur = head->next;
    Node* prev = head;

    while (cur)
    {
        // если уже есть в списке коллизий
        if (strcmp(cur->name,name) == 0)
            return prev;

        prev = cur;
        cur = cur->next;
    }

    return nullptr;
}

void openedHash::makeNull()
{
    destructor();
}

void openedHash::print()
{
    std::cout << std::endl;

    for (int i = 0; i < amountOfArrayElements; ++i) {
        Node* cur = array[i];

        // если этот элемент вообще заполнен
        if (cur) {
            while (cur)
            {
                std::cout << cur->name << ", ";
                cur = cur->next;
            }
            std::cout << std::endl;
        }
    }
}

void openedHash::destructor()
{
    for (int i = 0; i < amountOfArrayElements; ++i)
        delete array[i];
}
