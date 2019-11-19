#pragma once
#include "UnorderedArray.h"

template<class T>
class Stack
{
private:
	UnorderedArray<T>* mContainer;

public:
	Stack(int size, int growBy = 1)
	{
		assert(size > 0 && growBy >= 0);

		mContainer = new UnorderedArray<T>(size, growBy);
		assert(mContainer != NULL);
	}

	~Stack()
	{
		if (mContainer != NULL)
		{
			delete mContainer;
			mContainer = NULL;
		}
	}

	void push(T val)
	{
		assert(mContainer != NULL);
		mContainer->push(val);
	}

	void pop()
	{
		assert(mContainer != NULL);
		mContainer->pop();
	}

	const T& top()
	{
		assert(mContainer != NULL);
		return (*mContainer)[mContainer->GetSize() - 1];
	}

	int getSize()
	{
		assert(mContainer != NULL);
		return mContainer->GetSize();
	}

	bool isEmpty()
	{
		assert(mContainer != NULL);
		return (mContainer->GetSize() == 0);
	}

	bool isFull()
	{
		assert(mContainer != NULL);
		return (top == mContainer->GetMaxSize() - 1);
	}

};