#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <map>
#include "source.h"  

using namespace std;

enum class TokenType
{
    // reserved words
    PROGRAM, BEGIN, END, REPEAT, UNTIL, WRITE, WRITELN,
    DIV, MOD, AND, OR, NOT, CONST, TYPE, VAR, PROCEDURE,
    FUNCTION, WHILE, DO, FOR, TO, DOWNTO, IF, THEN, ELSE,
    WHILE, CASE, OF,

    // special symbols
    INTEGER, REAL, INDENTIFIER, STRING, CHARACTER

    PLUSOP, MINUSOP, MULTOP, DIVOP, ASSIGN,
    EQUALS, NE, LTEQ, GTEQ, LT, GT, 
    PLUSEQUAL, MINUSEQUAL, MULTEQUAL, DIVEQUAL,
    CARAT, SEMICOLOR, COMMA, LPAREN, RPAREN,
    LBRACKET, RBRACKET, LBRACE, RBRACE, 
    LCOMMENT, RCOMMENT;
};

static const string TOKEN_TYPE_STRINGS[] =
{
    "PROGRAM", "BEGIN", "END", "REPEAT", "UNTIL", "WRITE", "WRITELN",
    "DIV", "MOD", "AND", "OR", "NOT", "CONST", "TYPE", "VAR", "PROCEDURE",
    "FUNCTION", "WHILE", "DO", "FOR", "TO", "DOWNTO", "IF", "THEN", "ELSE",
    "WHILE", "CASE", "OF",
    
    "INTEGER", "REAL", "INDENTIFIER", "STRING", "CHARACTER"

    "PLUSOP", "MINUSOP", "MULTOP", "DIVOP", "ASSIGN",
    "EQUALS", "NE", "LTEQ", "GTEQ", "LT", "GT", 
    "PLUSEQUAL", "MINUSEQUAL", "MULTEQUAL", "DIVEQUAL",
    "CARAT", "SEMICOLOR", "COMMA", "LPAREN", "RPAREN",
    "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", 
    "LCOMMENT", "RCOMMENT";
};

constexpr TokenType PROGRAM        = TokenType::PROGRAM;
constexpr TokenType BEGIN          = TokenType::BEGIN;
constexpr TokenType END            = TokenType::END;
constexpr TokenType REPEAT         = TokenType::REPEAT;
constexpr TokenType UNTIL          = TokenType::UNTIL;
constexpr TokenType WRITE          = TokenType::WRITE;
constexpr TokenType WRITELN        = TokenType::WRITELN;
constexpr TokenType DIV            = TokenType::DIV;
constexpr TokenType MOD            = TokenType::MOD;
constexpr TokenType AND            = TokenType::AND;
constexpr TokenType OR             = TokenType::OR;
constexpr TokenType NOT            = TokenType::NOT;
constexpr TokenType CONST          = TokenType::CONST;
constexpr TokenType TYPE           = TokenType::TYPE;
constexpr TokenType VAR            = TokenType::VAR;
constexpr TokenType PROCEDURE      = TokenType::PROCEDURE;
constexpr TokenType FUNCTION       = TokenType::FUNCTION;
constexpr TokenType WHILE          = TokenType::WHILE;
constexpr TokenType DO             = TokenType::DO;
constexpr TokenType FOR            = TokenType::FOR;
constexpr TokenType TO             = TokenType::TO;
constexpr TokenType DOWNTO         = TokenType::DOWNTO;
constexpr TokenType IF             = TokenType::IF;
constexpr TokenType THEN           = TokenType::THEN;
constexpr TokenType ELSE           = TokenType::ELSE;
constexpr TokenType WHILE          = TokenType::WHILE;
constexpr TokenType CASE           = TokenType::CASE;
constexpr TokenType OF             = TokenType::OF;
constexpr TokenType INTEGER        = TokenType::INTEGER;
constexpr TokenType REAL           = TokenType::REAL;
constexpr TokenType IDENTIFIER     = TokenType::IDENTIFIER;
constexpr TokenType STRING         = TokenType::STRING;
constexpr TokenType CHARACTER      = TokenType::CHARACTER;
constexpr TokenType PLUSOP         = TokenType::PLUSOP;
constexpr TokenType MINUSOP        = TokenType::MINUSOP;
constexpr TokenType MULTOP         = TokenType::MULTOP;
constexpr TokenType DIVOP          = TokenType::DIVOP;
constexpr TokenType ASSIGN         = TokenType::ASSIGN;
constexpr TokenType EQUALS         = TokenType::EQUALS;
constexpr TokenType NE             = TokenType::NE;
constexpr TokenType LTEQ           = TokenType::LTEQ;
constexpr TokenType GTEQ           = TokenType::GTEQ;
constexpr TokenType LT             = TokenType::LT;
constexpr TokenType GT             = TokenType::GT;
constexpr TokenType PLUSEQUAL      = TokenType::PLUSEQUAL;
constexpr TokenType MINUSEQUAL     = TokenType::MINUSEQUAL;
constexpr TokenType MULTEQUAL      = TokenType::MULTEQUAL;
constexpr TokenType DIVEQUAL       = TokenType::DIVEQUAL;
constexpr TokenType CARAT          = TokenType::CARAT;
constexpr TokenType SEMICOLOR      = TokenType::SEMICOLOR;
constexpr TokenType COMMA          = TokenType::COMMA;
constexpr TokenType LPAREN         = TokenType::LPAREN;
constexpr TokenType RPAREN         = TokenType::RPAREN;
constexpr TokenType LBRACKET       = TokenType::LBRACKET;
constexpr TokenType RBRACKET       = TokenType::RBRACKET;
constexpr TokenType LBRACE         = TokenType::LBRACE;
constexpr TokenType RBRACE         = TokenType::RBRACE;
constexpr TokenType LCOMMENT       = TokenType::LCOMMENT;
constexpr TokenType RCOMMENT       = TokenType::RCOMMENT;
constexpr TokenType END_OF_FILE    = TokenType::END_OF_FILE;
constexpr TokenType ERROR          = TokenType::ERROR; 

class Token
{
private:
    //table initialization
    static map<string, TokenType> reservedWords;

public:
    //staticmap
    static void initialize();

    TokenType type; 
    string text;   
    int lineNumber;  
    Object value;   

    //token first char
    Token(char firstChar) : type(ERROR), lineNumber(0), text("")
    {
        text += firstChar;
    }

    //word token constructor
    Token *Word(char firstChar, Source *source)
    {
        Token *token = new Token(firstChar);
        token->text = source->text();

        Token wordvalue[] = token.numvalue();
        for(int i = firstIndex; i <= lastIndex; i++)
        {
            token.add(wordvalue[i].text().toupper());
        }

        return token;
    }

    //num. token constructor and value
    Token *Number(char firstChar, Source *source)
    {
        Token *token = new Token(firstChar);
        token->text = source->text();

        Token numvalue[] = token.numvalue();
        for(int i = firstIndex; i <= lastIndex; i++)
        {
            token.add(numvalue[i].text().toupper())
        }

        return token;
    }

    // string token constructor and value
    Token *CharacterOrString(char firstChar, Source *source)
    {
        Token *token = new Token(firstChar);
        token->text = source->text();

        Token strvalue[] = token.strvalue();
        for(int i = firstIndex; i <= lastIndex; i++)
        {
            token.add(strvalue[i].text().toupper())
        }

        return token;
    }

    //spcl symbol token and val
    Token *SpecialSymbol(char firstChar, Source *source)
    {
        Token *token = new Token(firstChar);
        token->text = source->text();

        Token specialvalue[] = token.specialvalue();
        for(int i = firstIndex; i <= lastIndex; i++)
        {
            token.add(specialvalue[i].text().toupper())
        }
        return token;
    }
};
#endif /* TOKEN_H_ */