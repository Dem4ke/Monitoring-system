#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include "choosetheproject.h"

#include <QMainWindow>

namespace Ui {
 class WorkWindow;
}

namespace monitoring {
 class WorkWindow : public QMainWindow {
     Q_OBJECT

 public:
     explicit WorkWindow(QWidget *parent = nullptr);
     ~WorkWindow();

     void drawPlots();
 private slots:
     void on_actionOpen_project_triggered();

 private:
     Ui::WorkWindow *ui;
     ChooseTheProject *chooseTheProject;

     Server server;
 };
}
#endif // WORKWINDOW_H
