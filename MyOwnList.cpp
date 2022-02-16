#include <iostream>
#include <vector>

using namespace std;

template<typename T> class List_iterator;


template<typename T>
class list
{
public:
	list();
	~list();

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
	bool empty();
	int front();
	int back();
	int getSize() { return size; }
	T& operator[](const int index);
	////
private:
	template<typename T>
	struct Node
	{
		Node* pNext;
		T data;
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
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->pNext = NULL;
	if (Begin == NULL)
	{
		Begin = temp;
		End = temp;
		temp = NULL;
	}
	else
	{
		End->pNext = temp;
		End = temp;
	}
	size++;
}

template<typename T>
void list<T>::push_front(T data)
{
	Node<T>* temp = Begin;
	Begin = new Node<T>;
	Begin->data = data;
	Begin->pNext = temp;
	size++;
}

template<typename T>
void list<T>::pop_front()
{
	Node<T> *temp = Begin;
	Begin = Begin->pNext;
	delete temp;
	size--;
}

template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void list<T>::insert(T data, int pos)
{
	Node<T>* temp = new Node<T>;
	Node<T>* temp1 = new Node<T>;
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
		temp1 = previous->pNext;
		temp->data = data;
		previous->pNext = temp;
		temp->pNext = temp1;
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
		Node<T>* temp = new Node<T>;
		Node<T>* temp1 = new Node<T>;

		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp1 = previous->pNext->pNext;
		temp = End;
		End = previous->pNext;

		for (int i = 0; i < count; i++)
		{
			push_back(data);
		}
		End->pNext = temp1;
		End = temp;
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
		Node<T>* temp = new Node<T>;
		Node<T>* temp1 = new Node<T>;

		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp1 = previous->pNext->pNext;
		temp = End;
		End = previous->pNext;

		for (int i = 0; i < vec.size(); i++)
		{
			push_back(vec[i]);
		}
		End->pNext = temp1;
		End = temp;
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
	}
	size--;
}

template<typename T>
bool list<T>::empty()
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
	lst.insert(17, 3);
	lst.push_front(7);
	lst.pop_front();
	lst.removeAt(3);
	lst.insert(3, 3, 2);
	lst.insert({ 0,1,2 }, 5);

}
