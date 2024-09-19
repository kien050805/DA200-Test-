#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <class T>
List<T>::List(void)
{
    \\ Create an empty list, setting the head and tail values as null pointers
    head = nullptr;
    tail = nullptr;
    size = 0;
};

template <class T>
List<T>::List(const T &list)
{
    \\ Create a new empty list
    head = nullptr;
    tail = nullptr;
    size = 0;

    \\ Iterate through the inputted list
    Node *current = list.head;
    while (current != nullptr)
    {
        \\ Add each item from inputted list to newly created list
        append(current->item);
        current = current->next;
    }
};

template <class T>
List<T>::~List(void)
{
    Node *current = head;
    while (head != nullptr)
    {
        \\ Iterate through the entire list and delete each index
        head = head->next;
        delete current;
        current = head;
    };
};

template <class T>
void List<T>::append(const T &item)
{
    \\ Add inputted item to final index of inputted list
    insert(item, size);
};

template <class T>
void List<T>::insert(const T &item, int index)
{
    \\ Test if the given index is invalid
    if (index < 0 || index > size)
    {
        throw out_of_range("Index out of range");
    }
    Node *temp = new Node;
    temp->item = item;

    \\ If list is empty, set the head and tail value to the inputted item and arranges list accordingly
    if (size == 0)
    {
        temp->next = nullptr;
        temp->prev = nullptr;

        head = temp;
        tail = temp;
    }
    \\ If inputted index is 0, sets the head to the inputted item and arranges list accordingly
    else if (index == 0)
    {
        temp->next = head;
        temp->prev = nullptr;
        head->prev = temp;
        head = temp;
    }
    \\ If inputted index is the last in the list, sets the tail to the inputted item and arranges list accordingly
    else if (index == size)
    {
        temp->next = nullptr;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        \\ Iterate through list until index is reached
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        };

        \\ Set current index to the inputted item and arrange list accordingly
        temp->next = current->next;
        temp->prev = current;
        current->next->prev = temp;
        current->next = temp;
    }
    size++;
};

template <typename T>
void List<T>::prepend(const T &item)
{
    \\ Inserts inputted item at the first index of the list
    insert(item, 0);
}

template <typename T>
void List<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range"); \\ Test if the given index is invalid
    }

    Node *current = head;

    if (index == 0)
    {
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // If the list becomes empty
        }
        delete current;
    }
    else
    {
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }

        current->prev->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev; // Update the tail if the last element is removed
        }
        delete current;
    }

    size--;
}

template <typename T>
int List<T>::search(const T &item) const
{
    Node *current = head;
    int index = 0;

    while (current != nullptr)
    {
        if (current->item == item)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Item not found
}

// Operator[] method
template <typename T>
T &List<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range");
    }

    Node *current = head;
    for (int i = 0; i < index; ++i)
    {
        current = current->next;
    }

    return current->item;
}

// Length method
template <typename T>
int List<T>::length() const
{
    return size;
}

// Empty method
template <typename T>
bool List<T>::empty() const
{
    return size == 0;
}

// Concatenation method
template <typename T>
List<T> List<T>::concat(const List<T> &list) const
{
    List<T> result;

    // Copy the elements from the first list (this)
    Node *current = head;
    while (current != nullptr)
    {
        result.append(current->item);
        current = current->next;
    }

    // Copy the elements from the second list (list)
    current = list.head;
    while (current != nullptr)
    {
        result.append(current->item);
        current = current->next;
    }

    return result;
}
