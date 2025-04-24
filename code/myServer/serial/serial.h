#ifndef SERIAL_H
#define SERIAL_H

#include <QWidget>

namespace Ui {
class serial;
}

class serial : public QWidget
{
    Q_OBJECT

public:
    explicit serial(QWidget *parent = nullptr);
    ~serial();

private:
    Ui::serial *ui;
};

#endif // SERIAL_H
