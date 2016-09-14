#include <iostream>
#include "queue.h"
#include "PriorityQueue.h"

using std::cout; 
using std::endl;

template<typename T>
class less_cmp
{
public:
	bool operator()(T lval, T rval)
	{
		return (lval < rval);
	}
};

int main()
{
	Queue<int> myQueue(10);

	PriorityQueue<int, less_cmp<int>> myPQueue(10);

	myPQueue.push(100);
	myPQueue.push(500);
	myPQueue.push(50);
	myPQueue.push(1000);
	myPQueue.push(150);

	cout << "Priority Queue contents: ";

	

	for (int i = 0; i < 10; i++)
	{
		myQueue.push(i + 1);
	}

	cout << "Queue contents: ";

	while (myQueue.empty() == false)
	{
		cout << myQueue.front() << " ";
		myQueue.pop();
	}


	system("pause");
	return 0;
}



