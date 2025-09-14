//STANDARD LIBRALIES
#include <stdio.h>
#include <string.h>
//STANDARD LIBRALIES

//OWN LIBRALIES
#include "linuxchto.h"
//OWN LIBRALIES


enum TOKENER {
NUMBER_TOKEN,
PLUS_TOKEN,
PRE_UNKNOWN_TOKEN,
};

enum TOKENER token;

int TRUE = 1;
int increment_checking_debug = 0;


FILE *f;

char store_tokens[100] = "";

int TOKENER_CHECKER_DBUG(){
	FILE *f = fopen("test.txt", "r");
while(TRUE){
if(chto(store_tokens[increment_checking_debug])){
token = NUMBER_TOKEN;
printf("Token: %c, Token Number: %d\n", store_tokens[increment_checking_debug], token);
}
else if(store_tokens[increment_checking_debug] == '+'){
token = PLUS_TOKEN;
printf("Token: %c, Token Number: %d\n", store_tokens[increment_checking_debug], token);
}
else if(store_tokens[increment_checking_debug] == '\n'){
token = PRE_UNKNOWN_TOKEN;
}
else{
token = PRE_UNKNOWN_TOKEN;
printf("Token: %c, Token Number: %d\n", store_tokens[increment_checking_debug], token);
}
increment_checking_debug++;
if(increment_checking_debug >= strlen(store_tokens)){
TRUE = 0;
return 0;
}
}
}

int main(){
      FILE *f = fopen("test.txt", "r");
      fgets(store_tokens, sizeof(store_tokens), f);
      printf("%s\n", store_tokens);
      TOKENER_CHECKER_DBUG();
	fclose(f);
	return 0;
}

