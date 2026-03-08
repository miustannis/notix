#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include <QRegularExpression>

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->codelineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmlineEdit->setEchoMode(QLineEdit::Password);

    ui->errortip->setProperty("state", "normal");
    repolish(ui->errortip);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_verifybtn_clicked()
{
    // stannnnis@163.com
    auto email = ui ->emaillineEdit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();

    if (match){

    }else{
        ShowTip(tr("邮箱格式不正确"), false);
    }
}

void RegisterDialog::ShowTip(QString str, bool b_ok)
{
    if (b_ok){
        ui->errortip->setProperty("state","normal");
    }else{
        ui->errortip->setProperty("state","err");
    }
    ui->errortip->setText(str);
    repolish(ui->errortip);
}

