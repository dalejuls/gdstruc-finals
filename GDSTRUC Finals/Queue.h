#pragma once
#include "UnorderedArray.h"

template<class T>
class Queue
{
public:
	Queue(int size, int growBy = 1)
	{
		assert(size > 0 && growBy >= 0);

		mContainer = new UnorderedArray<T>(size, growBy);
		assert(mContainer != NULL);
	}

	~Queue()
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
		mContainer->pushFront(val);
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

private:
	UnorderedArray<T> * mContainer;
};