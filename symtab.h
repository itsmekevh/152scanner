#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>

#include "symtabEntry.h"

using namespace std;

class Symtab
{
private:
    map<string, SymtabEntry *> contents;

public:
    /**
     * Make an entry.
     * @param name the entry's name.
     */
    SymtabEntry *enter(string name)
    {
        SymtabEntry *entry = new SymtabEntry(name);
        contents[name] = entry;

        return entry;
    }

    /**
     * Look up an entry.
     * @param name the entry's name.
     * @return the entry or null if it's not in the symbol table.
     */
    SymtabEntry *lookup(string name)
    {
        return contents.find(name) != contents.end() ? contents[name]
                                                     : nullptr;
    }
};

#endif /* SYMTAB_H_ */
