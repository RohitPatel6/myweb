#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "quiz.h"
#include "conio2.h"
#include<vector>
#include<cstdlib>
#include<time.h>
void Admin::create_admin(string userid,string password,string username)
{
    fstream fobj("Admin.bin",ios::binary|ios::in);
    if(fobj.fail())
    {
        fobj.open("Admin.bin",ios::out|ios::binary);
        Admin adminUser;
        adminUser.setUserDetails(userid,password,username);
        fobj.write((char*)&adminUser,sizeof(adminUser));
        cout<<"File created!";
    }
    else
        cout<<"File already present";
    fobj.close();
}
void User::setUserDetails(string userid,string pwd,string username)
{
    strcpy(this->userid,userid.c_str());
    strcpy(this->pwd,pwd.c_str());
    strcpy(this->username,username.c_str());


}
int User::input()
{
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(25,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(25,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<"QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"       "<<"*";
       gotoxy(25,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);
       gotoxy(20,7);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(20,8);
              cout<<"*"<<"     ";
       gotoxy(20,9);
              cout<<"*"<<"     ";
       gotoxy(20,10);
              cout<<"*"<<"     ";
       gotoxy(20,11);
              cout<<"*"<<"     ";
       gotoxy(20,12);
              cout<<"*"<<"     ";
       gotoxy(20,13);
              cout<<"*"<<"     ";
       gotoxy(20,14);
              cout<<"*"<<"     ";
       gotoxy(20,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
              cout<<"*"<<"     ";
       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";
       gotoxy(60,11);
              cout<<"*"<<"     ";
       gotoxy(60,12);
              cout<<"*"<<"     ";
       gotoxy(60,13);
              cout<<"*"<<"     ";
       gotoxy(60,14);
              cout<<"*"<<"     ";
       gotoxy(60,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(23,9);
       cout<<"        "<<"Enter UserId:";
       gotoxy(44,9);
       cin.getline(userid,20);

       if(strcmp(userid,"0")==0)
              return false;

       gotoxy(23,10);
       cout<<"        "<<"Enter Password:";
       gotoxy(46,10);

    char ch;
    int i=0;
    while(1)
    {
       ch=getch();

       if(ch==13)
        {
              break;
        }
        if(ch==8)
        {
               if(i==0)
                  continue;
               cout<<"\b \b";
               i--;
               continue;
        }
        cout<<ch;
        delay(200);
        cout<<"\b*";
        pwd[i]=ch;
        i++;
     }
     pwd[i]='\0';
     if(strcmp(pwd,"0")==0)
        return false;
     return true;
}
int User::checkUserExist(string usertype)
{
      if(strcmp(userid,"0")==0 || strcmp(pwd,"0")==0)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Both fields are mandatory";
              getch();
              return 0;
      }
      ifstream fin;
      User* uptr;

      if(usertype=="admin")
      {
             fin.open("Admin.bin",ios::in|ios::binary);
             uptr=new Admin;

      }else if(usertype=="student")
      {
             fin.open("Student.bin",ios::in|ios::binary);
             uptr=new student;
      }else
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid User Type!!";
              getch();
              return 0;
      }

      bool userIdFound=false;
      bool userpwdFound=false;

      while(1)
      {
             fin.read((char*)uptr,sizeof(*uptr));
             if(fin.eof())
               break;
             if(strcmp(userid,uptr->userid)==0)
             {
                    userIdFound=true;
                    if(strcmp(pwd,uptr->pwd)==0)
                    {
                           userpwdFound=true;
                    }
             }
      }
      bool result=false;
      if(userIdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"No such User exists!!!";
              getch();
              return 0;
      }
      else if(userIdFound&&userpwdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid Password!!!";
              getch();
              return 0;
      }
      else
      {
             strcpy(username,uptr->username);
             result=true;
      }
      fin.close();
     return result;
}
string User::getName()
{
    string USERNAME(username);
    return USERNAME;
}
void Admin::addQuestion()
{
    Question quesObj;
    quesObj.add();
    clrscr();
}
void Question::add()
{
    char uchoice;
    fstream fobj("Question.bin",ios::app|ios::in|ios::binary);
    if(!fobj)
    {
        gotoxy(32,18);
        textcolor(LIGHTRED);
        cout<<"Sorry! file cannot be opened!";
        getch();
        return;
    }
    fobj.seekg(0,ios::end);
    if(fobj.tellg()==0)
        quesid=1;
        else
        {
            fobj.seekg((-1)*sizeof(*this),ios::end);
            fobj.read((char*)this,sizeof(*this));
            cout<<"Last Question ID is: "<<quesid;
            quesid++;
        }
           cout<<endl<<"New Question Id is: "<<quesid;
getch();
           char unchoice;
        do
        {
            clrscr();
            textcolor(WHITE);
            gotoxy(58,4);
            cout<<"Press 0 to exit/Go back";
            textcolor(LIGHTGREEN);
            gotoxy(1,1);
            for(int i=0;i<80;i++)
                cout<<"*";
            gotoxy(37,2);
            textcolor(LIGHTRED);
            cout<<"QUIZ APP";
            textcolor(LIGHTGREEN);
            gotoxy(1,3);
            for(int i=0;i<80;i++)
                cout<<"*";
            textcolor(WHITE);
            gotoxy(25,5);
            cout<<"*****ADD QUESTION DETAILS*****";
            gotoxy(1,8);
            textcolor(YELLOW);
            string str;
            cout<<"Enter question:";
            textcolor(WHITE);
            cin.ignore();
            getline(cin,str,'*');
            if(strcmp(str.c_str(),"0")==0)
            {
                gotoxy(1,24);
                textcolor(LIGHTRED);
                cout<<"Closing add question"<<endl;
                getch();
                fobj.close();
                return;
            }
            strncpy(ques,str.c_str(),499);
            textcolor(LIGHTGREEN);
            cout<<endl<<"Carries Marks";
            textcolor(YELLOW);
            cin>>tot_marks;
            textcolor(LIGHTGREEN);
            cout<<endl<<"OPTIONS"<<endl<<endl;
            textcolor(YELLOW);
            cout<<"(a)";
            cin.ignore();
            textcolor(WHITE);
            getline(cin,str);
            strncpy(op1,str.c_str(),99);
            textcolor(YELLOW);
            cout<<"(b)";
            textcolor(WHITE);
            getline(cin,str);
            strncpy(op2,str.c_str(),99);
            textcolor(YELLOW);
            cout<<"(c)";
            textcolor(WHITE);
            getline(cin,str);
            strncpy(op3,str.c_str(),99);
            textcolor(YELLOW);
            cout<<"(d)";
            textcolor(WHITE);
            getline(cin,str);
            strncpy(op4,str.c_str(),99);
            bool valid;
            do
            {
                gotoxy(1,19);
                textcolor(YELLOW);
                cout<<endl<<"Enter correct ans(a/b/c/d): \b";
                textcolor(WHITE);
                cin>>ans;
                if(ans>='a'&&ans<='d')
                    valid=true;
                else{
                    gotoxy(24,22);
                     textcolor(LIGHTRED);
                     cout<<"Invalid choice. Please try again";
                     getch();
                     valid=false;
                }
            }while(valid==false);
            fobj.write((char*)this,sizeof(*this));
            quesid++;
            gotoxy(24,22);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(34,22);
            textcolor(LIGHTGREEN);
            cout<<"QUESTION ADDED SUCCESSFULLY!";
            getch();gotoxy(1,24);
            textcolor(LIGHTMAGENTA);
            cout<<endl<<"Do you want to add more questions(Y/N)";
            textcolor(WHITE);
            cin>>uchoice;
        }while(uchoice=='y' || uchoice=='Y');
        fobj.close();
}
void Admin::viewQuestion()
{
    Question quesObj;
    quesObj.viewQuestion();
    clrscr();
}
void Question::viewQuestion()
{
    ifstream fin("Question.bin" ,ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No questions have been added yet!";
         getch();
         return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
         textcolor(LIGHTRED);
         cout<<"No questions present in the file!";
         getch();
         return;
    }clrscr();
    fin.seekg(0);
    while(1)
        {
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(25,5);
        cout<<"*****SHOW QUESTION DETAILS*****";
        gotoxy(1,7);

textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
        {
            cout<<endl;
            textcolor(LIGHTRED);
            gotoxy(35,10);
            cout<<"NO MORE QUESTION PRESENT!";
            getch();
            break;

        }
    else{
        show();
        getch();
    }
        }
fin.close();
}
void Question::show()
{
    cout<<endl;
    textcolor(YELLOW);
    cout<<"Q."<<quesid<<" ";
    cout<<ques<<endl;
    cout<<"carries marks:"<<tot_marks;
    cout<<endl<<"a."<<op1;
    cout<<endl<<"b."<<op2;
    cout<<endl<<"c."<<op3;
    cout<<endl<<"d."<<op4;
    textcolor(LIGHTBLUE);
    cout<<endl<<endl<<"correct option: "<<ans<<endl;
}
void Admin::removeQuestion()
{
    Question quesobj;
    quesobj.Remove();
    clrscr();
}
void Question::Remove(){
 clrscr();


        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(25,6);

        cout<<"*****REMOVE QUESTION DETAILS*****";
        gotoxy(48,4);
        textcolor(WHITE);
        cout<<"press 0 to exit/go back "<<endl;

         ifstream fin("Question.bin",ios::in|ios::binary);
         if(!fin)
    {
        gotoxy(32,18);
        textcolor(LIGHTRED);
        cout<<"Sorry! file cannot be opened!";
        getch();
        return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
         gotoxy(1,10);
         textcolor(LIGHTRED);
         cout<<"No questions present in the file!";
         getch();
         return;
    }
   gotoxy(1,8);
        textcolor(YELLOW);
        cout<<"enter question id: \b ";
        bool found=false,valid=true;
        int id;
        ofstream fout("temp.bin",ios::out|ios::binary|ios::trunc);
        if(!fout)
    {
        gotoxy(32,10);
        textcolor(LIGHTRED);
        cout<<"  file cannot be response !";
        getch();
        fin.close();
        return;
    }

    fin.seekg(0);
    valid=false;

    do
    {
      found=false;
      cin>>id;
      if(id==0){
        fin.close();
        fout.close();
        remove("temp.bin");
        return;
      }
       else if(id<0){
        valid=false;
        gotoxy(1,25);
        textcolor(LIGHTRED);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\r Invlid Question Id";
        getch();
        gotoxy(20,8);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        gotoxy(20,8);
        getch();
        continue;
       }
       else{
            found=false;
        while(true){
            fin.read((char*)this,sizeof(*this));
            if(fin.eof())
                break;
            if(this->quesid==id){
                found=true;
                break;

            }
            else{
                fout.write((char*)this,sizeof(*this));
            }
        }
        fin.close();
        fout.close();
        if(found){
            gotoxy(1,26);
            textcolor(WHITE);
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\r Question Remove Succesfully ";
            getch();
            remove("Question.bin");
            rename("temp.bin","Question.bin");
            getch();
        }
         else{
                gotoxy(1,26);
               textcolor(WHITE);
              cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tt\t\t\t\t\r Question Id not Found ";

            remove("temp.bin");

                   getch();
                   return;
       }
       }

    }while(valid);

    }

    void Admin::addStudent()
    {
        student studobj;
        studobj.add();
    }
    void student::add()
    {
        int id;
        char stuid[12];
        char uchoice;
        string str;
        fstream fobj("Student.bin",ios::app|ios::in|ios::binary);
        fobj.seekg(0,ios::end);
        if(fobj.tellg()==0)
        {
            id=1;
        }
        else{
            fobj.seekg(-1*sizeof (*this),ios::end);
            fobj.read((char*)this,sizeof(*this));
            char *pos=strchr(userid,'-');
            if(pos!=NULL)
            {
            id=atoi(pos+1);

            }
            id++;

        }
        cout<<"Next Id is: "<<id;
        getch();
        do
        {
             textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"~";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"~";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        gotoxy(48,4);
        textcolor(WHITE);
        cout<<"press 0 to go back\exit";
        textcolor(WHITE);
        gotoxy(25,6);
        cout<<"*****Add Student Details*****";
        gotoxy(1,8);
        textcolor(LIGHTGREEN);
        cout<<"Enter Student Name: ";
        cin.ignore();
        getline(cin,str);
        strncpy(username,str.c_str(),19);
        if(strcmp(username,"0")==0)
        {
            gotoxy(1,25);
            textcolor(WHITE);
            cout<<"cancelling successfully"<<endl;
            getch();
            fobj.close();
            return;
        }
        gotoxy(1,9);
        textcolor(LIGHTGREEN);
        cout<<"Enter Student Password: ";
        textcolor(WHITE);
         getline(cin,str);
        strncpy(pwd,str.c_str(),19);
        if(strcmp(pwd,"0")==0)
        {
            gotoxy(1,25);
            textcolor(WHITE);
            cout<<"cancelling successfully"<<endl;
            getch();
            fobj.close();
            return;
        }
         sprintf(stuid,"STU-%d",id);
        strcpy(userid,stuid);
        fobj.write((char*)this,sizeof(*this));
        gotoxy(20,15);
        textcolor(LIGHTBLUE);
        cout<<"Student Added Successfully";
        cout<<endl<<"Student Id Is; "<<userid;
        getch();
        gotoxy(1,20);
        textcolor(LIGHTGRAY);
        cout<<"Do you want to add another student (y/n): ";
        cin>>uchoice;
        id++;
        }
        while(uchoice=='Y' || uchoice=='y');
            fobj.close();
    }
 void Admin::viewStudent()
 {    student studobj;
      studobj.showStudentDetails();
     clrscr();
 }
 void student::showStudentDetails()
{
    ifstream fin("Student.bin" ,ios::in|ios::binary);
    if(!fin)
    {
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Student have been added yet!";
         getch();
         return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
        gotoxy(1,10);
         textcolor(LIGHTRED);
         cout<<"No students present in the file!";
         getch();
         return;
    }clrscr();
    fin.seekg(0);
    while(1)
        {
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(WHITE);
        gotoxy(25,5);
        cout<<"*****SHOW STUDENTS DETAILS*****";
        gotoxy(1,7);

textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
        {
            cout<<endl;
            textcolor(LIGHTRED);
            gotoxy(35,10);
            cout<<"NO MORE STUDENT PRESENT!";
            getch();
            break;

        }
    else{
        show();
        getch();
        clrscr();
    }
        }
fin.close();
}
void student::show()
{
    cout<<endl;
    textcolor(YELLOW);
    cout<<"Student Name: "<<username;
    cout<<endl<<"Student id: "<<userid;
    textcolor(LIGHTBLUE);
    cout<<endl<<"Password: "<<pwd<<endl;
}

void Admin :: removeStudent()
{
      student obj;
      obj.Remove();
      clrscr();
}

void student :: Remove()
{
       string str;
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(1,1);
       for(int i=1; i<=80; i++)
        cout<<"*";
       gotoxy(1,3);
       for(int i=1;i<=80;i++)
        cout<<"*";
       textcolor(LIGHTRED);
       gotoxy(37,2);
       cout<<"QUIZ APP";
       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";
       textcolor(WHITE);
       gotoxy(25,6);
       cout<<"***** REMOVE STUDENT DETAILS *****";
       gotoxy(1,8);
       textcolor(YELLOW);
       cout<<"Enter Student ID: ";
       gotoxy(18,8);

        ifstream fin("Student.bin",ios::in|ios::binary);
        if(!fin){
            gotoxy(35,10);
            textcolor(LIGHTRED);
            cout<<"Sorry! File cannot be opened";
            getch();
            return;
        }
        fin.seekg(0,ios::end);
        if(fin.tellg()==0){
            gotoxy(1,10);
            textcolor(LIGHTRED);
            cout<<"No More Student Present... ";
            getch();
            fin.close();
            return;
        }
        fin.seekg(0,ios::beg);

      ofstream fout("temp.bin",ios::out|ios::binary);
      if(!fout)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Sorry! removal not possible!";
            getch();
            return;
      }
      bool valid=true;

      bool found=false;

     cin.ignore();

      do
      {
           textcolor(LIGHTGREEN);
           gotoxy(22,13);
           cout<<"\t\t\t\t\t\t\t\t";
           valid=true;
           gotoxy(18,8);
           cout<<"\t\t";
           gotoxy(18,8);
           getline(cin,str);
           if(str == "0")
           {
                  fin.close();
                  fout.close();
                  remove("temp.bin");
                  return;
           }
           if(str.size() < 3)
           {
                 textcolor(LIGHTRED);
                 gotoxy(25,13);
                 cout<<"ID Must have 3 characters!!!!";
                 getch();
           }
           else
           {
                   while(1)
                   {
                          fin.read((char*)this,sizeof(*this));
                          if(fin.eof())
                              break;
                          if(strcmp(this->userid,str.c_str())==0)
                          {
                                 found=true;
                                 continue;
                          }else{
                                 fout.write((char*)this,sizeof(*this));
                          }
                   }
                   fin.close();
                   fout.close();
                   if(found)
                   {
                        textcolor(LIGHTGREEN);
                        gotoxy(25,13);
                        cout<<"Student removed Successfully!!!";
                        getch();
                        remove("Student.bin");
                        rename("temp.bin","Student.bin");
                        return;
                   }
                   else
                   {
                        textcolor(LIGHTRED);
                        gotoxy(25,13);
                        cout<<"Student Id not found!!!";
                        getch();
                        remove("temp.bin");
                   }
           }

      }while(valid);

}

void student::Quiz()
{
    Question quesObj;
    quesObj.StartQuiz(userid);
    clrscr();
}
void Question::StartQuiz(string id)
{
    ifstream fin("Question.bin",ios::in|ios::binary);
    if(fin.fail())
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        cout<<"No Question Have Been Added Yet!!";
        getch();
        return;
    }
    vector <Question> vecQues;
    while(1){
        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
            break;
        vecQues.push_back(*this);
    }
    fin.close();
    vector<int> vecRand;
    srand((unsigned int)time(NULL));
    int randno;
    while(1)
    {
        randno=rand()%vecQues.size();
        if(isPresent(vecRand,randno)==true)
            continue;
        vecRand.push_back(randno);
        if(vecRand.size()==vecQues.size())
            break;
    }
    int count=0;
    User userObj;
    int local_marks=0;
    int local_tot_marks=0;
    string name=userObj.getName(id);
    for(int i=0;i<vecQues.size();i++)
    {
        int index=vecRand.at(i);
        *this=vecQues.at(index);
        clrscr();
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(YELLOW);
        gotoxy(1,4);
        for(int j=1;j<=80;j++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(50,5);
        cout<<name;
        gotoxy(10,5);
        cout<<"TOTAL QUESTION: "<<vecQues.size()<<endl;
        textcolor(YELLOW);
        gotoxy(1,6);
        for(int j=1;j<=80;j++)
            cout<<"*";
        textcolor(LIGHTGREEN);
        gotoxy(1,8);
        count++;
        cout<<count<<")";
        gotoxy(4,8);
        cout<<this->ques<<endl<<endl;
        textcolor(LIGHTGRAY);
        cout<<"a."<<this->op1<<endl<<endl;
        cout<<"b."<<this->op2<<endl<<endl;
        cout<<"c."<<this->op3<<endl<<endl;
        cout<<"d."<<this->op4<<endl<<endl;
        bool valid;
        char uAns;
        do
        {
            textcolor(YELLOW);
            cout<<"Enter Your Option(a/b/c/d):  \b";
            cin>>uAns;
            if(uAns>='a'&& uAns<='d')
                valid=true;
            else
            {
                valid=false;
                gotoxy(24,22);
                textcolor(LIGHTRED);
                cout<<"Invalid Option Entered. Try again...";
                getch();
                gotoxy(24,22);
                cout<<"\t\t\t\t\t\t\t\t\t";
                gotoxy(1,18);
            }
        }while(valid==false);
        local_tot_marks+= this->tot_marks;
        if(uAns==this->ans)
            local_marks+=this->tot_marks;

        getch();
    }

    clrscr();
    gotoxy(37,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(YELLOW);
    gotoxy(1,4);
    for(int j=1;j<=80;j++)
        cout<<"*";
    gotoxy(32,10);
    textcolor(LIGHTRED);
    cout<<"*** TEXT FINISHED ***";
    gotoxy(22,12);
    cout<<"PRES ANY KEY TO GO BACK MAIN MANU";
    getch();
    StudentPerformance sp;
    sp.setMarksDetails(id,local_marks,local_tot_marks);
    getch();
}
bool isPresent(vector<int> & v,int value)
{
    for(int i=0;i<v.size();i++)
    {
        if(v.at(i)==value)
            return true;
    }
    return false;
}
void StudentPerformance::setMarksDetails(string id,int marks,int tot_marks)
{
    strcpy(studid,id.c_str());
    this->marks=marks;
    this->tot_marks=tot_marks;
    saveMarksDetails();
}
void StudentPerformance::saveMarksDetails()
{
    ofstream fout("Performance.bin",ios::app|ios::binary);
    if(!fout)
    {
        gotoxy(1,26);
        textcolor(LIGHTRED);
        //cout<<"Error in creating/Opening file";
        //getch();
        return;
    }
    fout.write((char*)this,sizeof(*this));
    fout.close();
}


string User::getName(string id)
{
    ifstream fin("Student.bin",ios::in|ios::binary);
    while(1)
    {
        fin.read((char*)this,sizeof(User));
        if(fin.eof())
        {
            //cout<<"No match of record found!";
            break;
        }
        int result=strcmp(this->userid,id.c_str());
        if(result==0)
        {
            fin.close();
            return this->username;
        }
    }
    fin.close();
    return NULL;
}


void student::StudentPerformance()
{
       string id;
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(1,1);
       for(int i=1; i<=80; i++)
        cout<<"*";
       gotoxy(1,3);
       for(int i=1;i<=80;i++)
        cout<<"*";
       textcolor(LIGHTRED);
       gotoxy(37,2);
       cout<<"QUIZ APP";
       gotoxy(58,4);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";
       textcolor(WHITE);
       gotoxy(25,6);
       cout<<"***** VIEW REPORT CARD *****";
       gotoxy(1,7);
       textcolor(YELLOW);
       for(int i=1;i<=80;i++)
            cout<<"*";
       textcolor(LIGHTBLUE);
       gotoxy(1,9);}

       /*textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       textcolor(LIGHTGREEN);
       gotoxy(20,5);
       for(int i=15; i<=55; i++)
              cout<<"*";

       gotoxy(20,6);
              cout<<"*"<<"     ";
       gotoxy(20,7);
              cout<<"*"<<"     ";

       gotoxy(60,6);
              cout<<"*"<<"     ";
       gotoxy(60,7);
              cout<<"*"<<"     ";

       gotoxy(58,1);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);

       gotoxy(20,8);
       for(int i=15; i<=55; i++)
              cout<<"*";*/

       //textcolor(LIGHTBLUE);
       //gotoxy(26,6);


     /* cout<<"Enter Studnet Id: ";
       textcolor(LIGHTGRAY);
       cin.ignore();

      getline(cin,id);
      StudentPerformance stuPerObj;
      stuPerObj.viewDetails(id);
      clrscr();
}


void StudentPerformance::viewDetails(string id)
{
        int testNo=1;
        ifstream fin("Performance.bin",ios::in | ios::binary);
        if(!fin)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
       }
       fin.seekg(0,ios::end);
       if(fin.tellg()==0)
       {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"No Record present!!";
            getch();
            return;
       }

       fin.seekg(0,ios::beg);

       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(1,1);
       for(int i=1; i<=80; i++)
        cout<<"*";
       gotoxy(1,3);
       for(int i=1;i<=80;i++)
        cout<<"*";
       textcolor(LIGHTRED);
       gotoxy(37,2);
       cout<<"QUIZ APP";
       textcolor(WHITE);
       gotoxy(25,6);
       cout<<"***** VIEW REPORT CARD *****";
       textcolor(YELLOW);
       gotoxy(1,7);
       for(int i=1;i<=80;i++)
            cout<<"*";

       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       textcolor(LIGHTGREEN);
       gotoxy(26,5);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
              cout<<"*"<<"     ";
       gotoxy(26,7);
              cout<<"*"<<"     ";

       gotoxy(55,6);
              cout<<"*"<<"     ";
       gotoxy(55,7);
              cout<<"*"<<"     ";

       gotoxy(26,8);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
       cout<<"*";
       textcolor(LIGHTBLUE);
       cout<<"     "<<"View Report Card";

       gotoxy(35,10);
       User obj;
       textcolor(LIGHTMAGENTA);
       string name=obj.getName(id);
       cout<<name<<endl;

       textcolor(LIGHTBLUE);

       gotoxy(1,12);
       for(int i=1; i<=80; i++)
              cout<<"-";

       gotoxy(2,13);
       cout<<"TEST NO.               |";

       gotoxy(35,13);
       cout<<"MARKS OBTAINED            |";

       gotoxy(69,13);
       cout<<"TOTAL MARKS";

       gotoxy(1,14);
       for(int i=1; i<=80; i++)
              cout<<"-";

       gotoxy(1,15);

       while(1)
       {
              fin.read((char*)this,sizeof(*this));
              if(fin.eof())
              {
                     break;
              }

              if(strcmp(id.c_str(),this->studid)==0)
              {
                 this->show(testNo);
              }
      }

      if(testNo==1)
      {
             gotoxy(26,24);
             textcolor(LIGHTRED);
             cout<<"No Record Found !!!";
      }
      else
      {
             gotoxy(26,24);
             textcolor(LIGHTRED);
             cout<<"No More Records";
      }
      getch();
}

/*
void StudentPerformance::show(int& testNo)
{
       textcolor(LIGHTBLUE);
       cout<<"   "<<testNo;
       textcolor(LIGHTGREEN);
       cout<<"                                 "<<this->marks;
       textcolor(LIGHTBLUE);
       cout<<"                          "<<tot_marks<<endl;
       testNo++;
}

*/
