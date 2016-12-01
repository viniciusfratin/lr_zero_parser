#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t* list_create()
{
	list_t* list = (list_t*)malloc(sizeof(list_t));
	if(list != NULL)
	{
		list->prev = NULL;
		list->next = NULL;
		list->value = NULL;
		list->num_items = 0;
		list->top_item = list;
	}
	
	else
	{
		list = NULL;
	}
	
	return list;
}

list_t* list_insert(list_t* list, void* value)
{
	list_t* ret = NULL;
	
	if(list != NULL)
	{
		if(list->num_items == 0)
		{
			list->prev = NULL;
			list->next = NULL;
			list->value = value;
			list->num_items++;
			list->top_item = list;
			
			ret = list;
		}
		
		else
		{
			list_t* new_item = (list_t*)malloc(sizeof(list_t));
			if(new_item != NULL)
			{
				list->top_item->next = new_item;
				new_item->prev = list->top_item;
				new_item->next = NULL;
				new_item->value = value;
				
				list->num_items++;
				list->top_item = new_item;
				
				ret = list;
			}
		}			
	}
	
	return ret;
}

void list_free(list_t* list)
{
	list_t* temp;
	while(list != NULL)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void list_print(list_t* list)
{
	printf("Num items: %d\n", list->num_items);
	
	int count;
	for(count = 1; list != NULL; (count++, list = list->next))
	{
		printf("Item #%d: %p\n", count, list->value);
	}
	
	printf("\n");
}