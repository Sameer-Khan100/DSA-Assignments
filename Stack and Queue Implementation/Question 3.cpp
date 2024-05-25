#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool prcd(char c, char c2)
{
	if (c == '(')
		return false;

	else if (c2 == '(')
	{
		if (c == ')')
			return true;
		else
			return false;
	}

	else if (c2 == ')')
	{
		if (c == '(')
			return false;
		else
			return true;
	}

	else if (c == ')')
	{
		//do nothing
	}

	else if (c == '^')
	{
		if (c2 == '^')
			return true;
		else
			return false;
	}
	else if (c == '*' || c == '/')
	{
		if (c2 == '^')
			return false;
		else
			return true;
	}
	else if (c == '+' || c == '-')
	{
		if (c2 == '+' || c2 == '-')
			return true;
		else
			return false;
	}
}

bool operatorcheck(char ch)
{
	return (ch == '(' || ch == ')' || ch == '^' || ch == '*' ||
		ch == '/' || ch == '+' || ch == '-');
}

string Evaluatepostfix(string Str)
{
	string S = Str;
	stack<char> S1;
	int size = S.length();
	string postfix = "";
	string temp;
	string key = " ";
	int pos;
	bool last = false;

	while (1)
	{
		pos = S.find(key);
		temp = S.substr(0, pos);
		S = S.substr(pos + 1);

		if (last)
			break;
		if (pos == -1)
			last = true;

		if (operatorcheck(temp[0]))
		{
			if (S1.empty())
			{
				S1.push(temp[0]);
			}
			else
			{
				while (!S1.empty() && prcd(S1.top(), temp[0]))
				{
					char x = S1.top();
					string d(1, x);
					postfix += d + " ";
					S1.pop();
				}

				if (S1.empty() || temp[0] != ')')
					S1.push(temp[0]);
				else
					S1.pop();
			}
		}
		else
		{
			postfix += temp + " ";
		}
	}

	while (!S1.empty())
	{
		char x = S1.top();
		string d(1, x);
		postfix += d + " ";
		S1.pop();
	}

	return postfix;
}

int main(int argc,char**argv)
{
	string input;
	if (argc == 1)
	{
		cout << "No arguments passed" << endl;

	}
	else
		input = argv[1];

	//cout << "Please input the infix you want to convert to postfix: ";
	//getline(cin, input);

	string result = Evaluatepostfix(input);
	cout << "Result: " << result;

}