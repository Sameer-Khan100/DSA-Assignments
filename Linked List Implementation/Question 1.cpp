#include<iostream>
#include<string>
using namespace std;

#pragma warning (disable:4996)

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* it;
public:
	List()
	{
		head = NULL;
		tail = NULL;
		it = NULL;
	}

	List(const List& obj)
	{

		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			while (curr != NULL)
			{
				this->insert(curr->data);
				curr = curr->next;
			}
		}

	}

	List& operator=(const List& obj)
	{
		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			while (curr != NULL)
			{
				this->insert(curr->data);
				curr = curr->next;
			}
		}
		return *this;
	}

	void insert(T d)
	{
		Node<T>* temp = new Node<T>;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;

		}
		else
		{
			Node<T>* curr = head;
			while (curr && curr->data < d)
			{
				curr = curr->next;
			}

			if (curr == head)//head case
			{
				temp->next = curr;
				curr->prev = temp;
				head = temp;
			}
			else if (curr == NULL)//tail case
			{
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
			}
			else
			{
				//to add a node in the middle of the linked list
				temp->prev = curr->prev;
				temp->next = curr;
				curr->prev = temp;
				temp->prev->next = temp;
			}
		}

	}

	bool update(T olddata, T newdata)
	{
		if (IsEmpty())
		{
			cout << "List is empty" << endl;
			return false;
		}

		Node<T>* curr = head;
		while ((curr != NULL) && (curr->data != olddata))
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Data not found in the List" << endl;
			return false;
		}
		else
		{
			curr->data = newdata;
			cout << "Updated" << endl;
			return true;
		}

	}

	Node<T>* find(T d)
	{
		if (IsEmpty())
		{
			cout << "List is empty" << endl;
			return NULL;
		}

		Node<T>* curr = head;
		while ((curr != NULL) && (curr->data != d))
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Data not found in the List" << endl;
			return NULL;
		}
		else
		{
			return curr;
		}
	}

	void remove(T d)
	{
		Node<T>* curr = head;

		if (head == NULL && tail == NULL)
		{
			cout << "The List is Empty" << endl;
			return;
		}

		while ((curr != NULL) && curr->data != d)
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Data not found in the list" << endl;
			return;
		}

		if (curr->prev == NULL && curr->next == NULL)
		{
			delete curr;
			head = tail = NULL;
		}
		else if (curr->prev == NULL)
		{
			curr->next->prev = NULL;
			head = curr->next;
			delete curr;
		}
		else if (curr->next == NULL)
		{
			curr->prev->next = NULL;
			tail = curr->prev;
			delete curr;
		}
		else
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
		}

	}

	void clear()
	{
		if (head == NULL)
			return;

		Node<T> * curr = head;
		Node<T> * next = NULL;
		while (curr != head)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}

		delete head;
		head = tail = NULL;

	}

	bool IsEmpty()
	{
		if (head == NULL && tail == NULL)
		{
			return true;
		}

		return false;
	}

	T front()
	{
		if (!IsEmpty())
		{
			return head->data;
		}
		else
		{
			return T();
		}
	}

	T back()
	{
		if (!IsEmpty())
		{
			return tail->data;
		}
		else
		{
			return T();
		}
	}

	void display()
	{
		Node<T>* curr = head;

		if (IsEmpty())
		{
			return;
		}

		while (curr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	~List()
	{
		clear();
	}

	void reset_h()
	{
		it = head;
	}

	bool islast()
	{
		return it == NULL;
	}

	T get_next_h()
	{
		T temp;
		temp = it->data;
		it = it->next;
		return temp;
	}

	void reset_t()
	{
		it = tail;
	}

	bool isfirst()
	{
		return it == NULL;
	}

	T get_next_t()
	{
		T temp;
		temp = it->data;
		it = it->prev;
		return temp;
	}
};

template<typename T>
void display_for(List<T>& L1)
{
	L1.reset_h();
	while (!L1.islast())
	{
		cout << L1.get_next_h() << " ";
	}
	cout << endl;
}

template<typename T>
void display_back(List<T>& L1)
{
	L1.reset_t();
	while (!L1.isfirst())
	{
		cout << L1.get_next_t() << " ";
	}
	cout << endl;
}

int main()
{
	int data;
	List<int> L1;
	int option = 0;
	do
	{
	menu:
		cout << endl;
		cout << "Please select an Option." << endl;
		cout << "[1]-Insert Node." << endl;
		cout << "[2]-Remove an Node" << endl;
		cout << "[3]-Update data of a Node" << endl;
		cout << "[4]-Clear List." << endl;
		cout << "[5]-To check if list is empty." << endl;
		cout << "[6]-To check data at Head of the List" << endl;
		cout << "[7]-To check data at Tail of the List" << endl;
		cout << "[8]-To Traverse the List in Forward Direction" << endl;
		cout << "[9]-To Traverse the List in Backward Direction" << endl;
		cout << "[0]-To Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Please enter a value: ";
			cin >> data;
			L1.insert(data);
			display_for(L1);
			goto menu;
		}
		case 2:
		{
			cout << "Please enter a value you want to remove: ";
			cin >> data;

			L1.remove(data);
			display_for(L1);
			goto menu;
		}
		case 3:
		{
			int oldval = 0, newval = 0;
			cout << "Please enter old value :";
			cin >> oldval;

			cout << "Please enter old value :";
			cin >> newval;



			L1.update(oldval, newval);
			display_for(L1);
			goto menu;
		}
		case 4:
		{
			L1.clear();
			L1.display();

			goto menu;
		}
		case 5:
		{
			bool t = L1.IsEmpty();

			if (t)
			{
				cout << "The list is Empty!" << endl;
			}
			else
			{
				cout << "The list is NOT Empty!" << endl;
			}
			display_for(L1);
			goto menu;
		}
		case 6:
		{
			int dataathead = L1.front();
			cout << "Data at head is: " << dataathead << endl;

			goto menu;
		}
		case 7:
		{
			int dataattail = L1.back();
			cout << "Data at tail is: " << dataattail << endl;

			goto menu;
		}
		case 8:
		{
			if (!L1.IsEmpty())
			{
				cout << "Elements in the list in forward direction are: " << endl;
				display_for(L1);
			}
			else
			{
				cout << "List is empty!" << endl;
			}
			goto menu;
		}
		case 9:
		{
			List<int> L2;
			L2 = L1;

			if (!L2.IsEmpty())
			{
				cout << "Elements in the list in back direction are: " << endl;
				display_back(L2);
			}
			else
			{
				cout << "List is empty!" << endl;
			}
			goto menu;

		}

		}
	} while (option != 0);


	return 0;
}