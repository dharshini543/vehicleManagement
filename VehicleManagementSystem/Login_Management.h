
#ifndef LOGINMANAGEMENT_H
#define LOGINMANAGEMENT_H
#include<list>
#include "User.h"
using namespace std;

class Login_Management
{
public:
    Login_Management();
    ~Login_Management();

    int getUserCount();
    void setUserCount(int userCount);

    list<User*> getUserList();
    void setUserList(list<User*> userList);

    User *addAdmin();
    User* signUp();
    User *login();

private:
    list<User*> m_userList;
    int m_userCount;
};

#endif // LOGINMANAGEMENT_H
