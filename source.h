#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <fstream>
#include <string>

namespace frontend {

using namespace std;

class Source
{
private:
    ifstream source;
    string sourceFileName;
    int  lineNum;      // current source line number
    char currentCh;    // current source character

public:
    static const char EOL = '\n';

    /**
     * Constructor
     * @param sourceFileName the source file name.
     */
    

    /**
     * Getter.
     * @return the current source line number.
     */

    /**
     * Getter.
     * @return the current source character.
     */

    /**
     * Read and return the next input source character.
     * @return the character, or EOF if at the end of the file.
     */

};

}  // namespace frontend

#endif /* SOURCE_H_ */