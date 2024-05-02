/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */

#include "linkedlist.h"

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList L = LA; //new list is copies data values over from LA/L1
    Node* p = LB.front;//Node pointer created starting with front from LB/L2
    while(p != NULL){
        if (LA.search(p->val) < 0){//searches LA/L1 to make sure there are no duplicates
            L.addRear(p->val);//If the value is NOT a dublicate it is added to the end of the new list
            p = p->next;//move onto the next node in LB/L2
        }
      else
        p = p->next;//If the value IS a duplicate move onto the next node
    }

    return L;//when done return newly created list to main
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList L;//New empty list created
    Node* p1 = LA.front;//Node pointer created starting with front from LA/L1
    Node* p2 = LB.front;//Node pointer created starting with front from LB/L2
    while (p1 != NULL && p2 != NULL)//as long as both pointer are no emply, continue
    {
        if (p1->val <= p2->val) {//check if p1/LA value is smaller or equal to p2/LB value
            L.addRear(p1->val);//if smaller or same added to the new list
            p1 = p1->next;//move onto the next node in p1/LA
        }
        else {
            L.addRear(p2->val);//if P2/LB value is smaller it gets added to the new list
            p2 = p2->next;//move onto the next node in p2/LB
        }
        if (p2 == NULL) {//If p2/LB list is empty or reached the end...
            while (p1 != NULL) {//and p1/LA list is not empty or has more nodes...
                L.addRear(p1->val);//add values from p1/LA to new list
                p1 = p1->next;//move onto next node
            }
        }
        else if (p1 == NULL) {//If p1/LA list is empty or reached the end...
            while (p2 != NULL) {//and p2/LB list is not empty or has more nodes...
                L.addRear(p2->val);//add values from p2/LB to new list
                p2 = p2->next;//move onto next node
            }

        }
    }
    return L;//Return newly merged together list to main
}