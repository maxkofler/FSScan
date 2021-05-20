#include "../mainwindow.h"

#include <fstream>

void MainWindow::sl_load_db(std::string path){
    FUN();

    std::ifstream file;
    file.open(path);

    if (file.is_open()){
        int ammountLoaded = this->_indexer->loadPaths(file, false);
        this->_statusbar->showMessage(QString().fromStdString("Loaded " + std::to_string(ammountLoaded) + " entries"));
        LOGI("Loaded \"" + std::to_string(ammountLoaded) + "\" entries from \"" + path + "\"");
    }else{
        this->_statusbar->showMessage("Failed to open file!");
        LOGE("Error in opening file!");
    }

    this->refreshItemList();
}
