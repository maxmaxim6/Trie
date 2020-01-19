#include "trie.h"
#include <stdio.h>


node* newNode()
{
    struct node *n=(node*)malloc(sizeof(node));
    if(n)
    {
        n->end_string=false;
        n->count=0;
        for(int i =0 ; i < NUM_LETTERS ; i++)
        {
            n->next_char[i]=NULL;
        }
    }
    return n;
}

void insert ( node **head , char *str)
{
    int i=0;
    node *cur=*head;
    while(*(str+i)!='\0')
    {
        if((cur)->next_char[*(str+i)-'a']==NULL)
        {
            (cur)->next_char[*(str+i)-'a']=newNode(); 
            (cur)->ch=*(str+i);      
        }
        cur=(cur)->next_char[*(str+i)-'a'];
        i++;  
        
    }
    (cur)->count++;
    (cur)->end_string=true;

}

void PrintAll(node **root,char *word ,int index) 
{  
    if ((*root)->end_string)
    { 
        *(word+index)='\0';  
        printf("%s \t %d \n",word ,(*root)->count);
        
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
    if(checkEmpty(&(*root)))
    {
        *(word+index)='\0';
        if((*root)->end_string)
        {
            printf("%s \t %d \n",word ,(*root)->count);
        }
        index--;
        *(word+index)='\0';
        free((*root));
        return;

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

    if((*root)->end_string)
    {
        *(word+index)='\0';
        printf("%s \t %d \n",word,(*root)->count);
    }
    free(*root);
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

