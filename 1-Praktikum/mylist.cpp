#include "mylist.h"
#include "level.h"

#include <stdexcept>

MyList::MyList()
{

}

MyList::~MyList()
{
    while (head != nullptr)
    {
        pop_back();
    }
}

void MyList::push_back(Level* data)
{
    Element* tmp = new Element{data,nullptr,nullptr};

    // list is empty
    if (empty())
    {
        head = tmp;
        tail = tmp;
        m_size++;
        return;
    }

    tmp->previous = tail;
    tail->next = tmp;
    tail = tmp;
    m_size++;
}

void MyList::push_front(Level * data)
{
    Element* tmp = new Element{data,nullptr,nullptr};

    // list is empty
    if (empty())
    {
        head = tmp;
        tail = tmp;
        m_size++;
        return;
    }

    head->previous = tmp;
    tmp ->next = head;
    head = tmp;
    m_size++;

}

void MyList::pop_back()
{
    if(empty()) return;

    if (head->next == nullptr){
        delete head;
        head = nullptr;
        m_size--;
        return;
    }

    tail = tail->previous;
    delete tail->next;
    tail->next = nullptr;
    m_size--;

}

void MyList::pop_front()
{
    if(empty()) return;

    if (head->next == nullptr){
        delete head;
        head = nullptr;
        m_size--;
        return;
    }

    head = head->next;
    delete head->previous;
    head->previous = nullptr;
    m_size--;
}

bool MyList::empty()
{
    if (head == nullptr) return true;
    else return false;
}

size_t MyList::size()
{
 return m_size;
}

void MyList::remove(Level* eraseData)
{
    Element* current = head;
    while (current->next != nullptr){
        if(current->data == eraseData){
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current->data;
            current = nullptr;
            return;
        }
    }
}


MyList::iterator::iterator(MyList *list)
{
    currentList = list;
    currentLevel = nullptr;
}

MyList::iterator &MyList::iterator::operator++()
{
    if (*this == this->currentList->end()) throw std::runtime_error{"Invalid Iterator"};
    currentLevel = currentLevel->next;
    return *this;
}

MyList::iterator &MyList::iterator::operator--()
{
    if (*this == this->currentList->end()) throw std::runtime_error{"Invalid Iterator"};
    if (currentLevel == currentList->head) throw std::runtime_error{"Iterator out of List"};
    currentLevel = currentLevel->previous;
    return *this;

}

Level *&MyList::iterator::operator*()
{
    if (*this == this->currentList->end()) throw std::runtime_error{"Invalid Iterator"};
    return currentLevel->data;
}

bool MyList::iterator::operator==(const iterator &rhs)
{
    if (this->currentList == rhs.currentList && this->currentLevel == rhs.currentLevel) return true;
    else return false;
}

bool MyList::iterator::operator!=(const iterator & rhs)
{
    if (this->currentList == rhs.currentList && this->currentLevel == rhs.currentLevel) return false;
    else return true;
}

MyList::iterator MyList::begin()
{
    iterator it = iterator(this);
    it.currentLevel = it.currentList->head;
    return it;
}

MyList::iterator MyList::end()
{
    iterator it = iterator(this);
    return it;
}





