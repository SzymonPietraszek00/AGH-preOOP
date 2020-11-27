#include "studList.h"

StudList::StudList(const char* name_of_list){

    name_list = new char[strlen(name_of_list)+1];
    strcpy(name_list,name_of_list);
    head = tail = nullptr;

}

StudList::~StudList(){
    
    std::cout << "Destruktor StudList: " << name_list << std::endl;
    head = tail = nullptr;
    delete [] name_list;
    name_list = nullptr;
}

bool StudList::isEmpty() const{
    return (head == nullptr && tail == nullptr) ? 1 : 0;
}


void StudList::prepend(const char* name){

    if(*name){

        Element *temp = new Element((char*)name);
      
        prepend(temp);
    }

}

void StudList::prepend(Element *temp){

    if(isEmpty()){
        head = tail = temp;
    }else{
        temp->next = head;
         head = temp;
    }

}


void StudList::print() const{


    if(name_list != nullptr){
         Element *temp = head;
         std::cout << name_list << " = ";

        std::cout << "[ ";
    while(temp != NULL){

        std::cout << temp->name_element << " ";

        temp = temp->next;
        }
        std::cout << "]" << std::endl;
    }
}

Element* StudList::getHead() const{

    return head;

}

Element* StudList::getTail() const{

    return tail;

}

char* StudList::getName() const{
    return name_list;
}


Element* StudList::getLast(){


 Element *wsk = tail;

    if(head == tail){
       
        head = tail = nullptr;
      
    }else{

        Element *wsk1 = head;
        
        while(wsk1->next != tail){
          wsk1 = wsk1->next;
        }

        wsk1->next = nullptr;
        tail = wsk1;
        
    } 
  
  return wsk;
  
}


void StudList::removeLast(){

  if(head){
      if(tail == head){

          delete tail;
          head = tail = nullptr;

      }else{
        
          Element *wsk = head;
          while(wsk->next != tail){
            wsk = wsk->next;
          }
          delete tail;
          wsk->next = nullptr;
          tail = wsk;

      }
  }

}

void StudList::clearList(){

    if(!isEmpty()){

      while(head){
          removeLast();
      }
    }
}
