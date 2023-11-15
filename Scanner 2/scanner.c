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
	int i;
	for (i = 0; i < KEYWORDS_COUNT; i++)
	{
		if (strcasecmp(str, keywords[i].string) == 0)
		{
			return keywords[i].Token;
		}
	}
	
	return IDENT;
}

char getCh(){
  return fgetc(f);
}

TokenType getToken(){
//TODO:
//..............
	while (ch == ' '|| ch =='\n' || ch == 13) 
	{
		ch = getCh();
	}
	// kiem tra co la ky tu chuoi khong
	if (isalpha(ch))
	{
		int i = 0;
		while (isalpha(ch) || isdigit(ch))
		{
			Id[i]= ch;
			i++;
			ch = getCh();
		}
		Id[i] = '\0';
		TokenType token = checkKeyword(Id);
		if (token != IDENT) 
        {
            return token;
        }
        // Nếu không phải từ khóa, trả về IDENT
        return IDENT;
	}
	// kiem tra co la ky tu so khong
	else if (isdigit(ch))
	{
		Num = 0;
		while (isdigit(ch))
		{
			Num = Num * 10 + ch - 48;
			ch = getCh();
		}
		return NUMBER;
	}
	// kiem tra co phai la ky tu ';' khong
	else if (ch == ';')
	{
		ch = getCh();
		return SEMICOLON;
	}
	// kiem tra co phai la ky tu ',' khong
	else if (ch == ',')
	{
		ch = getCh();
		return COMMA;
	}
	// kiem tra co phai la ky tu '.' khong
	else if (ch == '.')
	{
		ch = getCh();
		return PERIOD;
	}
	// kiem tra co phai la ky tu '(' khong
	else if (ch == '(')
	{
		ch = getCh();
		return LPARENT;
	}
	// kiem tra co phai la ky tu ')' khong
	else if (ch == ')')
	{
		ch = getCh();
		return RPARENT;
	}
	// kiem tra co phai la ky tu '[' khong
	else if (ch == '[')
	{
		ch = getCh();
		return LBRACK;
	}
	// kiem tra co phai la ky tu ']' khong
	else if (ch == ']')
	{
		ch = getCh();
		return RBRACK;	
	}
	// kiem tra co phai la ky tu '%' khong
	else if (ch == '%')
	{
		ch = getCh();
		return PERCENT;
	}
	// kiem tra co phai la ky tu '+' khong
	else if (ch == '+')
	{
		ch = getCh();
		return PLUS;
	}
	// kiem tra co phai la ky tu '-' khong
	else if (ch == '-')
	{
		ch = getCh();
		return MINUS;
	}
	 // kiem tra co phai la ky tu '*' khong
	else if (ch == '*')
	{
		ch = getCh();
		return TIMES;
	}
	// kiem tra co phai la ky tu '/' khong
	else if (ch == '/')
	{
		ch = getCh();
		return SLASH;
	}
	 // kiem tra co phai la ky tu '=' khong
	else if (ch == '=')
	{
		ch = getCh();
		return EQU;
	}
	// kiem tra co phai la ky tu '<', '<=', '<>"" khong
	else if (ch == '<')
	{
		ch = getCh();
		if (ch == '=')
		{
			ch = getCh();
			return LEQ;
		}
		else if (ch == '>')
		{
			ch = getCh();
			return NEQ;
		}
		else
		{
			return LSS;
		}
		
	}
	// kiem tra co phai la ky tu '>=' khong
	else if (ch == '>')
	{
		ch = getCh();
		if (ch == '=')
		{
			ch = getCh();
			return GEQ;
		}
		else
		{
			return GTR;
		}
	}
	// kiem tra co phai la ky tu ':=' khong
	else if (ch == ':')
	{
		ch = getCh();
		if (ch == '=')
		{
			ch = getCh();
			return ASSIGN;
		}
		else
		{
			return NONE;
		}
	}
	
	
    return NONE;
}


void compile(char * filename){
  	if((f = fopen(filename,"rt")) == NULL) printf("File %s not found",filename);
  	else{
		ch =' ';
		do{
		 	Token = getToken();
			printf(" %s",TabToken[Token]);
			if(Token==IDENT) printf("(%s) \n",Id);
			else if(Token==NUMBER) printf("(%d) \n",Num);
			else printf("\n");
		}while(Token != NONE);
	}
  fclose(f);
}
