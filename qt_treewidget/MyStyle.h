#include <QtGui>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTabWidget>
#include <QStyle>


// Drawing a QTreeWidget with vertical column headers.
//

// from http://developer.qt.nokia.com/faq/answer/how_can_i_display_vertical_text_in_the_section_of_a_qheaderview
class MyStyle : public QProxyStyle
{
    private: QHeaderView * _header;
    public:
        MyStyle(QHeaderView * header, QStyle *style) : QProxyStyle(style)
        {
            Q_ASSERT(header);
            _header = header;
        }

        void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const
        {
            /// Maybe I should use QStyle::CE_HeaderSection instead of CE_HeaderLabel?
            //
            if ((widget == _header) && (element == QStyle::CE_HeaderLabel))
            {
                //qDebug() << "drawing header text";
                const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(option);
                painter->save();

                /*** Draw the label text ***/

                // Vertical column header reading down
                //painter->translate(header->rect.topLeft());
                //painter->rotate(90);
                //painter->drawText(0,0,header->text);

                // Vertical column header reading up
                int x, y, width, height;
                option->rect.getRect(&x, &y, &width, &height);
                painter->translate(header->rect.bottomLeft());
                painter->rotate(270);
                painter->drawText(40,40,header->text);
                //painter->drawText(option->rect, Qt::AlignHCenter,header->text);
                //painter->drawText(option->rect, Qt::AlignHCenter,header->text);

                /*** Draw the sort indicator arrow ***/
                //qDebug() << "drawing indicator header arrow";

                // Load the appropriate pixmap
                QPixmap pixmap;
                if (header->sortIndicator == QStyleOptionHeader::SortUp)
                {
                    // using left and right arrow. Remember, the section has be rotated/translated
                    // so up/down arrows are now sideways
                    pixmap.load("arrow_right.png");
                }
                else
                {
                    pixmap.load("arrow_left.png");
                }

                // get the dimensions
                // Here, rect is the drawing area for the arrow, which is a small area against the right 
                // edge of the column header. I do not know the dimensions of the section (ie width, height).
                // To draw the sort indicator in the center of the column header, need to implement this drawing in
                // drawControl(CE_HeaderSection) and use the rect x,y,width,height values for the header section.

                //option->rect.getRect(&x, &y, &width, &height);

                //y = 50;
                //qDebug() << QString("x=%1 y=%2 w=%3 h=%4").arg(x).arg(y).arg(width).arg(height);

                // Draw the goods
                //painter->translate(header->rect.bottomLeft());
                //painter->drawPixmap(x + width - 40, y + height - 40, pixmap);
                //painter->drawPixmap(x+width,y+height, pixmap);
                painter->drawPixmap(10,10, pixmap);

                // Finish up
                painter->restore();
                return;
            }
            return QProxyStyle::drawControl(element, option, painter, widget);
        }

        void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const
        {
            if ((widget == _header) && (element == QStyle::PE_IndicatorHeaderArrow))
            {
                // Drawing the PE_IndicatorHeaderArrow element puts the sort indicator arrow
                // in the right side of the section header. I do not have acces to the dimensions of
                // the section header from here, so I cannot guess how wide or tall the section is.
                //
                // So... if the PrimitiveElement QStyle::PE_IndicatorHeaderArrow is being drawn, don't.
                return;
            }

            // If any other PrimitiveElement is being drawn, call the default drawing function
            return QProxyStyle::drawPrimitive(element, option, painter, widget);
        }
};
