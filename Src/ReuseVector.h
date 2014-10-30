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

	unsigned size() const { return mData.size(); }
	unsigned capacity() const { return mData.capacity(); }
	void resize(unsigned capacity) { mData.resize(capacity); }

	Type& front() { return mData.front(); }
	Type& back() { return mData.back(); }

	void pushBack(const Type &value)
	{
		mData.push_back(value);
	}

private:
	std::vector<Type> mData;
};

#endif
