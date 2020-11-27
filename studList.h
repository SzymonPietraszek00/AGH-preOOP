#pragma once
#include <iostream>
#include "element.h"
#include <cstring>

///This class represent element
class Element;


///This class represent list
class StudList{

friend class Element;

public:

    ///constructor
    StudList();

    ///destructor
    ~StudList();

   /**
    * @brief assign name of list
    * @param [const char*] nazwa listy
    */
    StudList(const char* );

  /**
    * @brief function print list
    */
    void print() const;

  /**
    * @brief function clear list
    */
    void clearList();

  /**
    * @brief check if the list is empty
    * @return true or false
    */
    bool isEmpty() const;

  /**
    * @brief create and add elements to list
    * @param [const char*] name of element
    */
    void prepend(const char*);
 
  /**
    * @brief add existing elements to list
    * @param [Element*] object of class Element added to list
    */
    void prepend(Element *);
 
  /**
    * @brief add existing elements to list
    * @return first element of list
    */
    Element* getHead() const;
 
  /**
    * @brief add existing elements to list
    * @return last element of list
    */
    Element* getTail() const;
 
  /**
    * @brief add existing elements to list
    * @return name of list
    */
    char* getName() const;
 
  /**
    * @brief delete last element from list
    * @return element which is deleted from list
    */
    Element* getLast();
  
  /**
    * @brief delete last element list and frees up memory
    */
    void removeLast();

private:
    char* name_list;  /** name of list **/
    Element *head;    /** head of list **/
    Element *tail;    /** tail of list **/


};
