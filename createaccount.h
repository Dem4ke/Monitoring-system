#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include "server.h"

#include <QDialog>
#include <QMessageBox>

namespace Ui {
 class CreateAccount;
}

namespace monitoring {

 class CreateAccount : public QDialog {
     Q_OBJECT

 public:
     explicit CreateAccount(QWidget *parent = nullptr);
     ~CreateAccount();

     bool createAcc(std::vector<QString>& userInfo);
     bool getUserStatus();

 private slots:
     void on_createAccButton_clicked();

 private:
     Ui::CreateAccount *ui;
     Server server;

     std::vector<QString> userInfo;
     QString userFirstName;
     QString userLastName;
     QString userLogin;
     QString userPassword;
     QString userEmail;
     bool isUserRegistrated = false;
 };
}
#endif // CREATEACCOUNT_H
