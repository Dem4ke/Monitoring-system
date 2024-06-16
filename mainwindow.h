#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "signin.h"
#include "createaccount.h"
#include "workwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
 class MainWindow;
}
QT_END_NAMESPACE

namespace monitoring {

 class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
     MainWindow(QWidget *parent = nullptr);
     ~MainWindow();

 private slots:
     void on_singIn_clicked();
     void on_createAcc_clicked();

 private:
     Ui::MainWindow *ui;
     SignIn *signIn;
     CreateAccount *createAcc;
     WorkWindow *workWindow;
 };
}
#endif // MAINWINDOW_H
