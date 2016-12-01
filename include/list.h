#ifndef __LIST_H
#define __LIST_H

typedef struct struct_list
{
	struct struct_list *prev;
	struct struct_list *next;
	void* value;
	int num_items;
	struct struct_list *top_item;
} list_t;

list_t* list_create();
list_t* list_insert(list_t* list, void* value);
void list_free(list_t* list);
void list_print(list_t* list);

#endif