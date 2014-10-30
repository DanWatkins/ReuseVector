#ifndef REUSEVECTOR_H
#define REUSEVECTOR_H

#include <vector>
#include <list>

template <typename Type>
class ReuseVector
{
public:
	ReuseVector() :
		mCapacity(0),
		mSize(0)
	{
	}

	unsigned size() const { return mSize; }
	unsigned capacity() const { return mCapacity; }
	void resize(unsigned capacity) { mCapacity = capacity; }

	void pushBack(const Type &value)
	{
		mSize++;
	}

private:
	unsigned mCapacity;
	unsigned mSize;
};

#endif
