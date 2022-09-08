#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>

using namespace std;

class SymtabEntry
{
private:
    string name;
    double value;

public:
    /**
     * Constructor.
     * @param name the entry's name.
     */
    SymtabEntry(string name) : name(name), value(0.0) {}

    /**
     * Getter.
     * @return the entry's name.
     */
    string getName()  const { return name;  }

    /**
     * Getter.
     * @return the entry's valuel
     */
    double getValue() const { return value; }

    /**
     * Set the entry's value.
     * @param value the value to set.
     */
    void setValue(const double value) { this->value = value; }
};
#endif /* SYMTABENTRY_H_ */
