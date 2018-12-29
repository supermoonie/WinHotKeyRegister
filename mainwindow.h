#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // The method for processing native events from the OS in Qt
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void on_pushButton_clicked();
    void activated();

private:
    Ui::MainWindow *ui;
    QProcess* process;
};

#endif // MAINWINDOW_H
