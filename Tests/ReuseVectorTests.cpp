#include <QString>
#include <QtTest>
#include <ReuseVector.h>

class ReuseVectorTests : public QObject
{
	Q_OBJECT

public:
	ReuseVectorTests();

private Q_SLOTS:
	void resize()
	{
		ReuseVector<int> rv;
		rv.resize(50);

		QCOMPARE(rv.capacity(), 50);
	}
};

ReuseVectorTests::ReuseVectorTests()
{
}



QTEST_APPLESS_MAIN(ReuseVectorTests)

#include "ReuseVectorTests.moc"
