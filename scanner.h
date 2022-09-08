#ifndef SCANNER_H_
#define SCANNER_H_

#include "source.h"     //REMOVE Comments once files are completed
#include "token.h"      //REMOVE Comments once files are completed

//namespace std; //frontend {            //mentioned in lecture(?)

using namespace std;

class Scanner
{
private:
    Source *source;

public:
    //input source
    Scanner(Source *source) : source(source){}
    
    //extracting next token from source
    Token *nextToken()
    {
        //Skip blanks, comments, whitespaces
        char ch = nextNonblankCharacter();

        if (isalpha(ch))      return Token::Word(ch, source);
        else if (isdigit(ch)) return Token::Number(ch, source);
        else if (ch == '\'')  return Token::CharacterOrString(ch, source);
        else                  return Token::SpecialSymbol(ch, source);
    }
    

private:
    //Skip blanks, comments, whitespaces, return the next nonblank char

    char nextNonblankCharacter()
    {
        char ch = source->currentChar();

        while ((ch == '{') || isspace(ch))
        {
            if (ch == '{')
            {
                // Consume comment chars
                while ((ch != '}') && (ch != EOF)) ch = source->nextChar();
            }
            //// consume character
            ch = source->nextChar();  
        }
        // nonblank character
        return ch;  
    }
};

//}  

#endif /* SCANNER_H_ */