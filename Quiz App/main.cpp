
#include <iostream>
#include "quiz.h"
#include "conio2.h"
using namespace std;

int main()
{
    int c,choice,type;
    textcolor(LIGHTGREEN);
    for(int i=0;i<80;i++)
        cout<<"*";
    textcolor(LIGHTRED);
    gotoxy(32,2);
    cout<<"QUIZ APPLICATION";
    gotoxy(1,3);
    textcolor(LIGHTGREEN);
    for(int i=0;i<80;i++)
        gotoxy(20,10);
        textcolor(YELLOW);
        cout<<"WELOME TO TECH TEST - QUIZ APPLICATION";
        gotoxy(20,14);
        textcolor(LIGHTGREEN);
        cout<<"TEST YOUR SKILLS! IMPROVE YOUR KNOWLEDGE";
        textcolor(WHITE);
        gotoxy(1,20);
        cout<<"press any key to continue" ;
        getch();
        Admin::create_admin("uadmin","abc","Rohit");
        do{
            clrscr();
            gotoxy(1,1);
            textcolor(LIGHTGREEN);
            for(int i=0;i<80;i++)
                cout<<"*";
            textcolor(LIGHTRED);
            gotoxy(32,2);
            cout<<"QUIZ APPLICATION";
            gotoxy(1,3);
            textcolor(LIGHTGREEN);
            for(int i=0;i<80;i++)
                cout<<"*";
            textcolor(WHITE);
            gotoxy(58,4);
            cout<<"Press 0 to exit/go back";
            gotoxy(1,8);
            textcolor(YELLOW);
            for(int i=1;i<80;i++);
               cout<<"*";
            gotoxy(1,17);
            for(int i=0;i<80;i++)
                cout<<"*";
            gotoxy(32,10);
             textcolor(YELLOW);
             cout<<"1.Admin";
             gotoxy(32,12);
             cout<<"2.Student";
             gotoxy(32,14);
             textcolor(WHITE);
             cout<<"Select your role:";
             cin>>type;
             if(type==0)
                break;
             cin.ignore();
             if(type==1)
             {
                 Admin adminObj;
                 do
                 {
                     c=adminObj.input();
                     if(c==0)
                     {
                        gotoxy(30,14);
                     textcolor(LIGHTRED);
                     cout<<"Login cancelled";
                     gotoxy(1,20);
                     textcolor(WHITE);
                     cout<<"Press any key to continue";
                     getch();
                     break;
                     }
                     c=adminObj.checkUserExist("admin");
                     if(c==1)
                     {
                         gotoxy(28,18);
                         textcolor(LIGHTGREEN);
                         cout<<"Login Accepted!";
                         gotoxy(28,20);
                         cout<<"Welcome "<<adminObj.getName();
                         gotoxy(28,22);
                         textcolor(WHITE);
                         cout<<"Press any key to continue";
                         getch();
                         while(1)
                         {
                             clrscr();
                             textcolor(LIGHTGREEN);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                             gotoxy(1,3);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                             textcolor(LIGHTGREEN);
                             gotoxy(32,2);
                             cout<<"QUIZ APPLICATION";
                             textcolor(LIGHTGREEN);
                             gotoxy(35,6);
                             cout<<"ADMIN MENU"<<endl;
                             textcolor(YELLOW);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                                gotoxy(32,8);
                                cout<<"1. Add Question";
                                gotoxy(32,9);
                                cout<<"2. Add Student";
                                gotoxy(32,10);
                                cout<<"3. show Questions";
                                gotoxy(32,11);
                                cout<<"4. show students";
                                gotoxy(32,12);
                                cout<<"5. Remove Question";
                                gotoxy(32,13);
                                cout<<"6. Remove Student";
                                gotoxy(32,14);
                                cout<<"7. Exit";
                                gotoxy(32,16);
                                cout<<"Enter choice:";
                                textcolor(WHITE);
                                cin>>choice;
                                switch(choice)
                                {
                                case 1:
                                    clrscr();
                                    adminObj.addQuestion();
                                    break;
                                case 2:
                                    clrscr();
                                    adminObj.addStudent();
                                    break;
                                case 3:
                                    clrscr();
                                    adminObj.viewQuestion();
                                    break;
                                case 4:
                                    clrscr();
                                    adminObj.viewStudent();
                                    break ;
                                case 5:
                                    clrscr();
                                    adminObj.removeQuestion();
                                    break;
                                case 6:
                                    clrscr();
                                    adminObj.removeStudent();
                                    break;
                                case 7:
                                    clrscr();
                                    break ;
                                default:
                                    textcolor(LIGHTRED);
                                    gotoxy(32,18);
                                    cout<<"WRONG CHOICE, TRY AGAIN";
                                    getch();
                                }
                        }
                        if(choice==7)
                            break ;
                     }
                 }while(c==0);
             }
            else if(type==2)
            {
            student studObj;
                 do
                 {
                     c=studObj.input();
                     if(c==0)
                     {
                        gotoxy(30,14);
                     textcolor(LIGHTRED);
                     cout<<"Login cancelled";
                     gotoxy(1,20);
                     textcolor(WHITE);
                     cout<<"Press any key to continue";
                     getch();
                     break;
                     }
                     c=studObj.checkUserExist("student");
                     if(c==1)
                     {
                         gotoxy(28,18);
                         textcolor(LIGHTGREEN);
                         cout<<"Login Accepted!";
                         gotoxy(28,20);
                         cout<<"Welcome "<<studObj.getName();
                         gotoxy(28,22);
                         textcolor(WHITE);
                         cout<<"Press any key to continue";
                         getch();
                         while(1)
                         {
                             clrscr();
                             textcolor(LIGHTGREEN);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                             gotoxy(1,3);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                             textcolor(LIGHTGREEN);
                             gotoxy(32,2);
                             cout<<"QUIZ APPLICATION";
                             textcolor(LIGHTGREEN);
                             gotoxy(35,6);
                             cout<<"STUDENT MENU"<<endl;
                             textcolor(YELLOW);
                             for(int i=1;i<=80;i++)
                                cout<<"*";
                                gotoxy(32,9);
                                cout<<"1. Start Quiz";
                                gotoxy(32,10);
                                cout<<"2. View Performence";
                                gotoxy(32,11);
                                cout<<"7. Exit";
                                gotoxy(32,13);
                                cout<<"Enter choice:";
                                textcolor(WHITE);
                                cin>>choice;
                                switch(choice)
                                {
                                case 1:
                                    clrscr();
                                    studObj.Quiz();
                                    break;
                                case 2:
                                    clrscr();
                                    studObj.StudentPerformance();
                                    break;

                                case 3:
                                    clrscr();
                                    break ;
                                default:
                                    textcolor(LIGHTRED);
                                    gotoxy(32,18);
                                    cout<<"WRONG CHOICE, TRY AGAIN";
                                    getch();
                                }
                        }
                        if(choice==7)
                            break ;
                     }
                 }while(c==0);
            }
            else
            {
                textcolor(LIGHTRED);
                gotoxy(30,14);
                cout<<"\t\t\t\t\t\t\t\t\t";
                gotoxy(30,14);
                cout<<"Invalid user type";
                getch();
                textcolor(WHITE);
                clrscr();
            }
        }while((type!=1 || type!=2));

    return 0;
}
