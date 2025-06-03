#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

static int _ReadPermissionsToSet()
{
  int Permission = 0;
  char Answer = 'n';

  cout<<"\nDo you want to give full access? y/n? ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    return -1;
  }
  cout<<"\n\nDo you want to give access to : \n";

  cout<<"Show Clients List ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pShowClient;
  }

  cout<<"\nAdd Client ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pAddNewClient;
  }

  cout<<"\nDelete Client ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pDeleteClient;
  }

  cout<<"\nUpdate Client ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pUpdateClient;
  }

  cout<<"\nFind Client ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pFindClient;
  }

  cout<<"\nTransactions ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pTransaction;
  }

  cout<<"\nManageusers ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pManageusers;
  }
  cout<<"\nShow Registers ? y/n: ";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=clsUser::enMainMenuePermissions::pShowRegisterUsers;
  }
  return Permission;
}
static void _ReadInfoUser(clsUser &User) 
    {
        cout << "\nEnter First Name: ";
        User.SetFirstName(clsInputValidate::ReadString());
      
        cout << "\nEnter Last Name: ";
        User.SetLastName(clsInputValidate::ReadString());
      
        cout << "\nEnter Email: ";
        User.SetEmail(clsInputValidate::ReadString());
      
        cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());
      
        cout << "\nEnter Permissions: ";
        User.SetPermissions(_ReadPermissionsToSet());
      }  
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
static void ShowAddNewUserScreen() 
  {
    _DrawScreenHeader("\tAdd New User Screen");


    string Username = "";


    cout << "\nPlese enter Username: ";


    Username = clsInputValidate::ReadString();
  
    while (clsUser::IsUserExist(Username)) 
    {
      cout << "\nUser number is already used, enter choose one: ";
      Username = clsInputValidate::ReadString();
    }
  
    clsUser NewUser = clsUser::GetAddNewUserObject(Username);
    

    _ReadInfoUser(NewUser);
  
    clsUser::enSaveResults SaveResult;
  
    SaveResult = NewUser.Save();
  
    switch (SaveResult) 
    {
    case clsUser::enSaveResults::svSucceeded:
      cout << "\nUser Added Successfully =)\n";

      _PrintUser(NewUser);
      break;

      
    case clsUser::enSaveResults::svFaildEmptyObject:
      cout << "\nError User was not saved ! Because it's empty";
      break;

  
    case clsUser::enSaveResults::svFaildUserExists:
      cout << "\nError User was not saved because User number is used!\n";
      break;
    }
  }
};