#pragma once

#include "stdafx.h"

class Stack
{
public:
	Stack(int size);
	~Stack();

	void push(int i);
	int pop();
	int getLength();
	void print();
private:
	int* m_stack;
	int m_size;
	int m_maxSize;
};

Stack::Stack(int size)
{
	m_stack = (int*) calloc(size, sizeof(int));
	m_size = 0;
	m_maxSize = size;
}

Stack::~Stack()
{
	delete m_stack;
}

void Stack::push(int i)
{
	m_stack[m_size] = i;
	m_size++;
}

int Stack::pop()
{
	int temp = m_stack[m_size-1];
	m_stack[m_size-1] = 0;
	m_size--;
	return temp;
}

void HanoiSolve(Stack* start, Stack* goal, Stack* buffer, int numToMove)
{
	if (numToMove > 1){
		HanoiSolve(start, buffer, goal, numToMove - 1);
		goal->push(start->pop());
		HanoiSolve(buffer, goal, start, numToMove - 1);
	}
	else
		goal->push(start->pop());
}

int Stack::getLength()
{
	return m_size;
}

void Stack::print()
{
	for (int i = 0; i < m_maxSize; i++)
	{
		std::cout << m_stack[i] << ", ";
	}
	std::cout << std::endl;
}