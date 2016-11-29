#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammar.h"

int main()
{
	//S -> (AB) | C
	//A -> a
	//B -> b
	//C -> c

	grammar_terminal_t term_a = create_grammar_terminal("a");
	grammar_terminal_t term_b = create_grammar_terminal("b");
	grammar_terminal_t term_c = create_grammar_terminal("c");
	
	grammar_non_terminal_t non_term_A = create_grammar_non_terminal("A");
	grammar_non_terminal_t non_term_B = create_grammar_non_terminal("B");
	grammar_non_terminal_t non_term_C = create_grammar_non_terminal("C");
	
	grammar_sentence_t sentence_term_a = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_a);
	grammar_sentence_t sentence_term_b = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_b);
	grammar_sentence_t sentence_term_c = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_c);
	
	grammar_sentence_t sentence_non_term_A = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_A);
	grammar_sentence_t sentence_non_term_B = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_B);
	grammar_sentence_t sentence_non_term_C = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_C);
	
	return 0;
}