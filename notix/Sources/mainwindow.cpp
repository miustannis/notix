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

    // 创建和注册消息连接
    connect(_login, &LoginDialog::SwitchRegister, this, &MainWindow::SlotSwitchRegister);
    _register = new RegisterDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (_login){
        delete _register;
        _register = nullptr;
    }
    if (_register){
        delete _register;
        _register = nullptr;
    }
}

void MainWindow::SlotSwitchRegister()
{
    setCentralWidget(_register);
    _login->hide();
    _register->show();
}
