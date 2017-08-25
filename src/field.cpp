#include <QDebug>
#include "field.h"
namespace{
    const static QColor COLOR_BLUE(19,49,137);
    const static QColor COLOR_TRANSBLUE(19,49,137,25);
    const static QColor COLOR_YELLOW(241,231,36);
    const static QColor COLOR_TRANSYELLOW(241,231,36,25);
    const static QColor COLOR_PINK(255,63,149);
    const static QColor COLOR_GREEN(105,255,0);
    const static QColor COLOR_ORANGE(255,170,85);
    const static QColor COLOR_TRANSORANGE(255,170,85,25);
    const static QColor COLOR_DARKGREEN(Qt::darkGreen);
    const static QColor COLOR_TRANSPARENT(Qt::transparent);
}

Field::Field(QQuickItem *parent): QQuickPaintedItem(parent), pixmap(nullptr), pen(Qt::white,1) {
    connect(City::instance(),SIGNAL(needDraw()),this,SLOT(draw()));
    pixmap = new QPixmap(QSize(640, 480));
    pixmapPainter.begin(pixmap);
    area = QRect(0,0,640,480);
}

void Field::draw() {
    qDebug() << "debug" << endl;
    pixmap->fill(COLOR_DARKGREEN);
    pixmapPainter.strokePath(painterPath, pen);
    fillField();
    this->update(area);
}

void Field::paint(QPainter* painter){
    painter->drawPixmap(area,*pixmap);
}

void Field::fillField() {

}
