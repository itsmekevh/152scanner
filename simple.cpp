#include <string>
//#include <scanner.h>        //REMOVE Comments once files are completed
//#include <token.h>            //REMOVE Comments once files are completed

using namespace std;


void testScanner(Source *source);


int main (int argc, char *argv[]){
    if(argc != 3){
        cout << "Use: simple-{scan} sourceFileName" << endl;
        exit (-1);
    }

    Token::initialize();

    string operation = argv[1];
    string sourceFileName = argv[2];

    Source *source = new Source(sourceFileName);

    if(operation == "-scan"){
        testScanner(source);
    }
    return 0;
}

//testScanner
void testScanner(Source *source){
    cout << "Tokens: " << endl << endl;

    Scanner *scanner = new Scanner(source);         //creates scanner

    for(Token *token = scanner -> nextToken(); 
        token->type !=END_OF_FILE; 
        token = scanner->nextToken()){
        printf("%14s : %s\n", TOKEN_TYPE_STRINGS[(int) token->type].c_str(),
               token->text.c_str());
    }
}