#include "../uimenu.h"

#include <QFileDialog>

void UIMenu::sl_load_db(){
    FUN();
    QFileDialog dialog(this->_mainwindow);

    dialog.setFileMode(QFileDialog::ExistingFile);

    if (dialog.exec()){
        QStringList filepaths;
        filepaths = dialog.selectedFiles();

        LOGD("Selected file \"" + filepaths[0].toStdString() + "\"");

        emit onLoadDB(filepaths[0].toStdString());
    }else{
        LOGE("Error in executing filedialog");
    }


}
