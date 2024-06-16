#ifndef MONITORING_SERVER_H
#define MONITORING_SERVER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <unordered_map>

namespace monitoring {

 class Server {
 public:
     Server();

     // Work tools
     void openDataToRead(const QString file);
     void openDataToWrite(const QString file);
     void closeData();
     QString firstArgFromBase(QString& line);
     QString secondArgFromBase(QString& line);

     // Water info
     std::vector<QString> getWaterNames();
     std::vector<std::pair<QString, QString>> openProject(QString waterName);

     // Users
     bool isUserExists(QString& login);
     bool isPasswordCorrect(std::vector<QString>& userInfo);
     void addUserData(std::vector<QString>& userInfo);

 private:
     const QString dataPath = "DataBase/";
     const QString usersTable = "users.txt";
     const QString waterTable = "nameOfWaters.txt";
     const QString waterInfo = "Level of water Gulf of Finland.txt";

     QFile readWriteInData;
     QTextStream writeStream;
 };
}

#endif // MONITORING_SERVER_H
