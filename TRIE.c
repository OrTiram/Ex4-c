#include "TRIE.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

	
typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
int isEndWord;
}node;


node* Node_alloc(char letter, long unsigned int count, int isEndWord) {
	node* p= (node*)malloc(sizeof(node));
	if(p != NULL){
		p-> letter = letter;
		p-> count = count;
		p-> isEndWord = isEndWord;
		int i = 0;
		while(i < NUM_LETTERS) {
			p->children[i] =NULL;
			i++;
		}	
	
		return p;
	}
	return NULL;
}


void TRIE_insert(node** head,char* str){
    int i=0;
    int len = (int)strlen(str);
    size_t level=0;
    node* runner = *head;

    for (level = 0; level < len; level++)
    {
        i=Char_To_Index(str[level]);
        if(!runner->children[i]){
            runner->children[i]=Node_alloc((*str),0,0);
            runner->children[i]->letter=str[level];
        }
        runner=runner->children[i];
    }
    runner->isEndWord=1;
    runner->count++;
}





void print_TRIE(node** head,char word[], int level, int regular){
    node* runner = * head;
    int i;
    if(runner ==NULL){
		return;
	}
    if(runner->isEndWord){
        word[level]='\0';
        printf("%s \t %ld \n",word,runner->count);
    }
	
	if(regular){
    
		for(i = 0;i < NUM_LETTERS; i++){
			if(runner->children[i] != NULL){
				word[level] = runner->children[i]->letter;
				print_TRIE(&(runner->children[i]),word,level+1, regular);
			}
		}
	}
	else{
		for(i = NUM_LETTERS-1 ;0 <= i; i--){
			if(runner->children[i]!=NULL){
				word[level]=runner->children[i]->letter;
				print_TRIE(&(runner->children[i]),word,level+1, regular);
			}
		}
	}
	free(runner); 
}

void freeTrie(node** head){
    node* runner = *head;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        if(runner->children[i]!=NULL){
            freeTrie(&(runner->children[i]));
        }
    }
    free(runner);
}



