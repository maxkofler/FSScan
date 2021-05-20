#include "../mainwindow.h"

#include <QProgressDialog>
#include <QProgressBar>

#include <thread>

void MainWindow::sl_new_scan(std::string dir){
    FUN();
    /*
    QProgressDialog* dialog = new QProgressDialog(this);
    //QStatusBar* dialogstatus = new QStatusBar(dialog);

    QProgressBar bar(dialog);
    dialog->setBar(&bar);

    bar.setMaximum(100);
    bar.setValue(100);
    */

    //connect(this->_indexer, &Indexer::onFinishedIndex, dialog, &QProgressDialog::close);

    connect(this->_indexer, &Indexer::onFinishedIndex, this, &MainWindow::sl_onFinishedScanning);
    connect(this->_indexer, &Indexer::onStatusUpdate, this, &MainWindow::sl_postStatusUpdate);

    std::thread th_scan(&Indexer::indexDirRecursive, this->_indexer, dir, false, false, this->_statusbar);
    //this->_indexer->indexDirRecursive(dir, false, false);
    th_scan.detach();
}

void MainWindow::sl_onFinishedScanning(){
    this->refreshItemList();
}
