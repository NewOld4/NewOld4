#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:
    
    static void PrintLoginTransferRecordLine(clsBankClient::stLoginTransferRecord LoginTransferrRecord)
    { 

        cout << setw(8) << left << "" << "| " << setw(20) << left << LoginTransferrRecord.DateTime;
        cout << "| " << setw(10) << left << LoginTransferrRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << LoginTransferrRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << LoginTransferrRecord.Amount;
        cout << "| " << setw(10) << left << LoginTransferrRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << LoginTransferrRecord.drcBalanceAfter;
        cout << "| " << setw(10) << left << LoginTransferrRecord.UserName;
    }

public:
  
    static void ShowLoginTransferScreen()
    {


      
        vector <clsBankClient::stLoginTransferRecord> vLoginTransferRecord = clsBankClient::GetLoginTransferList();
        
       
        string Title = "\tLogin Transfer List Screen";
        string SubTitle =  "\t\t(" + to_string(vLoginTransferRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_____________________________";
        cout << "_________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t______________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vLoginTransferRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stLoginTransferRecord Record : vLoginTransferRecord)
            {

                PrintLoginTransferRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "________________________________________________\n" << endl;

    }

};

