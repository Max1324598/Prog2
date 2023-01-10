#ifndef MYLIST_H
#define MYLIST_H

#include <cstddef>

class Level;

using size_t = std::size_t;

class MyList
{
private:

    struct Element
    {
        Level* data;
        Element* next;
        Element* previous;
    };
    Element* head = nullptr;
    Element* tail = nullptr;
    std::size_t m_size = 0;

    class iterator{
       friend class MyList;
    public:
        explicit iterator(MyList* list);
        ~iterator() = default;

        iterator& operator++();
        iterator& operator--();
        Level*& operator*();
        bool operator==(const iterator&);
        bool operator!=(const iterator&);



    private:
        Element* currentLevel;
        MyList* currentList;


    };
public:
    MyList();
    ~MyList();
    void push_back(Level*);
    void push_front(Level*);
    void pop_back();
    void pop_front();
    bool empty();
    size_t size();
    void remove(Level*);
    iterator begin();
    iterator end() ;



};
#endif // MYLIST_H
