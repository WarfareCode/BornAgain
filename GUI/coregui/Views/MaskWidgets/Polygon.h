#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "DistributionEditor.h"
#include <QGraphicsView>
#include <QPainterPath>
#include <QBrush>

#ifndef POLYGON_H
#define POLYGON_H

class Polygon : public QGraphicsItem
{

public:

    enum {Type = UserType + 3};
    enum Color {INCLUDE, EXCLUDE};
    enum Corner { NONE, TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT };

    Polygon(qreal posX, qreal poxY, qreal width, qreal heigth);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void checkResizeRules(QGraphicsSceneMouseEvent *event);
    void calculateResize(QGraphicsSceneMouseEvent *event);
    qreal calculateRotation(QGraphicsSceneMouseEvent *event);
    bool checkCornerClicked(QGraphicsSceneMouseEvent *event);
    void calculateBoundingRectangle();
    void setWidth(qreal width);
    void setHeigth(qreal heigth);
    void setDrawingMode(QPointF firstPoint);
    bool getDrawingMode() const;
    void setMouseIsOverFirstPoint(bool mouseIsOverFirstPoint);
    QRectF getFirstPoint() const;
    int type() const {return Type;}
    void setExclude();
    void setInclude();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal m_posX;
    qreal m_posY;
    qreal m_width;
    qreal m_heigth;
    QRectF m_topLeftCorner;
    QRectF m_bottomLeftCorner;
    QRectF m_topRightCorner;
    QRectF m_bottomRightCorner;
    QRectF m_firstPoint;
    bool m_drawingMode;
    bool m_changeCornerMode;
    Corner m_corner;
    QPolygon m_polygon;
    int m_currentPoint1;
    int m_currentPoint2;
    bool m_mouseIsOverFirstPoint;
    Color m_color;
};
#endif
