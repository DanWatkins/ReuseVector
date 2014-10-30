#include <QString>
#include <QtTest>
#include <ReuseVector.h>
#include <string>

class ReuseVectorTests : public QObject
{
	Q_OBJECT

public:
	ReuseVectorTests();

private Q_SLOTS:
	void resizeCheckCapacity()
	{
		testResizeCapacity(0);
		testResizeCapacity(50);
		testResizeCapacity(8000);
	}


	void pushBackCheckSize()
	{
		ReuseVector<int> rv;
		QCOMPARE(rv.size(), 0U);

		rv.pushBack(45);
		QCOMPARE(rv.size(), 1U);

		rv.pushBack(77);
		QCOMPARE(rv.size(), 2U);
	}


	void frontAccess1()
	{
		ReuseVector<int> rv;
		rv.pushBack(4);
		rv.pushBack(77);
		QCOMPARE(rv.front(), 4);
	}


	void frontAccess2()
	{
		ReuseVector<std::string> rv;
		rv.pushBack("abc");
		rv.pushBack("bcd");
		rv.pushBack("cde");
		QCOMPARE(rv.front(), std::string("abc"));
	}


	void backAccess1()
	{
		ReuseVector<int> rv;
		rv.pushBack(45);
		QCOMPARE(rv.back(), 45);
	}


	void backAccess2()
	{
		ReuseVector<std::string> rv;
		rv.pushBack("Water");
		rv.pushBack("Salad");
		QCOMPARE(rv.back(), std::string("Salad"));
	}


    void iteratorToBegin()
    {
        ReuseVector<int> rv;
        rv.pushBack(50);
        ReuseVector<int>::Iterator iter = rv.begin();

        QCOMPARE(*iter, 50);
    }

    void iteratorToBegin2()
    {
        ReuseVector<int> rv;
        rv.pushBack(7);
        ReuseVector<int>::Iterator iter = rv.begin();

        QCOMPARE(*iter, 7);
    }


    void iteratorIncrement1()
    {
        ReuseVector<int> rv;
        rv.pushBack(50);
        rv.pushBack(300);

        ReuseVector<int>::Iterator iter = rv.begin();
        QCOMPARE(*(++iter), 300);
    }


    void iteratorIncrement2()
    {
        ReuseVector<std::string> rv;
        rv.pushBack("abc");
        rv.pushBack("lol");
        rv.pushBack("cpp");

        ReuseVector<std::string>::Iterator iter = rv.begin();
        ++iter;
        QCOMPARE(*(++iter), std::string("cpp"));
    }


private:
	void testResizeCapacity(unsigned capacity)
	{
		ReuseVector<int> rv;
		rv.resize(capacity);

		QCOMPARE(rv.capacity(), capacity);
	}
};

ReuseVectorTests::ReuseVectorTests()
{
}



QTEST_APPLESS_MAIN(ReuseVectorTests)

#include "ReuseVectorTests.moc"
