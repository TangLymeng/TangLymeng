#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Link{
public:
    Link();
    int intiData;        // data item
    Link* pNext;        // next link in list
    Link* pPrevious;    // previous link in list
};
//=================================================================================================================================================================================================
Link::Link() {
    intiData = -1;
    pNext = nullptr;
    pPrevious = nullptr;
}
// end class link
//=================================================================================================================================================================================================
class DoublyLinkedList{
private:
    Link* pFirst;       // pointer to first item
    Link* pLast;        // pointer to last item
public:
    int Size();                                     // Return number of links in the linked list
    void InsertFirst(int Data);                     // Create a new link with Data, and insert it to the first
    void InsertInThePosition(int Data, int Pos);    // Create a new link with Data, and insert it to the position Pos
    void InsertTail(int Data);                     // Create new link with Data, and insert the new list the tail of list
    void RemoveFirst();                             // Remove the first link from linked list
    void RemoveLinkInPosition(int Pos);             // Remove a link in the position Pos
    void RemoveTail();                              // Remove a link at the tail of list
    bool IsEmpty();                                 // Return true if the list is empty, else false
    DoublyLinkedList();
};      // end of class DoublyLinkedList
//=================================================================================================================================================================================================
DoublyLinkedList::DoublyLinkedList() {      // constructor
    pFirst = nullptr;
    pLast = nullptr;
}
//=================================================================================================================================================================================================
int DoublyLinkedList::Size() {      // display size of list
    int count = 0;
    Link* pCurrent = pFirst;
    while (pCurrent != nullptr){
        pCurrent = pCurrent->pNext;
        count++;
    }
    return count;
}
//=================================================================================================================================================================================================
bool DoublyLinkedList::IsEmpty() {
    if (pFirst == nullptr)
        return true;
    else
        return false;
}
//=================================================================================================================================================================================================
void DoublyLinkedList::InsertFirst(int Data) {      // insert at front of list
    Link* pNewLink = new Link;
    pNewLink -> intiData = Data;
    if ( IsEmpty() ){
        pLast = pNewLink;
    }
    else
        pFirst -> pPrevious = pNewLink;
    pNewLink -> pNext = pFirst;
    pFirst = pNewLink;
}
//=================================================================================================================================================================================================
void DoublyLinkedList::InsertInThePosition(int Data, int Pos) {

    Link* pNewLink = new Link;
    pNewLink -> intiData = Data;
    pNewLink -> pNext = nullptr;
    pNewLink -> pPrevious = nullptr;

    if ( Pos < 1 || Pos > Size() +1 ){
        cout << "Invalid position" << endl;
        return;
    }
    else if (Pos == 1) {        // insert at the front of linked list
        InsertFirst(Data);
    }
    else if (Pos == Size() + 1 ){       // insert at the tail of linked list
        InsertTail(Data);
    }
    else {
        Link* pCurrent = pFirst;
        int i = 1;
        while ( i < Pos - 1){
            pCurrent = pCurrent -> pNext;
            i++;
        }
        pNewLink -> pNext = pCurrent -> pNext;
        pCurrent -> pNext -> pPrevious = pNewLink;
        pNewLink -> pPrevious = pCurrent;
        pCurrent -> pNext = pNewLink;
    }
}
//=================================================================================================================================================================================================
void DoublyLinkedList::InsertTail(int Data) {
    Link* pNewLink = new Link;
    pNewLink -> intiData = Data;
    if ( IsEmpty() )
        pFirst = pNewLink;
    else {
        pLast->pNext = pNewLink;
        pNewLink->pPrevious = pLast;
    }
    pLast = pNewLink;
}
//=================================================================================================================================================================================================
void DoublyLinkedList::RemoveFirst() {
    Link* pTemp = pFirst;
    if(pFirst->pNext == nullptr) {      // if only one item
        pLast = nullptr;
    }
    else {          // if more than one item
        pFirst->pNext->pPrevious = nullptr;
    }
    pFirst = pFirst->pNext;
    delete pTemp;
}
//=================================================================================================================================================================================================
void DoublyLinkedList::RemoveTail() {
    Link* pTemp = pLast;
    if(pFirst->pNext == nullptr) {      // if only one item
        pFirst = nullptr;
    }
    else {      // if more than one item
        pLast->pPrevious->pNext = nullptr;
    }
    pLast = pLast->pPrevious;
    delete pTemp;
}
//=================================================================================================================================================================================================
void DoublyLinkedList::RemoveLinkInPosition(int Pos) {

    Link *pNewLink = new Link;
    pNewLink->pNext = nullptr;
    pNewLink->pPrevious = nullptr;

    if (Pos < 1 || Pos > Size() ) {
        cout << "Invalid position" << endl;
        return;
    } else if (Pos == 1) {        // remove the front link of linked list
        RemoveFirst();
    } else if (Pos == Size() ) {       // remove the tail link of linked list
        RemoveTail();
    } else {
        Link *pCurrent = pFirst;
        int i = 1;
        while (i < Pos - 1) {
            pCurrent = pCurrent->pNext;
            i++;
        }
        pCurrent -> pPrevious -> pNext = pCurrent -> pNext;
        pCurrent -> pNext -> pPrevious = pCurrent -> pPrevious;
    }
}
//=================================================================================================================================================================================================
int main() {
    DoublyLinkedList myList;

    myList.InsertFirst(90);
    myList.InsertInThePosition(83,2);
    myList.InsertTail(72);
    myList.RemoveLinkInPosition(1);

    cout<<myList.Size()<<endl;

    return 0;

}
