#include "mainwindow.h"
#include "./ui_mainwindow.h"

namespace monitoring {

// Initialize all buttons in heap
 MainWindow::MainWindow(QWidget *parent) :
     QMainWindow(parent), ui(new Ui::MainWindow),
     signIn(new SignIn(parent)),
     createAcc(new CreateAccount(parent)),
     workWindow(new WorkWindow(parent)) {

     ui->setupUi(this);
 }

 // Clear all data
 MainWindow::~MainWindow() {
     delete ui;
     delete workWindow;
 }

 // Show sing in window
 void MainWindow::on_singIn_clicked() {
     signIn->setModal(true);
     signIn->exec();
     if (signIn->getUserStatus()) {
         delete signIn;
         hide();
         workWindow->show();
     }
 }

 // Show account create window
 void MainWindow::on_createAcc_clicked() {
     createAcc->setModal(true);
     createAcc->exec();
     if (createAcc->getUserStatus()) {
         delete createAcc;
         hide();
         workWindow->show();
     }
 }
}

