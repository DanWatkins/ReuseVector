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

    Iterator begin() { return Iterator(&mData[0]); }
	Iterator end() { return Iterator(&mData.back() + 1); }

	unsigned size() const { return mData.size(); }
	unsigned capacity() const { return mData.capacity(); }
	void resize(unsigned capacity) { mData.resize(capacity); }

	Type& front() { return mData.front(); }
	Type& back() { return mData.back(); }

	void pushBack(const Type &value) { mData.push_back(value); }

	void erase(const Iterator &position)
	{
		int offset = position.mPos - &mData[0];
		mData.erase(mData.begin()+offset);
	}

	void erase(const Iterator &begin, const Iterator &end)
	{
		typename std::vector<Type>::iterator beginStd;
		typename std::vector<Type>::iterator endStd;
		beginStd = mData.begin() + (begin.mPos-&mData[0]);
		endStd = mData.begin() + (end.mPos-&mData[0]);

		mData.erase(beginStd, endStd);
	}

	void clear()
	{
		mData.clear();
		mData.shrink_to_fit();
	}

	void swap(ReuseVector<Type> &rv)
	{
		mData.swap(rv.mData);
	}

	void insert(Iterator position, const Type &value)
	{
		mData.insert(mData.begin()+(position.mPos-&mData[0]), value);
	}

private:
	std::vector<Type> mData;
};

#endif
