#include "login.h"
#include "ui_login.h"
#include "home.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("用户登录");
    /* 设置样式*/
    QPalette pal = this->palette();

    pal.setBrush(QPalette::Background,QBrush(QPixmap("://png/lgbg.jfif")));
//    pal.setBrush(QPalette::Background,QBrush(QPixmap("://png/lgbg3.png")));
//    pal.setBrush(QPalette::Background,QBrush(QPixmap("://png/login_bkg.jpg")));
    setPalette(pal);
    setWindowIcon(QIcon("://png/bgk.jfif"));
    //登录按钮
    form_init();
    func_init();


}

login::~login()
{
    delete ui;
}

void login::form_init()
{
//    // 文件标题名
//    ui->label_title->setGeometry(120,25,160,25);
//    ui->groupBox->setGeometry(50,60,300,125);
//    ui->label_name->setGeometry(25,25,100,25);
//    ui->edit_name->setGeometry(125,25,150,25);
//    ui->label_pw->setGeometry(25,75,100,25);
//    ui->edit_pw->setGeometry(125,75,150,25);
//    ui->check_name->setGeometry(85,200,100,25);
//    ui->check_pw->setGeometry(215,200,100,25);
//    ui->btn_log->setGeometry(50,235,120,30);
//    ui->btn_clear->setGeometry(230,235,120,30);


    //调整字体大小
    QFont font;
    font.setPointSize(16); //实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->label_title->setFont(font);
    font.setPointSize(12);
    ui->label_name->setFont(font);
    ui->label_pw->setFont(font);
}


void login::func_init()
{
    // connect
    // 触发重置按钮的信号槽连接

    connect(ui->btn_clear,SIGNAL(clicked()),this,SLOT(btn_clear_clicked()));
    // 触发登录按钮的信号槽连接
    connect(ui->btn_log,SIGNAL(clicked()),this,SLOT(btn_log_clicked()));
    // 发出信号后关闭登录窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));


    ui->edit_pw->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点


    m_username = "s";
    m_password = "123456";


    read_json();
}


// 清理输入栏
void login::btn_clear_clicked()
{
    ui->edit_pw->clear();
    ui->edit_name->clear();
}


void login::on_btn_log_clicked()
{
    QString name = ui->edit_name->text();
    QString password = ui->edit_pw->text();
    m_username = "s";
    m_password = "123456";


    if (name == m_username && password == m_password)
    {

        emit(login_in());
        write_json();
        emit(close_window());
        flag=1;

    }


    else
        QMessageBox::information(this, "Warning","Username or Password is wrong !");

}



void login::btn_log_clicked()
{
    QString name = ui->edit_name->text();
    QString password = ui->edit_pw->text();
    m_username = "s";
    m_password = "123456";

    if (name == m_username && password == m_password)
    {

        emit(login_in());
        write_json();
        emit(close_window());
        flag=1;

    }


    else
        QMessageBox::information(this, "Warning","Username or Password is wrong !");


}


void login::read_json()
{
    //打开文件
    QFile file(QApplication::applicationDirPath()+"/config.json");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";

    }
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    QJsonObject obj = jdc.object();
    QString save_name_flag=obj.value("SAVE_NAME").toString();
    QString save_password_flag=obj.value("SAVE_PASSWORD").toString();
    message_init(save_name_flag,save_password_flag);


}


void login::write_json()
{
    QFile file(QApplication::applicationDirPath()+"/config.json");
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";
    }
    QJsonObject obj;
    bool flag = ui->check_name->isChecked();
    if(flag == true)
    {
        obj["SAVE_NAME"] = "1";
    }
    else
        obj["SAVE_NAME"] = "0";
    flag = ui->check_pw->isChecked();
    if(flag == true)
    {
        obj["SAVE_PASSWORD"] = "1";
    }
    else
        obj["SAVE_PASSWORD"] = "0";
    QJsonDocument jdoc(obj);
    file.write(jdoc.toJson());
    file.flush();
}



void login::message_init(QString flag1,QString flag2)
{

    if (flag1 == "1")
    {
        ui->edit_name->setText("s");
        ui->check_name->setChecked(true);
    }
    if(flag2 == "1")
    {
        ui->edit_pw->setText("123456");
        ui->check_pw->setChecked(true);
    }
}


