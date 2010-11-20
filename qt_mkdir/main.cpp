#include <QDir>
#include <QDebug>
#include <QTemporaryFile>

// Testing the functionality of QDir::mkpath()
//
// QTemporary file is deleted upon leaving scope

int main()
{
    qDebug() << "hello";
    QString p = QDir::tempPath();
    qDebug() << "tempPath() == " << p;
    p += "/ju/nk";
    QDir d;
    if (d.mkpath(p))
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "fail";
    }

    QString filename = p + "/junk.XXXXX";
    QTemporaryFile f(filename);
    qDebug() << f.fileName();
    if (f.open())
    {
        qDebug() << "open success";
        qDebug() << f.fileName();
    }
    else
    {
        qDebug() << "open fail";
        qDebug() << f.fileName();
    }
    


}
