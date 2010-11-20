#include <QtGui>
#include <QWebView>
#include <QWidget>
#include "MyWidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug() << __FUNCTION__;
    MyWidget w;
    //app.setMainWidget(w);
    //
    //qDebug() << __FUNCTION__ << "before resize";
    w.resize(800, 600);

    //qDebug() << __FUNCTION__ << "before setWindow title";
    w.setWindowTitle(QApplication::translate("childwidget", "QWebView test"));

    //qDebug() << __FUNCTION__ << "before show";
    w.show();

    //qDebug() << __FUNCTION__ << "before exec";
    return app.exec();
}


