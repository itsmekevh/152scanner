#include <string>
#include <map>
#include <ctype.h>

#include "token.h"

namespace frontend {

using namespace std;

map<string, TokenType> Token::reservedWords;

void Token::initialize()
{
    reservedWords["PROGRAM"]   = PROGRAM;
    reservedWords["BEGIN"]     = BEGIN;
    reservedWords["END"]       = END;
    //include rest
}

Token *Token::Word(char firstChar, Source *source)
{
    

    // Loop to get the rest of the characters of the word token.
    // Append letters and digits to the token.
    

    // check is reserved word or an identifier
}

Token *Token::Number(char firstChar, Source *source)
{
    

    // Loop to get the rest of the characters of the number token.
    // Append digits to the token.
    

    // Integer constant


    // Real constant.


    return token;
}

Token *Token::CharacterOrString(char firstChar, Source *source)
{
    

    // Loop to append the rest of the characters of the string,
    // up to but not including the closing quote.
   
        // Append characters to the string until ' or EOF.
        

        // End of file. An unclosed string.
       

        // Got a ' so it can be the closing ', or a ''
        
    } 

    // It's a character token if the string length is 1.
    // Otherwise, it's a string token.
    
    // Don't include the leading and trailing '.

    return token;
}

Token *Token::SpecialSymbol(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    switch (firstChar)
    {
        case ',' : token->type = TokenType::COMMA ;     break;
        case ';' : token->type = TokenType::SEMICOLON;  break;
        //include rest

       
    }

 
}

void Token::tokenError(Token *token, string message)
{
    printf("TOKEN ERROR at line %d: %s at '%s'\n",
           token->lineNumber, message.c_str(), token->text.c_str());
}

}  // namespace frontend