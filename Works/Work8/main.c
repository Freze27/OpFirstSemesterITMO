#include <stdio.h>

int main() {
    int len_first, len_second;
    scanf("%d", &len_first);
    char str_first[len_first + 1];
    scanf("%s", str_first);
    scanf("%d", &len_second);
    char str_second[len_second + 1];
    scanf("%s", str_second);
    int i = 0;
    int j = 0;
    short flag = 0;
    if (len_first == len_second) {
        while (i < len_first && j < len_second) {
            if (str_first[i] == str_second[j]) {
                i++;
                j++;
            } else {
                printf("String first != String second \n");
                flag = 1;
                break;
            }
        }
    } else {
        flag = 1;
    }
    if (flag == 0) {
        printf("String first == String second \n");
    }
    int n;
    scanf("%d", &n);
    i = 0;
    j = 0;
    flag = 0;
    while (i < n && j < n) {
        if (str_first[i] == str_second[j]) {
            i++;
            j++;
        } else {
            printf("n characters in first string != n characters in second string \n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("n characters in first string == n characters in second string \n");
    }
    printf("Length First string %d\n", ((sizeof(str_first) - 1) / (sizeof(char))));
    printf("Length Second string %d\n", ((sizeof(str_second) - 1) / (sizeof(char))));
    char find = str_second[(len_second - 1) / 2];
    i = 0;
    flag = 0;
    while (i < len_first) {
        if (str_first[i] == find) {
            flag = 0;
            printf("Element %c in first string\n", find);
            break;
        } else {
            flag = 1;
            i++;
        }
    }
    if (flag == 1) {
        printf("Element %c not in first string\n", find);
    }
    i = 0;
    while (i < len_first) {
        if (str_first[i] == find) {
            for (int f = 0; f < i; f++) {
                printf("%c", str_first[f]);
            }
            printf(" ");
            i++;
            j = i;
        } else {
            i++;
        }
    }
    printf("\n");
    while (j < len_first) {
        printf("%c", str_first[j]);
        j++;
    }
}
