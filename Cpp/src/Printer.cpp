#include <iostream>
#include <string>

#include "Printer.h"

using namespace std;

void Printer::run(istream &in, ostream &prompt, ostream &output) {
    string name;
    prompt << "Enter your name:";
    in >> name;
    output << "Hello " + name + "!";
}