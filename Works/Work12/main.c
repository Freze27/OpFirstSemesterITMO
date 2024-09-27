#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[100];
    int lineCount = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (lineCount % 2 == 0) {
            printf("%s", line);
        }
        lineCount++;
    }
    fclose(file);
    return 0;
}