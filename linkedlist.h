#ifndef _LINKED_LIST
#define _LINKED_LIST
typedef struct linked_list
{
	char *data;
	int index; /* normally not used with Linked Lists, just for exercise */
	struct linked_list *next;
}linked_list;

int get_count(linked_list *ll);
int add_to_list(struct linked_list *ll, char *s);
//int display_item(struct linked_list *ll, int index);
int display_item(struct linked_list *ll);
int display_list(struct linked_list *ll);
struct linked_list * search_from_list(struct linked_list *ll, char *s);
int delete_from_list(struct linked_list *ll, int index);
int linkedlist_status(linked_list *ll);
void empty_list(linked_list *ll);
#endif
