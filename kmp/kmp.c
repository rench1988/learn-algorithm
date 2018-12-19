#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void kmp_calc_next(const char *pattern, int *next) {
    int i, k, pl;

    i  = 0;
    k  = -1;
    pl = strlen(pattern);
    
    next[i] = -1;
    while (i < pl - 1) {
        if (k == -1 || pattern[i] == pattern[k]) {
            i++;
            k++;
            next[i] = k;
        } else {
            k = next[k];
        }
    }
}

int kmp_search(const char *text, const char *pattern, int *next) {
    int tl, pl;
    int i, j;

    i = 0;
    j = 0;
    tl = strlen(text);
    pl = strlen(pattern);

    while (i < tl && j < pl) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
            continue;
        }

        j = next[j];
    }

    if (j == pl) {
        return i - j;
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    const char *patthern = "ABCDABD";

    int *next = (int *)calloc(strlen(patthern), sizeof(int));

    kmp_calc_next(patthern, next);

    int res = kmp_search("ABCcABCDABD", patthern, next);

    printf("%d\n", res);

    return 0;
}


