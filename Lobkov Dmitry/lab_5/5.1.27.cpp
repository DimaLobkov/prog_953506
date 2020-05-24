/*В текстовом файле содержится произвольный текст. С помощью
бинарного дерева определить частоту вхождения каждого слова в
текст. Вывести слова по убыванию частоты вхождения.
Примечание. Каждый элемент дерева должен хранить слово.
Кроме этого, необходимо вести счетчик числа вхождений этого
слова в текст. */

#include <stdio.h> 
#include <time.h>
#include <conio.h>
#define MAX 100
#define n 5

char* p[MAX];
int spos = 0;
int rpos = 0;

struct List {           //двунаправленный список
    int i;              //номер очереди
    char action;        //действие (удалить/добавить)
    char symbol;        //символ в списке
    struct List* prior; //указатель на предыдущий элемент
    struct List* next;  //указатель на следующий элемент
};

struct List* start;     //начало списка
struct List* last;      //конец списка

void Store(struct List* info) {
    struct List* old, * p;

    old = last;
    if (last == NULL) { 
        info->next = NULL;
        info->prior = NULL;
        last = info;
        start = info;

        return;
    }

    old->next = info; 
    info->next = NULL;
    info->prior = last;
    last = info;
}

void Enter(int number)          //создать новый элемент списка
{
    for (int j = 0; j < number; j++) {
        struct List* info;

        info = (struct List*)malloc(sizeof(struct List));
        info->i = n;
        if (number == 1) {
            printf("Press an action key (\"A\" to add a component to the queue, \"D\" to delete a component from the queue): ");
            info->action = _getch();
            printf("\nPress a data key (a symbal): ");
            info->symbol = _getch();
        }

        else {
            if (rand() % 2) info->action = 'A';

            else info->action = 'D';

            info->symbol = 97 + rand() % 26;
        }

        Store(info);
    }
}

void DeleteObject(_Bool isTrue)       //удаляет необходимый элемент списка
{
    struct List* info;

    info = start;
    int number;
    if (isTrue) {
        number = 1;
    }

    else {
        printf("Enter the component number: ");
        scanf_s("%d", &number);
    }

    for (int i = 1; i < number; i++) {
        info = info->next;
    }

    if (info) {
        if (start == info) {
            start = info->next;
            free(info->prior);
            if (start) {
                start->prior = NULL;
            } 
            
            else {
                last = NULL;
            }
        }

        else {
            info->prior->next = info->next;
            if (info != last) {
                info->next->prior = info->prior;
            }

            else {
                last = info->prior;
            }

            
            free(info);
        }
    }
}

void DeleteList(struct List* list)      //освобождение памяти от списка
{
    if (list != NULL)
    {
        DeleteList(list->next);
        free(list);
    }
}

void Display(struct List* info) {           //вывод данных списка
    printf("\nQueue: %d", info->i);
    printf("\nAction: %c", info->action);
    printf("\nData: %c", info->symbol);
    printf("\n\n");
}

void ShowList() {               //вывод списка
    struct List* info;

    info = start;
    while (info) {
        Display(info);
        info = info->next;  
    }

    printf("\n\n");
}

void QueueStore(char* q) {             //добавить новый элемент в очередь   
    if (spos == MAX) {
        printf("The queue is full\n");

        return;
    }

    p[spos] = q;
    spos++;
}

char* QueueRetrieve() {                 //получить элемент из очереди
    if (rpos == spos) {
        printf("There are no more events\n");

        return '\0';
    }

    rpos++;

    return p[rpos - 1];
}

void QueueRun() {       //запуск очереди
    struct List* info;
    int i = 0;

    info = start;
    while (info) {
        if (info->action == 'A') {
            QueueStore(info->symbol);
        }

        else {
            QueueRetrieve();
        }

        DeleteObject(1);
        info = info->next;  
    }
}

void QueueShow(int sp, int rp) {        //вывод очереди
    for (; rp <= sp; rp++) {
        printf("%c  ", p[rp]);
    }
}

int main() {
    int amount;
    start = last = NULL;  

    srand(time(NULL));
    amount = 30 + rand() % 31;
    for (int i = 0; i < amount; i++) {
        char data = 97 + rand() % 26;
        p[i] = data;
        spos++;
    }

    int select;
    for (;;) {
        printf("\t\tActions with a list\n1) Enter\n2) Random\n3) Delete\n4) The list\n\n");
        printf("\t\tActions with a queue\n5) Run the queue\n6) The queue\n\n\n7) Exit\n\nYour select: ");
        scanf_s("%d", &select);
        switch (select) {
        case 1: Enter(1); break;
        case 2: Enter(rand() % 24 + 2); break;
        case 3: DeleteObject(0); break;
        case 4: ShowList(); break;
        case 5: QueueRun(); break;
        case 6: QueueShow(spos, rpos); break;
        case 7: DeleteList(start); exit(0);
        }

        printf("\nPress any key to continue...");
        _getch();
        system("cls");
    }

    return 0;
}