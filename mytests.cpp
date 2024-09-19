#include <iostream>
#include "DoublyLinkedList.hpp"
#include "DoublyLinkedList.cpp"

void testPrepend()
{
    List<int> list;
    // Adds values to the beginning of the list 
    list.prepend(10);
    list.prepend(20);
    list.prepend(30);

    cout << "List after prepend:" << list << endl; // Outputs a check for the new values contained in the list
}

void testAppend()
{
    List<int> list;
    // Adds values to the list
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "List after appending:" << list << endl; // Outputs a check for the new values contained in the list
}

void testInsert()
{
    List<int> list;
    // Adds values to the beginning of the list 
    list.append(10);
    list.append(20);
    cout << "List before inserting:" << list << endl; // Outputs a benchmark for the current values within the list

    list.insert(15, 1); // Insert 15 between 10 and 20
    cout << "List after inserting:" << list << endl; // Outputs a check for the new values contained in the list
}

void testRemove()
{
    List<int> list;
    // Adds values to the list
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List before removing:" << list << endl; // Outputs a benchmark for the current values within the list
    list.remove(1); // Remove element at index 1 (20)
    cout << "List after removing:" << list << endl; // Outputs a check for the new values contained in the list
}

void testSearch()
{
    List<int> list;
    // Adds values to the list
    list.append(10);
    list.append(20);
    list.append(30);

    cout << list.search(10) << endl; // is in the list
    cout << list.search(20) << endl; // is in the list
    cout << list.search(30) << endl; // is in the list
    cout << list.search(40) << endl; // 40 is not in the list
}

void testOperatorBrackets()
{
    List<int> list;
    // Adds values to the list
    list.append(10);
    list.append(20);
    list.append(30);

    // Output list values at 3 separate indexes
    cout << list[0] << endl;
    cout << list[1] << endl;
    cout << list[2] << endl;

    // Modify the value at index 1
    list[1] = 25;
    cout << "After modifying value at index 1:" << list[1] << endl;
}

void testLength()
{
    List<int> list;
    // Adds values to the list
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Length of the list: " << list.length() << endl; // Output a check for the list's length
}

void testEmpty()
{
    List<int> list;
    cout << "Is the list empty? " << list.empty() << endl; // Outputs a check for if the list is empty or not

    list.append(10);
    // Outputs a check for if the list is empty or not after adding a value
    cout << "Is the list empty after appending a value? " << list.empty() << endl; 
}

void testConcat()
{
    List<int> list1;
    // Adds values to the list 
    list1.append(10);
    list1.append(20);

    List<int> list2;
    // Adds values to the list 
    list2.append(30);
    list2.append(40);

    List<int> list3 = list1.concat(list2); // Create new list that combines list1 and list2

    cout << "Concated list: " << list3 << endl; // Output the newly created list
}

void testCopy()
{
    List<int> list1;
    // Adds values to the list
    list1.append(10);
    list1.append(20);

    List<int>list2(list1); // Copy values from list1 to list 2

    cout << "Copy list: " << list2 << endl; // Output the newly copied list
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
    testCopy();

    return 0;
}
