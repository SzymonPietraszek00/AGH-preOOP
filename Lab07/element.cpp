#include "element.h"

Element::Element(const char *name){

    name_element = new char[strlen(name)+1];
    strcpy(name_element,name);
    next = nullptr;
}


Element::~Element(){

    std::cout << "Destruktor Element: " << name_element << std::endl;
    delete [] name_element;
    name_element = nullptr;
}

char* Element::getName(){

    return name_element;
}

void Element::printName(){

    std::cout << name_element;
}
