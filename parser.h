#ifndef PARSER_H_
#define PARSER_H_

#include <set>

#include "scanner.h"
#include "token.h"
#include "symtab.h"
#include "node.h"

using namespace std;

class Parser
{
private:
    Scanner *scanner;
    Symtab *symtab;
    Token *currentToken;
    int lineNumber;
    int errorCount;

    static set<TokenType> statementStarters;          // what starts a statement
    static set<TokenType> statementFollowers;         // what follows a statement
    static set<TokenType> relationalOperators;        // relational operators
    static set<TokenType> simpleExpressionOperators;  // simple expression operators
    static set<TokenType> termOperators;              // term operators

public:
    /**
     * Initialize the static sets.
     */
    static void initialize();

    Parser(Scanner *scanner, Symtab *symtab)
        : scanner(scanner), symtab(symtab), currentToken(nullptr),
          lineNumber(1), errorCount(0) {}

    int getErrorCount() const { return errorCount; }

    Node *parseProgram();

private:
    Node *parseStatement();
    Node *parseAssignmentStatement();
    Node *parseCompoundStatement();
    Node *parseRepeatStatement();
    Node *parseWriteStatement();
    Node *parseWritelnStatement();
    Node *parseExpression();
    Node *parseSimpleExpression();
    Node *parseTerm();
    Node *parseFactor();
    Node *parseVariable();
    Node *parseIntegerConstant();
    Node *parseRealConstant();
    Node *parseStringConstant();

    void parseStatementList(Node *parentNode, TokenType terminalType);
    void parseWriteArguments(Node *node);

    void syntaxError(string message);
    void semanticError(string message);
};

#endif /* PARSER_H_ */
