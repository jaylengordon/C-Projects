// GordonLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Jaylen Gordon
//Programming Assignment #17
//Program Name : GordonLinkedList
//Short Program Description: Linked List
//July 12, 2020

#include<iostream>

using namespace std;

class LinkedList

{

private:

	

	struct ListNode

	{

		int value; 

		struct ListNode* next;

	};

	ListNode* head; 

public:



	LinkedList()

	{
		head = NULL;
	}

	~LinkedList();

	

	void appendNode(int);

	void insertNode(int);

	void insertNodeAt(int, int);

	void deleteNode(int);

	void Reverse();

	void deleteAt(int);

	int Search(int);

	void display() const;

};



void LinkedList::appendNode(int num)

{

	ListNode* newNode; 

	ListNode* nodePtr; 

	newNode = new ListNode;

	newNode->value = num;

	newNode->next = NULL;

	

	if (!head)

		head = newNode;

	else 

	{

		

		nodePtr = head;

		

		while (nodePtr->next)

			nodePtr = nodePtr->next;

		

		nodePtr->next = newNode;

	} 

	display();

} 





void LinkedList::display() const

{

	ListNode* nodePtr; 

	if (!head)

	{

		cout << "\n\tThe list is empty.";

		return;

	}

	

	nodePtr = head;

	cout << "\n\n\tThe elements in the list are:\n\t";

	

	while (nodePtr)

	{

		

		cout << nodePtr->value << " -> ";

		

		nodePtr = nodePtr->next;

	} 

	cout << "Null";

} // end function displayList.


void LinkedList::Reverse()

{

	ListNode* nodePtr;

	ListNode* next;

	ListNode* result = NULL;

	if (!head)

	{

		cout << "\n\tThe list is empty.";

		return;

	}

	

	nodePtr = head;

	while (nodePtr != NULL)

	{

		next = nodePtr->next;

		nodePtr->next = result;

		result = nodePtr;

		nodePtr = next;

	}

	head = result;

	display();

}





void LinkedList::insertNode(int num)

{

	ListNode* newNode;

	ListNode* nodePtr; 

	ListNode* previousNode = NULL; 

	// Al

	newNode = new ListNode;

	newNode->value = num;

	newNode->next = NULL;

	

	if (!head)

		head = newNode;

	else // Otherwise, insert newNode.

	{

		

		nodePtr = head;

		previousNode = NULL;

		

		while (nodePtr != NULL && nodePtr->value < num)

		{

			previousNode = nodePtr;

			nodePtr = nodePtr->next;

		}

	

		if (previousNode == NULL)

		{

			head = newNode;

			newNode->next = nodePtr;

		}

		else 

		{

			previousNode->next = newNode;

			newNode->next = nodePtr;

		}

	} // end else-if

	display();

} // end function insertNode.







void LinkedList::insertNodeAt(int num, int pos)

{

	ListNode* newNode;

	ListNode* nodePtr; // To traverse the list.

	ListNode* previousNode = NULL; // 

	int i = 0;

	

	newNode = new ListNode;

	newNode->value = num;

	newNode->next = NULL;

	

	nodePtr = head;

	if (pos == 0)//to inserted at first.

	{

		newNode->next = head;

		head = newNode;

	}

	else

	{

		while (nodePtr != NULL && i < pos) //loop to reach position.

		{

			previousNode = nodePtr;

			nodePtr = nodePtr->next;

			i++;

		}

		if (nodePtr == NULL)//position not found.

			cout << "Invalid Position :" << endl;

		else//inserts node.

		{

			newNode->next = nodePtr;

			previousNode->next = newNode;

		}

	}

	display();

}



// The deleteNode function searches for a node with num as its value.

//The node, if found, is deleted from the list and from memory.

void LinkedList::deleteNode(int num)

{

	ListNode* nodePtr; // To traverse the list.

	ListNode* previousNode;//To point to the previous node.

	// If the list is empty, do nothing.

	if (!head)

	{

		cout << "\n\tFailed to delete as list is empty.";

		return;

	}

	// Determine if the first node is the one.

	if (head->value == num)

	{

		nodePtr = head->next;

		delete head;

		head = nodePtr;

	}

	else

	{

		// Initialize nodePtr to head of list.

		nodePtr = head;

		// Skip all nodes whose value member is not equal to num.

		while (nodePtr != NULL && nodePtr->value != num)

		{

			previousNode = nodePtr;

			nodePtr = nodePtr->next;

		}

		// If nodePtr is not at the end of the list,

		// link the previous node to the node after nodePtr, then delete nodePtr.

		if (nodePtr)

		{

			previousNode->next = nodePtr->next;

			delete nodePtr;

		}

		else

			cout << "\n\tFailed to delete as " << num

			<< " not found in the list.";

	} // end else-if

	display();

} // end function deleteNode

void LinkedList::deleteAt(int pos)

{

	ListNode* nodePtr; // To traverse the list.

	ListNode* previousNode{};//To point to the previous node.

	int i = 0;

	// If the list is empty, do nothing.

	if (!head)

	{

		cout << "\n\tFailed to delete as list is empty.";

		return;

	}

	// Position nodePtr at the head of list.

	nodePtr = head;

	if (pos == 0)//to inserted at first.

	{

		nodePtr = head->next;

		delete head;

		head = nodePtr;

	}

	else

	{

		while (nodePtr != NULL && i < pos)//loop to reach position.

		{

			previousNode = nodePtr;

			nodePtr = nodePtr->next;

			i++;

		}

		if (nodePtr)

		{

			previousNode->next = nodePtr->next;

			delete nodePtr;

		}

		else

			cout << "\n\tFailed to delete position " << pos << " not found .";

	} // end else-if

	display();

} // end function deleteNode.





//Searches for value and returns position if found returns -1 if not found.

int LinkedList::Search(int value)

{

	ListNode* nodePtr; // To move through the list.

	int pos = -1;

	if (!head)

	{

		cout << "\n\tThe list is empty.\n";

		return-1;

	}

	// Position nodePtr at the head of the list.

	nodePtr = head;

	while (nodePtr)

	{

		pos++;

		if (nodePtr->value == value)

			return pos;

		else

			nodePtr = nodePtr->next;

	}

	return -1;

}




// Destructor

//This function deletes every node in the list.



LinkedList::~LinkedList()

{

	ListNode* nodePtr;

	ListNode* nextNode; 

	

	nodePtr = head;

	

	while (nodePtr != NULL)

	{

		

		nextNode = nodePtr->next;

		

		delete nodePtr;

		

		nodePtr = nextNode;

	} // end while

}

int main()

{

	

	LinkedList myList;
	char choice;
	int n;

	cout << "\n\n\tA program to demonstrate LinkedList class.";


	do {

		cout << "\n\t\tMENU\n ";

		cout << "\n\n\tAppend a node\t : L";

		cout << "\n\tInsert a node\t : I";

		cout << "\n\tInsert a node At : S";

		cout << "\n\tDelete a node\t : K";

		cout << "\n\tRemove node At\t : F";

		cout << "\n\tSearch a node\t : R";

		cout << "\n\tReverse nodes : V";

		cout << "\n\tQuit \t : E";

		

		cout << "\n\n\tEnter your choice: ";

		cin >> choice;

		

		switch (choice)

		{

		case 'A':

		case 'a':

			

			cout << "\tEnter an integer: ";

			cin >> n;

		

			myList.appendNode(n);

			break;

		case 'I':

		case 'i':

			

			cout << "\tEnter an integer: ";

			cin >> n;

			

			myList.insertNode(n);

			break;

		case 'D':

		case 'd':

			

			cout << "\tEnter an integer : ";

			cin >> n;

			

			myList.deleteNode(n);

			break;

		case 'R':

		case 'r': 

			myList.Reverse();

			break;

		case 'T':

		case 't': int pos;

			

			cout << "\tEnter element position to be deleted:";

			cin >> pos;

			myList.deleteAt(pos);

			break;

		case 'S':

		case 's': int position;

			

			cout << "Enter element to be searched:";

			cin >> n;

			

			position = myList.Search(n);

			if (position == -1)

				cout << "\tElement not found in the list" << endl;

			else

				cout << "\tElement found at:" << position << endl;

			break;

		case 'P':

		case 'p': int Loc;

	

			cout << "\tEnter an integer: ";

			cin >> n;

			

			cout << "\tEnter position to be inserted:";

			cin >> Loc;

			myList.insertNodeAt(n, Loc);

			break;

		case 'Q':

		case 'q':

			choice = 'q';

		} 

	} while (choice != 'q'); 

	return 0; 

} // end 



