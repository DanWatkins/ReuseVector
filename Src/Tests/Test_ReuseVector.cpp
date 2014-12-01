#include <QString>
#include <gtest/gtest.h>
#include <ReuseVector.h>
#include <string>

class Test_ReuseVector : public ::testing::Test
{
protected:
	void testResizeCapacity(unsigned capacity)
	{
		ReuseVector<int> rv;
		rv.resize(capacity);

		ASSERT_EQ(rv.capacity(), capacity);
	}
};


TEST_F(Test_ReuseVector, resizeCheckCapacity)
{
	testResizeCapacity(0);
	testResizeCapacity(50);
	testResizeCapacity(8000);
}


TEST_F(Test_ReuseVector, pushBackCheckSize)
{
	ReuseVector<int> rv;
	ASSERT_EQ(rv.size(), 0U);

	rv.pushBack(45);
	ASSERT_EQ(rv.size(), 1U);

	rv.pushBack(77);
	ASSERT_EQ(rv.size(), 2U);
}


TEST_F(Test_ReuseVector, frontAccess1)
{
	ReuseVector<int> rv;
	rv.pushBack(4);
	rv.pushBack(77);
	ASSERT_EQ(rv.front(), 4);
}


TEST_F(Test_ReuseVector, frontAccess2)
{
	ReuseVector<std::string> rv;
	rv.pushBack("abc");
	rv.pushBack("bcd");
	rv.pushBack("cde");
	ASSERT_EQ(rv.front(), std::string("abc"));
}


TEST_F(Test_ReuseVector, backAccess1)
{
	ReuseVector<int> rv;
	rv.pushBack(45);
	ASSERT_EQ(rv.back(), 45);
}


TEST_F(Test_ReuseVector, backAccess2)
{
	ReuseVector<std::string> rv;
	rv.pushBack("Water");
	rv.pushBack("Salad");
	ASSERT_EQ(rv.back(), std::string("Salad"));
}


TEST_F(Test_ReuseVector, iteratorToBegin)
{
	ReuseVector<int> rv;
	rv.pushBack(50);
	ReuseVector<int>::Iterator iter = rv.begin();

	ASSERT_EQ(*iter, 50);
}


TEST_F(Test_ReuseVector, iteratorToBegin2)
{
	ReuseVector<int> rv;
	rv.pushBack(7);
	ReuseVector<int>::Iterator iter = rv.begin();

	ASSERT_EQ(*iter, 7);
}


TEST_F(Test_ReuseVector, iteratorIncrement1)
{
	ReuseVector<int> rv;
	rv.pushBack(50);
	rv.pushBack(300);

	ReuseVector<int>::Iterator iter = rv.begin();
	ASSERT_EQ(*(++iter), 300);
}


TEST_F(Test_ReuseVector, iteratorIncrement2)
{
	ReuseVector<std::string> rv;
	rv.pushBack("abc");
	rv.pushBack("lol");
	rv.pushBack("cpp");

	ReuseVector<std::string>::Iterator iter = rv.begin();
	++iter;
	ASSERT_EQ(*(++iter), std::string("cpp"));
}


TEST_F(Test_ReuseVector, iteratorSum)
{
	ReuseVector<int> rv;
	rv.pushBack(10);
	rv.pushBack(20);
	rv.pushBack(44);

	ASSERT_EQ(*(rv.begin()+2), 44);
}


TEST_F(Test_ReuseVector, iteratorDifference)
{
	ReuseVector<int> rv;
	rv.pushBack(10);
	rv.pushBack(20);
	rv.pushBack(44);

	ReuseVector<int>::Iterator iter = rv.begin();
	++iter;

	ASSERT_EQ(*(iter-1), 10);
}


/////// COMPOUND ASSIGNMENT ///////
ReuseVector<std::string> buildIteratorCompoundAssignmentVector()
{
	ReuseVector<std::string> rv;
	rv.pushBack("Cow");
	rv.pushBack("Ballon");
	rv.pushBack("The Walking Dead");
	rv.pushBack("Rick");
	rv.pushBack("Zombie Extras Drinking Water");
	rv.pushBack("Gareth");

	return rv;
}


TEST_F(Test_ReuseVector, iteratorAdditionAssignment)
{
	ReuseVector<std::string> rv = buildIteratorCompoundAssignmentVector();
	ASSERT_EQ(*(rv.begin()+=3), std::string("Rick"));
}


TEST_F(Test_ReuseVector, iteratorAdditionSubtractionAssignment)
{
	ReuseVector<std::string> rv = buildIteratorCompoundAssignmentVector();
	ReuseVector<std::string>::Iterator iter = rv.begin();
	iter += 4;
	iter -= 2;
	ASSERT_EQ(*iter, std::string("The Walking Dead"));
}


/////// BASIC ITERATION ///////
TEST_F(Test_ReuseVector, iteratorBeginToEnd1)
{
	ReuseVector<int> rv;
	rv.pushBack(10);
	rv.pushBack(20);
	rv.pushBack(44);

	ReuseVector<int>::Iterator iter = rv.begin();
	int sum = 0;	//sum of all values in rv

	while (iter != rv.end())
	{
		sum += *iter;
		++iter;
	}

	ASSERT_EQ(sum, 74);
}


TEST_F(Test_ReuseVector, iteratorBeginToEnd2)
{
	ReuseVector<int> rv;
	rv.pushBack(4);
	rv.pushBack(5);
	rv.pushBack(6);

	int sum = 0;	//sum of all values in rv

	ReuseVector<int>::Iterator iter = rv.begin();
	while (true)	//just testing a weird type of iteration here
	{
		if (iter == rv.end())
			break;

		sum += *iter;
		++iter;
	}

	ASSERT_EQ(sum, 15);
}


TEST_F(Test_ReuseVector, erasePosition1)
{
	ReuseVector<int> rv;
	rv.pushBack(3);
	rv.pushBack(68);

	rv.erase(rv.begin());

	ASSERT_EQ(rv.front(), 68);
	ASSERT_EQ(rv.size(), 1U);
}


TEST_F(Test_ReuseVector, erasePosition2)
{
	ReuseVector<std::string> rv;
	rv.pushBack("water");
	rv.pushBack("void");
	rv.pushBack("november");

	rv.erase(++rv.begin());

	ASSERT_EQ(rv.front(), std::string("water"));
	ASSERT_EQ(rv.size(), 2U);
}


TEST_F(Test_ReuseVector, eraseRange1)
{
	ReuseVector<int> rv;
	rv.pushBack(40);
	rv.pushBack(50);
	rv.pushBack(60);

	rv.erase(rv.begin(), rv.end());

	ASSERT_EQ(rv.size(), 0U);
}


TEST_F(Test_ReuseVector, eraseRange2)
{
	ReuseVector<std::string> rv;
	rv.pushBack("May");

	rv.erase(rv.begin(), rv.end());

	ASSERT_EQ(rv.size(), 0U);
}


TEST_F(Test_ReuseVector, eraseRange3)
{
	ReuseVector<std::string> rv;
	rv.pushBack("a");
	rv.pushBack("b");
	rv.pushBack("c");
	rv.pushBack("d");
	rv.pushBack("e");

	rv.erase(rv.begin()+1, rv.begin()+4);

	ASSERT_EQ(rv.size(), 2U);
	ASSERT_EQ(rv.front(), std::string("a"));
	ASSERT_EQ(rv.back(), std::string("e"));
}


TEST_F(Test_ReuseVector, swap1)
{
	ReuseVector<int> rv1;
	rv1.pushBack(556);
	rv1.pushBack(789);
	rv1.pushBack(9);

	ReuseVector<int> rv2;
	rv2.pushBack(2);
	rv1.swap(rv2);

	ASSERT_EQ(rv1.size(), 1U);
	ASSERT_EQ(rv1.front(), 2);
	ASSERT_EQ(rv2.size(), 3U);
	ASSERT_EQ(rv2.front(), 556);
	ASSERT_EQ(rv2.back(), 9);
}


TEST_F(Test_ReuseVector, insertSingleElement1)
{
	ReuseVector<int> rv;
	rv.pushBack(30);
	rv.pushBack(40);
	rv.pushBack(50);

	rv.insert(rv.begin(), 20);

	ASSERT_EQ(rv.front(), 20);
	ASSERT_EQ(*++rv.begin(), 30);
	ASSERT_EQ(rv.size(), 4U);
}


TEST_F(Test_ReuseVector, insertSingleElement2)
{
	ReuseVector<int> rv;
	rv.pushBack(30);
	rv.pushBack(40);
	rv.pushBack(50);

	rv.insert(++rv.begin(), 35);

	ASSERT_EQ(rv.front(), 30);
	ASSERT_EQ(*++rv.begin(), 35);
	ASSERT_EQ(rv.size(), 4U);
}
