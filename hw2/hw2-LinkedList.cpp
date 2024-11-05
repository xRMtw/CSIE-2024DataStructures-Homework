#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
	Node()
	{
		next = NULL;
	}
	Node(int n)
	{
		data = n;
		next = NULL;
	}
	int getData() { return data; }
	Node *getNext() { return next; }
	void setData(int d) { data = d; }
	void setNext(Node *n) { next = n; }

private:
	int data;
	Node *next; 
};

class List {
	
	public:

		List() { head = nullptr; }

		~List () {
			while ( removeFromTail() ) {}
			delete head;
		}

		bool addFromHead ( int d ) {

			Node *newNode = new Node( d );

			if ( newNode == nullptr ) return false;

			newNode->setNext( head );
			head = newNode;
			
			return true;
			
		}

		bool addFromTail ( int d ) {

			Node *newNode = new Node( d );

			if ( newNode == nullptr ) return false;

			if ( head == nullptr ) {
				head = newNode;
				return true;
			}

			Node *temp = head;
			for ( temp ; temp->getNext() != nullptr ; temp = temp->getNext() ) continue;
			temp->setNext( newNode );

			return true;

		}

		bool removeFromHead() {

            if ( head == nullptr ) return false;
            Node *temp = head->getNext();
            delete head;
            head = temp;
            return true;

        }

        bool removeFromTail() {

            if ( head == nullptr ) return false;
            if ( head -> getNext() == nullptr ) {
                delete head;
                head = nullptr;
                return true;
            }
            Node *temp;
            for ( temp = head ; temp -> getNext() != nullptr && temp -> getNext() -> getNext() != nullptr ; temp = temp -> getNext() ) continue;
            delete temp -> getNext();
            temp->setNext( nullptr );
            return true;
			
        }

		void print()
		{
			Node *cur = head;
			while( cur != NULL )
			{
				cout<<cur->getData()<<" ";
				cur = cur->getNext();
			}
			cout<<endl;
		}

		size_t getSize () {
			Node *temp = head;
			size_t s = 0;
			for ( temp ; temp != nullptr ; temp = temp->getNext() ) {
				s++;
			}
			return s;
		}
		
	private:
		Node *head;

};

int main() {
	
	List *singleList = new List();
    singleList->addFromHead(1);
    singleList->addFromTail(2);
    singleList->addFromTail(3);
    singleList->print();
    cout << "Single List Size: " << singleList->getSize() << endl;

	singleList->removeFromHead();
	singleList->removeFromTail();
	singleList->print();
    cout << "Single List Size: " << singleList->getSize() << endl;

	singleList->removeFromTail();
	singleList->print();
    cout << "Single List Size: " << singleList->getSize() << endl;

}
