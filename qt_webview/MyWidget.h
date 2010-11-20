#ifndef __MyWidget_h__
#define __MyWidget_h__

#include <QtGui>
#include <QWebView>
#include <QWidget>
#include "SleeperThread.h"


class MyWidget : public QWidget
{
    Q_OBJECT

    public:
        MyWidget(QWidget * parent = NULL);

    public slots:
        void load_web_page();
        void load_simple_embedded_xml();
        void load_xml_report();
        void load_xml_report_N_times(int n);
        void btn_clicked();


        void loadFinished(bool ok);

    private:
        QWebView * webView;
        int N;
};

#endif
