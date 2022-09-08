#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Source
{
private:
    ifstream source;
    int  line;      
    string fileName;
    char currCh;

public:
    static const char endOfLine = '\n';
    Source(string sourceName) : line(1)
    {
        source.open(sourceName);

        if (source.fail())
        {
            cout << "The program was unable to open the source file." << sourceName << endl;
            exit(-1);
        }
        currCh = nextCh(); 
    }
    
    int numLine() const { return line; }
    char currCh() const { return currCh; } 
  
    char nextCh()
    {
        currCh = source.get();
        if (source.eof()) currCh = EOF;
        else if (currCh == endOfLine) line++;
        else if (source.fail())
        {
            cout << "Failed to read the source file." << fileName << endl;
            exit(-1);
        }
        return currCh;
    }
};
 
#endif /* SOURCE_H_ */