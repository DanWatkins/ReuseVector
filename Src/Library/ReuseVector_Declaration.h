#ifndef _REUSE_VECTOR_DECLARATION_H
#define _REUSE_VECTOR_DECLARATION_H

#include <vector>
#include <list>

template <typename Type>
class ReuseVector
{
public:
	ReuseVector()
	{
	}

	class Iterator
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

	/*
	 * Returns a reference to the last element in the vector.
	 * Calling this function while the vector is empty is undefined behavior.
	 */
	Type& back() { return mData.back(); }

	/*
	 * Returns an iterator pointing to the first element in the vector.
	 * If the vector is empty, the returned iterator cannot be dereferenced.
	 */
	Iterator begin() { return Iterator(&mData[0]); }

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
	Iterator end() { return Iterator(&mData.back() + 1); }

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

#endif

