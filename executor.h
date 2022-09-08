#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include <string>
#include <vector>
#include <set>

#include "object.h"
#include "symtab.h"
#include "node.h"

using namespace std;

class Executor
{
private:
    int lineNumber;

public:
    /**
     * Initialize the static sets.
     */
    static void initialize();

    Executor() : lineNumber(0) {}

    Object visit(Node *node);

private:
    static set<NodeType> singletons;   // singleton factors
    static set<NodeType> relationals;  // relational operators

    Object visitProgram(Node *programNode);
    Object visitStatement(Node *statementNode);
    Object visitCompound(Node *compoundNode);
    Object visitAssign(Node *assignNode);
    Object visitLoop(Node *loopNode);
    Object visitTest(Node *testNode);
    Object visitWrite(Node *writeNode);
    Object visitWriteln(Node *writelnNode);
    Object visitExpression(Node *expressionNode);
    Object visitVariable(Node *variableNode);
    Object visitIntegerConstant(Node *integerConstantNode);
    Object visitRealConstant(Node *realConstantNode);
    Object visitStringConstant(Node *stringConstantNode);

    void printValue(vector<Node *> children);
    void runtimeError(Node *node, string message);
};
#endif /* EXECUTOR_H_ */
