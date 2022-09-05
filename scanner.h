#ifndef SCANNER_H_
#define SCANNER_H_

//#include "source.h"     //REMOVE Comments once files are completed
//#include "token.h"      //REMOVE Comments once files are completed

namespace frontend {

using namespace std;

class Scanner
{
private:
    Source *source;

public:
    /**
     * Constructor.
     * @param source the input source.
     */

    /**
     * Extract the next token from the source.
     * @return the token.
     */
    Token *nextToken()
    {
        // Skip blanks, comments, and other whitespace characters.

    }

private:
    /**
     * Skip blanks, comments, and other whitespace characters
     * and return the next nonblank character.
     * @return the next nonblank character.
     */
    
};

}  // namespace frontend

#endif /* SCANNER_H_ */
