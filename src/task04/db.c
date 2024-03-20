#include "db.h"

void work_with_db() {
    sqlite3 *db = _db_init("../../data-samples/task007.db");
    int menu_choice = 0;
    while( menu_choice != -1 ) {
        ...;
    }
    _db_close(db);
}

sqlite3 *_db_init(char *path){
    sqlite3 *db;
    int rc = sqlite3_open(path, &db);
    if( rc ) {
        exception("Can`t open database!");        
    }
    return db;
}

void _db_showall(sqlite3 *db) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, "SELECT id, name, age, email FROM Students", -1, stmt, 0);
    if( rc != SQLITE_OK ) {
        exception("Failure fetching data.");
    }
    rc = sqlite3_step(stmt);
    if( rc == SQLITE_ROW) {
        output_rows(sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
}

void _db_show_row(sqlite3 *db, char *id) {
    sqlite3_stmt *stmt;
    char sql_stmt_str[MAX_LEN_STR] = "SELECT id, name, age, email FROM Students WHERE id = ";
    strcat(sql_stmt_str, id);
    int rc = sqlite3_prepare_v2(db, "SELECT id, name, age, email FROM Students", -1, stmt, 0);
    if( rc != SQLITE_OK ) {
        exception("Failure fetching data.");
    }
    rc = sqlite3_step(stmt);
    if( rc == SQLITE_ROW) {
        output_row(sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
}

void _db_add_row(sqlite3 *db, char *new_row) {
    sqlite3_stmt *stmt;
    char sql_stmt_str[MAX_LEN_STR] = "INSERT INTO Students (name, age, email)\nVALUES (";
    strcat(sql_stmt_str, new_row);
    strcat(sql_stmt_str, ")");
    int rc = sqlite3_prepare_v2(db, sql_stmt_str, -1, stmt, 0);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void _db_delete_row(sqlite3 *db, char *id) {
    sqlite3_stmt *stmt;
    char sql_stmt_str[MAX_LEN_STR] = "DELETE FROM Students WHERE id = ";
    strcat(sql_stmt_str, id);
    int rc = sqlite3_prepare_v2(db, sql_stmt_str, -1, stmt, 0);
    if( rc != SQLITE_OK ) {
        exception("Failure fetching data.");
    }
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void _db_close(sqlite3 *db) {
    sqlite3_close(db);
}