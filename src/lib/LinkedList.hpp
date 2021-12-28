#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template<typename T>
class LinkedList {
protected:
    // ADT for our nodes
    struct Node
    {
        T value;
        Node* next;

        Node(T v = T(), Node* n = nullptr) :
        value(v), next(n) {}
    };
    // a pointer containing the head of the node
    Node* head;
    unsigned length;
private:
    void copy(const LinkedList<T>&);
public:
    // default constructor
    LinkedList();
    // copy constructor
    LinkedList(const LinkedList<T>&);
    // overloaded assignment operator
    LinkedList<T>& operator=(const LinkedList<T>&);
    // destructor
    virtual ~LinkedList();
    // add the argument to the end of the list
    virtual void append(const T&);
    // remove all elements in the list
    virtual void clear();
    // return the element at the given position (argument)
    virtual T getElement(int) const;
    // return the current length of the list
    virtual int getLength() const;
    // insert the given element (argument 2) at
    // the given position (argument 1)
    virtual void insert(int, const T&);
    // determine if the list currently empty
    virtual bool isEmpty() const;
    // remove the element at the given position (argument)
    virtual void remove(int);
    // replace the element at the given position (argument 1) with
    // the value given (argument 2)
    virtual void replace(int, const T&);
};

// default constructor
template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    length = 0;
}

// private copy method
template<typename T>
void LinkedList<T>::copy(const LinkedList<T>& obj) {
    this->length = obj.length;
    this->head = nullptr;

    if (this->length > 0) {
        this->head = new Node(obj.head->value);
        Node* copyCurr = obj.head->next;
        Node* myCurr = this->head;
        Node* n = nullptr;

        while (copyCurr != nullptr) {
            n = new Node(copyCurr->value);
            myCurr->next = n;
            myCurr = n;
            copyCurr = copyCurr->next;
        }
    }
}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& obj) {
    this->copy(obj);
}
// overloaded assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& obj) {
    if (this != &obj) {
        clear();
        copy(obj);
    }
    return *this;
}
// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}
// add the argument to the end of the list
template<typename T>
void LinkedList<T>::append(const T& v) {
    Node* n = new Node(v);
    if (this->length == 0) {
        head = n;
    }
    else {
        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        // once we finish looping, curr will point at the last node in the list
        curr->next = n;
    }
    this->length++;
}
// remove all elements in the list
template<typename T>
void LinkedList<T>::clear() {
    if (this->length == 0) return;

    Node* curr = head;
    Node* prev = nullptr;

    while(curr != nullptr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    this->length = 0;
}
// return the element at the given position (argument)
template<typename T>
T LinkedList<T>::getElement(int index) const {
    if (this->length == 0) return  0;
    
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->value;
}
// return the current length of the list
template<typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}
// insert the given element (argument 2) at
// the given position (argument 1)
template<typename T>
void LinkedList<T>::insert(int index, const T& elem) {
    if (this->length == 0) return;

    Node* n = new Node(elem);
    Node* curr = head;
    for (int i = 1; i < index; i++) {
        curr = curr->next;
    }
    // link n as the node after curr;
    n->next = curr->next;
    curr->next = n;
    
    this->length++; // increment the length of the linked list
}
// determine if the list currently empty
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return (this->length == 0);
}
// remove the element at the given position (argument)
template<typename T>
void LinkedList<T>::remove(int index) {
    if (this->length == 0) return;
    Node* curr = head;
    Node* prev = nullptr;
    for (int i = 0; i < index; i++){ // set up curr at the node to be removed
        prev = curr;                 // set up prev to be right before curr
        curr = curr->next;
    }
    // break the links at curr node, and create the links around curr
    prev->next = curr->next;
    delete curr;
    curr = nullptr;
    this->length--;
}
// replace the element at the given position (argument 1) with
// the value given (argument 2)
template<typename T>
void LinkedList<T>::replace(int index, const T& element) {
    if (this->length == 0) return;
    
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    curr->value = element;
}

#endif