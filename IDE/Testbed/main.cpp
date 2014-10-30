#include <QCoreApplication>
#include <ReuseVector.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	ReuseVector<int> rv;

	return a.exec();
}
