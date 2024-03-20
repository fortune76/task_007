#include "io_utils.h"

void exception(char *error_text) {
    fprintf(stderr, "Error. %s\n", error_text);
    exit(EXIT_FAILURE);
}