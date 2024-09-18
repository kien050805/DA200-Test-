#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <class T>
List<T>::List(void)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
};

template <class T>
List<T>::List(const T &list)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node<T>* current = list.head;
    while (current != nullptr) 
    {
        append(current->data);
        current = current->next;
    }
};

template <class T>
List<T>::~List(void)
{
    Node* current = head;
    while (head != nullptr)
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
        temp->next = nullptr;
        temp->prev = nullptr;

        head = temp;
        tail = temp;
    }
    else if (index == 0)
    {
        temp->next = head;
        temp->prev = nullptr;
        head->prev = temp;
        head = temp;
    }
    else if (index == size)
    {
        temp->next = nullptr;
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

template<typename T>
void List<T>::prepend(const T& item) 
{
    Node<T>* newNode = new Node<T>(item);
    if (empty()) 
    {
        head = newNode;
        tail = newNode;
    } else 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void List<T>::remove(int index) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;

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

template<typename T>
int List<T>::search(const T& item) const 
{
    Node<T>* current = head;
    int index = 0;

    while (current != nullptr) 
    {
        if (current->data == item) 
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Item not found
}

// Operator[] method
template<typename T>
T& List<T>::operator[](int index) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) 
    {
        current = current->next;
    }

    return current->data;
}

// Length method
template<typename T>
int List<T>::length() const 
{
    return size;
}

// Empty method
template<typename T>
bool List<T>::empty() const 
{
    return size == 0;
}

// Concatenation method
template<typename T>
List<T> List<T>::concat(const List<T>& list) const 
{
    List<T> result;

    // Copy the elements from the first list (this)
    Node<T>* current = head;
    while (current != nullptr) 
    {
        result.append(current->data);
        current = current->next;
    }

    // Copy the elements from the second list (list)
    current = list.head;
    while (current != nullptr)
    {
        result.append(current->data);
        current = current->next;
    }

    return result;
}
