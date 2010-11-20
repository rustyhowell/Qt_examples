#include <QtGui>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTabWidget>
#include "MyItem.h"
#include "MyStyle.h"

// 1. Can I add the same QTreeWidgetItem to two separate QTreeWidget objects???
// Answer: No
//
// 2. Can I add the same QTreeWidgetItem subclass to two separateQTreeWidget objects and hide different columns?
// Answer: Yes
//
// 3. Can a QTreeWidgetItem me a multiline item?
// Answer: Yes, use newline char, and setTextAlignment() to prettiness
//
// 4. How do I hide a tree widget item?


// Forward declarations
void question1(QTreeWidget *, QTreeWidget * );
void question2(QTreeWidget *, QTreeWidget * );
void question3(QTreeWidget *);
void question4(QTreeWidget *);
void question5(QTreeWidget *);
void question6(QTreeWidget *);


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setStyle(new MyStyle(app.style()));

    // Create window
    QWidget window;
    window.resize(800, 600);
    window.setWindowTitle(QApplication::translate("childwidget", "QTreeWidget test"));
    window.show();

    // Add tab widget
    QTabWidget * tabWidget = new QTabWidget(&window);
    tabWidget->show();
    QHBoxLayout * layout = new QHBoxLayout();
    layout->addWidget(tabWidget);
    window.setLayout(layout);

    // Add two tab pages, each with a QTreeWidget
    QList<QTreeWidget*> trees;
    for (int i = 0; i < 3; ++i)
    {
        // Add tab
        QWidget * page = new QWidget(tabWidget);
        tabWidget->insertTab(i, page ,"page " + QString::number(i+1));

        QHBoxLayout * layout = new QHBoxLayout();
        QTreeWidget * treeWidget = new QTreeWidget();
        trees << treeWidget;
        layout->addWidget(treeWidget);
        page->setLayout(layout);
        treeWidget->show();
    }
    QTreeWidget * tree1 = trees.at(0);
    QTreeWidget * tree2 = trees.at(1);
    QTreeWidget * tree3 = trees.at(2);


    tree1->setSortingEnabled(true);

    question1(tree1, tree2);
    question2(tree1, tree2);
    question3(tree1);
    question4(tree1);
    question5(tree1);
    question6(tree3);

    tabWidget->setCurrentIndex(2);

    return app.exec();
}

// 1. Can I add the same QTreeWidgetItem to two separate QTreeWidget objects???
// Answer: No
void question1(QTreeWidget * tree1, QTreeWidget * tree2)
{

    QTreeWidgetItem * item1 = new QTreeWidgetItem();
    item1->setText(0,"Hello there");

    QTreeWidgetItem * item2 = new QTreeWidgetItem();
    item2->setText(0,"Hello again");
    
    tree1->addTopLevelItem(item1);
    tree2->addTopLevelItem(item1); // This item does not get shown in tree2. Answer #1: No

    tree2->addTopLevelItem(item2);
    tree1->addTopLevelItem(item2); // This item does not appear in tree1

}

// 2. Can I add the same QTreeWidgetItem subclass to two separateQTreeWidget objects and hide different columns?
// Answer: Yes
void question2(QTreeWidget * tree1, QTreeWidget * tree2)
{
    // Set headers for the tree widget to show columns
    MyItem * header1 = new MyItem();
    tree1->setHeaderItem(header1);

    MyItem * header2 = new MyItem();
    tree2->setHeaderItem(header2);

    MyItem * myItem1 = new MyItem();
    tree1->addTopLevelItem(myItem1);
    tree1->hideColumn(2);

    MyItem * myItem2 = new MyItem();
    tree2->addTopLevelItem(myItem2);
    tree2->hideColumn(4);
}

// 3. Can a QTreeWidgetItem me a multiline item?
// Answer: Yes, use newline char, and setTextAlignment() to prettiness
void question3(QTreeWidget * tree)
{
    QTreeWidgetItem * item = new QTreeWidgetItem();
    item->setText(0,"Multiline item");
    item->setText(1,"line 1\nline2\nline 3");
    item->setTextAlignment(0,Qt::AlignTop);
    item->setTextAlignment(1,Qt::AlignTop);
    tree->addTopLevelItem(item);


}

void question4(QTreeWidget * tree)
{
    // looks like the child must be hidden AFTER it's added to it's parent
    QTreeWidgetItem * item1 = new QTreeWidgetItem();
    item1->setText(0,"top level");

    QTreeWidgetItem * child1 = new QTreeWidgetItem();
    child1->setText(0,"child 1");

    QTreeWidgetItem * child2 = new QTreeWidgetItem();
    child2->setText(0,"child 2 hidden");
    //child2->setHidden(true); // this doesn't work

    QTreeWidgetItem * child3 = new QTreeWidgetItem();
    child3->setText(0,"child 3");

    tree->addTopLevelItem(item1);
    //child2->setHidden(true); // this doesn't work
    item1->addChild(child1);
    item1->addChild(child2);
    child2->setHidden(true); // this works
    item1->addChild(child3);

    //child2->setHidden(true); // this works

}

void question5(QTreeWidget * tree)
{
    for (int i = 0; i < 10; ++i)
    {
        QTreeWidgetItem * item1 = new QTreeWidgetItem();
        item1->setText(0,"top level");
        QComboBox * combo = new QComboBox(tree);
        combo->addItem("alpha");
        combo->addItem("bravo");
        combo->addItem("charlie");

        QDoubleSpinBox * box = new QDoubleSpinBox(tree);
        tree->addTopLevelItem(item1);
        tree->setItemWidget(item1, 1, combo);
        tree->setItemWidget(item1, 3, box);
    }
}

void question6(QTreeWidget * tree)
{
    tree->header()->setSortIndicatorShown(false);
    tree->setStyle(new MyStyle(tree->header(), tree->style())); // this work but applies to the application
    //tree1->setStyle(new MyStyle(tree1->header(), app.style())); // this work but applies to the application

    //tree1->setStyle(new MyStyle(&style));
    //tree1->setStyle(new MyStyle(tree1, NULL));
    tree->header()->setFixedHeight(100);
    tree->setSortingEnabled(true);

    QStringList headers;
    headers << "Column A" << "Column B" << "Column C" << "Column D" << "Column E" << ""<<""<<""<<""<<""<<""<<""<<""<<"";
    tree->setHeaderLabels(headers);

    qsrand(1234);

    for (int i = 0; i < 10; ++i)
    {
        QTreeWidgetItem * item = new QTreeWidgetItem();

        for (int j = 0; j < 10; ++j)
        {
            item->setText(j,QString::number(rand() % 20));
        }
        tree->addTopLevelItem(item);
    }

    for (int i = 0; i < tree->columnCount(); ++i)
    {
        tree->setColumnWidth(i, 30);
    }


}
