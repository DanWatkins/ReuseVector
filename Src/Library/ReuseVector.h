#ifndef REUSEVECTOR_H
#define REUSEVECTOR_H

#include <vector>
#include <list>

template <typename Type>
class ReuseVector
{
public:
    ReuseVector()
    {
    }

    class Iterator;

    /*
     * Returns a reference to the last element in the vector.
     * Calling this function while the vector is empty is undefined behavior.
     */
    Type& back() { return mData.back(); }

    /*
     * Returns an iterator pointing to the first element in the vector.
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
     *
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
