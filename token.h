#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <map>

//file imports
namespace frontend {

using namespace std;

enum class TokenType
{

};

static const string TOKEN_TYPE_STRINGS[] =
{

};

constexpr TokenType PROGRAM        = TokenType::PROGRAM;
constexpr TokenType BEGIN          = TokenType::BEGIN;
constexpr TokenType END            = TokenType::END;
//include rest

class Token
{
private:
    /**
     * Initialize the table.
     */
    static map<string, TokenType> reservedWords;
public:
    /**
     * Initialize the static map.
     */
    static void initialize();

    TokenType type;  // what type of token
    int lineNumber;  // source line number of the token
    string text;     // text of the token
    Object value;    // the value (if any) of the token

    /**
     * Constructor.
     * @param firstChar the first character of the token.
     */
     Token(char firstChar) : type(ERROR), lineNumber(0), text("")
    {
        text += firstChar;
    }
    

    /**
     * Construct a word token.
     * @param firstChar the first character of the token.
     * @param source the input source.
     * @return the word token.
     */

    /**
     * Construct a number token and set its value.
     * @param firstChar the first character of the token.
     * @param source the input source.
     * @return the number token.
     */

    /**
     * Construct a string token and set its value.
     * @param firstChar the first character of the token.
     * @param source the input source.
     * @return the string token.
     */

    /**
     * Construct a special symbol token and set its value.
     * @param firstChar the first character of the token.
     * @param source the input source.
     * @return the special symbol token.
     */

};

}  // namespace frontend

#endif /* TOKEN_H_ */