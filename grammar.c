#include <stdlib.h>
#include <string.h>

#include "grammar.h"

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