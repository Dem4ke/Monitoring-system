#include "signin.h"
#include "ui_signin.h"

namespace monitoring {
 SignIn::SignIn(QWidget *parent) :
     QDialog(parent), ui(new Ui::SignIn) {

     ui->setupUi(this);
 }

 SignIn::~SignIn() {
     delete ui;
 }

 bool SignIn::signIn(std::vector<QString> &userInfo) {
     return server.isPasswordCorrect(userInfo);
 }

 bool SignIn::getUserStatus() { return isUserRegistrated; }

 // Sign in user in a system
 void SignIn::on_signInButton_clicked() {
     userInfo.clear();

     userLogin = ui->userLogin->text();
     userInfo.push_back(userLogin);

     userPassword = ui->userPassword->text();
     userInfo.push_back(userPassword);

     if (signIn(userInfo)) {
         isUserRegistrated = true;
         this->close();
     } else {
         QMessageBox::warning(this, "Denied", "User or password is wrong");
     }
 }
}
