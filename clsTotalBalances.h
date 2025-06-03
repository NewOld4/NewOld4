#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "iomanip"
#include "clsScreen.h"
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
  
    }

public:

static void ShowTotalBalances()
{
   
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    _DrawScreenHeader("Balances List Screen ","("+to_string (vClients.size()) + ") Client(s).");
    cout<< "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            _PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"<< endl;

    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumtoText(TotalBalances) << ")";
}

};