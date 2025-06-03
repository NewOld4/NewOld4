#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
static void _PrintUser(clsUser User)
      {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUsername    : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";
      }  
public:
   static void ShowFindUserScreen()
   {
       _DrawScreenHeader("\tFind User Screen");

        string Username = "";

        cout << "\nPlease Enter Username: ";

        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username)) 
        {
          cout << "\nUsername is not found, choose another one: ";
          Username = clsInputValidate::ReadString();
        }

       clsUser FindUser = clsUser::Find(Username);
       
       if(!FindUser.IsEmpty())
           cout<<"\nUser Found = )\n";
       else
       {
          cout<<"\nUser NOT Found = (\n";
       }
           
       _PrintUser(FindUser);


   }
};