#ifndef _TRIE
#define _TRIE
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define NUM_LETTERS 26

typedef struct node
{
    bool end_string;
    int count;
    struct node *next_char[NUM_LETTERS];
    char ch;
}node;

node* newNode();
void insert( node **head , char *str);
void PrintAll(node **root,char *word ,int index);
void frees(node **root);
void PrintRev(node **root,char *word ,int index);
bool checkEmpty(node **root);



#endif
