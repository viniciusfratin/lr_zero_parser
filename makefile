SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

all: grammar list main link

grammar: $(SRC_DIR)/grammar.c $(INCLUDE_DIR)/grammar.h
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/grammar.c -o $(OBJ_DIR)/grammar.o

list: $(SRC_DIR)/list.c $(INCLUDE_DIR)/list.h
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/list.c -o $(OBJ_DIR)/list.o

main: $(SRC_DIR)/main.c
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

link: $(OBJ_DIR)/grammar.o $(OBJ_DIR)/list.o $(OBJ_DIR)/main.o
	gcc $(OBJ_DIR)/grammar.o $(OBJ_DIR)/list.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/lr_zero_parser

	
