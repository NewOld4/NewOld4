#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "Global.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
  public:
    struct stLoginTransferRecord
    {
     string DateTime;   
     string SourceAccountNumber; 
     string DestinationAccountNumber; 
     float Amount;
     float srcBalanceAfter;
     float drcBalanceAfter;
     string UserName;
    };

  
private:    
    enum enMode { EmptyMode = 0, UpdateMode = 1  , AddMode = 3 , DeleteMode = 4 , ListMode = 5};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
       
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);
        
      

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
       
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
   
        stClientRecord += to_string(Client._AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if(C.MarkForDelete() == false)
                {  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }
  
    

    void _Update()
    {
      
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }
  

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
         

            MyFile.close();
        }

    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
      
    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }
    
    string _PrepareTransferLogInRecord(clsBankClient &Destination , float Amount ,string Username, string Seperator = "#//#")
    {
        string TransferLoginRecord = "";
        TransferLoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLoginRecord += _AccountNumber+ Seperator;
        TransferLoginRecord += Destination._AccountNumber + Seperator;
        TransferLoginRecord += to_string(Amount) + Seperator;
        TransferLoginRecord += to_string(_AccountBalance)+ Seperator;
        TransferLoginRecord += to_string(Destination._AccountBalance) + Seperator;
        TransferLoginRecord += Username;

        return TransferLoginRecord;
    }

    void _RegisterTransferLogIn(clsBankClient ToClient , float Amount , string Username)
    {

        string stDataLine = _PrepareTransferLogInRecord(ToClient , Amount , Username);
       
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }


    static stLoginTransferRecord _ConvertLoginTransferLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginTransferRecord LoginTransferRecord;
        
       
        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
     
       
        LoginTransferRecord.DateTime = LoginRegisterDataLine[0];
        
        LoginTransferRecord.SourceAccountNumber = LoginRegisterDataLine[1];
        LoginTransferRecord.DestinationAccountNumber = LoginRegisterDataLine[2];
        LoginTransferRecord.Amount = stof(LoginRegisterDataLine[3]);
        LoginTransferRecord.srcBalanceAfter = stod(LoginRegisterDataLine[4]); 
        LoginTransferRecord.drcBalanceAfter = stod(LoginRegisterDataLine[5]); 
        LoginTransferRecord.UserName = LoginRegisterDataLine[6];
      
        return LoginTransferRecord;
    }

   

public:
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }
    bool MarkForDelete()
    {
        return _MarkForDelete;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }
    bool WithDraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        
        _AccountBalance -= Amount;
        Save();
        return true;
    }
    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    
   /*No UI Related code inside Object.
    void Print()
    { 
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/
   

   static clsBankClient Find(string AccountNumber)
    {
       
     
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode
   
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
              
                clsBankClient Client = _ConvertLinetoClientObject(Line);
              
                
                if (Client._AccountNumber == AccountNumber)
                {
               
                    return Client;
                    MyFile.close();
                }
              
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1  , svFaildAccountNumberExists = 2};

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
        
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
      
        default:
        {
           break;
        }

        }
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddMode,"","","","",AccountNumber,"",0);
    }
    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C._MarkForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }
    static vector <clsBankClient> GetClientsList()
    {
      return _LoadClientsDataFromFile();
    }
    static float GetTotalBalances()
    {
        float TotalBalances = 0;

        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient Client : vClients)
        {
            TotalBalances = TotalBalances + Client.GetAccountBalance();
        }
        
        return TotalBalances;
        
    }
    bool Transfer(float Amount , clsBankClient &DesntinationClient , string Username)
    {
        if(Amount > _AccountBalance)
            return false;
        WithDraw(Amount);
        DesntinationClient.Deposit(Amount);
        _RegisterTransferLogIn(DesntinationClient , Amount ,Username);
        return true;
    }

   
    static vector <stLoginTransferRecord> GetLoginTransferList()
    {
        vector <stLoginTransferRecord> vLoginTransferRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            stLoginTransferRecord LoginTransferRecord;

            while (getline(MyFile, Line))
            {
                
                
                LoginTransferRecord = _ConvertLoginTransferLineToRecord(Line);
                
                vLoginTransferRecord.push_back(LoginTransferRecord);
                

            }

            MyFile.close();

        }

        return vLoginTransferRecord;

    }
    
   

};

