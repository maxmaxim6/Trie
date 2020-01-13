#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

node* newNode()
{
    struct node *n=(node*)malloc(sizeof(node));
    n->end_string=false;
    n->count=0;
    for(int i =0 ; i < NUM_LETTERS ; i++)
    {
        n->next_char[i]=NULL;
    }
    return n;
}

void insert ( node **head , char *str)
{
    int i=0;
    struct node **cur=head;
    while(*(str+i)!='\0')
    {
        if((*cur)->next_char[*(str+i)-'a']==NULL)
        {
            (*cur)->next_char[*(str+i)-'a']=newNode();       
        }
        cur=&((*cur)->next_char[*(str+i)-'a']);
        i++;   
        
    }
    (*cur)->count++;
    (*cur)->end_string=true;
}

void PrintAll(node **root,char *word ,int index) 
{  
    if ((*root)->end_string)
    { 
        *(word+index)='\0';
        printf("%s",word);
        printf("\t %d \n",(*root)->count);
        (*root)->end_string =false;
    } 
  
    int j; 
    for (j = 0; j < NUM_LETTERS; j++)  
    {  
        if((*root)->next_char[j]!=NULL)
        {
           *(word+index)=j+'a';
            PrintAll(&((*root)->next_char[j]),word,index+1);
        }
    } 
}
void frees(node **root)
{
  
    int j; 
    for (j = 0; j < NUM_LETTERS; j++)  
    {  
        if((*root)->next_char[j]!=NULL)
        {
            frees(&((*root)->next_char[j]));
        }
    }
    free((*root)); 
}

void PrintRev(node **root,char *word ,int index) 
{  
    if ((*root)->end_string)
    { 
        int a=0;
        for(int j= 0 ; j<NUM_LETTERS ; j++)
        {
            if((*root)->next_char[j]!=NULL)
            {
                a++;
            }
        }
        if(!a)
        {
            *(word+index)='\0';
            int i=0;
            while(*(word+i)!='\0')
            {
                printf("%c",*(word+i));
                i++;            
            }
            printf("\t %d \n",(*root)->count);
            (*root)->end_string =false;
        }
    } 
  
    int j; 
    for (j = NUM_LETTERS-1; j >=0; j--)  
    {  
        if((*root)->next_char[j]!=NULL)
        {
           *(word+index)=j+'a';
            PrintRev(&((*root)->next_char[j]),word,index+1);
        }
    }
}

bool checkEmpty(node **root)
{
    
    for(int i= 0 ; i <NUM_LETTERS ; i++)
    {
        if((*root)->next_char[i]!=NULL)
        {
            return false;
        }
    }
    return true;
}

bool cast(char *word)
{
    int i=0;
    while (*(word+i)!='\0')
    {
        if((*(word+i)<'a'  ||  *(word+i)>'z') && (*(word+i)<'A'  ||  *(word+i)>'Z'))
        {
            return false;
        }
        if(*(word+i)>='A'   &&  *(word+i)<='Z')
        {
            *(word+i)=*(word+i)+32;
        }
        i++;
    }
    return true;
    
}


// void main()
// {
//     char aa[100][100];
//     node *root=newNode();
//     char a1[]="ab";
//     char a[] ="ala"; 
//     char b[] ="bcd"; 
//     char c[] ="alad"; 
//     char d[] ="ab"; 
//     char e[] ="ala"; 
//     char f [] ="abca";
//     char t[10];
    
   
//    insert(&root,a);
//    insert(&root,b);
//    insert(&root,c);
//    insert(&root,d);
//    insert(&root,e);
//    insert(&root,f);
//    insert(&root,a1); 
//    PrintAll(&root,t,0); 
//    printf("\n");
//    frees(&root);



// }
