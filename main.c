#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "trie.h"


int main(int argc, char const *argv[])
{

char get;
node *root=newnode('\0');
node *n=root;
char w[WORD];
char c;

while((c=getc(stdin))!=EOF)
{
if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
  {
    n=insert(n,tolower(c));
     
  }
 else
   if(c=='\t'||c=='\n'||c== ' ')
    { 
     inccount(n);
     n=root;
    } 
  
}
 if(argc>1)
  {
   get=*argv[1];
   if(get=='r')
    printrev(root,w,0);
  }
 else
  printdef(root,w,0); 

 freetrie(root);
}



