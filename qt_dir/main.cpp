#include <QDir>
#include <QDebug>
#include <QStringList>

// checking the behavior of QString::split() with QString::SkipEmptyParts

int main()
{
    QString dirname = "test1";
    QDir d;
    if (d.exists(dirname))
    {
        qDebug() << "Deleting dir " << dirname;
        if (d.rmdir(dirname))
        {
            qDebug() << "done";
        }
        else
        {
            qDebug() << "Delete failed.";
        }
    }
    
    qDebug() << "Deleting dir " << dirname;
    if (d.mkdir(dirname))
    {
        qDebug() << "Create succeeded.";


        QFile f(dirname);
        QFile::Permissions p = (QFile::Permissions)0x7777;
        f.setPermissions(p);
    }
    else
    {
        qDebug() << "Create failed.";
    }


}
