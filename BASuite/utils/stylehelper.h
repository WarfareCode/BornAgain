/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef STYLEHELPER_H
#define STYLEHELPER_H


#include <QColor>
#include <QStyle>

class QPalette;
class QPainter;
class QRect;
void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);

class StyleHelper
{
public:
    static const unsigned int DEFAULT_BASE_COLOR = 0x666666;

    // Height of the project explorer navigation bar
    static int navigationWidgetHeight() { return 24; }
    static qreal sidebarFontSize();
    static QPalette sidebarFontPalette(const QPalette &original);

    // This is our color table, all colors derive from baseColor
    static QColor requestedBaseColor() { return m_requestedBaseColor; }
    static QColor baseColor(bool lightColored = false);
    static QColor panelTextColor(bool lightColored = false);
    static QColor highlightColor(bool lightColored = false);
    static QColor shadowColor(bool lightColored = false);
    static QColor borderColor(bool lightColored = false);
    static QColor buttonTextColor() { return QColor(0x4c4c4c); }
    static QColor mergedColors(const QColor &colorA, const QColor &colorB, int factor = 50);

    static QColor sidebarHighlight() { return QColor(255, 255, 255, 40); }
    static QColor sidebarShadow() { return QColor(0, 0, 0, 40); }

    // Sets the base color and makes sure all top level widgets are updated
    static void setBaseColor(const QColor &color);

    // Draws a shaded anti-aliased arrow
    static void drawArrow(QStyle::PrimitiveElement element, QPainter *painter, const QStyleOption *option);

    // Gradients used for panels
    static void horizontalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored = false);
    static void verticalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored = false);
    static void menuGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect);
    static bool usePixmapCache() { return true; }

    static void drawIconWithShadow(const QIcon &icon, const QRect &rect, QPainter *p, QIcon::Mode iconMode,
                                   int radius = 3, const QColor &color = QColor(0, 0, 0, 130),
                                   const QPoint &offset = QPoint(1, -2));
    static void drawCornerImage(const QImage &img, QPainter *painter, QRect rect,
                         int left = 0, int top = 0, int right = 0, int bottom = 0);

    static void tintImage(QImage &img, const QColor &tintColor);

private:
    static QColor m_baseColor;
    static QColor m_requestedBaseColor;
};





//#include <QColor>
//#include <QStyle>

//class QPalette;
//class QPainter;
//class QRect;

//// Note, this is exported but in a private header as qtopengl depends on it.
//// We should consider adding this as a public helper function.
//void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);

//// Helper class holding all custom color values
//class StyleHelper
//{
//public:
//    static const unsigned int DEFAULT_BASE_COLOR = 0x666666;

//    static qreal sidebarFontSize();
//    // This is our color table, all colors derive from baseColor
//    static QColor baseColor(bool lightColored = false);
//    static QColor panelTextColor(bool lightColored = false);
//    static QColor borderColor(bool lightColored = false);
//    static QColor sidebarHighlight() { return QColor(255, 255, 255, 40); }

//    // Sets the base color and makes sure all top level widgets are updated
//    static void setBaseColor(const QColor &color);
//    static void drawIconWithShadow(const QIcon &icon, const QRect &rect, QPainter *p, QIcon::Mode iconMode, int radius = 3, const QColor &color = QColor(0, 0, 0, 130), const QPoint &offset = QPoint(1, -2));

//    static QColor requestedBaseColor() { return m_requestedBaseColor; }
//private:
//    static QColor m_baseColor;
//    static QColor m_requestedBaseColor;
//};

#endif // STYLEHELPER_H
