/*
该控件源码来着网络，链接为：
https://devbox.cn/p/613892860
*/


#ifndef SLIDERBUTTON_H
#define SLIDERBUTTON_H

#include <qwidget>
#include <qmouseevent>
#include <qpaintevent>
#include <qpainter>
#include <qpen>
#include <qpainterpath>
#include <qcolor>
#include <qtimer>
#include <qdebug>

namespace Ui {
class SliderButton;
}


class SliderButton : public QWidget
{
 Q_OBJECT

public:
 explicit SliderButton(QWidget *parent = nullptr);
 ~SliderButton();

 void set_button_size(const int &w, const int &h);
 void set_button_color(const QColor & , const QColor & ,const QColor & );

 signals:
 void signal_button_on();
 void signal_button_off();

protected:
 virtual void mousePressEvent(QMouseEvent *event);
 virtual void paintEvent(QPaintEvent *event);

public slots:
 void slot_update();

private:
 bool m_button_status;

 int m_circle_width;
 int m_button_pos;
 int m_move_distance;

 QColor m_backcolor_on;
 QColor m_backcolor_off;
 QColor m_circle_color;

 QTimer *m_timer;
};

#endif
