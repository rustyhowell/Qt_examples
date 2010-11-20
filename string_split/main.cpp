#include <QDir>
#include <QDebug>
#include <QStringList>

// checking the behavior of QString::split() with QString::SkipEmptyParts

int main()
{
    qDebug() << "hello";
    QString s1 = "1,2,,,3,";
    QStringList l1 = s1.split(',');
    qDebug() << l1.size();



    QStringList l2 = s1.split(',',QString::SkipEmptyParts);

    qDebug() << l2.size();

}
