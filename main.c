#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include <string.h>
#define SIZE 1000


int main(int argc , char *argv[])
{
    node *root=newNode();
    char a[SIZE];
    char temp[SIZE];
    char b[SIZE];
    while(fgets(a,SIZE,stdin))
    {
        int i=0,j=0;
        while(a[i]!='\0')
        {
            if(a[i]!=' ')
            {
                b[j++]+=a[i];
            }
            else
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
    if(argc!=1)
    {
       PrintRev(&root,temp,0);
    }
    else
    {
       PrintAll(&root,temp,0);
    }
    frees(&root);
    return 0;
}
