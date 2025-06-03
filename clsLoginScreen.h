#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

  static  bool _Login()
    {
        bool LoginFaild = false;
        short trials = 3;
        string Username, Password;
        do
        {
     
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                --trials;
                cout<<"You have "<<trials<<" Trials to login.";
            }
            if(trials==0)
            {
                cout<<"\n\n\nYou are Locked after 3 failed trials";
                return false;
            }

            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            
            LoginFaild = CurrentUser.IsEmpty();
           

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
 

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

