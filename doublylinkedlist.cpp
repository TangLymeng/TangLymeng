//doublyLinked.cpp
//demonstrates doubly-linked list
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Link
{
public:
double dData; //data item
Link* pNext; //next link in list
Specialized Lists 197
10
FIGURE 10.6
Deleting an arbitrary
link.
first
current.prev
last
next
prev prev prev
next next
Null
Null
current current.next
❶
❷
INPUT
continues
13 72316331 Ch10 10/31/02 7:13 AM Page 197
LISTING 10.3 CONTINUED
Link* pPrevious; //previous link in list
public:
//-------------------------------------------------------------
Link(double dd) : //constructor
dData(dd), pNext(NULL), pPrevious(NULL)
{ }
//-------------------------------------------------------------
void displayLink() //display this link
{ cout << dData << “ “; }
//-------------------------------------------------------------
}; //end class Link
////////////////////////////////////////////////////////////////
class DoublyLinkedList
{
private:
Link* pFirst; //pointer to first item
Link* pLast; //pointer to last item
public:
//-------------------------------------------------------------
DoublyLinkedList() : //constructor
pFirst(NULL), pLast(NULL)
{ }
//-------------------------------------------------------------
~DoublyLinkedList() //destructor (deletes links)
{
Link* pCurrent = pFirst; //start at beginning of list
while(pCurrent != NULL) //until end of list,
{
Link* pOldCur = pCurrent; //save current link
pCurrent = pCurrent->pNext; //move to next link
delete pOldCur; //delete old current
}
}
//-------------------------------------------------------------
bool isEmpty() //true if no links
{ return pFirst==NULL; }
//-------------------------------------------------------------
void insertFirst(double dd) //insert at front of list
{
Link* pNewLink = new Link(dd); //make new link
if( isEmpty() ) //if empty list,
pLast = pNewLink; //newLink <-- last
else
pFirst->pPrevious = pNewLink; //newLink <-- old first
pNewLink->pNext = pFirst; //newLink --> old first
pFirst = pNewLink; //first --> newLink
}
198 Hour 10
13 72316331 Ch10 10/31/02 7:13 AM Page 198
TeamLRN
//-------------------------------------------------------------
void insertLast(double dd) //insert at end of list
{
Link* pNewLink = new Link(dd); //make new link
if( isEmpty() ) //if empty list,
pFirst = pNewLink; //first --> newLink
else
{
pLast->pNext = pNewLink; //old last --> newLink
pNewLink->pPrevious = pLast; //old last <-- newLink
}
pLast = pNewLink; //newLink <-- last
}
//-------------------------------------------------------------
void removeFirst() //remove first link
{ //(assumes non-empty list)
Link* pTemp = pFirst;
if(pFirst->pNext == NULL) //if only one item
pLast = NULL; //null <-- last
else
pFirst->pNext->pPrevious = NULL; //null <-- old next
pFirst = pFirst->pNext; //first --> old next
delete pTemp; //delete old first
}
//-------------------------------------------------------------
void removeLast() //remove last link
{ //(assumes non-empty list)
Link* pTemp = pLast;
if(pFirst->pNext == NULL) //if only one item
pFirst = NULL; //first --> null
else
pLast->pPrevious->pNext = NULL; //old previous --> null
pLast = pLast->pPrevious; //old previous <-- last
delete pTemp; //delete old last
}
//-------------------------------------------------------------
//insert dd just after key
bool insertAfter(double key, double dd)
{ //(assumes non-empty list)
Link* pCurrent = pFirst; //start at beginning
while(pCurrent->dData != key) //until match is found,
{
pCurrent = pCurrent->pNext; //move to next link
if(pCurrent == NULL)
return false; //didn’t find it
}
Link* pNewLink = new Link(dd); //make new link
if(pCurrent==pLast) //if last link,
{
Specialized Lists 199
10
continues
13 72316331 Ch10 10/31/02 7:13 AM Page 199
LISTING 10.3 CONTINUED
pNewLink->pNext = NULL; //newLink --> null
pLast = pNewLink; //newLink <-- last
}
else //not last link,
{ //newLink --> old next
pNewLink->pNext = pCurrent->pNext;
//newLink <-- old next
pCurrent->pNext->pPrevious = pNewLink;
}
pNewLink->pPrevious = pCurrent; //old current <-- newLink
pCurrent->pNext = pNewLink; //old current --> newLink
return true; //found it, did insertion
}
//-------------------------------------------------------------
bool removeKey(double key) //remove item w/ given key
{ //(assumes non-empty list)
Link* pCurrent = pFirst; //start at beginning
while(pCurrent->dData != key) //until match is found,
{
pCurrent = pCurrent->pNext; //move to next link
if(pCurrent == NULL)
return false; //didn’t find it
}
if(pCurrent==pFirst) //found it; first item?
pFirst = pCurrent->pNext; //first --> old next
else //not first
//old previous --> old next
pCurrent->pPrevious->pNext = pCurrent->pNext;
if(pCurrent==pLast) //last item?
pLast = pCurrent->pPrevious; //old previous <-- last
else //not last
//old previous <-- old next
pCurrent->pNext->pPrevious = pCurrent->pPrevious;
delete pCurrent; //delete item
return true; //successful deletion
}
//-------------------------------------------------------------
void displayForward()
{
cout << “List (first-->last): “;
Link* pCurrent = pFirst; //start at beginning
while(pCurrent != NULL) //until end of list,
{
pCurrent->displayLink(); //display data
pCurrent = pCurrent->pNext; //move to next link
}
cout << endl;
200 Hour 10
13 72316331 Ch10 10/31/02 7:13 AM Page 200
TeamLRN
}
//-------------------------------------------------------------
void displayBackward()
{
cout << “List (last-->first): “;
Link* pCurrent = pLast; //start at end
while(pCurrent != NULL) //until start of list,
{
pCurrent->displayLink(); //display data
pCurrent = pCurrent->pPrevious; //go to previous link
}
cout << endl;
}
//-------------------------------------------------------------
}; //end class DoublyLinkedList
////////////////////////////////////////////////////////////////
int main()
{
DoublyLinkedList theList; //make a new list
theList.insertFirst(22); //insert at front
theList.insertFirst(44);
theList.insertFirst(66);
theList.insertLast(11); //insert at rear
theList.insertLast(33);
theList.insertLast(55);
theList.displayForward(); //display list forward
theList.displayBackward(); //display list backward
cout << “Deleting first, last, and 11” << endl;
theList.removeFirst(); //remove first item
theList.removeLast(); //remove last item
theList.removeKey(11); //remove item with key 11
theList.displayForward(); //display list forward
cout << “Inserting 77 after 22, and 88 after 33” << endl;
theList.insertAfter(22, 77); //insert 77 after 22
theList.insertAfter(33, 88); //insert 88 after 33
theList.displayForward(); //display list forward
return 0;
} //end main()