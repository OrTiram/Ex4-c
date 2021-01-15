#ifndef TRIE_H
#define TRIE_H
#include <stdlib.h>
#define NUM_LETTERS ((int)26)
#define Char_To_Index(c) ((int)c - (int)'a')


struct node;
typedef struct node node;
node* Node_alloc(char letter, long unsigned int count, int isEndWord);
void TRIE_insert(node** head,char* str);
void print_TRIE(node** head,char word[], int level, int regular);
void freeTrie(node** head);

#endif
