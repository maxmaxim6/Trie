#include <stdio.h>
#include "trie.h"


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
        
        printf("%s",word);
        printf("\t %d \n",(*root)->count);
        //(*root)->end_string =false;
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

void cast(char **word)
{
    int i=0,j=0;
    char newWord[SIZE];
    char *a=*word;
    while (*(a+i)!='\0')
    {
        if(*(a+i)>='a'  &&  *(a+i)<='z')
        {
            *(newWord+j++)=*(a+i);
        }
        if(*(a+i)>='A'   &&  *(a+i)<='Z')
        {
            *(newWord+j++)=*(a+i)+32;
        
        }
        i++;
    }
    *(newWord+j)='\0';
    strcpy(a,newWord);
    
}


// int main()
// {
//     node *root=newNode();
//     char a1[]="a";
//     char a[] ="ab"; 
//     char b[] ="abc"; 
//     char c[] ="b"; 
//     char d[] ="bc"; 
//     char e[] ="bcd"; 
//     char f [] ="a";
//     char a2 [] ="aa";
//     char a3 [] ="bb";
//     char a4 [] ="aa";
//     char t[10];
   
//     insert(&root,a);
//     insert(&root,b);
//     insert(&root,c);
//     insert(&root,d);
//     insert(&root,e);
//     insert(&root,f);
//     insert(&root,a1);
//     insert(&root,a2); 
//     insert(&root,a3);
//     insert(&root,a4);
//     PrintAll(&root, t, 0);
//     printf("\n");
//     PrintRev(&root,t,0); 
//     //frees(&root);
//     return 0;


// }
