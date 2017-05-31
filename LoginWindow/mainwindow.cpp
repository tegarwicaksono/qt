#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //One way to set an image: uncomment the box below

    QPixmap pix(":/resources/img/login_icon.png");
    int width = ui->label_loginpic->width();
    int height = ui->label_loginpic->height();
    ui->label_loginpic->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));

    //One can add status bar to the login window.
    //Uncomment the block below
    /*
    ui->statusBar->addPermanentWidget(ui->label_statusBar);
    ui->statusBar->addPermanentWidget(ui->progressBar);
    */
    //Another way is using the GNU of Forms
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "test" && password == "test") {

        //Commenting the second dialog and the part that tells login is successful
        /*
        QMessageBox::information(this, "Login", "Login is successful!");
        hide();
        secDialog = new SecondDialog(this);

        //To run, click Build>Run qmake, AND then the Run command
        secDialog->show();
        */
        ui->statusBar->showMessage("Username and password are correct", 5000); //5000 = bar disappears in 5000 ms = 5 second
    } else {
        QMessageBox::warning(this, "Login", "Incorrect login info");
        ui->statusBar->showMessage("Username and password are incorrect", 5000); //5000 = bar disappears in 5000 ms = 5 second

    }
}
