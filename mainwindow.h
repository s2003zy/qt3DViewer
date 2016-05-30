#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <viewfacrtory.h>
#include <QMessageBox>
#include <time.h>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QMenu *menuFile;
    QMenuBar *menuBar;
/*
 * Action list of the main window
*/
private:
    /*File Action*/
    QAction* normalViewAction;
private:
    void createView(string viewName, string path = "");
    void setUpMenu();
/*
* use the follow slot to change view
*/
private slots:
    void normalViewSlot();
};

#endif // MAINWINDOW_H
