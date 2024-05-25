#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct PatientInfo
{
	int patient_id;
	string patient_name;
	int age;
	string patient_details;

};

void display(string* n, int num)
{
	cout << "Queues are:" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}
int main()
{
	int i;
	string n;
	string* queuename;
	queue<PatientInfo>* q;
	char ch;
	int num;
	PatientInfo p;
	cout << "Hospital Management System!" << endl;
	cout << "Please enter the number of queues want to create: ";
	cin >> num;
	q = new queue<PatientInfo>[num];
	cin.ignore();
	queuename = new string[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Please enter the name for Queue " << i + 1 << " : ";
		getline(cin, queuename[i]);
	}

	int choice = 0;
menu:
	cout << "Menu:" << endl;
	cout << "Press [1] If you want to Admit a Patient" << endl;
	cout << "Press [2] If you want to Remove a Patient" << endl;
	cout << "Press [3] Display details of all patients in all Queues." << endl;
	cout << "Press [0] If you want to exit" << endl;
	cout << "Enter Choice:" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		display(queuename, num);
		cout << endl;
		cout << "Please select the name of queue in which you want to admit: " << endl;
		cin.get();
		getline(cin, n);
		for (i = 0; i < num; i++)
		{
			if (n == queuename[i])
			{
				do
				{
					cin.get();
					cout << "Please enter patient Name: ";
					
					getline(cin, p.patient_name);
					cout << "Please enter patient Details: ";
					getline(cin, p.patient_details);
					cout << "Please enter patient Age: ";
					cin >> p.age;
					cout << "Please enter patient ID: ";
					cin >> p.patient_id;
					q[i].push(p);
					cout << "Do you want to Continue?";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');
			}
		}
		goto menu;
	}
	case 2:
	{
		cout << "Please select the name of queue in which you want to admit: " << endl;
		cin.get();
		getline(cin, n);
		for (i = 0; i < num; i++)
		{
			do
			{

				if (n == queuename[i])
				{
					q[i].pop();
					cout << "Removed Successfully." << endl;
					cout << "Do you want to Continue?";
					cin >> ch;
				}
			} while (ch == 'y' || ch == 'Y');
		}
		goto menu;
	}
	case 3:
	{
		queue<PatientInfo>* t;
		int i = 0;
		t = new queue<PatientInfo>[num];
		cout << "Name\t\tDetails\t\tAge\t\tId" << endl;
		for (i = 0; i < num; i++)
		{
			t[i] = q[i];
			if (t[i].empty())
			{
				continue;
			}
			else
			{
				PatientInfo p;

				cout << "Details of " << queuename[i] << endl;
				while (!t[i].empty())
				{
					p = t[i].front();
					cout << p.patient_name << "\t\t" << p.patient_details << "\t\t" << p.age << "\t\t" << p.patient_id << endl;
					t[i].pop();
				}
			}

		}
	}
	case 0:
	{
		exit(0);
	}
	}
	return 0;
}