#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <EvernoteClient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void updateNotebooks();
    void updateTags();

private:
    Ui::MainWindow *ui;
    EvernoteClient *evernoteClient;
};

#endif // MAINWINDOW_H
