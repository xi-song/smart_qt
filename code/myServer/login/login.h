#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QByteArray>
#include <QMovie>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void form_init(); //格式初始化
    void func_init(); //功能初始化
    void read_json();
    void write_json();
    void message_init(QString flag1,QString flag2);
    int flag=0;

signals:
    void login_in(); //登录主界面信号
    void close_window();  //关闭登录界面信号


public slots:
    void btn_clear_clicked();  //重置按钮按下后触发的事件
    void btn_log_clicked();  //登录按钮按下后触发的事件


private slots:
    void on_btn_log_clicked();

private:
    QString m_username;
    QString m_password;

    Ui::login *ui;


};

#endif // LOGIN_H
