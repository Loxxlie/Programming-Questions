// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Day3.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Stack* one = new Stack(6);
	Stack* two = new Stack(6);
	Stack* three = new Stack(6);

	one->push(6);
	one->push(5);
	one->push(4);
	one->push(3);
	one->push(2);
	one->push(1);


	std::cout << "Before Solve:" << std::endl;
	one->print();
	two->print();
	three->print();

	HanoiSolve(one, three, two, one->getLength());

	std::cout << "After Solve:" << std::endl;
	one->print();
	two->print();
	three->print();

	system("pause");
}

