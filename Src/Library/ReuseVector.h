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
     * @returns the maximum number of elements that can be stored before a
     * reallocation must occur.
     */
    unsigned capacity() const { return mData.capacity(); }

    /*
     * Removes all elements from the container with a resulting size of 0. The
     * capacity remains the same.
     */
    void clear();

    /*
     * @returns true if an occurence of value is found.
     */
    bool contains(const Type &value);

    /*
     * @returns an Iterator that points to one past the last element. The
     * Iterator is not dereferencable.
     */
    Iterator end();

    /*
	 * Nulls the value at the iterator position, and then swaps it with the last
     * value in the container. Runs in O(1) time. Size is decremented by 1.
     * Capacity is unaffected.
     */
    void erase(const Iterator &position);

    /*
     * Performs an erase(position) for each iterator position in the range
     * [begin, end]. Runs in O(n) time on the number of positions erased. Size
     * is decremented by the number of positions erased. Capacity is unaffected.
     */
    void erase(const Iterator &begin, const Iterator &end);

    /*
     * @returns a reference to the first element in the vector.
     * Calling this function while the vector is empty is undefined behavior.
     */
    Type& front() { return mData.front(); }

    /*
     * TODO remove this. It doesn't make sense for an orderless container
     */
    void insert(Iterator position, const Type &value);

    /*
     * Adds a new element after the current last element. value is copied into
     * the new location. TODO move semantics someday. This increments the size
     * by 1. If the size exceeds the capacity, a resize will occur to accomodate
     * the new element. TODO define growth rate here someday maybe.
     */
    void pushBack(const Type &value) { mData.push_back(value); }

    /*
     * @returns the number of elements in the container.
     */
    unsigned size() const { return mData.size(); }

    /*
     * Exchanges the elements in rv with the contents of this. TODO iter valid?
     */
    void swap(ReuseVector<Type> &rv);

private:
    std::vector<Type> mData;
};

#include "ReuseVector.cpp"

#endif
