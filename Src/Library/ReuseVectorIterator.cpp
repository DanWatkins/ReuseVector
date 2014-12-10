#ifndef _REUSE_VECTOR_ITERATOR_CPP
#define _REUSE_VECTOR_ITERATOR_CPP

#include "ReuseVectorIterator.h"

#define iterator_t ReuseVector<Type>::Iterator
//template <typename W> using iterator_t = ReuseVector<W>::Iterator;



template <typename Type>
typename ReuseVector<Type>::Iterator& ReuseVector<Type>::Iterator::operator++()
{
    ++mPos;
    return *this;
}


template <typename Type>
typename iterator_t& iterator_t::operator--()
{
    --mPos;
    return *this;
}


template <typename Type>
bool iterator_t::operator==(const typename iterator_t &iter)
{
    return mPos == iter.mPos;
}


template <typename Type>
bool iterator_t::operator!=(const typename iterator_t &iter)
{
    return mPos != iter.mPos;
}


template <typename Type>
typename iterator_t iterator_t::operator+(int offset)
{
	return Iterator(mPos + offset);
}


template <typename Type>
typename iterator_t iterator_t::operator-(int offset)
{
    return Iterator(mPos - offset);
}


template <typename Type>
typename iterator_t& iterator_t::operator+=(int offset)
{
    mPos += offset;
    return *this;
}


template <typename Type>
typename iterator_t& iterator_t::operator-=(int offset)
{
    mPos -= offset;
    return *this;
}

#endif
