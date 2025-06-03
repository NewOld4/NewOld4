#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteUserScreen : protected clsScreen
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

    static void ShowDeleteUserScreen() 
    {
        _DrawScreenHeader("\tDelete User Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Username: ";

        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsUser::IsUserExist(AccountNumber)) 
        {
          cout << "\nUsername is not found, choose another one: ";
          AccountNumber = clsInputValidate::ReadString();
        }
      
        clsUser User1 = clsUser::Find(AccountNumber);
        _PrintUser(User1);
     
        cout << "\nAre you sure you want to delete this User y/n? ";
      
        char Answer = 'n';
        cin >> Answer;
      
        if (Answer == 'y' || Answer == 'Y') {
      
          if (User1.Delete()) 
          {
            cout<<"\nUser Deleted Successfully = )\n";
            _PrintUser(User1);
    
          } else 
          {
            cout << "\nError User Was not Deleted\n";
          }
        }
      }
};