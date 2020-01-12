#include <stdio.h>
#include "trie.h"
#include <limits.h>
#define SIZE 1000


int main(int argc , char *argv[])
{
    node *root=newNode();
    char a[SIZE];
    if(argc!=1)
    {
        while(fgsets(a,SIZE,stdin))
        {
            char b[INT_MAX];
            int i=0,j=0;
            while(a[i]!='\0')
            {
                if(a[i]!=' ')
                {
                    b[j++]+=a[i];
                }
                if(a[i]==' ')
                {
                    b[j]='\0';
                    if(cast(b))
                    {
                        insert(&root,b);
                    }
                    memset(b,0,sizeof(b)); // reset the string
                    j=0;
                   
                }
                i++;   
            }
        }
        PrintAll(&root)
        frees(&root);
    }
    else
    {
        while(fgsets(a,SIZE,stdin))
        {
            char b[INT_MAX];
            int i=0,j=0;
            while(a[i]!='\0')
            {
                if(a[i]!=' ')
                {
                    b[j++]+=a[i];
                }
                if(a[i]==' ')
                {
                    b[j]='\0';
                    if(cast(b))
                    {
                        insert(&root,b);
                    }
                    memset(b,0,sizeof(b)); // reset the string
                    j=0;
                   
                }
                i++;   
            }
        }
        PrintRev(&root)
        frees(&root);
    }
    char theWord[WORD];
    char op;
    scanf("%s",theWord);
    scanf(" %c",&op);
   
    if(op=='a')
    {
        print_lines(theWord);
    }
    if(op=='b')
    {
        print_word(theWord);
    }
    return 0;
}