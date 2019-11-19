#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <assert.h>

using namespace std;

template<class T>

class UnorderedArray
{
public:
	UnorderedArray(int size, int growBy = 1) :
		mArray(NULL), mMaxSize(0), mGrowSize(0), mNumElements(0)
	{
		if (size)
		{
			mMaxSize = size;
			mArray = new T[mMaxSize];
			memset(mArray, 0, sizeof(T) * mMaxSize);
			mGrowSize = ((growBy > 0) ? growBy : 0);
		}
	}

	virtual ~UnorderedArray()
	{
		if (mArray != NULL)
		{
			delete[] mArray;
			mArray = NULL;
		}
	}

	void print()
	{
		for (int i = 0; i < GetSize(); i++)
			cout << mArray[i] << " ";
	}

	virtual void push(T val)
	{
		assert(mArray != NULL);

		if (mNumElements >= mMaxSize)
		{
			Expand();
		}

		mArray[mNumElements] = val;
		mNumElements++;
	}

	virtual void pushFront(T val)
	{
		assert(mArray != NULL);

		if (mNumElements >= mMaxSize)
		{
			Expand();
		}
		
		for (int i = mNumElements; i > 0; i--)
		{
			mArray[i] = mArray[i - 1];
		}

		mArray[0] = val;
		mNumElements++;
	}

	void pop()
	{
		if (mNumElements > 0)
		{
			mNumElements--;

		}
	}

	void popFront()
	{
		if (mNumElements > 0)
		{
			mNumElements--;

			for (int i = 0; i < mNumElements; i++)
			{
				mArray[i] = mArray[i + 1];
			}
		}
	}

	void remove(int index)
	{
		assert(mArray != NULL);

		if (index >= mMaxSize)
		{
			cout << "Index is more than the current size!" << endl;
			return;
		}

		for (int i = index; i < mMaxSize - 1; i++)
			mArray[i] = mArray[i + 1];

		mMaxSize--;

		if (mNumElements >= mMaxSize)
			mNumElements = mMaxSize;
	}

	virtual T & operator[](int index)
	{
		assert(mArray != NULL && index <= mNumElements);
		return mArray[index];
	}

	virtual int linearSearch(T val)
	{
		assert(mArray != NULL);
		int i;
		for (i = 0; i < mNumElements; i++)
		{
			if (mArray[i] == val)
			{
				cout << "\nLinear Search took " << i + 1 << " comparisons.\n";
				return i;
			}
		}
		return -1;
	}

	void Clear()
	{
		mNumElements = 0;
	}

	int GetSize()
	{
		return mNumElements;
	}

	int GetMaxSize()
	{
		return mMaxSize;
	}

	int GetGrowSize()
	{
		return mGrowSize;
	}

	void SetGrowSize(int val)
	{
		assert(val >= 0);
		mGrowSize = val;
	}


private:
	T* mArray;
	int mMaxSize;
	int mGrowSize;
	int mNumElements;

	bool Expand()
	{
		if (mGrowSize <= 0)
		{
			return false;
		}

		T* temp = new T[mMaxSize + mGrowSize];
		assert(temp != NULL);

		memcpy(temp, mArray, sizeof(T) * mMaxSize);

		delete[] mArray;
		mArray = temp;

		mMaxSize += mGrowSize;
		return true;
	}
};