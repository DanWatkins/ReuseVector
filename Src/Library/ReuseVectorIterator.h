#ifndef _REUSE_VECTOR_ITERATOR_H
#define _REUSE_VECTOR_ITERATOR_H

#include "ReuseVector.h"

template <typename Type>
class ReuseVector<Type>::Iterator
{
public:
	friend class ReuseVector;

	/*
	 *
	 */
	Type operator*() { return *mPos; }

	/*
	 *
	 */
    Iterator& operator++();

	/*
	 *
	 */
    Iterator& operator--();

	/*
	 *
	 */
    bool operator==(const Iterator &iter);

	/*
	 *
	 */
    bool operator!=(const Iterator &iter);

	/*
	 *
	 */
    Iterator operator+(int offset);

	/*
	 *
	 */
    Iterator operator-(int offset);

	/*
	 *
	 */
    Iterator& operator+=(int offset);

	/*
	 *
	 */
    Iterator& operator-=(int offset);

private:
	Iterator(Type *pos) :
		mPos(pos)
	{
	}

	Type *mPos;
};

#include "ReuseVectorIterator.cpp"

#endif
