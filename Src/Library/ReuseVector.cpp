#ifndef _REUSE_VECTOR_IMPLEMENTATION_H
#define _REUSE_VECTOR_IMPLEMENTATION_H

#include "ReuseVector.h"
#include "ReuseVectorIterator.h"

template <typename Type>
bool ReuseVector<Type>::contains(const Type &value)
{
	auto i = mData.cbegin();
	while (i != mData.cend())
	{
		if (*i == value)
			return true;
	}

	return false;
}


template <typename Type>
void ReuseVector<Type>::erase(const Iterator &position)
{
	int offset = position.mPos - &mData[0];
	mData.erase(mData.begin()+offset);
}


template <typename Type>
void ReuseVector<Type>::erase(const Iterator &begin, const Iterator &end)
{
	typename std::vector<Type>::iterator beginStd;
	typename std::vector<Type>::iterator endStd;
	beginStd = mData.begin() + (begin.mPos-&mData[0]);
	endStd = mData.begin() + (end.mPos-&mData[0]);

	mData.erase(beginStd, endStd);
}


template <typename Type>
void ReuseVector<Type>::clear()
{
	mData.clear();
	mData.shrink_to_fit();
}


template <typename Type>
void ReuseVector<Type>::swap(ReuseVector<Type> &rv)
{
	mData.swap(rv.mData);
}


template <typename Type>
void ReuseVector<Type>::insert(Iterator position, const Type &value)
{
	mData.insert(mData.begin()+(position.mPos-&mData[0]), value);
}


template <typename Type>
typename ReuseVector<Type>::Iterator ReuseVector<Type>::begin()
{
	return Iterator(&mData[0]);
}

template <typename Type>
typename ReuseVector<Type>::Iterator ReuseVector<Type>::end()
{
	return Iterator(&mData.back() + 1);
}


#endif
