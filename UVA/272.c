#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main() {
    int toggle = false;
    char ch;
    while((ch = getchar()) != EOF) {
        if(ch != '"') {
            putchar(ch);
            continue;
        }
        if(toggle) {
            printf("''");
            toggle = false;
        }
        else {
            printf("``");
            toggle = true;
        }
    }
    return 0;
}

