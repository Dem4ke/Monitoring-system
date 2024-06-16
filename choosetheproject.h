#ifndef CHOOSETHEPROJECT_H
#define CHOOSETHEPROJECT_H

#include "server.h"

#include <QDialog>

namespace Ui {
 class ChooseTheProject;
}

namespace monitoring {
 class ChooseTheProject : public QDialog {
     Q_OBJECT

 public:
     explicit ChooseTheProject(QWidget *parent = nullptr);
     ~ChooseTheProject();

     void setWatersList();
     QString getProjectName() const;
     bool isProjectChoosen() const;
 private slots:
     void on_choiceOfWater_clicked();

 private:
     Ui::ChooseTheProject *ui;
     Server server;

     QString currentProject;
     bool projectChoosen = false;

 };
}
#endif // CHOOSETHEPROJECT_H
