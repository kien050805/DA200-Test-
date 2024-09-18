#include <iostream>


using namespace std;

#ifndef LIST_HPP
#define LIST_HPP

template <class T>
class List
{
private:
    struct Node
    {
        T item;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;
    int size;

public:
    List(void);
    ~List(void);

    void append(const T &item);
    void insert(const T &item, int index);
    
    friend ostream &operator<<(ostream &os, List<T> &list)
    {
        Node *ptr = list.head;
        while (ptr != NULL)
        {
            if (ptr->next != NULL)
                os << ptr->item << " ";
            else
                os << ptr->item;
            ptr = ptr->next;
        };
        return os;
    };
};


#endif