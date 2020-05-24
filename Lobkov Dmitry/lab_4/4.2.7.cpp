/*Текстовый файл содержит текст произвольной длины. Построить
гистограмму распределения длин слов, которые он содержит. 
*/

#include <stdio.h>

int LengthOfString(char* str) {     //длина строки
    int i;

    for (i = 0; str[i] != '\0'; i++);

    return i;
}

void Histogram(char* str, int length, int* hist) {      //устанавливает длину стобца каждого слова
    for (int i = 0, j = 0; i < length; i++) {
        if ((str[i] > 47 && str[i] < 58) || (str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91)) {
            hist[j]++;
        }

        if (str[i] == ' ') {
            j++;
        }
    }
}

void OutputHistogram(int* hist, int amount) {       //вывод гистограмм
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < hist[i]; j++) {
            printf("___");
        }

        printf("%d\n", hist[i]);
    }
}

int main() {
    FILE* file;
    char str[4096];
    int amountOfWord = 0, length;

    fopen_s(&file, "text.txt", "r");
    fgets(str, 4096, file);
    fclose(file);
    puts(str);
    length = LengthOfString(str); //1159
    if (str[0] != ' ') amountOfWord++;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ') {  //считает, сколько слов в тексте
            amountOfWord++;
        }
    }

    int* hist = malloc(amountOfWord * sizeof(int));     //массив для гистограммы

    for (int i = 0; i < amountOfWord; i++) {
        hist[i] = 0;
    }

    Histogram(str, length, hist);

    OutputHistogram(hist, amountOfWord);
    free(hist);
    printf("\n");
    return 0;
}