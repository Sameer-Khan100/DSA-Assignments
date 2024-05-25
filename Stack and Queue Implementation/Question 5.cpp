#include<iostream>

using namespace std;

template <class T>
struct node {
	T data;
	node<T>* previous;

	node() : data(T()), previous(NULL) {};
};

template <class T>
class Queue {
	node<T>* rear;
public:
	Queue() {
		rear = NULL;
	}

	T back() {
		if (!is_empty())
			return rear->data;
		return T();
	}

	T front() {
		if (!is_empty())
		{
			node<T>* currnode = rear;

			do
			{
				currnode = currnode->previous;
			} while (currnode->previous != rear);

			return currnode->data;
		}
		return T();
	}

	void enqueue(T input) {
		node<T>* newnode = new node<T>;

		newnode->data = input;
		newnode->previous = NULL;

		if (is_empty())
		{
			newnode->previous = newnode;
			rear = newnode;
		}
		else
		{
			node<T>* currnode = rear;
			do
			{
				currnode = currnode->previous;
			} while (currnode->previous != rear);

			currnode->previous = newnode;
			newnode->previous = rear;
			rear = newnode;
		}
	}

	T dequeue() {
		if (!is_empty())
		{
			node<T>* currnode = rear;

			if (rear->previous == rear)
			{
				rear = NULL;
			}
			else
			{
				node<T>* previous = NULL;
				do
				{
					previous = currnode;
					currnode = currnode->previous;
				} while (currnode->previous != rear);
				previous->previous = rear;
			}

			T output = currnode->data;
			delete currnode;
			return output;
		}
		return T();
	}

	bool is_empty() {
		if (rear == NULL)
			return true;
		return false;
	}

	void display()
	{
		if (!is_empty())
		{
			node<T>* currnode = rear;

			do
			{
				cout << currnode->data << " ";
				currnode = currnode->previous;
			} while (currnode != rear);
		}
	}

	~Queue()
	{
		while (!is_empty())
		{
			dequeue();
		}
	}
};

int main()
{
	Queue<int> Q;

	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(8);
	Q.enqueue(7);
	Q.enqueue(6);
	cout << Q.dequeue();
	cout << Q.dequeue();
	

	//	Q.display();
}