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

	void resize(int capacity) {}
	int capacity() { return 50; }
};

#endif
