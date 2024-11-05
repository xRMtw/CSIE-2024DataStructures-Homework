#include <bits/stdc++.h>

using namespace std;

template<class T>
class Tnode {
public:
    Tnode() : data(T()), pre(nullptr), next(nullptr) {}
    Tnode(T d) : data(d), pre(nullptr), next(nullptr) {}

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
    DoublyLinkedList() : head(nullptr), trailer(nullptr) {}

    ~DoublyLinkedList() {
        while (removeFromHead()) {}
    }

    bool addFromHead(T d) {
        Tnode<T> *newNode = new Tnode<T>(d);
        if (newNode == nullptr) return false;

        if (head == nullptr) {
            head = trailer = newNode; // 當列表為空時，head和trailer都指向新節點
        } else {
            newNode->setNext(head);
            head->setPre(newNode);
            head = newNode; // 將head指向新節點
        }
        return true;
    }

    bool addFromTail(T d) {
        Tnode<T> *newNode = new Tnode<T>(d);
        if (newNode == nullptr) return false;

        if (trailer == nullptr) {
            head = trailer = newNode; // 當列表為空時，head和trailer都指向新節點
        } else {
            trailer->setNext(newNode);
            newNode->setPre(trailer);
            trailer = newNode; // 將trailer指向新節點
        }
        return true;
    }

    bool removeFromHead() {
        if (head == nullptr) { // 如果列表為空，拋出例外
            throw runtime_error("List is empty. Cannot remove from head.");
        }

        Tnode<T> *temp = head->getNext(); // 獲取新的head
        delete head; // 刪除原有head
        head = temp; // 更新head指向新的head

        if (head == nullptr) { // 如果刪除後列表變空，更新trailer
            trailer = nullptr; // 更新trailer為空
        } else {
            head->setPre(nullptr); // 更新新head的前驅指針
        }
        return true;
    }

    bool removeFromTail() {
        if (trailer == nullptr) { // 如果列表為空，拋出例外
            throw runtime_error("List is empty. Cannot remove from tail.");
        }

        if (head == trailer) { // 如果只剩一個元素
            delete head; // 刪除唯一的節點
            head = trailer = nullptr; // 更新head和trailer為空
        } else {
            Tnode<T> *temp = trailer->getPre(); // 獲取新的trailer
            delete trailer; // 刪除原有trailer
            trailer = temp; // 更新trailer指向新的trailer
            trailer->setNext(nullptr); // 更新新trailer的後繼指針
        }
        return true;
    }

    void print() const {
        Tnode<T> *cur = head;
        while (cur != nullptr) {
            cout << cur->getData() << " ";
            cur = cur->getNext();
        }
        cout << endl;
    }

    size_t getSize() const {
        Tnode<T> *temp = head;
        size_t s = 0;
        while (temp != nullptr) {
            s++;
            temp = temp->getNext();
        }
        return s;
    }

private:
    Tnode<T> *head;    // 指向列表的開頭
    Tnode<T> *trailer; // 指向列表的結尾
};

int main() {
    try {
        DoublyLinkedList<int> doubleList;
        doubleList.addFromHead(1);
        doubleList.addFromTail(2);
        doubleList.addFromTail(3);
        doubleList.print();
        cout << "Doubly List Size: " << doubleList.getSize() << endl;

        doubleList.removeFromHead(); // 刪除一個節點
        doubleList.removeFromTail(); // 刪除一個節點
        doubleList.print();
        cout << "Doubly List Size: " << doubleList.getSize() << endl;

        // 這裡移除最後一個節點，不會拋出例外
        doubleList.removeFromHead(); 
        
        // 此時 doubleList 已經是空的，再次移除會拋出例外
        // doubleList.removeFromHead(); // 這行如果執行，會觸發例外
    } catch (const runtime_error &e) {
        cout << e.what() << endl;  // 捕獲並輸出例外訊息
    }
}
