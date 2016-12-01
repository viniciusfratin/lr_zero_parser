#ifndef __GRAMMAR_H
#define __GRAMMAR_H

#include "list.h"

#define GRAMMAR_TYPE char

#define GRAMMAR_TYPE_EMPTY 0
#define GRAMMAR_TYPE_TERMINAL 1
#define GRAMMAR_TYPE_NON_TERMINAL 2
#define GRAMMAR_TYPE_CONCATENATION 3
#define GRAMMAR_TYPE_ALTERNATION 4

typedef struct grammar_terminal
{
	char* value;
} grammar_terminal_t;

typedef struct grammar_non_terminal
{
	char* value;
} grammar_non_terminal_t;

typedef struct grammar_sentence
{
	GRAMMAR_TYPE sentence_type;
	void* sentence_value;
} grammar_sentence_t;

typedef struct grammar_production
{
	grammar_non_terminal_t production_head;
	grammar_sentence_t production_body;
} grammar_production_t;

typedef struct grammar_concatenation
{
	grammar_sentence_t sentence1;
	grammar_sentence_t sentence2;
} grammar_concatenation_t;

typedef struct grammar_alternation
{
	grammar_sentence_t sentence1;
	grammar_sentence_t sentence2; 
} grammar_alternation_t;

typedef struct grammar
{
	list_t* grammar_productions;
} grammar_t;

grammar_terminal_t create_grammar_terminal(const char* terminal_text);
grammar_non_terminal_t create_grammar_non_terminal(const char* terminal_text);
grammar_sentence_t create_grammar_sentence(GRAMMAR_TYPE sentence_type, void* sentence_value);
grammar_concatenation_t create_grammar_concatenation(grammar_sentence_t sentence1, grammar_sentence_t sentence2);
grammar_alternation_t create_grammar_alternation(grammar_sentence_t sentence1, grammar_sentence_t sentence2);
grammar_production_t create_grammar_production(grammar_non_terminal_t production_head, grammar_sentence_t production_body);
void print_grammar(grammar_t grammar);
grammar_t create_grammar(grammar_production_t *start_production);
grammar_t insert_grammar_production(grammar_t grammar, grammar_production_t *production);

#endif