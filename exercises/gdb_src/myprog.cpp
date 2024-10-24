#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_array(char *a) {
    char *p;
    char current_letter = 'a';

    for (p = a; p < (a + MAX_LETTERS); p++) {
        *p = current_letter++;
    }
}

void print_characters_in_reverse(char *b) {
    char *p;

    printf("\nReverse alpha...\n");

    for (p = (b + MAX_LETTERS - 1); p >= b; p--) {
        printf("%c ", *p);
    }
    printf("\n");
}

int main(void) {
    int i = 0;
    initialize_array(alphabet);
    while (i++ < 10) {
        print_characters_in_reverse(alphabet);
    }
}
