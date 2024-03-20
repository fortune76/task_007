#include "binary_div.h"

int main() {
    binary_div();
    exit(EXIT_SUCCESS);
}

void binary_div() {
    char input_str[MAX_LEN_STR] = {0};
    scanf("%1024s", input_str);
    char tmp_str[MAX_LEN_STR] = {0};
    strcpy(tmp_str, input_str);
    while (strlen(tmp_str) > 1) {
        printf("%s\n", tmp_str);
        int len = (strlen(tmp_str) / 2) == (float)strlen(tmp_str) / 2 ? strlen(tmp_str) / 2 : strlen(tmp_str) / 2 + 1;
        memset(tmp_str, 0, MAX_LEN_STR - 1);
        for (int i = 0; i < len; i++) {
            tmp_str[i] = input_str[i];
        }
    }
    printf("%s\n", tmp_str);
}