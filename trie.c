#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define NUM_LETTERS 26


typedef struct node{
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];

}node;



node* newnode(char letter)
{

node* n=(node*)malloc(sizeof(node));

n->count=0;

n->letter=letter;

for(int i=0;i<NUM_LETTERS;i++)
n->children[i]=NULL;

return n;

}


node* insert(node *n, char c){

  
    node *no = newnode(c);
	
if(n->children[c-'a'] == NULL)
 {


    n->children[c-'a'] = no;
    return n->children[c-'a'];

 }
 return n->children[c-'a'];

}


int isleaf(node* n)
{
for(int i=0;i<NUM_LETTERS;i++)
if(n->children[i]!=NULL)
 return 0;


return 1;
}

void freetrie(node* n)
{
if(n==NULL)
return;

if(isleaf(n)==1)
{
free(n);
return;
}

for(int i=0;i<NUM_LETTERS;i++)
{
   if(n->children[i]!=NULL)
      freetrie(n->children[i]);
}
free(n);

}


void inccount(node* n)
{
n->count++;
}


void printdef(node* n,char* c,int i)
{
  if (isleaf(n)){
		c[i] = '\0';
		printf("%s\t%ld\n", c, n->count);
		return;
	}
	if (n->count > 0){
		c[i] = '\0';
		printf("%s\t%ld\n", c, n->count);
	}
	int j;
	for (j=0; j<NUM_LETTERS; j++){
		if (n->children[j]!=NULL){
			c[i] = n->children[j]->letter;
                        
			printdef(n->children[j], c, i+1);
		}
	}
}


void printrev(node* n,char* c,int i)
{
  if (isleaf(n)){ 
      c[i] = '\0';
       printf("%s\t%ld\n", c, n->count);
	return;
	}
	if (n->count > 0){
	c[i] = '\0';
	printf("%s\t%ld\n", c, n->count);
	}
	int j;
      for (j=NUM_LETTERS-1; j>=0; j--){
	 if (n->children[j]!=NULL){
	   c[i] = n->children[j]->letter;

	    printdef(n->children[j], c, i+1);
		}
	}
}

void move(node* n,char i)
{
 n=n->children[i-'a'];
}
