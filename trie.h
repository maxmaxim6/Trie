#ifndef _TRIE
#define _TRIE
#include <stdbool.h>


#define NUM_LETTERS 26
extern char Words[100][100];

typedef struct node
{
    bool end_string;
    int count;
    struct node *next_char[NUM_LETTERS];
}node;

node* newNode();
void addi ( node **head , char *str);
void PrintAll(node **root,char *word ,int index);
void PrintRev(node **root,char *word ,int index);
bool cast(char * word);
void frees(node **root);



#endif