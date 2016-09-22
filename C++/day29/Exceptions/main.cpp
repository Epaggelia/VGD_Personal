#include <iostream>
#include <exception>

using std::exception;
using std::cout; 
using std::endl;

class MyException : public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened.";
	}
} myex;

int main()
{
	try
	{
		throw myex;
	}
	catch (MyException e)
	{
		cout << e.what() << endl;
	}
	catch (char e)
	{
		cout << "char: " << e << endl;
	}
	catch (int e)
	{
		cout << "int: " << e << endl;
	}

	system("pause");
	return 0;
}