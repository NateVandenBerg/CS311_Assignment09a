/**
 * @brief You will implement the insertion sort and merge sort algorithms for a linked list in this file
 */

#include "sorting.h"
#include "linkedlist.h"
#include <iostream>

Node* sortingInsert(Node** newNode, Node* sorted) {
    if (newNode == NULL) {
        return sorted;
    }
    //cout << "test 3, ";//bug testing
    Node* nodeNew = *newNode;

    if (sorted == NULL || sorted->val >= nodeNew->val) {
        nodeNew->next = sorted;
        sorted = nodeNew;

        //cout << "test 4, ";//bug testing

        return sorted;
    }
    else {
        Node* currNode = sorted;
        //cout << "test 6, ";//bug testing

        while (currNode->next != NULL && currNode->next->val < nodeNew->val) {
            currNode = currNode->next;
        }
        nodeNew->next = currNode->next;
        currNode->next = nodeNew;
        *newNode = nodeNew;
    }
    return sorted;
}

void insertionSort(Node** frontNode) {
    Node* sorted = NULL;
    Node* currNode = *frontNode;

    /*Node* x = currNode;//bug testing
    cout << "\ninsertion pre:";
    while (x != NULL) {
        cout << " " << x->val;
        x = x->next;
    }
    cout << "\ntest 3\n";*/

    while (currNode != NULL) {
        //cout << "\ntest 1, ";//bug testing
        Node* next = currNode->next;
        //cout << "test 2 ";//bug testing

        sorted = sortingInsert(&currNode, sorted);
        //cout << "test 5";//bug testing
        currNode = next;        
    }
    *frontNode = sorted;
}
    
/*
 * Implement the insertion sort algorithm for Linkedlist correctly
 */
LinkedList insertionSortLL(const LinkedList& listA, bool reversed) {
    LinkedList listReturn = listA;//copy of original list
    Node* head = listReturn.front;
    
    insertionSort(&head);

    listReturn.front = head;
    if (reversed == true) {
        Node* curr = listReturn.front;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr != NULL ) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        listReturn.front = prev;
    }
    
    /*Node* y = listReturn.front;//bug testing
    cout << "\ninsertion finished: ";
    while (y->next != NULL) {
        cout << " " << y->val;
        y = y->next;
    }*/
    
    return listReturn;
}
/*
* This function takes 2 node pointers p & q. 
* p represents the front for the left half of a LL
* q represents the front for the right half of a LL
* The function compares which value(->val) in the nodes is smaller. 
* The smaller one is set as the front. 
* Then moves onto the next node and repeats the process until both NODES are empty (x->next == NULL)
*/
Node* sortMergeLinkedList(Node* p, Node* q) {//always sort LL in ascending order
    Node* result = NULL;//node pointer created
    if (p == NULL) {
        return (q);//if p is empty node pointer q is returned 
    }
    else if (q == NULL) {
        return (p); //if q is empty node pointer q is returned 
    }

    if (p->val <= q->val) { //if p->val is smaller node pointer "result" is updated to be p
        result = p;
        result->next = sortMergeLinkedList(p->next, q);//result->next is updated as a recursive function by sending p->next pointer and q pointer
    }
    else { //if p->val is larger node pointer "result" is updated to be q
        result = q;
        result->next = sortMergeLinkedList(p, q->next);//result->next is updated ad a recursive function by sending q->next pointer and p pointer
    }
    return (result);//fine merge sort is sent back as "result"
}

void LLSplit(Node* list, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    slow = list;
    fast = list->next;

    while (fast != NULL) {
        fast = fast->next ;//move "fast" 1 node here
        if (fast != NULL) {
            slow = slow->next;//"slow" is moved only 1 node per 2 "fast" nodes
            fast = fast->next;//move "fast" a second node here
        }
    }
    *front = list;//represents front half of left half LL
    *back = slow->next;//represents front node for right half of LL
    slow->next = NULL;    
}

void mergeSort(Node** frontNode) {
    Node* listFront = *frontNode;//represents front pointer of LL
    Node* p;
    Node* q;     

    if (listFront->next == NULL) {
        return;
    }

    LLSplit(listFront, &p, &q);//front pointer sent to be split. 
    //p will represent front of left half, q will be right half

    mergeSort(&p);//p front LL is recursively sent to this function
    mergeSort(&q);//q front LL is recursively sent to this function

    *frontNode = sortMergeLinkedList(p, q);//p & q LL are sorted via sortMergeLinkedList and update frontNode 
}
/*
* mergeSortLL is called by main() by sending a LL and a bool to determine if LL should be reversed. 
* cannot use original LL as it is used in main() to show original LL order
* instead, this function makes a copy of original list and sends new LL front pointer to mergeSort()
* 
*/
 LinkedList mergeSortLL(const LinkedList& list, bool reversed) {
     LinkedList listReturn = list;//copy of original list
     Node* head = listReturn.front;//node pointer copy of new LL front/head

     mergeSort(&head);//front/head node pointer sent to mergeSort()

     listReturn.front = head;//update LL front to new head node

    if (reversed == true) {//if bool "reversed" is true the node->next pointers are updated to point to previous node
        Node* curr = listReturn.front;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        listReturn.front = prev;
    }

    return listReturn;//new sorted list is sent back
 }
