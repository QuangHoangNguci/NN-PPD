#define	MAX_NUMBER_LEN   6
#define MAX_IDENT_LEN   10
#define KEYWORDS_COUNT  15

typedef enum {NONE=0, IDENT, NUMBER,
		KW_BEGIN, KW_CALL, KW_CONST, KW_DO,  KW_ELSE, KW_END, KW_FOR, KW_IF, KW_ODD,
		KW_PROCEDURE, KW_PROGRAM, KW_THEN, KW_TO, KW_VAR, KW_WHILE,
		
		PLUS, MINUS, TIMES, SLASH, EQU, NEQ, LSS, LEQ,GTR, GEQ, PERCENT,
		LPARENT, RPARENT, LBRACK,RBRACK,PERIOD,COMMA,SEMICOLON, ASSIGN
} TokenType;

struct {
  	char string[MAX_IDENT_LEN + 1];
  	TokenType Token;
} keywords[KEYWORDS_COUNT] = {
  		{"BEGIN", KW_BEGIN},
  		{"CALL", KW_CALL},
  		{"CONST", KW_CONST},
  		{"DO", KW_DO}, 
    	{"ELSE", KW_ELSE},
      	{"END", KW_END},
        {"FOR", KW_FOR},
   		{"IF", KW_IF},
     	{"ODD",KW_ODD},
  		{"PROCEDURE", KW_PROCEDURE},
		{"PROGRAM", KW_PROGRAM},
    	{"THEN", KW_THEN},
    	{"TO", KW_TO},
		{"VAR", KW_VAR},
  		{"WHILE", KW_WHILE}
};

char TabToken[][10] = {	"NONE", "IDENT", "NUMBER",		
		"BEGIN", "CALL", "CONST", "DO",  "ELSE", "END", "FOR", "IF", 
		"ODD", "PROCEDURE", "PROGRAM", "THEN", "TO", "VAR", "WHILE",
	
		"PLUS", "MINUS", "TIMES", "SLASH", "EQU", "NEQ", "LSS", 
		"LEQ", "GTR", "GEQ", "PERCENT", "LPARENT", "RPARENT", 
		"LBRACK", "RBRACK", "PERIOD", "COMMA", "SEMICOLON", "ASSIGN"
	};
