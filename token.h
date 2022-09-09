#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <map>
#include "Source.h"

namespace frontend {
using namespace std;
enum class TokenType
{
    PROGRAM, BEGIN, END, REPEAT, UNTIL, WRITE, WRITELN, DIV, MOD, AND, OR, NOT, CONST, TYPE, VAR, PROCEDURE, FUNCTION, 
    WHILE, DO, FOR, TO, DOWNTO, IF, THEN, ELSE, CASE, OF, PERIOD, COMMA, COLON, COLON_EQUALS, SEMICOLON, PLUS, 
    MINUS, STAR, SLASH, LPAREN, RPAREN, EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,GREATER_THAN, GREATER_EQUALS, 
    DOT_DOT, QUOTE, LBRACKET, RBRACKET, CARAT, IDENTIFIER, INTEGER, REAL, CHARACTER, STRING, END_OF_FILE, ERROR
};

static const string TOKEN_TYPE_STRINGS[] =
{
    "PROGRAM", "BEGIN", "END", "REPEAT", "UNTIL", "WRITE", "WRITELN", "DIV", "MOD", "AND", "OR", "NOT", "CONST", "TYPE", 
    "VAR", "PROCEDURE", "FUNCTION", "WHILE", "DO", "FOR", "TO", "DOWNTO", "IF", "THEN", "ELSE", "CASE", "OF", "PERIOD", 
    "COMMA", "COLON", "COLON_EQUALS", "SEMICOLON", "PLUS", "MINUS", "STAR", "SLASH", "LPAREN", "RPAREN", "EQUALS", "NOT_EQUALS", 
    "LESS_THAN", "LESS_EQUALS", "GREATER_THAN", "GREATER_EQUALS", "DOT_DOT", "QUOTE", "LBRACKET", "RBRACKET", "CARAT", "IDENTIFIER", 
    "INTEGER", "REAL", "CHARACTER", "STRING", "END_OF_FILE", "ERROR"
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
constexpr TokenType CASE           = TokenType::CASE;
constexpr TokenType OF             = TokenType::OF;
constexpr TokenType PERIOD         = TokenType::PERIOD;
constexpr TokenType COMMA          = TokenType::COMMA;
constexpr TokenType COLON          = TokenType::COLON;
constexpr TokenType COLON_EQUALS   = TokenType::COLON_EQUALS;
constexpr TokenType SEMICOLON      = TokenType::SEMICOLON;
constexpr TokenType PLUS           = TokenType::PLUS;
constexpr TokenType MINUS          = TokenType::MINUS;
constexpr TokenType STAR           = TokenType::STAR;
constexpr TokenType SLASH          = TokenType::SLASH;
constexpr TokenType LPAREN         = TokenType::LPAREN;
constexpr TokenType RPAREN         = TokenType::RPAREN;
constexpr TokenType EQUALS         = TokenType::EQUALS;
constexpr TokenType NOT_EQUALS     = TokenType::NOT_EQUALS;
constexpr TokenType LESS_THAN      = TokenType::LESS_THAN;
constexpr TokenType LESS_EQUALS    = TokenType::LESS_EQUALS;
constexpr TokenType GREATER_THAN   = TokenType::GREATER_THAN;
constexpr TokenType GREATER_EQUALS = TokenType::GREATER_EQUALS;
constexpr TokenType DOT_DOT        = TokenType::DOT_DOT;
constexpr TokenType QUOTE          = TokenType::QUOTE;
constexpr TokenType LBRACKET       = TokenType::LBRACKET;
constexpr TokenType RBRACKET       = TokenType::RBRACKET;
constexpr TokenType CARAT          = TokenType::CARAT;
constexpr TokenType IDENTIFIER     = TokenType::IDENTIFIER;
constexpr TokenType INTEGER        = TokenType::INTEGER;
constexpr TokenType REAL           = TokenType::REAL;
constexpr TokenType CHARACTER      = TokenType::CHARACTER;
constexpr TokenType STRING         = TokenType::STRING;
constexpr TokenType END_OF_FILE    = TokenType::END_OF_FILE;
constexpr TokenType ERROR          = TokenType::ERROR;

class Token
{
private:
    static map<string, TokenType> reservedWords;
public:

     //Static map.
    static void initialize();
    
    TokenType type;  // Type of token
    int lineNumber;  // Line number of token
    string text;     // Text of token
    Object value;    // Value of token
    
    Token(char firstChar) : type(ERROR), lineNumber(0), text("")
    {
        text += firstChar;
    }

    //Constructor for word token.
    static Token *Word(char firstChar, Source *source);

    //Constructor for number token and set its value.

    static Token *Number(char firstChar, Source *source);


    //Constructor for string token and set its value.

    static Token *CharacterOrString(char firstChar, Source *source);


    //Constructor for special symbol token and set its value.
    static Token *SpecialSymbol(char firstChar, Source *source);

    static void tokenError(Token *token, string message);
};

}

#endif /* TOKEN_H_ */
