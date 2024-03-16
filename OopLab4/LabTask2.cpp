#include <list>
#include <iostream>

using namespace std;

void printList(const list<int>& lst) {
    for (int n : lst) cout << n << " ";
    cout << endl;
}

// Sort Method
void customSort(list<int>& lst) {
    lst.sort(); // Using std::list's built-in sorting function
}

// Merge
list<int> mergeLists(const list<int>& lst1, const list<int>& lst2) {
    list<int> mergedList;
    auto iter1 = lst1.begin();
    auto iter2 = lst2.begin();

    while (iter1 != lst1.end() && iter2 != lst2.end()) {
        if (*iter1 < *iter2) {
            mergedList.push_back(*iter1);
            ++iter1;
        }
        else {
            mergedList.push_back(*iter2);
            ++iter2;
        }
    }

    // Apend values of List1
    while (iter1 != lst1.end()) {
        mergedList.push_back(*iter1);
        ++iter1;
    }

    // Apend values of List2
    while (iter2 != lst2.end()) {
        mergedList.push_back(*iter2);
        ++iter2;
    }

    return mergedList;
}

int main() {
    list<int> myList = { 5, 3, 1, 4, 2 };
    myList.push_back(6); 
    myList.push_front(0); 

    cout << "Original list: ";
    printList(myList);

    // Sort

    customSort(myList);
    cout << "Sorted list: ";
    printList(myList);

    // Merge

    list<int> list1 = { 1, 3, 5 };
    list<int> list2 = { 2, 4, 6 };

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    list<int> mergedList = mergeLists(list1, list2);
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
