
#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    User(string userName, string passWord, string userRole);
    ~User();

    string getUserName();
    void setUserName(string UserName);

    string getPassWord();
    void setPassWord(string PassWord);

    string getUserRole();
    void setUserRole(string UserRole);

    int getisLoggedIn();
    void setUserLogin(int isLoggedIn);

private:
    string m_userName;
    string m_passWord;
    string m_userRole;
    int m_isLoggedIn;
};

#endif // USER_H
