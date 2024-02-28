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
	void insert(T data, int index);
	void pop_front();
	void pop_back();
	void removeAt(int index);
	void clear();


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
	if (Size != 0)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}
}

template<typename T>
void NodeList<T>::pop_back()
{
	Node* current = this->head;
	while (current->pNext != 0)
	{
		current = current->pNext;
	}
	delete current;
	Size--;
}

template<typename T>
void NodeList<T>::removeAt(int index)
{
	if (Size>1) 
	{

		Node* current = this->head;
		int counter = 0;
		while (counter < index - 1)
		{
			current = current->pNext;
			counter++;
		}
		Node* temp = current->pNext;
		current->pNext = (current->pNext)->pNext;
		delete temp;
		Size--;
	}
	else
	{
		pop_front();
	}
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
	if (index==0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* newNode = new Node(data, previous->pNext);
		previous->pNext = newNode;

		Size++;
	}
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
	NodeList<double> l;
	return 0;
}