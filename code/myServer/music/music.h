#ifndef MUSIC_H
#define MUSIC_H

#include <QMainWindow>

namespace Ui {
class music;
}

class music : public QMainWindow
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();

private:
    Ui::music *ui;
};

#endif // MUSIC_H
