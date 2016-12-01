SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

GRAMMAR_OBJ = $(OBJ_DIR)/grammar.o
LIST_OBJ = $(OBJ_DIR)/list.o
MAIN_OBJ = $(OBJ_DIR)/main.o
PARSER_BIN = $(BIN_DIR)/lr_zero_parser

all: $(GRAMMAR_OBJ) $(LIST_OBJ) $(MAIN_OBJ) $(PARSER_BIN)

$(GRAMMAR_OBJ): $(SRC_DIR)/grammar.c $(INCLUDE_DIR)/grammar.h
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/grammar.c -o $(GRAMMAR_OBJ)

$(LIST_OBJ): $(SRC_DIR)/list.c $(INCLUDE_DIR)/list.h
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/list.c -o $(LIST_OBJ)

$(MAIN_OBJ): $(SRC_DIR)/main.c
	gcc -c -I$(INCLUDE_DIR) $(SRC_DIR)/main.c -o $(MAIN_OBJ)

$(PARSER_BIN): $(GRAMMAR_OBJ) $(LIST_OBJ) $(MAIN_OBJ)
	gcc $(GRAMMAR_OBJ) $(LIST_OBJ) $(MAIN_OBJ) -o $(PARSER_BIN)

clean: 
	rm $(OBJ_DIR)/* $(BIN_DIR)/*
