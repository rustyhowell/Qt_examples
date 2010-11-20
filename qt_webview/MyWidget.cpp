#include <QtGui>
#include <QWebView>
#include <QWidget>
#include "SleeperThread.h"
#include "MyWidget.h"
#include <QWebPage>


MyWidget::MyWidget(QWidget * parent)
    : QWidget(parent)
    , webView(NULL)
    , N(5)
{
    // Create window

    qDebug() << __FUNCTION__;
    //*
    QVBoxLayout * vlayout = new QVBoxLayout();

    QWidget * top = new QWidget();
    QHBoxLayout * hlayout = new QHBoxLayout();
    QLabel * label = new QLabel();
    hlayout->addWidget(label);

    QPushButton * button = new QPushButton();
    hlayout->addWidget(button);
    button->setText("Load Xml Report 50 times");
    top->setLayout(hlayout);
    vlayout->addWidget(top);
    
    webView = new QWebView();
    webView->show();
    vlayout->addWidget(webView);
    
    this->setLayout(vlayout);
    // */

    QWebPage * page = webView->page();
    connect(page, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));

    connect(button, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(webView, SIGNAL(clicked()), this, SLOT(btn_clicked()));


    //load_web_page();
    load_simple_embedded_xml();
    //load_xml_report_N_times(1);
}

void MyWidget::load_web_page()
{
    Q_ASSERT(webView);
    QUrl url("http://www.google.com");
    webView->setUrl(url);
}

void MyWidget::load_simple_embedded_xml()
{
    Q_ASSERT(webView);
    // does not work :(
    //webView->setUpdatesEnabled(false);
    QUrl url("simple_inline_style.xml");
    //webView->setUrl(url);
    webView->load(url);
}

void MyWidget::load_xml_report_N_times(int n)
{
    //qDebug() << __FUNCTION__ << " N = " << n;
    N = n;
    QTimer::singleShot(1000, this,SLOT(load_xml_report()));

}

void MyWidget::load_xml_report()
{
    Q_ASSERT(webView);
    if (N > 0)
    {
        //webView->setUpdatesEnabled(false);
        qDebug() << __FUNCTION__ << "slot called, N = " << N;
        --N;
        QUrl url("SavedFile.1.xml");

        qDebug() << "setting url";
        webView->setUrl(url);

        //qDebug() << "repaint";
        //webView->repaint();

        //qDebug() << "reload";
        //webView->reload();

        //QTimer::singleShot(3000, this,SLOT(load_xml_report()));
    }
}

void MyWidget::btn_clicked()
{
    qDebug() << __FUNCTION__;
    load_xml_report_N_times(50);
    //QTimer::singleShot(1000, this,SLOT(load_xml_report()));
}

void MyWidget::loadFinished(bool ok)
{
    qDebug() << "load finished. bool ok = " << ok;
    if (ok)
    {
    }
    //webView->setUpdatesEnabled(true);
}
