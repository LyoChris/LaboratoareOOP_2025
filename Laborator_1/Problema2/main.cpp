//problema 2, break down a unei propozitii si sortarea cuvintelor 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int compare(const void* a, const void* b) {
    char* wd1 = *(char**)a;
    char* wd2 = *(char**)b;
    int l1 = strlen(wd1);
    int l2 = strlen(wd2);

    if (l1 != l2) {
        return l2 - l1;
    }
    return strcmp(wd1, wd2); // pentru sortare alfabetica daca au aceeasi lungime
}

int main() {
    char words[100][100];
    char* pwords[MAX_WORDS];
    int count = 0;
    
    while (count < MAX_WORDS && scanf("%99s", words[count]) == 1) {
        pwords[count] = words[count];
        count++;

        char nextChar = getchar();
        if (nextChar == '\n' || nextChar == EOF) {
            break;
        }
    }


    qsort(pwords, count, sizeof(char*), compare);


    for (int i = 0; i < count; i++) {
        printf("%s\n", pwords[i]);
    }

    return 0;
}