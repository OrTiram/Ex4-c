#include <stdlib.h>
#define NUM_LETTERS ((int)26)
#define LONGEST_WORD 50
#define Char_To_Index(c) ((int)c - (int)'a')


struct node;
typedef struct node node;
node* Node_alloc(char letter, long unsigned int count, int isEndWord);
void Node_free(node* n);
void TRIE_insert(node** head,char* str);
void print_TRIE(node** head,char word[], int level, int regular);
void freeTrie(node** head);
