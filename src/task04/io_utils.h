#ifndef _IO_UTILS
#define _IO_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 1025
#define COLUMNS 4

typedef struct {
    char name[MAX_LEN_STR];
    char age[MAX_LEN_STR];
    char email[MAX_LEN_STR];
} InsertString;

int menu();
void scan_char(char *char_id);
void scan_correct_sql_row(InsertString *InsertStr);
void output_row(const unsigned char *str, int column);
void output_unknown_command(const char *error);
void exception(const unsigned char *error_text);

#endif