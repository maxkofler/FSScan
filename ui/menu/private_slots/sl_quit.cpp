#include "../uimenu.h"

void UIMenu::sl_quit(){
    FUN();
    QMessageBox msg;
    msg.setText("Wirklich verlassen?");
    msg.setInformativeText("Möchten sie das Programm wirklich verlassen?");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int ret = msg.exec();

    switch (ret) {
        case QMessageBox::Ok:   emit onQuit();      break;
    default:    break;
    }
}
