/*В узлах бинарного дерева расположены строки. Создать стек и
поместить в него все строки, содержащиеся в листьях дерева и
имеющие четную сумму кодов символов*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Tree {           //бинарное дерево
    char info[MAX];
    struct Tree* left;
    struct Tree* right;
};

struct Tree* root;      //корень дерева
char stack[MAX][MAX];   //стек
int tos = 0;            //вершина стека

int Compare(char* str1, char* str2) {       //сравнение строк в дереве
    int i;

    for (i = 0; str1[i] != '\n' && str2[i] != '\n'; i++) {
        if (str1[i] == str2[i]) {
            continue;
        }

        else if (str1[i] > str2[i]) {
            return 1;
        }

        return 0;
    }
    
    if (str1[i] != '\n') {
        return 1;
    }

    else {
        return 0;
    }
}

void Push(char* str ) {     //положить элемент на вершину стека
    if (tos >= MAX) {
        printf("The stack is full\n");

        return;
    }

    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        counter += str[i];
    }

    if (!(counter % 2)) {
        strcpy_s(stack[tos], str);
        tos++;
    }
}

int Pop() {         //забирает элемент с вершины стека
    tos--;
    if (tos < 0) {
        printf("The stack is empty\n");

        return 0;
    }

    printf("%s", stack[tos]);

    return 1;
}

struct Tree* TreeBuild(struct Tree* root, struct Tree* r, char* info)       //строит бинарное дерево
{
    if (!r) {
        r = (struct Tree*) malloc(sizeof(struct Tree));

        if (!r) {
            printf("Not enough memory\n");
            exit(0);
        }

        r->left = NULL;
        r->right = NULL;
        strcpy_s(r->info, info);        
        
        if (!root) return r;

        if (Compare(root->info, info)) {
            root->left = r;
        }

        else {
            root->right = r;
        }

        return r;
    }


    if (Compare(r->info, info)) {
        TreeBuild(r, r->left, info);
    }

    else {
        TreeBuild(r, r->right, info);
    }

    return root;
}

void InOrder(struct Tree* root)     //добавляет элементы из дерева в стек
{
    if (!root) return;

    InOrder(root->left);
    if (!root->left && !root->right) Push(root->info);

    InOrder(root->right);
}

void DeleteTree(struct Tree* tree)  //освобождение памяти от дерева
{
    if (tree != NULL)
    {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        free(tree);
    }
}

int main() {
    char info[MAX] = ""; 
    int i;

    root = NULL;

    while (1) {
        printf("Enter string (\"\\stop\" to stop): ");
        fgets(info, MAX, stdin);
        fflush(stdin);
        if (!strcmp(info, "\\stop\n")) {
            printf("\n");
            break;
        }

        root = TreeBuild(root, root, info);
    } 

    InOrder(root);
    do {
        i = Pop();
    } while (i);

    DeleteTree(root);

	return 0;
}