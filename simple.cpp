#include <string>
#include <scanner.h>        
#include <token.h> 

#include "source.h"
#include "scanner.h"
#include "parser.h"
#include "token.h"
#include "parserTreePrinter.h"
#include "executor.h"

using namespace std;

void testScanner(Source *source);
void testParser(Scanner *scanner, Symtab *symtab);
void executeProgram(Parser *parser, Symtab *symtab);

int main (int argc, char *argv[]){
    if(argc != 3){
        cout << "Use: simple-{scan, parse, execute} fileName" << endl;
        exit (-1);
    }

    Token::initialize();
    Parser::initialize();
    Executor::initialize();

    string operation = argv[1];
    string fileName = argv[2];

    Source *source = new Source(fileName);

    if(operation == "-scan"){
        testScanner(source);
    }
    else if (operation == "-parse")
    {
        testParser(new Scanner(source), new Symtab());
    }
    else if (operation == "-execute")
    {
        Symtab *symtab = new Symtab();
        executeProgram(new Parser(new Scanner(source), symtab), symtab);
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

void testParser(Scanner *scanner, Symtab *symtab)
{
    Parser *parser = new Parser(scanner, symtab);  // create the parser
    Node *programNode = parser->parseProgram();    // and parse the program
    int errorCount = parser->getErrorCount();

    if (errorCount == 0)
    {
        cout << "Parse tree:" << endl << endl;

        ParseTreePrinter *printer = new ParseTreePrinter();
        printer->print(programNode);
    }
    else
    {
        cout << endl << "There were " << errorCount << " errors." << endl;
    }
}

void executeProgram(Parser *parser, Symtab *symtab)
{
    Node *programNode = parser->parseProgram();
    int errorCount = parser->getErrorCount();

    if (errorCount == 0)
    {
        Executor *executor = new Executor();
        executor->visit(programNode);
    }
    else
    {
        cout << endl << "There were " << errorCount << " errors." << endl;
    }
}