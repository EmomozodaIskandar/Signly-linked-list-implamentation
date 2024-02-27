#include<iostream>

using namespace std;

template<typename T>
class NodeList
{
public:
	NodeList();
	~NodeList();
	int size();
	T& operator[](int index);
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	void clear();
	void insert(T data, int index = Size);


private:
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(),Node* pNext = nullptr);
		~Node();
	};

	Node* head;
	int Size;

};

template<typename T>
NodeList<T>::NodeList()
{
	this->head = nullptr;
	this->Size = 0;
}

template<typename T>
NodeList<T>::~NodeList()
{
	this->clear();
}

template<typename T>
void NodeList<T>::push_back(T data)
{
	if (this->head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}
	Size++;
}

template<typename T>
int NodeList<T>::size()
{
	return this->Size;
}

template<typename T>
T& NodeList<T>::operator[](const int index)
{
	Node* current = this->head;
	int counter = 0;
	while (current != nullptr) 
	{
		if(counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void NodeList<T>::push_front(T data)
{
	head = new Node(data, head);
	Size++;
}

template<typename T>
void NodeList<T>::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void NodeList<T>::pop_back()
{
	Node* current = head;
	while (current->pNext != 0)
	{
		current = current->pNext;
	}
	delete current;
	Size--;
}

template<typename T>
void NodeList<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void NodeList<T>::insert(T data, int index)
{
	Node* current = head;
	int counter=0;
	while (index-1>counter)
	{
		current = current->pNext;
		counter++;
	}
	current->pNext = new Node(data, current->pNext);
	Size++;
}


template<typename T>
NodeList<T>::Node::Node(T data, Node* pNext) {
	this->data = data;
	this->pNext = pNext;
}

template<typename T>
NodeList<T>::Node::~Node() {

}

int main() {
	NodeList<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_front(i);
	}
	l.insert(5, 8);
	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i] << '\n';
	}
}