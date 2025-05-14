#ifndef MUSIC_H
#define MUSIC_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>//照片的头文件
#include <QPalette>

#include <QMediaPlayer>//音频播放器
#include <QTimer>
//文件系统
#include<QDir>
#include<QFile>
#include<QFileInfo>

#include<QMessageBox>//对话框

#include<time.h>

#include<QPropertyAnimation>//动画


namespace Ui {
class music;
}
enum PLAYMODE{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE
};
class music : public QMainWindow
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();
public slots:
    void handlePlaySlot();//处理播放暂停
    void handleModeSlot();//处理音乐播放模式
    void handleNextSlot();//处理音乐下一首模式
    void handlePrevSlot();//处理音乐上一首模式
    void handleListSlot();//处理列表
    void handlePositionSlot(int position);//处理音乐进度
    void handleDurationSlot(int duration);//处理音乐总时长

private:

    QMediaPlayer *m_player;
    PLAYMODE m_mode;//模式
private:
    void initButtons();//初始化按钮
    void setButtonStyle(QPushButton * button,const QString &filename);//设置按钮的样式
    void setBackground(const QString &filename);
    void loafAPPointMusicDir(const QString &filename);//加载指定的文件夹
    void startPLayMusic();//播放音乐
    void showAnimation(QWidget *window);//显示动画
    void hideAnimation(QWidget *window);//隐藏动画
    void on_hSliderPlayProgress_sliderMoved(int position);
    void setSliderValue();
    QString settime(int time);
    void getduration();
    void setPlayTime();

    QString m_musicDir;//音乐绝对路径的文件夹
    bool m_isShow_Flag;
    QTimer *timer; //定时器
    int playtime;
private:
    Ui::music *ui;
};

#endif // MUSIC_H
