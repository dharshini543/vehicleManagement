
#include "User.h"
#include <iostream>

User::User(string userName, string passWord, string userRole)
{
    cout<<"User Constructor"<<endl;
    m_userName = userName;
    m_passWord = passWord;
    m_userRole = userRole;
}

User::~User()
{
    cout<<"User Destructor"<<endl;
}

string User::getUserName()
{
    return m_userName;
}

string User::getPassWord()
{
    return m_passWord;
}

string User::getUserRole()
{
    return m_userRole;
}

int User::getisLoggedIn()
{
    return m_isLoggedIn;
}

void User::setUserName(string UserName)
{
    m_userName = UserName;
}

void User::setPassWord(string PassWord)
{
    m_passWord = PassWord;
}

void User::setUserRole(string UserRole)
{
    m_userRole = UserRole;
}

void User::setUserLogin(int isLoggedIn)
{
    m_isLoggedIn = isLoggedIn;
}
