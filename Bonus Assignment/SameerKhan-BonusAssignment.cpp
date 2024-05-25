#include<iostream>
#include<queue>
#include<list>
#include<map>
#include<unordered_map>
#include<cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
#include<fstream>
#include <array>  
#include <random>
using  namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};


//Linked List(unsorted)
template<typename T>
class UList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* it;
public:
	UList()
	{
		head = NULL;
		tail = NULL;
		it = NULL;
	}

	UList(const UList& obj)
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

	UList& operator=(const UList& obj)
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
		if (head == NULL && tail == NULL)
		{
			head = new Node<T>;
			head->data = d;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			return;

		}
		Node<T>* New_Node = new Node<T>;
		New_Node->data = d;
		New_Node->next = NULL;
		New_Node->prev = tail;
		tail->next = New_Node;
		tail = New_Node;
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
			//cout << "Data not found in the List" << endl;
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

		Node<T>* curr = head;
		Node<T>* next = NULL;
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

	~UList()
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
//Linked List(Sorted)
template<typename T>
class SList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* it;
public:
	SList()
	{
		head = NULL;
		tail = NULL;
		it = NULL;
	}

	SList(const SList& obj)
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

	SList& operator=(const SList& obj)
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
			//cout << "List is empty" << endl;
			return NULL;
		}

		Node<T>* curr = head;
		while ((curr != NULL) && (curr->data != d))
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			//cout << "Data not found in the List" << endl;
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
			//cout << "The List is Empty" << endl;
			return;
		}

		while ((curr != NULL) && curr->data != d)
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			//cout << "Data not found in the list" << endl;
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

		Node<T>* curr = head;
		Node<T>* next = NULL;
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

	~SList()
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
//List STL
//Binary Search Tree STL

template <typename T>
struct BSTNode
{
	T data;
	BSTNode<T>* left_child;
	BSTNode<T>* right_child;

	BSTNode()
	{
		data = T();
		left_child = NULL;
		right_child = NULL;
	}

	BSTNode(T d)
	{
		data = d;
		left_child = NULL;
		right_child = NULL;
	}
};

template <typename T>
class Tree
{
	BSTNode<T>* root;
	queue<T> q;
public:
	Tree()
	{
		root = NULL;
	}

	Tree(const Tree<T>& Obj)
	{
		root = NULL;
		queue<BSTNode<T>*> Q;
		Q.push(Obj.root);
		BSTNode<T>* currnode;
		while (!Q.empty())
		{
			currnode = Q.front();
			Q.pop();
			insert(currnode->data);
			if (currnode->left_child != NULL)
			{
				Q.push(currnode->left_child);
			}

			if (currnode->right_child != NULL)
			{
				Q.push(currnode->right_child);
			}

		}
	}
	Tree<T>& operator=(const Tree<T>& Obj)
	{

		queue<BSTNode<T>*> Q;
		Q.push(Obj.root);
		BSTNode<T>* currnode;
		while (!Q.empty())
		{
			currnode = Q.front();
			Q.pop();
			insert(currnode->data);
			if (currnode->left_child != NULL)
			{
				Q.push(currnode->left_child);
			}

			if (currnode->right_child != NULL)
			{
				Q.push(currnode->right_child);
			}

		}
		return *this;
	}

	void erase(T val)
	{
		BSTNode<T>* curr = root;
		BSTNode<T>* parent = NULL;

		while (curr != NULL && curr->data != val) {
			parent = curr;
			if (val < curr->data)
				curr = curr->left_child;
			else
				curr = curr->right_child;
		}

		if (curr == NULL)
		{
			return;
		}
		if (curr->left_child == NULL && curr->right_child == NULL)
		{
			if (parent == NULL)
			{
				root = NULL;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = NULL;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = NULL;
			}
			delete curr;

		}
		else if (curr->right_child == NULL)
		{
			if (parent == NULL)
			{
				root = curr->left_child;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = curr->left_child;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = curr->left_child;
			}
			delete curr;
		}
		else if (curr->left_child == NULL)
		{
			if (parent == NULL)
			{
				root = curr->right_child;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = curr->right_child;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = curr->right_child;
			}
			delete curr;
		}
		else
		{
			BSTNode<T>* tempparent = NULL;
			BSTNode<T>* temp;

			temp = curr->right_child;
			while (temp->left_child != NULL) {
				tempparent = temp;
				temp = temp->left_child;
			}

			if (tempparent != NULL)
			{

				tempparent->left_child = temp->right_child;
			}

			else
				curr->right_child = temp->right_child;

			curr->data = temp->data;
			delete temp;
		}

	}



	void insert(T input)
	{
		BSTNode<T>* newnode = new BSTNode<T>(input);

		if (root == NULL)
		{
			root = newnode;
		}
		else
		{
			BSTNode<T>* currnode = root;

			while (currnode != NULL)
			{
				if (input < currnode->data) // Left subtree
				{
					if (currnode->left_child)
					{
						currnode = currnode->left_child;
					}
					else
					{
						currnode->left_child = newnode;
						break;
					}
				}
				else if (input > currnode->data) // Right subtree
				{
					if (currnode->right_child)
					{
						currnode = currnode->right_child;
					}
					else
					{
						currnode->right_child = newnode;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	bool find(T num)
	{
		BSTNode<T>* currnode = root;

		while (currnode != NULL)
		{
			if (currnode->data == num)
				return true;  // value is found
			else if (num < currnode->data)
				currnode = currnode->left_child;
			else
				currnode = currnode->right_child;
		}
		return false; // value not found
	}

	bool update(T olddata, T newdata)
	{
		BSTNode<T>* currnode = root;

		while (currnode != NULL)
		{
			if (currnode->data == olddata)
			{
				currnode->data = newdata;
				return true;  // value is found
			}
			else if (olddata < currnode->data)
			{
				currnode = currnode->left_child;
			}
			else
			{
				currnode = currnode->right_child;
			}
		}
		return false; // value not found
	}

	void levelOrder()

	{
		queue<BSTNode<T>*> tempq;
		if (!q.empty())
		{
			while (!q.empty())
			{
				q.pop();
			}
		}
		if (root != NULL)
		{
			tempq.push(root);
		}
		BSTNode<T>* temp = NULL;
		while (!tempq.empty())
		{
			temp = tempq.front();
			tempq.pop();
			q.push(temp->data);
			if (temp->left_child != NULL)
			{
				tempq.push(temp->left_child);
			}
			if (temp->right_child != NULL)
			{
				tempq.push(temp->right_child);
			}
		}
	}


	void clear() //will be used in destructor to prevent memory leak
	{
		if (root != NULL)
		{
			queue<BSTNode<T>*> Q;
			BSTNode<T>* currNode = NULL;
			Q.push(root);

			while (!Q.empty())
			{
				currNode = Q.front();
				Q.pop();

				if (currNode->left_child != NULL)
					Q.push(currNode->left_child);
				if (currNode->right_child != NULL)
					Q.push(currNode->right_child);

				delete currNode;
			}

			root = NULL;
		}
	}

	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void reset()
	{
		levelOrder();
	}

	bool islast()
	{
		return q.empty();
	}
	T getnext()
	{
		T temp = q.front();
		q.pop();
		return temp;
	}

	~Tree()
	{
		clear();
	}

};


//Hash Tables Chaining and Multiplication

template<typename T>
class hashtable_m
{
private:
	list<T>* data;
	int m;
public:
	hashtable_m(int s)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtable_m() {
		delete[] data;

	}
	int hash_mul(T k, int m, float a)
	{
		return m * ((k * a) - int(k * a));
	}
	void insert(const T& val)
	{
		int idx = hash_mul(val, m, 0.3);
		data[idx].push_back(val);
	}
	bool find(const T& val)
	{
		typename list<T>::iterator it;
		int idx = hash_mul(val, m, 0.3);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					return true;
				}

			}
		}
		return false;
	}

	bool erase(const T& val)
	{

		typename list<T>::iterator it;
		int idx = hash_mul(val, m, 0.3);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					data[idx].erase(it);
					return true;
				}

			}
		}

		return false;
	}
};
//Hash Tables Chaining and Division
template<typename T>
class hashtable_d {
private:
	list<T>* data;
	int m;
public:
	hashtable_d(int s)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtable_d() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		data[idx].push_back(val);
	}
	bool find(const T& val)
	{
		typename list<T>::iterator it;
		int idx = hash_div(val, m);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					return true;
				}

			}
		}
		return false;
	}

	bool erase(const T& val)
	{

		typename list<T>::iterator it;
		int idx = hash_div(val, m);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					data[idx].erase(it);
					return true;
				}

			}
		}

		return false;
	}



};
//Hash Tables Open Addressing and Linear Probing
template<typename T>
class hashtable_lp {
private:
	T* data;
	int m;
	int n;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_lp(int s)
	{
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_lp() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == EMPTY || data[idx2] == DEL)
			{
				data[idx2] = val;
				n++;
				return;
			}
		}

	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == val)
			{

				return true;
			}
		}
		return false;
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == val)
			{
				data[idx2] = DEL;
				n--;
				return true;
			}
		}
		return false;
	}



};
//Hash Tables Open Addressing and Quadratic Probing
template<typename T>
class hashtable_qp {
private:
	T* data;
	int m;
	int n;
	int C1;
	int C2;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_qp(int s)
	{
		C1 = 3;
		C2 = 2;
		n = 0;
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_qp() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
			if (data[idx2] == EMPTY || data[idx2] == DEL)
			{
				data[idx2] = val;
				n++;
				return;
			}
		}

	}
	bool find(const T& val)
	{

		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
			if (data[idx2] == val)
			{

				return true;
			}

		}
		return false;
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
			if (data[idx2] == val)
			{
				data[idx2] = DEL;
				n--;
				return true;
			}
		}
		return false;
	}



};
//Hash Tables Open Addressing and Double Hashing
template<typename T>
class hashtable_dh {
private:
	T* data;
	int m;
	int n;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_dh(int s)
	{
		n = 0;
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_dh() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == EMPTY || data[idx2] == DEL)
				{
					data[idx2] = val;
					n++;
					return;
				}
			}
		}


	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == val)
				{

					return true;
				}
			}
		}

		return false;
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == val)
				{
					data[idx2] = DEL;
					n--;
					return true;
				}
			}
		}

		return false;
	}

};

int main()
{
	using namespace std::chrono;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	ofstream file_1;
	ofstream file_2;
	string F_observations = "Observations.csv";
	string F_report = "Final_report.csv";

	int const ARRAYSIZE = 11;
	int const OPS = 5000;
	array<int, OPS> Data{ 0 };

	int const hashtablesize = OPS / 5;
	int const hashtablesize2 = OPS * 1.3;
	UList<int> unorderedlist;
	SList<int> sortedlist;
	list<int> l;
	Tree<int> T;
	map<int, int> BstT;
	unordered_map<int, int> HashT;
	hashtable_m<int> hashmul(hashtablesize);
	hashtable_d<int> hashdiv(hashtablesize);
	hashtable_lp<int> hashlin(hashtablesize2);
	hashtable_qp<int> hashquad(hashtablesize2);
	hashtable_dh<int> hashdoub(hashtablesize2);

	string ADT[ARRAYSIZE] = {"Unordered List","Sorted List","STL List","BST Tree","MAP","Unordered MAP","HashTable_Multiplication","HashTable_Division" ,"HashTable_LinearProbing" ,"HashTable_QuadraticProbing" ,"HashTable_Doublehashing" };
	duration<double> INSERT[ARRAYSIZE];
	duration<double> FINDP[ARRAYSIZE];
	duration<double> FINDN[ARRAYSIZE];
	duration<double> DELETE[ARRAYSIZE];

	duration<double> FINSERT[ARRAYSIZE];
	duration<double> FFINDP[ARRAYSIZE];
	duration<double> FFINDN[ARRAYSIZE];
	duration<double> FDELETE[ARRAYSIZE];

	for (short o = 0; o < ARRAYSIZE; o++)
	{
		INSERT[o] = duration<double>(0);
		FINDP[o] = duration<double>(0);
		FINDN[o] = duration<double>(0);
		DELETE[o] = duration<double>(0);

		FINSERT[o] = duration<double>(0);
		FFINDP[o] = duration<double>(0);
		FFINDN[o] = duration<double>(0);
		FDELETE[o] = duration<double>(0);
	}

	for (short i = 0; i < 10; i++)
	{
		for (short o = 0; o < ARRAYSIZE; o++)
		{
			INSERT[o] = duration<double>(0);
			FINDP[o] = duration<double>(0);
			FINDN[o] = duration<double>(0);
			DELETE[o] = duration<double>(0);
		}

		srand(time(NULL));
		for (int i = 0; i < OPS; i++)
		{
			Data[i] = rand() % OPS;
		}

		duration<double> inserttime_0;
		for (int j = 0; j < OPS; j++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.insert(Data[j]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			INSERT[0] = INSERT[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			INSERT[1] = INSERT[1] + time_1;

			t1 = steady_clock::now();
			l.push_front(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			INSERT[2] = INSERT[2] + time_2;

			t1 = steady_clock::now();
			T.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			INSERT[3] = INSERT[3] + time_3;

			t1 = steady_clock::now();
			BstT.insert(pair<int ,int>(j,Data[j]));
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			INSERT[4] = INSERT[4] + time_4;

			t1 = steady_clock::now();
			HashT.insert(pair<int, int>(j, Data[j]));
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			INSERT[5] = INSERT[5] + time_5;

			t1 = steady_clock::now();
			hashmul.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			INSERT[6] = INSERT[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			INSERT[7] = INSERT[7] + time_7;

			t1 = steady_clock::now();
			hashlin.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			INSERT[8] = INSERT[8] + time_8;

			t1 = steady_clock::now();
			hashquad.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			INSERT[9] = INSERT[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			INSERT[10] = INSERT[10] + time_10;

		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FINSERT[a] = FINSERT[a] + INSERT[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int k = 0; k < OPS; k++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.find(Data[k]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			FINDP[0] = FINDP[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			FINDP[1] = FINDP[1] + time_1;

			t1 = steady_clock::now();
			find(l.begin(), l.end(), Data[k]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			FINDP[2] = FINDP[2] + time_2;

			t1 = steady_clock::now();
			T.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			FINDP[3] = FINDP[3] + time_3;

			t1 = steady_clock::now();
			BstT.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			FINDP[4] = FINDP[4] + time_4;

			t1 = steady_clock::now();
			HashT.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			FINDP[5] = FINDP[5] + time_5;

			t1 = steady_clock::now();
			hashmul.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			FINDP[6] = FINDP[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			FINDP[7] = FINDP[7] + time_7;

			t1 = steady_clock::now();
			hashlin.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			FINDP[8] = FINDP[8] + time_8;

			t1 = steady_clock::now();
			hashquad.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			FINDP[9] = FINDP[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			FINDP[10] = FINDP[10] + time_10;
		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FFINDP[a] = FFINDP[a] + FINDP[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int q = 0; q < OPS; q++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.find(-1);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			FINDN[0] = FINDN[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.find(-1);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			FINDN[1] = FINDN[1] + time_1;

			t1 = steady_clock::now();
			find(l.begin(), l.end(), -1);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			FINDN[2] = FINDN[2] + time_2;

			t1 = steady_clock::now();
			T.find(-1);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			FINDN[3] = FINDN[3] + time_3;

			t1 = steady_clock::now();
			BstT.find(-1);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			FINDN[4] = FINDN[4] + time_4;

			t1 = steady_clock::now();
			HashT.find(-1);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			FINDN[5] = FINDN[5] + time_5;

			t1 = steady_clock::now();
			hashmul.find(-1);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			FINDN[6] = FINDN[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.find(-1);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			FINDN[7] = FINDN[7] + time_7;

			t1 = steady_clock::now();
			hashlin.find(-1);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			FINDN[8] = FINDN[8] + time_8;

			t1 = steady_clock::now();
			hashquad.find(-1);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			FINDN[9] = FINDN[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.find(-1);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			FINDN[10] = FINDN[10] + time_10;

		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FFINDN[a] = FFINDN[a] + FINDN[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int m = 0; m < OPS; m++)
		{

			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.remove(Data[m]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			DELETE[0] = DELETE[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.remove(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			DELETE[1] = DELETE[1] + time_1;

			t1 = steady_clock::now();
			l.remove(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			DELETE[2] = DELETE[2] + time_2;

			t1 = steady_clock::now();
			T.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			DELETE[3] = DELETE[3] + time_3;

			t1 = steady_clock::now();
			BstT.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			DELETE[4] = DELETE[4] + time_4;

			t1 = steady_clock::now();
			HashT.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			DELETE[5] = DELETE[5] + time_5;

			t1 = steady_clock::now();
			hashmul.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			DELETE[6] = DELETE[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			DELETE[7] = DELETE[7] + time_7;

			t1 = steady_clock::now();
			hashlin.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			DELETE[8] = DELETE[8] + time_8;

			t1 = steady_clock::now();
			hashquad.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			DELETE[9] = DELETE[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			DELETE[10] = DELETE[10] + time_10;

		}
		
		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FDELETE[a] = FDELETE[a] + DELETE[a];
		}

		file_1.open(F_observations, ios_base::app);
		file_1 << "Obseravtion# "<< i<< ",Insert" <<",Search(Present)" <<",Search(Not Present): " <<",Delete"<<"\n";
		for (int a = 0; a < ARRAYSIZE; a++)
		{
			file_1 << ADT[a] << "," << INSERT[a].count() << "," << FINDP[a].count() << "," << FINDN[a].count() << "," << DELETE[a].count() << "\n";
		}
		file_1 << "\n";
		file_1.close();
	}

	file_2.open(F_report, ios_base::app);
	file_2 << "FINAL AVERAGES: "<< ",Insert" << ",Search(Present)" << ",Search(Not Present): " << ",Delete" << "\n";
	for (int a = 0; a < ARRAYSIZE; a++)
	{
		file_2 << ADT[a] << "," << (FINSERT[a].count())/ARRAYSIZE << "," << (FFINDP[a].count())/ARRAYSIZE << "," << (FFINDN[a].count())/ARRAYSIZE << "," << (FDELETE[a].count())/ARRAYSIZE << "\n";
	}
	file_2.close();

	return 0;
}