#include <string>
#include <scanner.h>        
#include <token.h> 

#include "source.h"
#include "scanner.h"
#include "token.h"
using namespace std;

void testScanner(Source *source);

int main (int argc, char *argv[]){
    if(argc != 3){
        cout << "Use: simple-{scan, parse, execute} fileName" << endl;
        exit (-1);
    }

    Token::initialize();
    string operation = argv[1];
    string fileName = argv[2];

    Source *source = new Source(fileName);

    if(operation == "-scan"){
        testScanner(source);
    }
    return 0;
}

void testScanner(Source *source){
    cout << "Tokens: " << endl << endl;

    Scanner *scanner = new Scanner(source); 

    for(Token *token = scanner -> nextToken(); 
        token->type !=END_OF_FILE; 
        token = scanner->nextToken()){
        printf("%14s : %s\n", TOKEN_TYPE_STRINGS[(int) token->type].c_str(),
               token->text.c_str());
    }
}
