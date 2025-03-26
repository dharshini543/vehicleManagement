
#ifndef USER_FILEOPERATION_H
#define USER_FILEOPERATION_H

#include "User.h"
#include <list>

class User_FileOperation
{
public:
    User_FileOperation();
    ~User_FileOperation();

    void writeData(list<User*> userList);
    list<User*> readData();
};

#endif // USER_FILEOPERATION_H
