
#include "Login_Management.h"
#include <iostream>
#include <string>

Login_Management::Login_Management()
{
    cout<<"Login Management Constructor"<<endl;
    m_userCount = 0;
}

Login_Management::~Login_Management()
{
    cout<<"Login Management Destructor"<<endl;

    for(auto* user : m_userList)
    {
        delete user;
    }
}

int Login_Management::getUserCount()
{
    return m_userCount;
}

void Login_Management::setUserCount(int userCount)
{
    m_userCount = userCount;
}

User* Login_Management::addAdmin()
{
    string adminName,adminPassword;

    if(m_userCount == 0)
    {
        m_userList.push_back(new User("Dharshini","1234","ADMIN"));
        m_userCount++;
        for(auto* user:m_userList)
        {
            if(user->getUserName() == "Dharshini" && user->getPassWord() == "1234")
            {
                return user;
            }
        }
        return NULL;
    }
    else
    {
        while(true)
        {
            cout<<"Enter AdminName"<<endl;
            cin>>adminName;
            if(adminName.length() > 15)
            {
                cout<<"Please enter maximum 15 Characters"<<endl;
            }
            else
            {
                break;
            }
        }
        while(true)
        {
            cout<<"Enter AdminPassword"<<endl;
            cin>>adminPassword;
            if(adminPassword.length() > 15)
            {
                cout<<"Please enter maximum 15 Characters"<<endl;
            }
            else
            {
                break;
            }
        }
        m_userList.push_back(new User(adminName, adminPassword, "ADMIN"));
        m_userCount++;
        for(auto* admin:m_userList)
        {
            if(admin->getUserName() == adminName && admin->getPassWord() == adminPassword)
            {
                return admin;
            }
        }
        return NULL;
    }
}

User* Login_Management::signUp()
{
    string userName,passWord;
    while(true)
    {
        cout<<"Enter UserName"<<endl;
        cin>>userName;
        if(userName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Password"<<endl;
        cin>>passWord;
        if(passWord.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    m_userList.push_back(new User(userName, passWord, "CUSTOMER"));
    m_userCount++;
    for(auto* user:m_userList)
    {
        if(user->getUserName() == userName && user->getPassWord() == passWord)
        {
            return user;
        }
    }
    return NULL;
}

User* Login_Management::login()
{
    string userName,passWord;
    int userFound = 0;
    while(true)
    {
        cout<<"Enter UserName"<<endl;
        cin>>userName;
        if(userName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Password"<<endl;
        cin>>passWord;
        if(passWord.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    for(auto* user:m_userList)
    {
        if(user->getUserName() == userName)
        {
            if(user->getPassWord() == passWord)
            {
                if(user->getUserRole() == "ADMIN" || user->getUserRole() == "CUSTOMER")
                {
                    user->setUserLogin(1);
                    userFound++;
                    cout<<"Login SuccessFull Welcome "<<user->getUserName()<<endl;
                    return user;
                }
            }
        }
    }
    if(userFound == 0)
    {
        cout<<"Username or password is incorrect"<<endl;
        cout<<"Please try again..."<<endl;
    }
    return NULL;

}

list<User*> Login_Management::getUserList()
{
    return m_userList;
}

void Login_Management::setUserList(list<User*> userList)
{
    m_userList= userList;
}
