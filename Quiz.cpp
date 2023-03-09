#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include "Quiz.h"
#include "conio2.h"
using namespace std;

void User::setUserDetails(string user_id,string user_name ,string pwd ){
strcpy(this->userid,user_id.c_str());
strcpy(this->username,user_name.c_str());
strcpy(this->pwd,pwd.c_str());

}
void Admin::create_admin(string userid, string password, string userName)
{
 fstream fobj;
 fobj.open("Admin.bin",ios::in|ios::binary);
 if(!fobj){
    fobj.open("Admin.bin",ios::out|ios::binary);
    Admin adminUser;
    adminUser.setUserDetails(userid,password,userName);
    fobj.write((char*)&adminUser,sizeof(Admin));
    cout<<"file created!";

 }
 else
    cout<<"file already present!";
 fobj.close();

}
