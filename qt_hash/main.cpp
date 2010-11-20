#include <QHash>
#include <QtDebug>

int main()
{
    qDebug() << "hello";
    QHash<int, QString> hash;

    for (int i = 0; i < 10; ++i)
    {
        hash[i] = "hello " + QString::number(i);
    }

    QHashIterator<int, QString> iter(hash);

    int counter = 0;
    while(iter.hasNext())
    {
        qDebug() << counter;
        ++counter;
        iter.next();
        qDebug() << iter.key() << iter.value();
    }
}
