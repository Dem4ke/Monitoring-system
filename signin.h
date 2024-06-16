#ifndef SIGNIN_H
#define SIGNIN_H

#include "server.h"

#include <QDialog>
#include <QMessageBox>

namespace Ui {
 class SignIn;
}

namespace monitoring {
 class SignIn : public QDialog
 {
     Q_OBJECT

 public:
     explicit SignIn(QWidget *parent = nullptr);
     ~SignIn();

     bool signIn(std::vector<QString>& userInfo);
     bool getUserStatus();

 private slots:
     void on_signInButton_clicked();

 private:
     Ui::SignIn *ui;
     Server server;

     std::vector<QString> userInfo;
     QString userLogin;
     QString userPassword;
     bool isUserRegistrated = false;
 };
}
#endif // SIGNIN_H
