#include "createaccount.h"
#include "ui_createaccount.h"

namespace monitoring {

 CreateAccount::CreateAccount(QWidget *parent) :
     QDialog(parent), ui(new Ui::CreateAccount) {

     ui->setupUi(this);
 }

 CreateAccount::~CreateAccount() {
     delete ui;
 }

 // Make a request to server for add the user
 bool CreateAccount::createAcc(std::vector<QString>& userInfo) {

     // If user doesn't exist we create a new account
     if (!server.isUserExists(userInfo[0])) {
         server.addUserData(userInfo);
         return true;
     }
     return false;
 }

  bool CreateAccount::getUserStatus() { return isUserRegistrated; }

 void CreateAccount::on_createAccButton_clicked() {
     // Set information of user
     userInfo.clear();

     userLogin = ui->userLogin->text();
     userInfo.push_back(userLogin);

     userPassword = ui->userPassword->text();
     userInfo.push_back(userPassword);

     userFirstName = ui->userFirstName->text();
     userInfo.push_back(userFirstName);

     userLastName = ui ->userLastName->text();
     userInfo.push_back(userLastName);

     userEmail = ui->userEmail->text();
     userInfo.push_back(userEmail);

     // Make a request to server for add the user
     if (createAcc(userInfo)) {
         QMessageBox::information(this, "Success","Account has been created");
         isUserRegistrated = true;
         this->close();
     } else {
         QMessageBox::warning(this, "Denied","User with same login exist");
     }
 }
}
