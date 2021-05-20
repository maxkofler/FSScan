#include "../uimenu.h"

#include <QFileDialog>

void UIMenu::sl_store_db(){
    FUN();

    QFileDialog dialog(this->_mainwindow);

    dialog.setFileMode(QFileDialog::AnyFile);

    if (dialog.exec()){
        QStringList filepaths;
        filepaths = dialog.selectedFiles();

        LOGD("Selected file \"" + filepaths[0].toStdString() + "\"");

        emit onStoreDB(filepaths[0].toStdString());
    }else{
        LOGE("Error in executing filedialog");
    }
}
