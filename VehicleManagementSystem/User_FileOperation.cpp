
#include "User_FileOperation.h"
#include<fstream>
#include <iostream>

User_FileOperation::User_FileOperation()
{
    cout<<"User File operations Constructor"<<endl;
}

User_FileOperation::~User_FileOperation()
{
    cout<<"User File operations Destructor"<<endl;
}

void User_FileOperation::writeData(list<User *> userList)
{
    ofstream file("user.csv");
    if (!file)
    {
        cout << "Error opening User  file for writing!" << endl;
        return ;
    }
    file<<"UserName    "<<"Password    "<<"UserRole    "<<endl;
    for(auto* i:userList)
    {
        file<<i->getUserName()<<","<<i->getPassWord()<<","<<i->getUserRole()<<endl;
    }
    cout<<"Data written to User file"<<endl;
    file.close();
}

list<User *> User_FileOperation::readData()
{
    list<User*> userList;
    ifstream file("user.csv");
    if (!file)
    {
        cout << "Error opening User file for reading!" << endl;
        return userList;
    }

    string line, userName, passWord, userRole;
    int userID;

    getline(file, line);
    while (getline(file, userName, ',') && getline(file, passWord, ',') && getline(file, userRole))
    {
        userList.push_back(new User(userName, passWord, userRole));
    }

    file.close();
    cout<<"Data read from User file"<<endl;

    return userList;
}
