#ifndef HASH_TABLE
#define HASH_TABLE
int SIZE = 100;
struct hash_element
{
        char *str;
        struct hash_element *next;
};
int hash_function( char *key );
int add_to_hash_table( struct hash_element *hash_table[], char *key );
void  print_hash_table( struct hash_element * hash_table[] );



#endif