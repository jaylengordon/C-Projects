// GordonStaticStackTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Jaylen Gordon
//Programming Assignment # 18
//Program Name: GordonStaticStackTemplate
//Short Program Description
//July 12, 2020


#include <iostream>
#include <exception>
#include <string>

using namespace std;

const int STACK_MAX_SIZE(8);
//  stack full exception
class stackFullException : public exception
{
	const char* what() const throw()
	{
		return "Exception: Stack Full..";
	}
};
// stack empty exception
class stackEmptyException : public exception
{
	const char* what() const throw()
	{
		return "Exception: Stack Empty..";
	}
};


// push, pop, peek and isEmpty.
template <typename T> class StaticStack
{
public:
	StaticStack()
	{
		TOS = -1; 
	}

	// push to stack if not Full
	// if Full throw stack full exception.
	void push(T t)
	{
		if (TOS == (STACK_MAX_SIZE - 1))
		{
			throw stackFullException();
		}
		else
		{
			stack[++TOS] = t;
			cout << t << " Push Successful.." << endl;
		}
	}
	// pop from stack if not empty
	// if empty throw stack empty exception.
	T pop()
	{
		if (TOS < 0)
		{
			throw stackEmptyException();
		}
		return stack[TOS--];
	}

	// returns true if stack is empty.
	bool isEmpty()
	{
		return TOS < 0;
	}
	// if stack is not empty returns the top element of stack
	//if empty returns a default constructed object.
	T peek()
	{
		if (TOS < 0)
		{
			cout << "Stack is Empty..." << endl;
			return T();
		}

		return stack[TOS];
	}

private:
	int TOS;
	T stack[STACK_MAX_SIZE];
};

// create and test an integer stack
void testIntStack()
{
	StaticStack<int> s_int;
	cout << "Integer Push Test.." << endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			s_int.push(i);
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Integer Peek Test.." << endl;
	cout << s_int.peek() << endl;
	cout << "Integer Pop Test.." << endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			cout << s_int.pop() << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Integer Is Empty Test.." << endl;
	cout << (s_int.isEmpty() ? "stack is Empty" : "Stack is not Empty") << endl;
}


void testStringStack()
{
	StaticStack<string> s_string;
	string str;
	cout << "String Push Test.." << endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			str = "String" + to_string(i);
			s_string.push(str);
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "String Peek Test.." << endl;
	cout << s_string.peek() << endl;
	cout << "String Pop Test.." << endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			cout << s_string.pop() << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "String Is Empty Test.." << endl;
	cout << (s_string.isEmpty() ? "stack is Empty" : "Stack is not Empty") << endl;
}

// main
int main()
{
	testIntStack();
	testStringStack();
	return 0;
}
