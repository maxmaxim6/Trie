#include "trie.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




int main(int argc , char *argv[])
{
    node *root=newNode();
    char *word=(char*)malloc(10*sizeof(char));
    int index=0;
    int cursize=100;
    char ch;
    while(scanf("%c",&ch)==1)
    {
        if(ch!=' ' && ch!='\n' && ch!='\t' && ch!='\0' && ch!=',' && ch!='.')
        {
            if(ch>='a'  &&  ch<='z')
            {
                *(word+index)=ch;
            }
            if(ch>='A'   &&  ch<='Z')
            {
                word[index]=ch+32;    
            }
            index++;
            word=(char*)realloc(word,index+2);
            if(index+2>cursize)
            {
                cursize=index+10;
            }
        }
        else
        {
            word[index]=0;
            if(index>0)
            {
                insert(&root,word);
            }
            memset(word,0,sizeof(char)*index);
            *word=0;
            index=0;
        }
    }
    if(index>0)
    {
        insert(&root,word);
    }
    free(word);
    char *temp=(char*)malloc(cursize*sizeof(char));
    if(argc!=1)
    {
        PrintRev(&root,temp,0);
    }
    else
    {
        PrintAll(&root,temp,0);
        frees(&root);
    }
    free(temp);
    return 0;
}
