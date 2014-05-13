#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <EvernoteClient.h>
#include <SidebarTreeModel.h>

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
    void signOut();

    void onSidebarElementClicked(QModelIndex index);
    void onNoteListElementClicked(QModelIndex index);

private:
    Ui::MainWindow *ui;
    EvernoteClient *evernoteClient;
    SidebarTreeModel *sidebarTreeModel;
    QStandardItemModel *notesListModel;
};

#endif // MAINWINDOW_H
