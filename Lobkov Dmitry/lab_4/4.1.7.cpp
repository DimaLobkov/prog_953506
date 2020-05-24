/*Для двух строк символов найти самую длинную общую подстроку.
Пробелы и знаки препинания игнорировать, строчные и прописные
буквы считать неразличимыми. Например, строки: “Дай вилку! Бок
севрюжий кончается” и “Чемпионский кубок достался не нам”
содержат общую подстроку “кубок”. 
*/

#include <stdio.h>
#include <string.h>
#define length 100

void OptimizeString(char *str, char *optStr) {      //оптимизация строки (удаление лишних символов, смена прописных на строчные)
    for (int i = 0, j = 0; i < length; i++) {
        if ((str[i] > 47 && str[i] < 58) || (str[i] > 96 && str[i] < 123)) {
            optStr[j] = str[i];
            j++;
        }

        else if (str[i] > 64 && str[i] < 91) {
            optStr[j] = str[i] + 32;
            j++;
        }
    }
}

void CompareStrings(char* str1, char* str2) {       //сравнение строк
    int len1, len2, maxCounter = 0;
    char subStr[length + 25] = "The largest substring is ";

    len1 = LengthOfString(str1);
    len2 = LengthOfString(str2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                int counter = 0;
                for (int k = i, l = j; str1[k] == str2[l] && str1[k] != '\0'; counter++, k++, l++);
                if (counter > maxCounter) {
                    maxCounter = counter;
                    for (int j = i, k = 25; j < i + counter; j++, k++) {
                        subStr[k] = str1[j];
                    }
                }
            }
        }
    }

    fputs(subStr, stdout);
}

int LengthOfString(char* str) {     //вычисление длины строки
    int i;

    for (i = 0; str[i] != '\0'; i++);

    return i;
}

int main() {
	char str1[length] = "", str2[length] = "", extraStr1[length] = "", extraStr2[length] = "";

    printf("Enter the first string: ");
    fgets(str1, length, stdin);
    fflush(stdin);
    printf("Enter the second string: ");
    fgets(str2, length, stdin);
    fflush(stdin);
    OptimizeString(str1, extraStr1);
    OptimizeString(str2, extraStr2);
    CompareStrings(extraStr1, extraStr2);

    return 0;
}