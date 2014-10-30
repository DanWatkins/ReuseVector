#include <QString>
#include <QtTest>
#include <ReuseVector.h>

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
