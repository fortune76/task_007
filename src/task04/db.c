#include "db.h"

sqlite3 *_db_init(char *path) {
    sqlite3 *db;
    int rc = sqlite3_open(path, &db);
    if (rc) {
        const unsigned char exception_text[MAX_LEN_STR] = "Can`t open database!";
        exception(exception_text);
    }
    return db;
}

void _db_showall(sqlite3 *db) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, "SELECT id, name, age, email FROM Students", -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        const unsigned char exception_text[MAX_LEN_STR] = "Failure fetching data.";
        exception(exception_text);
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int i = 0; i < COLUMNS; i++) {
            output_row(sqlite3_column_text(stmt, i), i);
        }
    }
    sqlite3_finalize(stmt);
}

void _db_show_row(sqlite3 *db, char *id) {
    sqlite3_stmt *stmt;
    char sql_stmt_str[MAX_LEN_STR] = "SELECT id, name, age, email FROM Students WHERE id = ";
    strcat(sql_stmt_str, id);
    int rc = sqlite3_prepare_v2(db, sql_stmt_str, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        const unsigned char exception_text[MAX_LEN_STR] = "Failure fetching data.";
        exception(exception_text);
    }
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int i = 0; i < COLUMNS; i++) {
            output_row(sqlite3_column_text(stmt, i), i);
        }
    } else {
        const unsigned char error_text[MAX_LEN_STR] = "NO DATA";
        output_unknown_command(error_text);
    }
    sqlite3_finalize(stmt);
}

void _db_add_row(sqlite3 *db, InsertString InsertStr) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, "INSERT INTO Students (name,age,email) VALUES (?, ?, ?);", -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        const unsigned char exception_text[MAX_LEN_STR] = "Failure during add data.";
        exception(exception_text);
    }
    sqlite3_bind_text(stmt, 1, InsertStr.name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, InsertStr.age, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, InsertStr.email, -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void _db_delete_row(sqlite3 *db, char *id) {
    sqlite3_stmt *stmt;
    char sql_stmt_str[MAX_LEN_STR] = "DELETE FROM Students WHERE id = ";
    strcat(sql_stmt_str, id);
    int rc = sqlite3_prepare_v2(db, sql_stmt_str, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        const unsigned char exception_text[MAX_LEN_STR] = "Failure fetching data.";
        exception(exception_text);
    }
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        const unsigned char error_text[MAX_LEN_STR] = "NO DATA";
        output_unknown_command(error_text);
    }
    sqlite3_finalize(stmt);
}

void _db_close(sqlite3 *db) { sqlite3_close(db); }

void work_with_db() {
    sqlite3 *db = _db_init("data-samples/task007.db");
    int menu_choice = menu();
    while (menu_choice != EXIT) {
        if (menu_choice == SHOW) {
            char id[MAX_LEN_STR] = {0};
            scan_char(id);
            _db_show_row(db, id);
        } else if (menu_choice == SHOWALL)
            _db_showall(db);
        else if (menu_choice == ADD) {
            InsertString InsertStr = {0, 0, 0};
            scan_correct_sql_row(&InsertStr);
            _db_add_row(db, InsertStr);
        } else if (menu_choice == REMOVE) {
            char id[MAX_LEN_STR] = {0};
            scan_char(id);
            _db_delete_row(db, id);
        } else {
            const unsigned char error_text[MAX_LEN_STR] = "UNKNOWN COMMAND";
            output_unknown_command(error_text);
        }
        menu_choice = menu();
    }
    _db_close(db);
}
