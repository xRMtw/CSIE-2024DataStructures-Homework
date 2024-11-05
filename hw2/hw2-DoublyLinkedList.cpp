#include<bits/stdc++.h>

using namespace std;

template<class T>
class Tnode {
	public:
		Tnode () {
			pre = nullptr;
			next = nullptr;
		}
		Tnode( T d ) {
			data = d;
			pre = nullptr;
			next = nullptr;
		}

		T getData() { return data; }
		Tnode<T> *getNext() { return next; }
		Tnode<T> *getPre() { return pre; }
		void setData(T d) { data = d; }
		void setNext(Tnode<T> *n) { next = n; }
		void setPre(Tnode<T> *p) { pre = p; }

	private:
		T data;
		Tnode<T> *pre, *next;

};

template<class T>
class DoublyLinkedList {

	public:
		DoublyLinkedList() { 
			head = nullptr; 
			trailer = nullptr;
		}

		~DoublyLinkedList() {
			while ( removeFromHead() ) {}
			delete head;
			delete trailer;

		}

		bool addFromHead ( T d ) {

			Tnode<T> *newNode = new Tnode( d );

			if ( newNode == nullptr ) return false;
			
			if ( head == nullptr ) {
				head = trailer = newNode;

			} else {

				newNode->setNext(head);
				head->setPre(newNode);
				head = newNode;
			
			}
			return true;
		}

		bool addFromTail ( T d ) {

			Tnode<T> *newNode = new Tnode( d );

			if ( newNode == nullptr ) return false;

			if ( trailer == nullptr ) {

				head = trailer = newNode;

			} else {

				trailer->setNext(newNode);
				newNode->setPre(trailer);
				trailer = newNode;

			}

			return true;
		}

		bool removeFromHead() {
			if (head == nullptr) return false;

			Tnode<T> *temp = head->getNext();

			delete head;
			head = temp;

			if ( head == nullptr ) {
			
				trailer = nullptr;

			} else {

				head->setPre( nullptr );
			}

			return true;
		}

		bool removeFromTail() {

			if (trailer == nullptr) return false;

			if (head == trailer) {
				delete head;
				head = trailer = nullptr;
			} else {
				Tnode<T> *temp = trailer->getPre();

				delete trailer;
				trailer = temp;
				trailer->setNext(nullptr);
			}

			return true;
		}

		void print()
		{
			Tnode<T> *cur = head;
			while( cur != NULL )
			{
				cout<<cur->getData()<<" ";
				cur = cur->getNext();
			}
			cout<<endl;
		}

		size_t getSize () {
			Tnode<T> *temp = head;
			size_t s = 0;
			for ( temp ; temp != nullptr ; temp = temp->getNext() ) {
				s++;
			}
			return s;
		}
		
	private:
		Tnode<T> *head;
    	Tnode<T> *trailer;
};

int main() {

	DoublyLinkedList<int> *doubleList = new DoublyLinkedList<int>();
	doubleList->addFromHead(1);
	doubleList->addFromTail(2);
	doubleList->addFromTail(3);
	doubleList->print();
	cout << "Doubly List Size: " << doubleList->getSize() << endl;

	doubleList->removeFromHead();
	doubleList->removeFromTail();
	doubleList->print();
	cout << "Doubly List Size: " << doubleList->getSize() << endl;

	doubleList->removeFromHead();
	doubleList->print();
	cout << "Doubly List Size: " << doubleList->getSize() << endl;

}
