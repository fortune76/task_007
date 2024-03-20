#ifndef _DB
#define _DB

#include <sqlite3.h>
#include <string.h>

#include "io_utils.h"

#define SHOW 0
#define SHOWALL 1
#define ADD 2
#define REMOVE 3
#define EXIT 4

#define COLUMNS 4

void work_with_db();

#endif