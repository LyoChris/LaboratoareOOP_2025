//problema 1, suma numere
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int my_atoi(const char* str) {
    int result = 0;
    while (*str && *str != '\n') {
        if (!isdigit(*str)) {
            return 0;
        }
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main() {
    FILE* file = fopen("in.txt", "r");
    if (!file) {
        return 1;
    }

    char buffer[100];
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        sum += my_atoi(buffer);
    }

    fclose(file);
    printf("%d\n", sum);
    return 0;