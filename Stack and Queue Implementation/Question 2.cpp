#include<iostream>
#include<stack>
#include<math.h>
#include<string>

using namespace std;

bool operatorcheck(char ch)
{
	return (ch == '(' || ch == ')' || ch == '^' || ch == '*' ||
		ch == '/' || ch == '+' || ch == '-' || ch == '$');
}

int Evaluatepostfix(string Str)
{
	string S = Str;
	stack<int> S1;
	int value1, value2;
	string temp;
	string key = " ";
	int pos;
	int val;
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
			value2 = S1.top();
			S1.pop();
			value1 = S1.top();
			S1.pop();

			switch (temp[0])
			{
			case '+':
			{
				S1.push(value1 + value2);
				break;
			}
			case '-':
			{
				S1.push(value1 - value2);
				break;
			}
			case '*':
			{
				S1.push(value1 * value2);
				break;
			}
			case '/':
			{
				S1.push(value1 / value2);
				break;
			}
			case '$':
			{
				S1.push(pow(value1, value2));
				break;
			}
			}
		}
		else
		{
			val = stoi(temp);
			S1.push(val);
		}
	}

	val = S1.top();
	S1.pop();

	return val;
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
	//cout << "Please input the posfix you want to evalaute: ";
	//getline(cin, input);

	int result = Evaluatepostfix(input);
	cout << "Result: " << result;

}