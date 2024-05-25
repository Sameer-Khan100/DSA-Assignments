#include<iostream>

using namespace std;

class Queue
{
	int* array;
	int front;
	int rear;
	int size;
public:
	Queue(int s = 0)
	{
		array = NULL;
		front = -1;
		rear = -1;
		size = s;
		if (size != 0)
			array = new int[size];
	}
	void enqueue(int data)
	{
		rear = (rear + 1) % size;
		array[rear] = data;
	}
	int dequeue()
	{
		front = (front + 1) % size;
		return front;
	}
	bool enqueuefront(int data)
	{
		if (isfull())
		{
			return false;
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (front == 0)
		{
			front = size - 1;
		}
		else
		{
			front = front - 1;
		}

		array[front] = data;
		return true;
	}

	bool enqueuerear(int data)
	{
		if (isfull())
		{
			return false;
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (rear == size - 1)
		{
			rear = 0;
		}
		else
		{
			rear = rear + 1;
		}

		array[rear] = data;
		return true;
	}

	int dequeuefront()
	{
		if (isempty())
		{
			return -1;
		}
		int data = array[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (front == size - 1)
		{
			front = 0;
		}
		else
		{
			front = front + 1;
		}
		return data;

	}

	int dequeuerear()
	{
		if (isempty())
		{
			return -1;
		}

		int data = array[rear];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (rear == 0)
		{
			rear = size - 1;
		}
		else
		{
			rear = rear - 1;
		}
		return data;
	}

	int getFront()
	{
		if (!isempty())
		{
			return array[front];
		}
		return -1;
	}

	int getRear()
	{
		if (!isempty())
		{
			return array[rear];
		}
		return -1;
	}

	bool isfull()
	{
		return ((front == 0 && rear == size - 1) || front == rear + 1
			|| front + 1 == rear);
	}

	bool isempty()
	{
		return (front == -1 && rear == -1);
	}
};

int main()
{
	Queue Q(5);

	Q.enqueuefront(6);
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueuerear(7);

	
		cout << Q.dequeuerear()<<endl;
	

	return 0;
}
