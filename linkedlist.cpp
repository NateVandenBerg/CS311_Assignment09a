//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes


// ====================================================
//Your name: Nathaniel VandenBerg
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
  //Starting at the front destructor will go from each node 
  //and delete the information until pointer is NULL
  Node *p = front;  
  
  while (p != NULL)
    {
        Node *q = p->next;
        delete p;
		p = q;
    }
}

bool LinkedList::destroy(){
	Node *p = front;  
  
  while (p != NULL)
    {
        Node *q = p->next;
        delete p;
		p = q;
    }
    delete p;
	front = NULL;
    rear = NULL;
    return true; 
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if(front == NULL)
      return true;
    else
      return false;
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
  Node *p = front;
  int cnt = 0;  
  while(p != NULL)
    {
      cnt++;
      p = p->next;
    }
  return cnt;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

/*
addRear will take the passed value and add it to the end of the LinkedList.
If the list is empty it will add the value to the front and update the front
and rear pointers to point to the new Node. Otherwise, it will traverse the 
list until the next ponter is NULL and add the Node to the ende of the list. 
The previous Node next pointer will be updated to point to the new Node. Same
for the rear pointer. Node count is then increased by 1.
*/
void LinkedList::addRear(T val) {
  if(front == NULL)//If the list is empty it will add the value to the front 
    {               //and update the front and rear pointers to point to the new Node.
      Node *p = new Node(val);
      front = p;
      rear = p;
	  count++;
      return;
    }
  
	Node *p = new Node(val);
  Node* temp = front;
  
  while(temp->next != NULL)// traverse the list until the next pointer is NULL
    temp = temp->next;
  temp->next = p;//The previous Node next pointer will be updated to point to the new Node. add the Node to the ende of the list.
  rear = p;//Same for the rear pointer.
  count++;
  return;
}

/*
addFront will take the passed value and add it to the front of the LinkedList.
If the list is empty it will add the value to the front and update the front
and rear pointers to point to the new Node. Otherwise, the new Node's next pointer
will point to the previous front and update the front pointer to the new Node.
Node count is then increased by 1.
*/
void LinkedList::addFront(T val) {
    if(front == NULL)//If the list is empty it will add the value to the front and update the front and rear pointers to point to the new Node.
    {
      Node *p = new Node(val);
      front = p;
      rear = p;
	  count++;
      return;
    }
	Node *p = new Node(val);
  p->next = front;
  front = p;
  count++;
} 

/*
deleteFront will check if there is a list to delete. If front is NULL it will 
return false. Otherwise it will first update the front pointer to the next Node
then delete the original front node. If the list contains only one Node it will
also update the front and rear pointers to NULL. Node count is then reduced by 1.
*/
bool LinkedList::deleteFront(T &OldNum) {
  if (front == NULL) //check if there is a list to delete. If front is NULL it will return false.
    return false;
  Node* p = front;
  OldNum = front->val; //assign deleted value to OldNum
  front = front->next; //it will first update the front pointer to the next Node
  delete p; //delete the original front node
  p = NULL;
  count--;
  

  return (OldNum);//return the deleted value to the main
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

/*
deleteRear will check if there is a list to delete. If front is NULL it will 
return false. If there is only a list of 1 Node it will call deleteFront(); 
Otherwise it will traverse the list getting the previous node as well as the 
current nude until the current Node's next pointer is NULL. It will then delete
the current(Rear Node), update the rear pointer to point to the previous nude,
and update the new rear Node's next pointer to NULL. Node count is reduced by 1.
*/
bool LinkedList::deleteRear(T &OldNum) {
  
  if (front == NULL) //check if there is a list to delete. If front is NULL it will return false.
		return false;
  if (count == 1)
    {
		deleteFront(OldNum);//if there is only 1 node in the list it will call deleteFront
		return(OldNum);
	}
  
  
  Node* p = front;
  while(p->next->next != NULL)//traverse list to second to last node
      p = p->next;
  rear = p->next;//update rear pointer to the new last node
  OldNum = p->next->val;//assign the deleted value to OldNum
  
  delete p->next;//delete the last node
  p->next = NULL;
  count--;
  return (OldNum);////return the deleted value to the main
} 

/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
/*
deleteAt will check if there is a list to delete. If front is NULL it will 
return false. If the position passed to this function is outside the range of
count it will return false. If the pos is 1 Node it will call deleteFront(); If
the pos is the same as the count it will call deleteRear();. Otherwise it will 
traverse the list getting the previous node as well as the current nude until 
the current Node's next pointer is NULL. It will then delete the current(Rear Node),
update the rear pointer to point to the previous nude, and update the new rear 
Node's next pointer to NULL. Node count is reduced by 1.
*/
bool LinkedList::deleteAt(int pos, T &val) {
  if (front == NULL) //check if there is a list to delete. If front is NULL it will return false.
    return false;
  if ((pos >= count)||(pos < 0))//if the posistion sent to the function is outside it's range return false
    return false;
  if (pos == 0)
    {
	  deleteFront(val);//if pos is 0 deleteFront is called
	  return(val);
    }
  if (pos == count)
    {
	  deleteRear(val);//if pos is the same out the node count deleteRear is called
	  return(val);
    }
  
  Node* a = front;
  Node* b = a->next;
  Node* c = b->next;
  for (int i = 0; i < pos-1; i++)//traverse the list until pos is reached
    {
      a = a->next;//node before the TO BE delete node
      b = b->next;//TO BE deleted node
      c = c->next;//node AFTER deleted node
    }
  a->next = c;//previous node next pointer updated to the node after deleted node
  val = b->val;//assign val to deleted deleted node data

  delete b;

  count--;
    
  return val;//return deleted node data value
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value.
}

/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
  if ((pos > count+1)||(pos < 0))//check if Pos is beyond the range of the node
    return false;
  if (pos == 0)
    {
      addFront(val);//if Pos is 0 addFront is called
      return true;
    }
  if (pos == count)
    {
      addRear(val);//if pos is the same as the node count add rear is called
      return true;
    }
  
  Node* a = front;//node before new node
  for (int i = 0; i < pos; i++)//traverse node list until at pos-1. before current pos nose
      a = a->next;
  Node* b = new Node(val);//new node to be inserted
  Node* c = a->next;//update node
  a->next = b;//update so that previous node now point to new node
  b->next = c;//new node now point to next node
  
  count++;
    
  return true;
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    if(this == &other)//check if asked to create list to same mem address
        return;//if it does is will just return to main. nothing needs to be done
	// Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
	
	Node* node = other.front;//get first node data from old list 
      while(node != NULL)//travrese old list until it reaches the end
      {
        addRear(node->val);//call addRear to create new list. apply data to new list
        node = node->next;//get data from the next node in old list
      }
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
    
		count = 0;
	if(this != &other) { // check if the same object
      
        destroy();//clear out the list
		Node* node = other.front;//get front pointer from old list
      while(node!=NULL)
      {
        addRear(node->val);//call addRear to create new list. apply data to new list
        node = node->next;//get next pointer in old list
      }
    }
    return *this;//return new list
}

/**
 * Implement the search function.
 *
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
int LinkedList::search(const T& val) const {
    Node* ptr = front;//start search at the head or front
    int pos = 0;
    while (ptr != NULL) {
        if (ptr->val == val)//If the searched value is the same as the data in the node...
        {
            return pos;//the posistion of the value is returned to main
        }
        else
        ptr = ptr->next;//otherwise we move onto the next node
        pos++;//posistion is updated and process repeats
    }
    return -1;//if the value cannot be found -1 is returned indicating search could not find anything
}
