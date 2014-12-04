#ifndef _REUSE_VECTOR_ITERATOR_H
#define _REUSE_VECTOR_ITERATOR_H

#include "ReuseVector_Declaration.h"

template <typename Type>
class ReuseVector<Type>::Iterator
{
public:
	friend class ReuseVector;
	Type operator*() { return *mPos; }

	Iterator& operator++()
	{
		++mPos;
		return *this;
	}


	Iterator& operator--()
	{
		--mPos;
		return *this;
	}


	bool operator==(const Iterator &iter)
	{
		return mPos == iter.mPos;
	}


	bool operator!=(const Iterator &iter)
	{
		return mPos != iter.mPos;
	}

	Iterator operator+(int offset)
	{
		return Iterator(mPos + offset);
	}

	Iterator operator-(int offset)
	{
		return Iterator(mPos - offset);
	}

	Iterator& operator+=(int offset)
	{
		mPos += offset;
		return *this;
	}

	Iterator& operator-=(int offset)
	{
		mPos -= offset;
		return *this;
	}

private:
	Iterator(Type *pos) :
		mPos(pos)
	{
	}

	Type *mPos;
};

#endif
