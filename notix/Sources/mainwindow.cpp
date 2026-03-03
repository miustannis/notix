#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login = new LoginDialog();
    setCentralWidget(_login);
    _login->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
