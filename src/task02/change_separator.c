#include "change_separator.h"

int main() {
    change_separator();
    exit(EXIT_SUCCESS);
}

void change_separator() {
    char str[MAX_LEN_STR] = {0};
    fgets(str, MAX_LEN_STR - 1, stdin);
    char new_sep = 0;
    scanf("%c", &new_sep);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') str[i] = new_sep;
    }
    printf("%s", str);
}