#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mysleep(unsigned int msec)
{
    QTime newTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < newTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);

}

void MainWindow::run()
{
    while(1){
        int car_x = ui->label->x();
        int car_y = ui->label->y();

        //向左走
        for(int i = car_x; i > 0; i--){
            ui->label->setGeometry(i,ui->label->y(),
                                 ui->label->width(),
                                 ui->label->height()
                                 );
            mysleep(10);
        }

        //向下走
        for(int i = car_y; i <= 285; i++){
            ui->label->setGeometry(ui->label->x(),i,
                                 ui->label->width(),
                                 ui->label->height()
                                 );
            mysleep(10);
        }

        //向右走
        for(int i = car_y; i <= 490; i++){
            ui->label->setGeometry(i,ui->label->y(),
                                 ui->label->width(),
                                 ui->label->height()
                                 );
            mysleep(10);
        }

        //向上走
        for(int i = car_x-243; i > 0; i--){
            ui->label->setGeometry(ui->label->x(),i,
                                 ui->label->width(),
                                 ui->label->height()
                                 );
            mysleep(10);
        }
    }
}

