#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
bool Process(Elem* L, int count, int number_of_elements, int cur_poss);
int Count(Elem* L, int count);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    bool result;

    Info value, N;

    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть дані: "; cin >> value;
        Enqueue(first, last, value);
    }

    cout << "Елементи черги: "; Print(first); cout << endl;

    cout << "\nРезультат: ";
    Process(first, 0, Count(first, 0), 0) ? cout << "Так!" : cout << "Ні";
    return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}
void Print(Elem* L)
{
    if (L != NULL)
    {
        cout << L->info << " ";
        return Print(L->next);
    }
}
bool Process(Elem* L, int count, int number_of_elements, int cur_poss)
{
    if (number_of_elements == 1)
        return false;
    if (cur_poss < number_of_elements - 1)
    {
        Info curent,
            next;

        curent = L->info;
        L = L->next;
        next = L->info;
        if (next >= curent)
            count++;

        return Process(L, count, number_of_elements, cur_poss + 1);
    }
    else
    {
        if (count == number_of_elements - 1)
            return true;
        else
            return false;
    }
}
int Count(Elem* L, int count)
{
    if (L != NULL)
    {
        count++;
        L = L->next;

        return Count(L, count);
    }
    else
        return count;
}