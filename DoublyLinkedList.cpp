#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <class T>
List<T>::List(void)
{
    head = NULL;
    tail = NULL;
    size = 0;
};

template <class T>
List<T>::~List(void)
{
    Node* current = head;
    while (head != NULL)
    {
        head = head->next;
        delete current;
        current = head;
    };
};

template <class T>
void List<T>::append(const T &item)
{
    insert(item, size);
};

template <class T>
void List<T>::insert(const T &item, int index)
{
    Node *temp = new Node;
    temp->item = item;

    if (size == 0)
    {
        temp->next = NULL;
        temp->prev = NULL;

        head = temp;
        tail = temp;
    }
    else if (index == 0)
    {
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    else if (index == size)
    {
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        };

        temp->next = current->next;
        temp->prev = current;
        current->next->prev = temp;
        current->next = temp;
    }
    size++;
};