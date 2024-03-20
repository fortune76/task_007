GC=gcc
FLAGS=-Wall -Werror -Wextra
BIN=../bin/
TASK01=task01/
TASK02=task02/
TASK03=task03/
TASK04=task04/

all: show_str change_separator binary_div real_db

show_str: $(TASK01)show_str.c
	$(GC) $(FLAGS) $(TASK01)show_str.c -o $(BIN)show_str

change_separator: $(TASK02)change_separator.c
	$(GC) $(FLAGS) $(TASK02)change_separator.c -o $(BIN)change_separator

binary_div: $(TASK03)binary_div.c
	$(GC) $(FLAGS) $(TASK03)binary_div.c -o $(BIN)binary_div
	
real_db: $(TASK04)db.c $(TASK04)io_utils.c $(TASK04)real_db.c
	$(GC) $(FLAGS) $(TASK04)db.c $(TASK04)io_utils.c $(TASK04)real_db.c -o $(BIN)real_db -lsqlite3

clean:
	rm -f $(BIN)*

clang: 
	clang-format $(TASK01)* $(TASK02)* $(TASK03)* $(TASK04)* -n
	clang-format $(TASK01)* $(TASK02)* $(TASK03)* $(TASK04)* -i

rebuild:
	clean all