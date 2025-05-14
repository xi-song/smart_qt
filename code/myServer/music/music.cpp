#include "music.h"
#include "ui_music.h"

music::music(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);

     setWindowTitle("我的音乐播放器");//设置标题
     m_player=new QMediaPlayer(this);//音乐播放器

//     //固定窗口大小
//     setFixedSize(1420,840);
     //设置背景
     setBackground(":/imag/3.jpg");
     initButtons();//初始化按钮

//     //加载音乐
     QString musicPath="D:\\1\\learning\\QT_proj\\9_MusicAction\\music\\七里香-周杰伦.mp3";//加载音乐路径
     //注意，Windows的路径 反斜杠要变成两个 转义字符
     m_player->setMedia(QUrl::fromLocalFile(musicPath));//加载音乐

     //加载音乐文件夹
     m_musicDir ="D:\\1\\learning\\QT_proj\\9_MusicAction\\music\\";//加载音乐路径
    // m_musicDir ="D:\\1\\learning\\QT_proj\\qt_smart_home-master\\code\\myServer\\musicc";//加载音乐路径
     loafAPPointMusicDir(m_musicDir);
     //随机数种子
      srand(time(NULL));


}

music::~music()
{
    delete ui;
}


void music::on_hSliderPlayProgress_sliderMoved(int position){

    m_player->setPosition(m_player->duration()*position/100);
}
void music::setSliderValue()
{
    ui->progressBar->setValue(m_player->position()*100/m_player->duration());
    if(m_player->position()>=m_player->duration()){
        handleNextSlot();
    }
}

QString music::settime(int time)
{
    int h,m,s;
    time /= 1000;  //获得的时间是以毫秒为单位的
    h = time/3600;
    m = (time-h*3600)/60;
    s = time-h*3600-m*60;
    return QString("%1:%2:%3").arg(h).arg(m).arg(s);
}

void music::getduration()
{
     playtime =m_player->duration();
    ui->totalTime->setText(settime(playtime));
}
void music::setPlayTime()
{
    ui->currentTime->setText(settime( m_player->position()));
}



void music::initButtons(){
    setButtonStyle(ui->prevBtn,":/icon/pre.png");
    setButtonStyle(ui->nextBtn,":/icon/next.png");
    setButtonStyle(ui->playBtn,":/icon/paly.png");
    setButtonStyle(ui->modeBtn,":/icon/order.png");
    setButtonStyle(ui->listBtn,":/icon/music.png");

    ui->musicList->setStyleSheet("QListWidget{"
                                 "border: none;"
                                 "border-radius: 20px;"
                                 "background-color: rgba(255,255,255,0.7);}");
    ui->musicList->hide();//初始化隐藏列表
    m_isShow_Flag=false;

    connect(ui->playBtn,&QPushButton::clicked,this,&music::handlePlaySlot);
    connect(ui->modeBtn,&QPushButton::clicked,this,&music::handleModeSlot);
    connect(ui->nextBtn,&QPushButton::clicked,this,&music::handleNextSlot);
    connect(ui->prevBtn,&QPushButton::clicked,this,&music::handlePrevSlot);
    connect(ui->listBtn,&QPushButton::clicked,this,&music::handleListSlot);

    //处理音乐的进度
    connect(m_player,&QMediaPlayer::positionChanged,this,&music::setPlayTime);

    //处理音乐的总时长
    connect(m_player,&QMediaPlayer::durationChanged,this,&music::getduration);


    ui->progressBar->setValue(m_player->position());

    connect(timer, SIGNAL(timeout()), this, SLOT(setSliderValue()));


}//初始化按钮
void music::setButtonStyle(QPushButton * button,const QString &filename){
    button->setFixedSize(50,50);
    //按钮设置图标
    button->setIcon(QIcon(filename));
    //设置图标大小
    button->setIconSize(QSize(ui->prevBtn->width(),ui->prevBtn->height()));
    //设置按钮的背景为透明色
    button->setStyleSheet("background-color:transparent");

}//设置按钮的样式


//处理音乐总时长
void music::handleDurationSlot(int position ){

     ui->progressBar->setValue(position);//更新进度表里程


}
//处理音乐进度
void music::handlePositionSlot(int  duration ){
   ui->progressBar->setRange(0,duration); //毫秒转为 mm：ss.

}

//处理列表的槽函数
void music::handleListSlot(){
    if(m_isShow_Flag==false){
        ui->musicList->show();
        //动画的方式出现
        showAnimation(ui->musicList);
        m_isShow_Flag=true;
    }else{

        //动画的方式渐出
        hideAnimation(ui->musicList);
        ui->musicList->hide();
        m_isShow_Flag=false;
    }
}

void music::showAnimation(QWidget *window){
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(500);//动画持续时间500ms
    animation.setStartValue(QPoint(this->width(),0));//起始坐标
    animation.setEndValue(QPoint(this->width()-ui->musicList->width(),0));

    animation.start();

    QEventLoop loop;
    //等待动画结束
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}//显示动画
void music::hideAnimation(QWidget *window){
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(500);//动画持续时间500ms
    animation.setStartValue(QPoint(this->width()-ui->musicList->width(),0));
    animation.setEndValue(QPoint(this->width(),0));


    animation.start();

    QEventLoop loop;
    //等待动画结束
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}//隐藏动画

//播放音乐
void music::startPLayMusic(){
    QString musicName=ui->musicList->currentItem()->text();//音乐的名字
    QString musicAbsPath=m_musicDir+musicName+".mp3";//音乐的绝对路径
    m_player->setMedia(QUrl::fromLocalFile(musicAbsPath));//加载音乐
    handlePlaySlot();//播放音乐
}

void music::setBackground(const QString &filename){
    QPixmap pixmap(filename);//创建招聘
    QSize windowSize=this->size();//获取当前窗口大小
    QPixmap scalePixmap=pixmap.scaled(windowSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);//把图片照片缩放到当前窗口的大小
    QPalette palette=this->palette();//创建QPalette对象并设置背景照片
    palette.setBrush(QPalette::Background,QBrush(scalePixmap));//设置调色板
    this->setPalette(palette);//把调色板应用到窗口


}
void music::handlePlaySlot(){
    if(m_player->state()==QMediaPlayer::PlayingState){//如果正在播放
        m_player->pause();
        ui->playBtn->setIcon(QIcon(":/icon/paly.png"));

    }else{

        m_player->play();
        ui->playBtn->setIcon(QIcon(":/icon/stop.png"));
    }
}
void music::handleModeSlot(){
    if(m_mode==ORDER_MODE){
        m_mode=RANDOM_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/random.png"));

    }else if(m_mode==RANDOM_MODE){
        m_mode=CIRCLE_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/circle.png"));
    }else if(m_mode==CIRCLE_MODE){
        m_mode=ORDER_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/order.png"));
    }
}

void music::handleNextSlot(){
    int currentRow=ui->musicList->currentRow();
    int nextRow=0;
    if (m_mode==ORDER_MODE){
        nextRow=(currentRow+1) % ui->musicList->count();
    }else if(m_mode==RANDOM_MODE){
        //如果随机的下一首 是本身 重新来
        //如果只有一首 避免死循环
        int cnt=0;
        do{
            nextRow=rand()% ui->musicList->count();
            cnt++;
        }while((currentRow==nextRow)&&(cnt<=3));

    }else if(m_mode==CIRCLE_MODE){
        nextRow=currentRow;
    }
    ui->musicList->setCurrentRow(nextRow);
    startPLayMusic();
}

void music::handlePrevSlot(){
    //当前播放行
    int currentRow=ui->musicList->currentRow();
    int prevRow=0;
    if (m_mode==ORDER_MODE){
        prevRow=currentRow-1;
        if(prevRow<0){
            prevRow=ui->musicList->count()-1;
        }
    }else if(m_mode==RANDOM_MODE){
        //如果随机的下一首 是本身 重新来
        //如果只有一首 避免死循环
        int cnt=0;
        do{
            prevRow=rand()% ui->musicList->count();
            cnt++;
        }while((currentRow==prevRow)&&(cnt<=3));

    }else if(m_mode==CIRCLE_MODE){
        prevRow=currentRow;
    }
    //设置当前列表高亮
     ui->musicList->setCurrentRow(prevRow);
     startPLayMusic();
}

void music::loafAPPointMusicDir(const QString &filename){
    // 在初始化代码中添加

    QDir dir(filename);
    if(dir.exists()==false){
        QMessageBox::warning(this,"文件夹","文件夹打开失败");
        return;
    }
    qDebug()<<"111";
    //读文件夹
    QFileInfoList filelist = dir.entryInfoList(QDir::Files);

    for(auto element : filelist){
        //判断后缀是否是mp3文件
//        if(element.suffix() == ".mp3"){
//            ui->musicList->addItem(element.baseName());//添加到音乐列表
//        }
//        绝对注意！不能加点 .mp3
        if(element.suffix() == "mp3"){
            ui->musicList->addItem(element.baseName());//添加到音乐列表
        }
    }
    ui->musicList->setCurrentRow(0);//默认选择第一行高亮

}
