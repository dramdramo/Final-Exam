#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "linkedlist.h"

int get_count(linked_list *ll)
{
	linked_list * tmp=ll;
	int count=0;
	while(tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
return count;
}
int add_to_list(struct linked_list *ll, char *s )
{
	linked_list * tmp = ll;
	int ctr = 1;
	while( tmp->next  != NULL )
	{//as long as tmp is not the last element which is not null
		ctr ++;
		tmp = tmp->next;
	}
	if( tmp->next == NULL )
	{//add element
		tmp->next = ( linked_list *)malloc( sizeof( linked_list ));
		tmp->next->next = NULL;
		tmp->next->data = s;
		tmp->next->index = ctr;
		return 1;
	}
	return -1;//error
}

int display_item( linked_list *ll, int index)
{
	 linked_list * tmp = ll;

	 while  (tmp != NULL )
	{//as long as index is not found, keep iterating

		 if( tmp->index == index )
		{//if we reached the end, exit!
			printf("\n Display item at index %d is having data %s \n",index,tmp->data);//if we didnt exit, we found a good element

			 return 0;
		}
		tmp = tmp->next;
	}
	return -1;
}

 int display_list(struct linked_list *ll)
{
	 linked_list * tmp = ll;
	 int ctr = 0;
	if((tmp==NULL))
	{
		return ctr;
	}
	else {
	while( (tmp != NULL))
	{//iterate through all list, print data and keep count of nr of iterations

		ctr ++;
		printf("\n\r %s", tmp->data);
		tmp = tmp->next;
	}
	}
	return ctr;

}

linked_list * search_from_list( linked_list *ll, char *s)
{
	linked_list * tmp = ll;
	while( tmp != NULL )
	{
		if(  strcmp(tmp->data, s)==0  )
		{//found
			return tmp;
		}
		tmp = tmp->next;//keep iterating
	}
	return NULL;//we exited the while, because no solution was found
}

int delete_from_list( linked_list *ll, int index)
{
	linked_list * tmp = ll;
	int count;
	while( tmp != NULL )
	{
		if( tmp->next != NULL && tmp->next->index == index  )
		{//found element
			struct linked_list * tmp_N;
        		tmp_N = tmp->next->next;
        		free(tmp->next);//delete pointer
        		tmp->next = tmp_N;
        		count=get_count(tmp);
			return count;
		}
		tmp = tmp->next;
	}
	//not found
	return -1 ;
}
/*
void main()
{
	struct linked_list head;
	head.data = "thisishead";
	head.index = 0;
	head.next = NULL;
	add_to_list( &head, "eL01");
	add_to_list( &head, "eL02");
	add_to_list( &head, "eL03");
	display_list(&head);
	display_item(&head,2);
	printf("\n Searched from list : %s\n", search_from_list(&head, "eL03")->data );
	delete_from_list(&head, 1);
	display_list(&head);
}
*/
