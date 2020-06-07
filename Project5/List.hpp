#include <iostream>
using namespace std;

template <class Iter, class T, class func = T(*)(T&)>
void for_each(Iter begin, Iter end, func a) {
	for (; begin != end; begin++) {
		a(*begin);
	}
}

template <typename T>
class List
{
private:
	template <typename T>
	class Node
	{
	public:
		Node* Next;
		T data;

		Node(T data = T(), Node* Next = nullptr)  //конструктор класса Node
		{
			this->data = data; this->Next = Next;
		}
	};

	int Size;
	Node<T>* Head;

public:
	List();    //конструктор класса List
	~List();   //деструктор класса List

	void pop_front();                 //удаление элемента с начала списка
	void pop_back();                  //удаление элемента с конца списка
	void push_front(T data);          //добавление элемента в начало списка
	void push_back(T data);           //добавление элемента в конец списка
	void show();                      //показать все элементы списка
	void clear();                     //очистить список
	void reverse();                   //переворот списка
	void insert(T data, int index);   //вставка по индексу
	void remove_i(int index);         //удаление элемента по индексу
	void remove_d(T data);            //удаление элемента по значению
	int get_size() { return Size; };

	T& operator[](const int index);   //оператор для получения значения Node по индексу

	class LIterator
	{
	public:
		LIterator() noexcept {
			Value = nullptr;
		}

		LIterator(Node<T>* value) noexcept {
			Value = value;
		}

		_NODISCARD T& operator*() const {
			return Value->data;
		}

		_NODISCARD T* operator->() {
			return &(Value->data);
		}

		LIterator& operator++() {
			Value = Value->Next;
			return *this;
		}

		LIterator operator++(int) {
			LIterator temp = *this;
			Value = Value->Next;

			return temp;
		}

		LIterator operator+(int step) {
			for (auto i = 0; i < step; i++) {
				Value = Value->Next;
			}
		}

	private:
		Node<T>* Value;
	};


	LIterator begin() {
		return Head;
	}

	LIterator end() {
		return new Node<T>();
	}
};

template <typename T>
List<T>::List()
{
	Size = 0;
	Head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	if (Head != nullptr)
	{
		Node<T> *current = Head;
		Head = Head->Next;
		delete current;
		Size--;
	}
	else
	{
		throw exception("The list is empty");
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (Head != nullptr)
	{
		remove_i(Size - 1);
	}
	else
	{
		throw exception("The list is empty");
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	Head = new Node<T>(data, Head);
	Size++;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (Head == nullptr)
	{
		Head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->Head;

		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		current->Next = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	if (Size != 0)
	{
		while (Size)
		{
			pop_front();
		}
	}
	else
	{
		throw exception("The list is empty");
	}
}

template<typename T>
void List<T>::reverse()
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1 - i; j++)
		{
			Node<T> *current = this->Head; int current_i = 0;
			for (int k = 0; k < Size - 1 - i; k++)
			{
				current = current->Next; current_i++;
			}
			push_front(current->data);
			remove_i(current_i + 1);
		}
	}
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else if (index == Size - 1)
	{
		push_back(data);
	}
	else if (index >= Size)
	{
		throw exception("Index not found");
	}
	else
	{
		Node<T> *current = this->Head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->Next;
		}
		Node<T> *newNode = new Node<T>(data, current->Next);
		current->Next = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::remove_i(int index)
{
	if (Head != nullptr)
	{
		if (index == 0)
		{
			pop_front();
		}
		else if (index >= Size)
		{
			throw exception("Node not found");
		}
		else
		{
			Node<T> *current = this->Head;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->Next;
			}
			Node<T> *Delete = current->Next;
			current->Next = Delete->Next;
			delete Delete;
			Size--;
		}
	}
	else
	{
		throw exception("The list is empty");
	}
}

template<typename T>
void List<T>::remove_d(T data)
{
	if (Head != nullptr)
	{
		Node<T> *current = this->Head;
		if (current->data == data)
		{
			pop_front();
		}
		else
		{
			int i;
			for (i = 0; (current->Next->data != data) && (i < Size - 1); i++)
			{
				current = current->Next;
			}
			if (i < Size - 1 && current->Next->data == data)
			{
				Node<T> *Delete = current->Next;
				current->Next = Delete->Next;
				delete Delete; Size--;
			}
			else
			{
				throw exception("Node not found");
			}
		}
	}
	else
	{
		throw exception("The list is empty");
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->Head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->Next;
		counter++;
	}
}

template<typename T>
void List<T>::show()
{
	if (Head != nullptr)
	{
		Node<T> *current = this->Head;
		cout << "1. " << current->data << endl;
		for (int i = 1; i < Size; i++)
		{
			current = current->Next;
			cout << i + 1 << ". " << current->data << endl;
		}
	}
	else
	{
		throw exception("The list is empty");
	}
}
