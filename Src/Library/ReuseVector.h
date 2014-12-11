#ifndef REUSEVECTOR_H
#define REUSEVECTOR_H

#include <vector>
#include <list>

/*
 *  @brief A sequence container very similar to std::vector.
 *
 *  The main difference between ReuseVector and the standard C++ vector is that
 *  the erase operation performs in O(1) time on the container size instead of
 *  O(n). Range erasures are still O(n) time on the number of elements erased,
 *  but each erasure is O(1) on the size of the container instead of O(n). This
 *  makes it very useful for systems that require data to be stored in a
 *  contiguous block of memory for performance reasons. The order of elements is
 *  not guaranteed.
 */
template <typename Type>
class ReuseVector
{
public:
    ReuseVector()
    {
    }

    class Iterator;

    /*
	 * @returns a reference to the last element in the vector.
     * Calling this function while the vector is empty is undefined behavior.
     */
    Type& back() { return mData.back(); }

    /*
	 * @returns an iterator pointing to the first element in the vector.
     * If the vector is empty, the returned iterator cannot be dereferenced.
     */
    Iterator begin();

    /*
     *
     */
    unsigned capacity() const { return mData.capacity(); }

    /*
     *
     */
    void clear();

    /*
     *
     */
    bool contains(const Type &value);

    /*
     *
     */
    Iterator end();

    /*
	 * Nulls the value at the iterator position, and then swaps it with the last
	 * value in the container. Runs in O(1) time. Size is decremented by 1 and
	 * capacity is unaffected.
     */
    void erase(const Iterator &position);

    /*
     *
     */
    void erase(const Iterator &begin, const Iterator &end);

    /*
     *
     */
    Type& front() { return mData.front(); }

    /*
     *
     */
    void insert(Iterator position, const Type &value);

    /*
     *
     */
    void pushBack(const Type &value) { mData.push_back(value); }

    /*
     *
     */
    void resize(unsigned capacity) { mData.resize(capacity); }

    /*
     *
     */
    unsigned size() const { return mData.size(); }

    /*
     *
     */
    void swap(ReuseVector<Type> &rv);

private:
    std::vector<Type> mData;
};

#include "ReuseVector.cpp"

#endif
