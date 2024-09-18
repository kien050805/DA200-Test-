#include <iostream>
#include "DoublyLinkedList.hpp"
#include "DoublyLinkedList.cpp"

void testPrepend() 
{
    List<int> list;
    list.prepend(10);
    list.prepend(20);
    list.prepend(30);

    cout << "List:" << list << endl;
}

void testAppend() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "List after appending:" << list << endl;
}

void testInsert() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    cout << "List before inserting:" << list << endl;
    
    list.insert(15, 1);  // Insert 15 between 10 and 20
    cout << "List after inserting:" << list << endl;
}

void testRemove() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List before removing:" << list << endl;
    list.remove(1);  // Remove element at index 1 (20)
    cout << "List after removing:" << list << endl;
}

void testSearch() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << list.search(10) << endl;
    cout << list.search(20) << endl;
    cout << list.search(30) << endl;
    cout << list.search(40) << endl;  // 40 is not in the list
}

void testOperatorBrackets() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << list[0] << endl;
    cout << list[1] << endl;
    cout << list[2] << endl;

    // Modify the value at index 1
    list[1] = 25;
    cout << "After modifying value at index 1:" <<list[1] << endl;
}

void testLength() 
{
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Length of the list: " << list.length() << endl;
}

void testEmpty() 
{
    List<int> list;
    cout << "Is the list empty? " << list.empty() << endl;

    list.append(10);
    cout << "Is the list empty after appending a value? " << list.empty() << endl;
}

void testConcat() 
{
    List<int> list1;
    list1.append(10);
    list1.append(20);

    List<int> list2;
    list2.append(30);
    list2.append(40);

    List<int> list3 = list1.concat(list2);

    cout << "Concated list: " << list3 << endl;

}

int main() 
{
    testPrepend();
    testAppend();
    testInsert();
    testRemove();
    testSearch();
    testOperatorBrackets();
    testLength();
    testEmpty();
    testConcat();

    return 0;
}
