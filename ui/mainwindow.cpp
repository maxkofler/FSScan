#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    FUN();
    ui->setupUi(this);

    this->_statusbar = new QStatusBar(this);
    setStatusBar(this->_statusbar);

    this->_menubar = new QMenuBar(nullptr);
    setMenuBar(this->_menubar);

    this->_menu = new UIMenu(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
