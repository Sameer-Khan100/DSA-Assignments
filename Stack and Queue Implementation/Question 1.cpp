#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;


template <typename T>
int Checkbracket(stack<T>* S1, string input)
{
	int size = input.length();
	int i = 0;
	int pos1 = -1, pos2 = -1;
	int line = -1;
	while (i < size)
	{
	label:
		char temp = input[i++];
		switch (temp)
		{
		case '[':
		{
			S1->push(temp);
			goto label;
		}
		case '{':
		{
			S1->push(temp);
			goto label;
		}
		case '(':
		{
			S1->push(temp);
			goto label;
		}
		case ']':
		{
			if (!S1->empty())
			{
				if (S1->top() != '[')
				{
					return line;
				}
				else
				{
					S1->pop();
					goto label;
				}
			}
			else
			{
				return line;
			}
		}
		case '}':
		{
			if (!S1->empty())
			{
				if (S1->top() != '{')
				{
					return line;
				}
				else
				{
					S1->pop();
					goto label;
				}
			}
			else
			{
				return line;
			}
		}
		case ')':
		{
			if (!S1->empty())
			{
				if (S1->top() != '(')
				{
					return line;
				}
				else
				{
					S1->pop();
					goto label;
				}
			}
			else
			{

				return line;
			}
		}
		case '$':
		{
			int pos = input.find('$', i);
			line = stoi(input.substr(i, pos));
			i = pos + 1;
			break;
		}
		}
	}

	if (!S1->empty())
	{
		while (!S1->empty())
		{
			S1->pop();
		}
		return -2;
	}
	return -1;
}

int main(int argc, char** argv)
{
	stack<char> S1;
	string program, temp;
	ifstream obj1;
	program = "";
	string filename;

	//for command line input for space in file name pass filename in quotation marks (single or double)  

	//filename = "file.txt";

	filename = argv[1];

	obj1.open(filename);

	if (!obj1.is_open())
	{
		cout << "File not found";
		return 0;
	}

	int count = 1;
	getline(obj1, temp);
	program = "$" + to_string(count) + "$" + temp;

	while (!obj1.eof())
	{
		count++;
		getline(obj1, temp);
		program += "$" + to_string(count) + "$" + temp;
	}
	obj1.close();

	count++;

	program += "$" + to_string(count) + "$";

	//cout << program << endl;

	int check = Checkbracket<char>(&S1, program);

	if (check == -1)
		cout << "Program is okay.\n";
	else if (check == -2)
		cout << "Error in last line.\n";
	else
		cout << "Error in line " << check << ".\n";
}
