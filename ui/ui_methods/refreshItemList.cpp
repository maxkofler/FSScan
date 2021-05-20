#include "../mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

void MainWindow::refreshItemList(){
    FUN();

    this->_statusbar->showMessage("Copying entries...");

    if (this->_lv_model != nullptr)
        delete this->_lv_model;

    this->_lv_model = new QStringListModel(this);
    this->_lv_list.clear();

    this->_lv_model->setStringList(this->_lv_list);
    this->_lv_results->setModel(this->_lv_model);
    this->_lv_results->setEditTriggers(QListView::NoEditTriggers);

    //Select the correct source for the entries
    if (this->_filterActive){
        for(auto& i : this->_curFilter){
            this->_lv_list.append(QString().fromStdString(i));
        }
    }else{
        for (auto& i : this->_indexer->getVector()){
            this->_lv_list.append(QString().fromStdString(i.getPath()));
        }
    }

    //Set the model, the model to the view and set the edit triggers
    this->_statusbar->showMessage(QString().fromStdString("Showing " + std::to_string(this->_lv_list.length()) + " entries (may take some time)"));

    this->repaint();

    //this->repaint();
    this->_statusbar->showMessage(QString().fromStdString("Done indexing " + std::to_string(this->_lv_list.length()) + " entries"));
}

void MainWindow::sl_doubleClickedItem(QModelIndex index){
    FUN();
    QString cur = this->_lv_list.at(index.row());
    LOGD("Selected \"" + cur.toStdString() + "\"");

    QDesktopServices::openUrl(QUrl::fromLocalFile(cur));
}
