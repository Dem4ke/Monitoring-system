#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include "choosetheproject.h"
#include "qcustomplot.h"

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

     void drawPlots(QString project);
 private slots:
     void on_actionOpen_project_triggered();

     void on_actionLog_out_triggered();

 private:
     Ui::WorkWindow *ui;
     ChooseTheProject *chooseTheProject;
     QCustomPlot plot;

     QString project;
     Server server;
 };
}
#endif // WORKWINDOW_H
