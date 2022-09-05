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

public:
    /**
     * Initialize the static map.
     */
    

    /**
     * Constructor.
     * @param firstChar the first character of the token.
     */


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