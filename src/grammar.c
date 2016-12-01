#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammar.h"

static char* create_grammar_text(const char* text);
static void print_grammar_production(grammar_production_t production);
static void print_grammar_sentence(grammar_sentence_t sentence);

grammar_terminal_t create_grammar_terminal(const char* terminal_text)
{
	grammar_terminal_t terminal;
	terminal.value = create_grammar_text(terminal_text);
	
	return terminal;
}

grammar_non_terminal_t create_grammar_non_terminal(const char* non_terminal_text)
{
	grammar_non_terminal_t non_terminal;
	non_terminal.value = create_grammar_text(non_terminal_text);
	
	return non_terminal;
}

static char* create_grammar_text(const char* text)
{
	int num_bytes = strlen(text) + 1;
	
	char* text_buffer = (char*)malloc((strlen(text) + 1) * sizeof(char));
	if(text_buffer != NULL)
	{
		memcpy(text_buffer, text, num_bytes);
	}
	
	else
	{
		text_buffer = NULL;
	}
	
	return text_buffer;
}

grammar_sentence_t create_grammar_sentence(GRAMMAR_TYPE sentence_type, void* sentence_value)
{
	grammar_sentence_t sentence;
	sentence.sentence_type = sentence_type;
	sentence.sentence_value = sentence_value;
	
	return sentence;
}

grammar_concatenation_t create_grammar_concatenation(grammar_sentence_t sentence1, grammar_sentence_t sentence2)
{
	grammar_concatenation_t concatenation;
	concatenation.sentence1 = sentence1;
	concatenation.sentence2 = sentence2;
	
	return concatenation;
}

grammar_alternation_t create_grammar_alternation(grammar_sentence_t sentence1, grammar_sentence_t sentence2)
{
	grammar_alternation_t alternation;
	alternation.sentence1 = sentence1;
	alternation.sentence2 = sentence2;
	
	return alternation;
}

grammar_production_t create_grammar_production(grammar_non_terminal_t production_head, grammar_sentence_t production_body)
{
	grammar_production_t production;
	production.production_head = production_head;
	production.production_body = production_body;
	
	return production;
}

void print_grammar(grammar_t grammar)
{
	list_t* productions = grammar.grammar_productions;
	
	int count;
	for(count = 1; productions != NULL; (count++, productions = productions->next))
	{
		printf("%d. ", count);
		print_grammar_production(*((grammar_production_t*)productions->value));
	}
}

static void print_grammar_production(grammar_production_t production)
{
	printf("%s", production.production_head.value);
	printf(" --> ");
	
	print_grammar_sentence(production.production_body);
	
	printf("\n");
}

static void print_grammar_sentence(grammar_sentence_t sentence)
{
	switch(sentence.sentence_type)
	{
		case GRAMMAR_TYPE_EMPTY:
			break;
			
		case GRAMMAR_TYPE_TERMINAL:
			printf("%s", ((grammar_terminal_t*)sentence.sentence_value)->value);
			break;
			
		case GRAMMAR_TYPE_NON_TERMINAL:
			printf("%s", ((grammar_non_terminal_t*)sentence.sentence_value)->value);
			break;
			
		case GRAMMAR_TYPE_CONCATENATION:
			printf("(");
			print_grammar_sentence(((grammar_concatenation_t*)sentence.sentence_value)->sentence1);
			print_grammar_sentence(((grammar_concatenation_t*)sentence.sentence_value)->sentence2);
			printf(")");
			break;
			
		case GRAMMAR_TYPE_ALTERNATION:
			printf("(");
			print_grammar_sentence(((grammar_alternation_t*)sentence.sentence_value)->sentence1);
			printf("|");
			print_grammar_sentence(((grammar_alternation_t*)sentence.sentence_value)->sentence2);
			printf(")");
			break;
			
		default:
			printf("Invalid sentence!");
	}
}

grammar_t create_grammar(grammar_production_t *start_production)
{
	grammar_t grammar;
	
	list_t* productions = list_create();
	
	if(productions != NULL)
	{
		productions = list_insert(productions, start_production);
	}
	
	grammar.grammar_productions = productions;
	
	return grammar;
}

grammar_t insert_grammar_production(grammar_t grammar, grammar_production_t *production)
{
	list_t* productions = grammar.grammar_productions;
	
	if(productions != NULL)
	{
		productions = list_insert(grammar.grammar_productions, production);
	}
	
	grammar.grammar_productions = productions;
	
	return grammar;
}

