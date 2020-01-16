#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
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
            if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
            {
                b[j++]+=a[i];
            }
            else
            {
                b[j]='\0';    
        
                insert(&root,b);
                memset(b,0,sizeof(b)); // reset the string
                j=0;           
            }
            i++;   
        }
        memset(b,0,sizeof(b));
    }
    if(argc!=1)
    {
        PrintRev(&root,temp,0);
    }
    else
    {
        PrintAll(&root,temp,0);
        frees(&root);
    }
    return 0;
}
