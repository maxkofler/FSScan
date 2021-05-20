#include "../mainwindow.h"

void MainWindow::sl_postStatusUpdate(QString text){
    this->_statusbar->showMessage(text);
}
