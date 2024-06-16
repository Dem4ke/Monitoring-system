#include "workwindow.h"
#include "ui_workwindow.h"

namespace monitoring {
 WorkWindow::WorkWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::WorkWindow),
    chooseTheProject(new ChooseTheProject(parent)){
     ui->setupUi(this);
 }

 WorkWindow::~WorkWindow() {
     delete ui;
     delete chooseTheProject;
 }

 void WorkWindow::drawPlots() {

 }

 void WorkWindow::on_actionOpen_project_triggered() {
     chooseTheProject->setModal(true);
     chooseTheProject->exec();

     if (chooseTheProject->isProjectChoosen()) {
         server.openProject(chooseTheProject->getProjectName());
     }
 }

}
