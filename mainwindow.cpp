#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setUpMenu();
    this->setWindowTitle("qt3DViwer");
    this->resize(1024, 800);
    this->createView("NULLVIEW");
}

void MainWindow::setUpMenu() {
    //create NormalView Action
    normalViewAction = new QAction(this);

    // create MenuBar
    menuBar = new QMenuBar(this);
    menuBar -> setObjectName(QStringLiteral("menuBar"));
    menuBar -> setDefaultUp(false);

    // create file menue and setting stuff
    menuFile = new QMenu(menuBar);
    menuFile->setObjectName(QStringLiteral("menuFile"));
    this -> setMenuBar(menuBar);
    menuBar -> addAction(menuFile->menuAction());

    // add Aciton to menuFile
    menuFile -> addAction(normalViewAction);

    // set action name
    normalViewAction -> setText(QApplication::translate("MainWindow", "file open", 0));

    // set menu title
    menuFile -> setTitle(QApplication::translate("MainWindow", "File", 0));

    // connecting the signal and slot
    QObject::connect(normalViewAction, SIGNAL(triggered()), this, SLOT(normalViewSlot()));
}

void MainWindow::createView(string viewName, string path) {
    QWidget* widget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(2);
    gridLayout->setMargin(2);
    ViewBase* view = ViewFacrtory::create(viewName, path);
    gridLayout->addWidget(view, 0, 0);
    widget->setLayout(gridLayout);

    QWidget* savedWidget = this->centralWidget();
    if (savedWidget != NULL){
        savedWidget -> setParent(0);//now it is saved
    }

    this->setCentralWidget(widget);
}


void MainWindow::normalViewSlot() {
    QString file = QFileDialog::getOpenFileName(this,"",
                                                "",
                                                "Images (*.obj *.ply)"
                          );
    string path = file.toStdString();
    if (path != "") {
        createView("normalview", path);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
