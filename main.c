#include "TRIE.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE_TO_ADD 30


int main(int argc, char* argv[]){

	
	char* word = (char*)malloc(sizeof(char)*256);
	int size = 256;
    char* temp=NULL;
    int check = 0;
    int i = 0;
	char c = getchar();
	node* root = Node_alloc((*word),0,0);
	
	while(c != EOF || (c==EOF && check!=1)){
		if(64 < c && c < 91){
			word[i] = tolower(c);
			}
		     if((96 < c && c < 123) && c!=' ' && c!= '\n' && c!='\0' && c!='\t'){
             if(i == size){
                 temp=(char*)realloc(word,(size+SIZE_TO_ADD)*sizeof(char));
                 size+= SIZE_TO_ADD;
                 if(temp==NULL && word != NULL){
                     free(word);
                     return -1;
             } 
                word=(char*)calloc(size,sizeof(char));
                strcpy(word,temp);
                free(temp);
             }
             word[i] = c;
             i++;			 
		}
		
		if(((c == ' ' || c == '\n' || c=='\t' || c=='\0') || c==EOF)){
             word[i]='\0';
			 if(word[0]!=' ' && i>=1){
             TRIE_insert(&root,word);
             }
             i=0;
         }
		
	   if(c == EOF) check = 1;
       c = getchar();						
			
	}
	
	
	  if(argc==2 && strcmp(argv[1],"r")==0){
		  print_TRIE(&root, word, 0, 0);
	  }
	else{
		print_TRIE(&root, word, 0, 1);
		free(word);
	
	}
	return 0;
}