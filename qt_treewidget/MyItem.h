#ifndef __MYITEM__
#define __MYITEM__

#include <QTreeWidgetItem>

class MyItem : public QTreeWidgetItem
{
    public:
        MyItem(QTreeWidget * parent = 0)
            : QTreeWidgetItem(parent)
        {
            this->setText(0, "column one");
            this->setText(1, "column two");
            this->setText(2, "column three");
            this->setText(3, "column four");
            this->setText(4, "column five");
            this->setText(5, "column six");
        }

        ~MyItem() { }
};
#endif
