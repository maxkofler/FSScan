#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    FUN();

    this->_indexer = new Indexer();
    this->_lv_model = nullptr;
    this->_filterActive = false;

    ui->setupUi(this);

    this->_le_search = ui->lineEdit;
    this->_bt_search = ui->pushButton;
    this->_lv_results = ui->listView;

    connect(this->_lv_results, &QListView::doubleClicked, this, &MainWindow::sl_doubleClickedItem);

    this->_statusbar = new QStatusBar(this);
    setStatusBar(this->_statusbar);

    this->_menubar = new QMenuBar(nullptr);
    setMenuBar(this->_menubar);

    this->_menu = new UIMenu(this);

    this->_statusbar->showMessage("Starting...", 2000);

    this->p_connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}
