#ifndef _TRIE_H_
#define _TRIE_H_
#define NUM_LETTERS 30
#define WORD 30
   
   typedef struct node node;
   node* newnode(char);
   node* insert(node*,char);
   int isleaf(node*);
   void freetrie(node*);
   void inccount(node*);
   void printdef(node*,char*,int);
   void printrev(node*,char*,int);
   void move(node*,char);

#endif

