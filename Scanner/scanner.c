#include <stdio.h>
#include "scanner.h"
#include <ctype.h>
#include <string.h>

TokenType Token;
int		  Num;
char	  Id[MAX_IDENT_LEN + 1];

FILE * f;
char ch;

TokenType checkKeyword(char * str){
	//TODO: Kiem tra tham so truyen vao co phai la mot Tu khoa khong
	//................
	int i;
	for ( i = 0; i < KEYWORDS_COUNT; i++)
	{
		if (strcmp(str, keywords[i].string) == 0)
		{
			return keywords[i].Token;
		}
		return IDENT;
	}
	

	return NONE;
}

char getCh(){
  return fgetc(f);
}

TokenType getToken(){
//TODO:
//..............
	while (ch == ' ' || ch == 13 || ch == '\n') ch = getCh();
	if (isalpha(ch))
	{
		int i = 0;
		while (isalpha(ch) || isdigit(ch))
		{
			Id[i] = ch;
			i++;
			ch = getCh();
		}
		Id[i] = '\0';
		
		return checkKeyword(Id);
		
		
	}
	else if (isdigit(ch)){
		Num = 0;
		while (isdigit(ch))
		{
			Num = Num * 10 + ch - 48;
			ch = getCh();
		}
		return NUMBER;

	} else if (ch == ';'){
		ch= getCh();
		return SEMICOLON;

	} else if (ch == ','){
		ch = getCh();
		return COMMA;
	}else if (ch == ':'){
		ch = getCh();
		if(ch == '='){
			ch = getCh();
			return EQU;
		}
		else{
			ch = getCh();
			return NONE;
		}
	} else if (ch == '+'){
		ch = getCh();
		return PLUS;
	} else if (ch == '*'){
		ch = getCh();
		return TIMES;
	} else if (ch == '>'){
		ch = getCh();
		return GTR;
	}
	

	



    return NONE;
}


void compile(char * filename){
  	if((f = fopen(filename,"rt")) == NULL) printf("File %s not found",filename);
  	else{
		ch =' ';
		do{
		 	Token = getToken();
			//printf("%d\n",Token);
			printf(" %s", TabToken[Token]);
			if(Token==IDENT) printf("(%s) \n",Id);
			else if(Token==NUMBER) printf("(%d) \n",Num);
			else printf("\n");
		}while(Token != NONE);
	}
  fclose(f);
}
