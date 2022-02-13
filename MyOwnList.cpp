#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class list
{
public:
	list();
	~list();
	
	//class iterator
	//{
	//public:
	//	//iterator(const iterator&);
	//	iterator();
	//	~iterator();
	//	iterator operator=(const iterator&) { return pos_; }
	//	/*iterator operator++() { return pos_++; } 
	//	iterator& operator++() { return ++pos_; } *///prefix increment
	//	//reference operator*() const;
	//};

	//iterator pos_;


	//Adding elements//
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int pos);
	void insert(T data, int count, int pos);
	void insert(vector<int> vec, int pos);
	////

	//Removing
	void clear();
	void removeAt(int pos);
	void pop_front();
	void pop_back();
	////

	//Geting info//
	list<T>* begin() { return Begin; }
	list<T>* end() { return End; }
	int empty();
	int front();
	int back();
	int getSize() { return size; }
	T& operator[](const int index);
	////
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	size_t size;
	Node<T> *End;
	Node<T> *Begin;
};

template<typename T>
list<T>::list()
{
	size = 0;
	End = nullptr;
	Begin = nullptr;
}

template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
void list<T>::push_back(T data)
{
	if (Begin == nullptr)
	{
		Begin = new Node<T>(data);
	}
	else
	{
		End = this->Begin;
		while (End->pNext != nullptr)
		{
			End = End->pNext;
		}
		End->pNext = new Node<T>(data);
		End = End->pNext;
	}
	size++;
}

template<typename T>
void list<T>::push_front(T data)
{
	Begin = new Node<T>(data, Begin);
	End = End->pNext;
	size++;
}

template<typename T>
void list<T>::pop_front()
{
	Node<T> *temp = Begin;
	Begin = Begin->pNext;
	delete temp;
	size--;
	End = Begin;
	for (int i = 0; i < size; i++)
	{
		End = End->pNext;
	}
}

template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void list<T>::insert(T data, int pos)
{
	if (pos == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);
		End = End->pNext;
	}
	size++;
}

template<typename T>
void list<T>::insert(T data, int count, int pos)
{
	if (pos == 0)
	{
		for (int i = 0; i < count;i++)
		{
			push_front(data);
		}
	}
	if (pos == size - 1)
	{
		for (int i = 0; i < count; i++)
		{
			push_back(data);
		}
	}
	else
	{
		Node<T>* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		for (int i = 0; i < count; i++)
		{
			previous->pNext = new Node<T>(data, previous->pNext);
			End = End->pNext;
		}
		size += count;
	}
}

template<typename T>
void list<T>::insert(vector<int> vec, int pos)
{
	if (pos == 0)
	{
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			push_front(vec[i]);
		}
	}
	if (pos == size - 1)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			push_back(vec[i]);
		}
	}
	else
	{
		Node<T>* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		for (int i = 0; i < vec.size(); i++)
		{
			previous->pNext = new Node<T>(vec[i], previous->pNext);
			End = End->pNext;
		}
		size += vec.size();
	}
}

template<typename T>
void list<T>::clear()
{
	while (size) 
	{
		pop_front();
	}
}

template<typename T>
void list<T>::removeAt(int pos)
{
	if (pos == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* to_delete = previous->pNext;
		previous->pNext = to_delete->pNext;
		delete to_delete;
		End = previous->pNext;
	}
	size--;
}

template<typename T>
int list<T>::empty()
{
	if (Begin == End)
	{
		return 0;
	}
	return 1;
}

template<typename T>
int list<T>::front()
{
	return Begin->data;
}

template<typename T>
int list<T>::back()
{
	return End->data;
}


template<typename T>
T& list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->Begin;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	list<int> lst;
	
	lst.push_back(11);
	lst.push_back(12);
	lst.push_back(13);
	lst.push_back(14);
	lst.push_back(15);


	
}

//template<typename T>
//list<T>::iterator::iterator(const iterator&)
//{
//
//}

//template<typename T>
//list<T>::iterator::iterator()
//{
//	pos_ = nullptr;
//}
//
//template<typename T>
//list<T>::iterator::~iterator()
//{
//
//}
