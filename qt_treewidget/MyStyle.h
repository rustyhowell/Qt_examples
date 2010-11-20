#include <QtGui>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTabWidget>
#include <QStyle>

// from http://developer.qt.nokia.com/faq/answer/how_can_i_display_vertical_text_in_the_section_of_a_qheaderview
class MyStyle : public QProxyStyle
{
    private: QHeaderView * _header;
    public:
        MyStyle(QHeaderView * header, QStyle *style) : QProxyStyle(style)
        {
            Q_ASSERT(header);
            _header = header;
            QString st = " QHeaderView::section {";
            //st += "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            //     "stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); ";
            //st += "color: blue;";
            st += "padding-left: 4px;"; // does not affect vertical orientation
            //st += "border: 1px solid #6c6c6c;";
            st += "}";

            //QString st = "QHeaderView::section:checked { background-color: red; }";
            //QString st = "QHeaderView { color: red; }";

            st += "QHeaderView::down-arrow { image: url(down_arrow.jpg); top: 40px;}";
            // st += "QHeaderView::down-arrow { image: url(down_arrow.jpg);} ";
            st += "QHeaderView::up-arrow { image: url(up_arrow.jpg); }";

            header->setStyleSheet(st);
        }

        void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const
        {
            if ((widget == _header) && (element == QStyle::CE_HeaderLabel)) {
                /*
                const QHeaderView *hv = qobject_cast<const QHeaderView *>(widget);
                if (!hv || hv->orientation() != Qt::Horizontal)
                {
                    return QProxyStyle::drawControl(element, option, painter, widget);
                }
                */
                const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(option);
                //header->sortIndicator = QStyleOptionHeader::None;
                painter->save();

                // Vertical column header reading down
                //painter->translate(header->rect.topLeft());
                //painter->rotate(90);
                //painter->drawText(0,0,header->text);

                // Vertical column header reading up
                painter->translate(header->rect.bottomLeft());
                painter->rotate(270);
                painter->drawText(0,20,header->text);

                // Finish up
                painter->restore();
                return;
            }
            return QProxyStyle::drawControl(element, option, painter, widget);
        }
};
