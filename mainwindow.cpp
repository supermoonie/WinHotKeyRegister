#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <windows.h>
#include <QMessageBox>

int translate(QString type);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    process(0)
{
    RegisterHotKey((HWND)MainWindow::winId(),
                   101,
                   MOD_CONTROL,
                   'T');
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString first = ui->comboBox_1_1->currentText();
    QString second = ui->comboBox_1_2->currentText();
    QString ch = ui->comboBox_1_3->currentText();
    RegisterHotKey((HWND)MainWindow::winId(),
                   100,
                   translate(first) | translate(second),
                   ch[0].toLatin1());
    QMessageBox::information(this, "提示", "设置成功!");
}

int translate(QString type) {
    if(type == "Ctrl") {
        return MOD_CONTROL;
    } else if (type == "Alt") {
        return MOD_ALT;
    } else if (type == "Shift") {
        return MOD_SHIFT;
    } else if (type == "Win") {
        return MOD_WIN;
    }
    return 0;
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)
    // Transform the message pointer to the MSG WinAPI
    MSG* msg = reinterpret_cast<MSG*>(message);

    // If the message is a HotKey, then ...
    if(msg->message == WM_HOTKEY){
        if(msg->wParam == 100){
            QProcess::startDetached("cmd.exe", QStringList(), "C:\\");
            qDebug() << "started";
            return true;
        }
    }
    return false;
}

void MainWindow::activated()
{
    qDebug() << "...";
}
