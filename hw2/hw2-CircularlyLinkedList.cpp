#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
	Node()
	{
		next = NULL;
		pre = NULL;
	}
	Node(int n)
	{
		data = n;
		next = NULL;
		pre = NULL;
	}
	int getData() { return data; }
	Node *getNext() { return next; }
	Node *getPre() { return pre; }
	void setData(int d) { data = d; }
	void setNext(Node *n) { next = n; }
	void setPre(Node *p) { pre = p; }

private:
	int data;
	Node *next, *pre; 
};

class CircularlyLinkedList {

	public:

		CircularlyLinkedList() { cursor = nullptr; }

		~CircularlyLinkedList() {
			while ( !Empty() ) {
				removeNode();
			}
			delete cursor;
		}

		bool Empty() {
			return( cursor == nullptr );
		}

		bool addFromHead( int d ) {

			Node* newNode = new Node(d);
			if( newNode == nullptr ) return false;

			if( cursor == nullptr ) { 
				cursor = newNode;
				cursor->setNext( cursor );

			} else {
				newNode->setNext( cursor->getNext() );
				cursor->setNext( newNode );
			}
			return true;
		}

		bool addFromTail(int d) {

			bool result = addFromHead(d);
			if (result) cursor = cursor->getNext();  
			return result;

		}

		void removeNode() {

			if (cursor == nullptr) throw invalid_argument("List is empty. Cannot remove from head.");

			Node* head = cursor->getNext();
			if (cursor == head) {
				delete cursor;
				cursor = nullptr;
			} else {
				cursor->setNext(head->getNext());
				delete head;
			}
			return;
		}

		void print() {

			if (cursor == nullptr) return;
			Node* temp = cursor->getNext();

			do {
				cout << temp->getData() << " ";
				temp = temp->getNext();
			} while ( temp != cursor->getNext() );
			cout << endl;

		}

		size_t countNodes() {
			if ( cursor == nullptr ) return 0;
			size_t count = 0;

			Node* temp = cursor->getNext();

			do {
				count++;
				temp = temp->getNext();
			} while ( temp != cursor->getNext() );
			return count;
		}

	private:
		Node* cursor;
};

int main() {

	try {

		CircularlyLinkedList *circularList = new CircularlyLinkedList();
		circularList->addFromHead(1);
		circularList->addFromHead(2);
		circularList->addFromTail(3);
		circularList->print();
		cout << "Circularly List Nodes number: " << circularList->countNodes() << endl;
		
		circularList->removeNode();
		circularList->removeNode();
		circularList->print();
		cout << "Circularly List Nodes number: " << circularList->countNodes() << endl;

		circularList->removeNode();
		circularList->print();
		cout << "Circularly List Nodes number: " << circularList->countNodes() << endl;
		circularList->removeNode();
		
	}
	catch ( invalid_argument &e ) {
		cout << "Exception: " << e.what() << endl;
	}

}
