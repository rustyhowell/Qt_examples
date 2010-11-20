#include <QDir>
#include <QDebug>
#include <QStringList>
#include <QCryptographicHash>

// checking the behavior of QCryptographicHash

int main()
{
    QCryptographicHash hash(QCryptographicHash::Sha1);

    QString s = ("this is a test");
    hash.addData(s.toUtf8());

    // This also works
    //hash.addData("this is a test", 14);

    QByteArray r = hash.result();
    qDebug() << r.toHex();
}
