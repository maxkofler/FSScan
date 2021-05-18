#include "../uimenu.h"
#include <QFileDialog>

void UIMenu::sl_new_scan(){
    FUN();

    QFileDialog dialog(this->_mainwindow);

    dialog.setFileMode(QFileDialog::Directory);

    QString dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());

    LOGD("Selected directory \"" + dir.toStdString() + "\"");

    emit onNewScan(dir.toStdString());

}
