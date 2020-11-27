#pragma once
#include <iostream>
#include "studList.h"

///This class represent list
class StudList;

///This class represent Element from list
class Element{

friend class StudList;

public:

  ///destructor
    ~Element();

  /**
    * @brief assign name of elements
    * @param [const char*] name of element
    */
    Element(const char *);

  /**
    * @brief getting name of element
    * @return name of element
    */
    char* getName();

  /**
    * @brief printing name of element
    */
    void printName();

private:

    char* name_element; /** name of element in list **/
    Element *next;      /** next element of list **/

};
