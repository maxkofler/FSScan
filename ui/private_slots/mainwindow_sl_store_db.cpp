#include "../mainwindow.h"

#include <fstream>

void MainWindow::sl_store_db(std::string path){
    FUN();

    std::ofstream file;
    file.open(path, std::ios::out);

    if (file.is_open()){
        int ammountStored = this->_indexer->savePaths(file);
        this->_statusbar->showMessage(QString().fromStdString("Stored " + std::to_string(ammountStored) + " entries"));
        LOGI("Stored DB to \"" + path + "\"");
    }else{
        LOGE("Error in opening file!");
    }

    this->refreshItemList();
}
