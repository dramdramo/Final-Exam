#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include  "hash_table.h"


int hash_function( char *key )
{
	return toupper( key[ 0 ] ) - 'A' % SIZE;
}

int add_to_hash_table( struct hash_element *hash_table[], char *key )
{
	int hash = hash_function(key);
	if( hash_table[ hash ] == NULL )
	{
		 hash_table[ hash ] = ( struct hash_element* )malloc( sizeof( struct hash_element ) );
		 hash_table[ hash ] -> str = key;
		 printf("\n Added %s to hash %d\n",key,hash);
		 hash_table[ hash ] -> next = NULL;
		 return 0;
	}
	else
	{
		printf("\n Colision ocurred!\n");
		struct hash_element * temp = hash_table[ hash ];
		while( temp ->next != NULL )
		{
			temp = temp -> next;
		}
		temp -> next = ( struct hash_element* )malloc( sizeof( struct hash_element ) );
		temp -> next-> str = key;
		temp -> next -> next = NULL;
		printf("\n Added %s to hash %d\n",key,hash);
		return 1;
	}
}
void  print_hash_table( struct hash_element * hash_table[] )
{
	int i;
	struct hash_element * temp = hash_table[0];
	for( i = 0; i < SIZE; i ++ )
	{
		temp = hash_table[ i ];
		while( temp != NULL )
		{
			printf( "\n%s\n", temp -> str );
			temp = temp->next;
		}
	}
}

void main()
{
	struct hash_element *hash_table[SIZE];
	int i ;
	for( i = 0; i < SIZE; i++)
	{
		hash_table[ i ] = NULL;
	}
	char *name ="Daniel";
	add_to_hash_table( hash_table, name);
	name = "Dan";
	add_to_hash_table( hash_table, name);
	add_to_hash_table( hash_table, "Ann" );
	add_to_hash_table( hash_table, "Abn" );
	add_to_hash_table( hash_table, "Acn" );
	add_to_hash_table( hash_table, "Zen" );
	add_to_hash_table( hash_table, "Zack" );
	add_to_hash_table( hash_table, "Ann" );
	print_hash_table(hash_table);
}

