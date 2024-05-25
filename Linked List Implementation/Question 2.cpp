#include<iostream>
#include<string>

using namespace std;

template<typename T>

struct Node
{
public:
	T data;
	Node<T>* next;
};

template<typename T>
class CList
{
	Node<T>* head;
	Node<T>* it;

public:
	CList()
	{
		head = NULL;
		it = NULL;
	}

	CList(const CList& obj)
	{
		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			do
			{
				this->insert(curr->data);
				curr = curr->next;
			} while (curr != obj.head);
		}
	}

	CList& operator=(const CList & obj)
	{
		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			do
			{
				this->insert(curr->data);
				curr = curr->next;
			} while (curr != obj.head);
		}
		return *this;
	}

	void insert(T d)
	{
		Node<T>* current = head;

		Node<T>* newP = new Node<T>;
		newP->data = d;
		newP->next = NULL;

		if (current == NULL)
		{
			head = newP;
			head->next = head;
		}
		else
		{
			if (current->data >= newP->data)
			{
				while (current->next != head)
				{
					current = current->next;
				}

				current->next = newP;
				newP->next = head;
				head = newP;
			}
			else
			{
				while (current->next != head && current->next->data < newP->data)
				{
					current = current->next;
				}
				newP->next = current->next;
				current->next = newP;
			}
		}

	}


	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}

	void Remove(T d)
	{
		if (isEmpty())
		{
			cout << "Sorry! List is empty.\n";
			return;
		}

		if (head->data == d && head->next == head)
		{
			delete head;
			head = NULL;
			return;
		}

		Node<T>* curr = head;
		Node<T>* prev = NULL;

		if (head->data == d)
		{
			while (curr->next != head)
			{
				curr = curr->next;
			}
			curr->next = head->next;
			delete head;
			head = curr->next;
			return;
		}
		else
		{
			while ((curr->next != head) && (curr->next->data != d))
			{
				curr = curr->next;
			}

			if (curr->next->data == d)
			{
				prev = curr->next;
				curr->next = prev->next;
				delete prev;
			}
			else
			{
				cout << "Data not found!" << endl;
			}
		}
	}


	void update(T oldval, T newval)
	{
		if (isEmpty())
		{
			cout << "Sorry! List is empty.\n";
			return;
		}

		Node<T>* curr = head;
		Node<T>* prev = NULL;
		do
		{
			if (curr->data == oldval)
			{
				break;
			}
			prev = curr;
			curr = curr->next;
		} while (curr != head);


		if (curr->data != oldval)
		{
			cout << "Data not found.\n";
			return;
		}
		else
		{
			curr->data = newval;
		}
	}

	void Clear()
	{
		if (head == NULL)
			return;

		Node<T> * curr = head->next;
		Node<T> * next = NULL;
		while (curr != head)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}

		delete head;
		head = NULL;
	}

	void Display()
	{
		if (isEmpty())
		{
			cout << "\nList is Empty.\n";
			return;
		}

		Node<T>* curr = head;
		int count = 1;

		do
		{
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head);
		cout << endl;
	}

	T front()
	{
		if (!isEmpty())
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
		if (!isEmpty())
		{
			Node<T>* curr = head;
			do
			{
				curr = curr->next;
			} while (curr->next != head);
			return curr->data;

		}
		else
		{
			return T();
		}
	}

	~CList()
	{
		Clear();
	}

	void reset_h()
	{
		it = head;
	}

	bool islast()
	{
		return it == head;
	}

	T get_next_h()
	{
		if (!isEmpty())
		{
			T val;
			val = it->data;
			it = it->next;
			return val;
		}
	}
};

template<typename T>
void display_for(CList<T> & L1)
{
	L1.reset_h();
	do
	{
		cout << L1.get_next_h() << " ";
	} while (!L1.islast());
	cout << endl;
}


int main()
{
	int data;
	CList<int> L1;
	int option = 0;
	do
	{
	menu:
		cout << "Please select an Option." << endl;
		cout << "[1]-Insert Node." << endl;
		cout << "[2]-Remove an Node" << endl;
		cout << "[3]-Update data of a Node" << endl;
		cout << "[4]-Clear List." << endl;
		cout << "[5]-To check if list is empty." << endl;
		cout << "[6]-To check data at Head of the List" << endl;
		cout << "[7]-To check data at End of the List" << endl;
		cout << "[8]-To traverse and Display in Forward Direction" << endl;
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

			L1.Remove(data);
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
			L1.Clear();
			display_for(L1);

			goto menu;
		}
		case 5:
		{
			bool t = L1.isEmpty();

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
			cout << "Data at end is: " << dataattail << endl;

			goto menu;
		}
		case 8:
		{
			CList<int> L2;
			L2 = L1;
			if (!L2.isEmpty())
			{
				display_for(L2);
			}
			else
			{
				cout << "List is Empty!" << endl;
			}
			goto menu;
		}

		}
	} while (option != 0);


	return 0;
}