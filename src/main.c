#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammar.h"
#include "list.h"

int main()
{
	/* 	
		S -> (AB) | C
	 	A -> a
	 	B -> b
	 	C -> c
	*/

	//terminals
	grammar_terminal_t term_a = create_grammar_terminal("\'a\'");
	grammar_terminal_t term_b = create_grammar_terminal("\'b\'");
	grammar_terminal_t term_c = create_grammar_terminal("\'c\'");
	
	//non-terminals
	grammar_non_terminal_t non_term_S_prime = create_grammar_non_terminal("S'");
	grammar_non_terminal_t non_term_S = create_grammar_non_terminal("S");
	grammar_non_terminal_t non_term_A = create_grammar_non_terminal("A");
	grammar_non_terminal_t non_term_B = create_grammar_non_terminal("B");
	grammar_non_terminal_t non_term_C = create_grammar_non_terminal("C");

	//terminals sentences
	grammar_sentence_t sentence_term_a = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_a);
	grammar_sentence_t sentence_term_b = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_b);
	grammar_sentence_t sentence_term_c = create_grammar_sentence(GRAMMAR_TYPE_TERMINAL, &term_c);
	
	//non-terminals sentences
	grammar_sentence_t sentence_non_term_S = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_S);
	grammar_sentence_t sentence_non_term_A = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_A);
	grammar_sentence_t sentence_non_term_B = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_B);
	grammar_sentence_t sentence_non_term_C = create_grammar_sentence(GRAMMAR_TYPE_NON_TERMINAL, &non_term_C);
	
	grammar_concatenation_t concat_AB = create_grammar_concatenation(sentence_non_term_A, sentence_non_term_B);
	grammar_sentence_t sentence_concat_AB = create_grammar_sentence(GRAMMAR_TYPE_CONCATENATION, &concat_AB);
	
	grammar_alternation_t alter_AB_C = create_grammar_alternation(sentence_concat_AB, sentence_non_term_C);
	grammar_sentence_t sentence_alter_AB_C = create_grammar_sentence(GRAMMAR_TYPE_ALTERNATION, &alter_AB_C);
	
	grammar_production_t produc_0 = create_grammar_production(non_term_S_prime, sentence_non_term_S);
	grammar_production_t produc_1 = create_grammar_production(non_term_S, sentence_alter_AB_C);
	grammar_production_t produc_2 = create_grammar_production(non_term_A, sentence_term_a);
	grammar_production_t produc_3 = create_grammar_production(non_term_B, sentence_term_b);
	grammar_production_t produc_4 = create_grammar_production(non_term_C, sentence_term_c);

	grammar_t grammar = create_grammar(&produc_0);
	grammar = insert_grammar_production(grammar, &produc_1);
	grammar = insert_grammar_production(grammar, &produc_2);
	grammar = insert_grammar_production(grammar, &produc_3);
	grammar = insert_grammar_production(grammar, &produc_4);
	
	print_grammar(grammar);
	
	return 0;
}