#include "io_utils.h"

int menu() {
    const char *menu_commands[MAX_LEN_STR] = {"SHOW", "SHOWALL", "ADD", "REMOVE", "EXIT"};
    char menu_input[MAX_LEN_STR] = {0};
    scanf("%1024s", menu_input);
    int res = -1;
    for (int i = 0; i < 5; i++) {
        if (!strcmp(menu_input, menu_commands[i])) {
            res = i;
        }
    }
    return res;
}

void scan_char(char *char_id) { scanf("%1024s", char_id); }

void scan_correct_sql_row(InsertString *InsertStr) {
    char tmp_row[MAX_LEN_STR] = {0};
    scanf("%1024s", tmp_row);
    while (tmp_row[0] > 57 || tmp_row[0] < 48) {
        strcat(InsertStr->name, tmp_row);
        scanf("%1024s", tmp_row);
        if (tmp_row[0] > 57 || tmp_row[0] < 48) {
            strcat(InsertStr->name, " ");
        }
    }
    strcat(InsertStr->age, tmp_row);
    scanf("%1024s", tmp_row);
    strcat(InsertStr->email, tmp_row);
}

void output_row(const unsigned char *str, int column) {
    if (column < COLUMNS - 1)
        printf("%s ", str);
    else
        printf("%s\n", str);
}

void output_unknown_command(const char *error) { printf("%s\n", error); }

void exception(const unsigned char *error_text) {
    fprintf(stderr, "Error. %s\n", error_text);
    exit(EXIT_FAILURE);
}