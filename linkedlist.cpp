#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int data);
};

class LinkedList {
	public:
		Node *head;

		void appendNode(Node *node);
		void displayNodes();
		bool deleteNode(int data);
		void reverse();
		void rearrange();
		void displayNodesStartingFrom(Node *nodeHead);
};

Node::Node(int data) {
		this->data=data;
		this->next=NULL;
}

void LinkedList::appendNode(Node *node) {
	Node *temp=head;
	if(head == NULL) {
		head=node;
	} else {
		while(temp->next != NULL) {
			temp=temp->next;
		}
		temp->next=node;
	}
}

void LinkedList::displayNodes() {
	Node *temp=head;

	while(temp != NULL) {
		cout << temp->data << " " ;
		temp=temp->next;
	}
}

void LinkedList::displayNodesStartingFrom(Node *nodeHead) {
	Node *temp=nodeHead;

	while(temp != NULL) {
		cout << temp->data << " " ;
		temp=temp->next;
	}
}

bool LinkedList::deleteNode(int data) {
	Node *temp=head;
	Node *prev=NULL;
	while(temp->next != NULL) {
		if(temp->data == data) {
			if(prev != NULL) {
				prev->next=temp->next;
				free(temp);
			} else {
				head=temp->next;
				free(temp);
			}
		}
		prev=temp;
		temp=temp->next;
	}
	return true;
}

void LinkedList::reverse() {
	Node *cur=head;
	Node *nextNode=head->next;
	Node *prev=NULL;

	while(cur != NULL) {
		nextNode=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nextNode;
	}
	head=prev;
}

/**
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. 
Rearrange the nodes in the list so that the 
new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
**/
void LinkedList::rearrange() {
	Node *fast=head->next;
	Node *slow=head;
	Node *secHead=NULL;

	//Tortoise and hare method
	while(fast->next != NULL) {
		fast=fast->next->next;
		slow=slow->next;
	}

	cout << "Found the middle point" << slow->data << endl;

	//Split the halves
	secHead=slow->next;
	slow->next=NULL;

	//Reverse the second list
	Node *cur=secHead;
	Node *nextNode=secHead->next;
	Node *prev=NULL;
	while(cur != NULL) {
		nextNode=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nextNode;
	}
	secHead=prev;

	cout << "Reverse the second list" << endl;
	displayNodes();
	cout << "2nd::" << endl;
	displayNodesStartingFrom(secHead);
	//Merge by taking elements alternatively

	Node *tempHead=head;
	Node *firstHead=head->next;

	bool alternate=false;
	while(secHead != NULL && firstHead != NULL ) {
		if(!alternate) {
			tempHead->next=secHead;
			secHead=secHead->next;
			tempHead=tempHead->next;
			alternate=true;
		} else {
			tempHead->next=firstHead;
			firstHead=firstHead->next;
			tempHead=tempHead->next;
			alternate=false;
		}
	}

	if(!(secHead == NULL && firstHead == NULL)) {
		if(secHead == NULL) {
			tempHead->next=firstHead;
		} else {
			tempHead->next=secHead;
		}
	}
	cout << "After rearranging" << endl;
	displayNodes();
}

int main(int argc,char *argv[]) {
		
		LinkedList *ll1=new LinkedList();
		ll1->appendNode(new Node(23));
		ll1->appendNode(new Node(34));
		ll1->appendNode(new Node(45));
		ll1->appendNode(new Node(56));
		ll1->displayNodes();
		ll1->deleteNode(34);
		ll1->appendNode(new Node(67));
		ll1->appendNode(new Node(78));
		ll1->appendNode(new Node(89));
		ll1->appendNode(new Node(101));
		ll1->appendNode(new Node(133));
		ll1->displayNodes();
		cout << "After reversing.." << endl;
		ll1->reverse();
		ll1->displayNodes();
		ll1->rearrange();
		// ll1->displayNodes();
		return 1;
	}

