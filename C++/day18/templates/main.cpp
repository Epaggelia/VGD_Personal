#include <iostream>
#include <string>

using std::string; 
using std::cout;
using std::endl;

template <typename T, typename U> 
T addTwoValues(T val1, U val2);


int main()
{
	cout << "5 + 6 = " << addTwoValues<int,int>(5, 6) << endl;

	cout << "5.8 + 6.3 = " << addTwoValues<float, float>(5.8f, 6.3f) << endl;

	cout << "5.8 + 6 = " << addTwoValues<float, int>(5.8f, 6) << endl;

	cout << "Hello + World = " << addTwoValues<string, string>("Hello", "World") << endl;



	system("pause");
	return 0;
}

template <typename T, typename U>
T addTwoValues(T val1, U val2)
{
	return val1 + val2;
}










