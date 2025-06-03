#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdio>
using namespace std;
const string ClientFilename = "Clients.txt";
const string UserFilename = "Users.txt";
enum enMainMenuePermissions
{
  eAll = -1 , pShowClient = 1 , pAddNewClient = 2 , pDeleteClient = 4 , pUpdateClient = 8 , pFindClient = 16 , pTransaction = 32 , pManageusers = 64
};
enum enMainUsersOption
{
  eShowUser = 1,
  eAddUser = 2,
  eDeleteUser = 3,
  UpdateUser = 4,
  eFindUser = 5,
  MainMenue = 6
};
enum enMainOption
{
  eShowClient = 1,
  eAddNewClient = 2,
  eDeleteClient = 3,
  Update = 4,
  eFind = 5,
  eTransactions = 6,
  eManageUsers = 7,
  eLogout = 8
};
enum enATMmenue{eQuickWithDraw = 1, eNormalWithDraw = 2, eDeposit = 3, eCheckBalance = 4 , enLogout = 5};
void ShowManageUsersMenue();
void ShowMainMenue();
void ShowTransactionsMenue();
void ShowATMMenue();
bool CheckAccessPermission(enMainMenuePermissions Permission);
void Login();
void ShowQuickWithdrawScreen();
void ShowNormalWithDrawScreen();
bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{
  for (short i = 0; i < rows; i++)
  {
    for (short j = 0; j < cols / 2; j++)
    {
      if (matrix[i][j] != matrix[i][cols - 1 - j])
      {
        return false;
      }
    }
  }
  return true;
}
void FibonacciSeries(short Number)
{
  short prev1 = 1;
  short prev2 = 1;
  short count = 1;
  cout << prev1 << " ";
  for (short i = 1; i < Number; i++)
  {
    cout << prev2 << " ";
    count = prev2;
    prev2 += prev1;
    prev1 = count;
  }
}
void FibonacciSeriesRecursion(short Number, short prev1, short prev2)
{
  short Fibonacci = 0;
  if (Number > 0)
  {
    Fibonacci = prev1 + prev2;
    prev2 = prev1;
    prev1 = Fibonacci;
    cout << Fibonacci << "  ";
    FibonacciSeriesRecursion(Number - 1, prev1, prev2);
  }
}
string ReadString()
{
  string Reading;
  cout << "Please enter your string: \n";
  getline(cin, Reading);
  return Reading;
}
string ReadClientAccountNumber()
{
  string Reading;
  cout << "\nPlease enter account number: \n";
  cin >> Reading;
  return Reading;
}
void PrintFirstLetterOfEachWord(string R1)
{
  short Rlength = R1.length();
  bool isfirstletter = true;
  for (short i = 0; i < Rlength; i++)
  {
    if (R1[i] != ' ' && isfirstletter)
    {
      cout << R1[i] << endl;
    }
    isfirstletter = (R1[i] == ' ' ? true : false);
  }
}
void UpperFirstLetterOfEachWord(string R1)
{
  short Rlength = R1.length();
  bool isfirstletter = true;
  for (short i = 0; i < Rlength; i++)
  {
    if (R1[i] != ' ' && isfirstletter)
    {
      R1[i] = toupper(R1[i]);
    }
    isfirstletter = ((R1[i] == ' ' )|( R1[i] == '-') ? true : false);
  }
  cout << R1;
}
void LowerFirstLetterOfEachWord(string R1)
{
  bool isfirstletter = true;
  short Rlength = R1.length();
  for (short i = 0; i < Rlength; i++)
  {
    if (R1[i] != ' ' && isfirstletter)
    {
      R1[i] = tolower(R1[i]);
    }
    isfirstletter = ((R1[i] == ' ' )| (R1[i] == '-') ? true : false);
  }
  cout << R1;
}
string LowerString(string R1)
{
  short Rlength = R1.length();
  for (short i = 0; i < Rlength; i++)
  {
    R1[i] = tolower(R1[i]);
  }
  return R1;
}
string UpperString(string R1)
{
  short Rlength = R1.length();
  for (short i = 0; i < Rlength; i++)
  {
    R1[i] = toupper(R1[i]);
  }
  return R1;
}
char ReadChar()
{
  char C;
  cout << "Please enter your character: ";
  cin >> C;
  return C;
}
char Invertingcase(char char1)
{
  return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InvertingAllStringLettersCase(string String1)
{
  short Slength = String1.length();
  for (short i = 0; i < Slength; i++)
  {
    String1[i] = Invertingcase(String1[i]);
  }
  return String1;
}
short CountCapitalLetters(string S1)
{
  short Slength = S1.length();
  short counter = 0;
  for (short i = 0; i < Slength; i++)
  {
    if (isupper(S1[i]))
    {
      ++counter;
    }
  }
  return counter;
}
short CountSmallLetters(string S1)
{
  short Slength = S1.length();
  short counter = 0;
  for (short i = 0; i < Slength; i++)
  {
    if (islower(S1[i]))
    {
      ++counter;
    }
  }
  return counter;
}
enum enWhatToCount
{
  SmallLetters = 0,
  CapitalLetters = 1,
  All = 2
};
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
  short counter = 0;
  short Slength = S1.length();
  if (WhatToCount == enWhatToCount::All)
  {
    return Slength;
  }
  for (short i = 0; i < Slength; i++)
  {
    if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
    {
      ++counter;
    }
    else if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
    {
      ++counter;
    }
  }
  return counter;
}
short CountCaracter(string S1, char C, bool MatchCase = true)
{
  short Slength = S1.length();
  short count = 0;
  for (short i = 0; i < Slength; i++)
  {
    if (MatchCase)
    {
      if (S1[i] == C)
        ++count;
    }
    else
    {
      if (tolower(S1[i]) == tolower(C))
        ++count;
    }
  }
  return count;
}
bool IsVowel(char letter)
{
  letter = tolower(letter);
  return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u');
}
short CountVowels(string text)
{
  short txtlength = text.length();
  short counter = 0;
  for (short i = 0; i < txtlength; i++)
  {
    if (IsVowel(text[i]))
      ++counter;
  }
  return counter;
}
void PrintVowels(string text)
{
  short txtlength = text.length();
  cout << "\nVowels in string are: ";
  for (short i = 0; i < txtlength; i++)
  {
    if (IsVowel(text[i]))
      cout << text[i] << " ";
  }
}
void PrintEachWord(string S1)
{
  string delim = " ";
  cout << "your string words are: \n\n";
  short pos = 0;
  string Sword;
  while ((pos = S1.find(delim)) != std::string::npos)
  {
    Sword = S1.substr(0, pos);
    if (Sword != "")
    {
      cout << Sword << endl;
    }
    S1.erase(0, pos + delim.length());
  }
  if (S1 != " ")
  {
    cout << S1 << endl;
  }
}
short CountEachWordinString(string S1)
{
  string delim = " ";
  short counter = 0;
  short pos = 0;
  string Sword;
  while ((pos = S1.find(delim)) != std::string::npos)
  {
    Sword = S1.substr(0, pos);
    if (Sword != "")
    {
      ++counter;
    }
    S1.erase(0, pos + delim.length());
  }
  if (S1 != " ")
  {
    ++counter;
  }
  return counter;
}
vector<string> vSplit(string S1, string delim)
{
  vector<string> vstring;
  short pos = 0;
  string Sword;
  while ((pos = S1.find(delim)) != std::string::npos)
  {
    Sword = S1.substr(0, pos);
    if (Sword != "")
    {
      vstring.push_back(Sword);
    }
    S1.erase(0, pos + delim.length());
  }
  if (S1 != " ")
  {
    vstring.push_back(S1);
  }
  return vstring;
}

void PrintSplitVector(vector<string> vString)
{

  for (string &Vsplit : vString)
  {
    cout << Vsplit;
  }
}
string JoinStrings(vector<string> vString, string delim)
{
  string S1 = "";
  for (string &s : vString)
  {
    S1 = S1 + s + delim;
  }
  return S1.substr(0, S1.length() - delim.length());
}
string JoinStrings(string array[], short length, string delim)
{
  string S1 = "";
  for (short i = 0; i < length; i++)
  {
    S1 = S1 + array[i] + delim;
  }
  return S1.substr(0, S1.length() - delim.length());
}
string TrimRight(string S1)
{
  for (short i = S1.length() - 1; i >= 0; i--)
  {
    if (S1[i] != ' ')
    {
      return S1.substr(0, i + 1);
    }
  }
  return "";
}
string TrimLeft(string S1)
{
  short Slength = S1.length();
  for (short i = 0; i < Slength; i++)
  {
    if (S1[i] != ' ')
    {
      return S1.substr(i, S1.length() - i);
    }
  }
  return "";
}
string Trim(string S1)
{
  return TrimRight(TrimLeft(S1));
}
string ReverseString(string S1)
{
  vector<string> vString;
  string S2 = "";
  vString = vSplit(S1, " ");
  vector<string>::iterator iter = vString.end();
  while (iter != vString.begin())
  {
    --iter;
    S2 += *iter + " ";
  }
  S2 = S2.substr(0, S2.length() - 1);
  return S2;
}
string ReplaceWord(string S1, string Oldword, string Newword, bool matchcase = true)
{
  vector<string> vstring;
  vstring = vSplit(S1, " ");
  for (string &s : vstring)
  {
    if (matchcase)
    {
      if (s == Oldword)
      {
        s = Newword;
      }
    }
    else
    {
      if (LowerString(s) == LowerString(Oldword))
      {
        s = Newword;
      }
    }
  }
  return JoinStrings(vstring, " ");
}
string ReplaceBuiltInFunction(string S1, string toreplace, string replaceto)
{
  short pos = S1.find(toreplace);
  while (pos != std::string::npos)
  {
    S1 = S1.replace(pos, toreplace.length(), replaceto);
    pos = S1.find(toreplace); //*find Next ONE
  }
  return S1;
}
string RemovePunctuaions(string S1)
{
  short Slength = S1.length();
  string S2 = "";
  for (short i = 0; i < Slength; ++i)
  {
    if (!ispunct(S1[i]))
    {
      S2 += S1[i];
    }
  }
  return S2;
}


enum enTransactions
{
  edeposit = 1,
  ewithdraw = 2,
  eTotalBalances = 3,
  eMainmenue = 4
};
struct StClient
{
  string account_number;
  string PinCode;
  string Name;
  string Phone;
  double AccPalance = 0;
  bool Makrfordelete = false;
  bool Update = false;
};
struct StUsers
{
  string username;
  string password;
  short Permissions;
  bool Makrfordelete = false;
};
StUsers CurrentUser;
StClient CurrentClient;
StClient ClientRecord(string Line, string delim = "#//#")
{
  vector<string> vstring;
  vstring = vSplit(Line, delim);
  StClient stRecord;
  stRecord.account_number = vstring[0];
  stRecord.PinCode = vstring[1];
  stRecord.Name = vstring[2];
  stRecord.Phone = vstring[3];
  stRecord.AccPalance = stod(vstring[4]);
  return stRecord;
}
vector<StClient>SaveFiletoVectorClient(string Filename)
{
  vector<StClient> vclient;
  fstream Myfile;
  Myfile.open(Filename, ios::in);
  if (Myfile.is_open())
  {
    string line;
    StClient client;
    while (getline(Myfile, line))
    {
      client = ClientRecord(line);
      vclient.push_back(client);
    }
    Myfile.close();
  }
  return vclient;
}
bool FindClientByAccNumber(string AccountNumber, StClient &Client)
{
  vector<StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  for (StClient C : vClients)
  {
    if (C.account_number == AccountNumber)
    {
      Client = C;
      return true;
    }
  }
  return false;
}
bool FindClientByAccNumberAndPinCode(string AccountNumber,string Pincode, StClient &Client)
{
  vector<StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  for (StClient C : vClients)
  {
    if (C.account_number == AccountNumber && C.PinCode == Pincode)
    {
      Client = C;
      return true;
    }
  }
  return false;
}
StUsers UserRecord(string Line, string delim = "#//#")
{
  vector<string> vstring;
  vstring = vSplit(Line, delim);
  StUsers stRecord;
  stRecord.username = vstring[0];
  stRecord.password = vstring[1];
  stRecord.Permissions = stod(vstring[2]);
  return stRecord;
}
void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}
vector<StUsers>SaveFiletoVectorUsers(string Filename)
{
  vector<StUsers> vusers;
  fstream Myfile;
  Myfile.open(Filename, ios::in); //?(ios::in) ==> read mode
  if (Myfile.is_open())
  {
    string line;
    StUsers user;
    while (getline(Myfile, line))
    {
      user = UserRecord(line);
      vusers.push_back(user);
    }
    Myfile.close();
  }
  return vusers;
}
void AddDataLineToFile(string FileName, string stDataLine)
{
   fstream MyFile;
   MyFile.open(FileName, ios::out | ios::app);
   if (MyFile.is_open())
   {
     MyFile << stDataLine << endl;
     MyFile.close();
   }
}
bool UserExistsByUsername(string Username, string FileName)
{
  vector <StUsers> vUsers;
  fstream MyFile;
  MyFile.open(FileName, ios::in);//read Mode
  if (MyFile.is_open())
  {
  string Line;
  StUsers User;
  while (getline(MyFile, Line))
  {
    User = UserRecord(Line);
    if (User.username == Username)
   {
     MyFile.close();
     return true;
   }
    vUsers.push_back(User);
  }
    MyFile.close();
  }
  return false;
}
int ReadPermissionsToSet()
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

  cout<<"Show Clients List ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pShowClient;
  }

  cout<<"Add Client ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pAddNewClient;
  }

  cout<<"Delete Client ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pDeleteClient;
  }

  cout<<"Update Client ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pUpdateClient;
  }

  cout<<"Find Client ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pFindClient;
  }

  cout<<"Transactions ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pTransaction;
  }

  cout<<"Manageusers ? y/n";
  cin>>Answer;
  if(Answer == 'Y' || Answer == 'y')
  {
    Permission +=enMainMenuePermissions::pManageusers;
  }
  return Permission;
}
StUsers ReadNewUser()
{
    StUsers User;
    cout << "Enter Username? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, User.username);
    while (UserExistsByUsername(User.username, UserFilename))
    {
       cout << "\nUser with [" << User.username << "] already exists, Enter another Username? ";
       getline(cin >> ws, User.username);
    }
    cout << "Enter Password? ";
    getline(cin, User.password);
    User.Permissions = ReadPermissionsToSet();
    return User;
}
string ConverUserRecordToLine(StUsers stRecord, string delim = "#//#")
{
  string Line = "";
  Line += stRecord.username + delim;
  Line += stRecord.password + delim;
  Line += to_string(stRecord.Permissions);
  return Line;
}
void AddNewUser()
{
  StUsers User;
  User = ReadNewUser();
  AddDataLineToFile(UserFilename, ConverUserRecordToLine(User));
}
bool FindUserByUsernameAndPassword(string Username, string pass , StUsers &User)
{
  vector<StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
  for (StUsers U : vUsers)
  {
    if (U.username == Username && U.password == pass)
    {
      User = U;
      return true;
    }
  }
  return false;
}
bool FindUserByUsername(string Username, vector<StUsers> vUsers, StUsers &User)
{
  for (StUsers U : vUsers)
  {
    if (U.username == Username)
    {
      User = U;
      return true;
    }
  }
  return false;
}
string ReadUserName()
{
  string Username = "";
  cout << "\nPlease enter Username? ";
  cin >> Username;
  return Username;
}


void PrintUserRecord(StUsers stRecord)
{
  cout << "\n\nThe following is extracted User record: \n---------------------------\n";
  cout << "\nUsername      : " << stRecord.username;
  cout << "\nPassword      : " << stRecord.password;
  cout << "\nPermissions   : " << stRecord.Permissions;
 
  cout << "\n---------------------------";
}



void PrintClientRecord(StClient stRecord)
{
  cout << "\n\nThe following is extracted client record: \n---------------------------\n";
  cout << "\nAccount Number: " << stRecord.account_number;
  cout << "\nPin Code      : " << stRecord.PinCode;
  cout << "\nName          : " << stRecord.Name;
  cout << "\nPhone         : " << stRecord.Phone;
  cout << "\nAccount Balance: " << stRecord.AccPalance;
  cout << "\n---------------------------";
}
void GoBackToMainMenue()
{
  cout << "\n\nPress any key to go back to Main Menue...";
  system("pause>0");
  ShowMainMenue();
}
void ShowFindClientScreen()
{
   if(!CheckAccessPermission(enMainMenuePermissions::pFindClient))
   {
     ShowAccessDeniedMessage();
     GoBackToMainMenue();
     return ;
   }
   cout << "\n-----------------------------------\n";
   cout << "\tFind Client Screen";
   cout << "\n-----------------------------------\n";
   vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);
   StClient Client;
   string Acc = ReadClientAccountNumber();
   if (FindClientByAccNumber(Acc, Client))
        PrintClientRecord(Client);
   else
      cout << "\nUser with Account Number [" << Acc << "] is not found!";
}

void ShowFindUserScreen()
{
  
   cout << "\n-----------------------------------\n";
   cout << "\tFind User Screen";
   cout << "\n-----------------------------------\n";
   vector <StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
   StUsers User;
   string Username = ReadUserName();
   if (FindUserByUsername(Username, vUsers, User))
        PrintUserRecord(User);
   else
      cout << "\nUser with Username [" << Username << "] is not found!";
}
string ConverRecordToLine(StClient stRecord, string delim = "#//#")
{
  string Line = "";
  Line += stRecord.account_number + delim;
  Line += stRecord.PinCode + delim;
  Line += stRecord.Name + delim;
  Line += stRecord.Phone + delim;
  Line += to_string(stRecord.AccPalance);
  return Line;
}



bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
  vector <StClient> vClients;
  fstream MyFile;
  MyFile.open(FileName, ios::in);//read Mode
  if (MyFile.is_open())
  {
  string Line;
  StClient Client;
  while (getline(MyFile, Line))
  {
    Client = ClientRecord(Line);
    if (Client.account_number == AccountNumber)
   {
     MyFile.close();
     return true;
   }
    vClients.push_back(Client);
  }
    MyFile.close();
  }
  return false;
}


bool FindUser(string username,string password,  StUsers &User)
{
  vector<StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
  for (StUsers U : vUsers)
  {
    if (U.username == username && U.password == password)
    {
      User = U;
      return true;
    }
  }
  return false;
}
StClient ReadClient()
{
  StClient S1;
  cout << "Please Enter Account Number: ";
  getline(cin >> ws, S1.account_number);
  while (ClientExistsByAccountNumber(S1.account_number, ClientFilename))
    {
      cout << "\nClient with [" << S1.account_number << "] already exists, Enter another Account Number? ";
      getline(cin >> ws, S1.account_number);
    }  
  cout << "Enter PinCode: ";
  getline(cin, S1.PinCode);
  cout << "Enter Name: ";
  getline(cin, S1.Name);
  cout << "Enter Phone: ";
  getline(cin, S1.Phone);
  cout << "Enter Account Palance: ";
  cin >> S1.AccPalance;
  return S1;
}

StUsers ReadUser()
{
  StUsers S1;
  
  cout << "Enter Username? ";
  getline(cin >> ws, S1.username);
  while (UserExistsByUsername(S1.username, UserFilename))
  {
    cout << "\nUser with [" << S1.username << "] already exists, Enter another Username? ";
    getline(cin >> ws, S1.username);
  } 
  cout << "Enter Password? ";
  getline(cin, S1.password);
  
  S1.Permissions = ReadPermissionsToSet();
  return S1;
}



void PrintClientRecordFile(StClient Client)
{
  cout << "| " << setw(15) << left << Client.account_number;
  cout << "| " << setw(10) << left << Client.PinCode;
  cout << "| " << setw(40) << left << Client.Name;
  cout << "| " << setw(12) << left << Client.Phone;
  cout << "| " << setw(12) << left << Client.AccPalance;
}
void PrintAllClientsData()
{
  if(!CheckAccessPermission(enMainMenuePermissions::pShowClient))
  {
    ShowAccessDeniedMessage();
    GoBackToMainMenue();
    return ;
  }
  vector<StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n"
       << endl;
  cout << "| " << left << setw(15) << "Accout Number";
  cout << "| " << left << setw(10) << "Pin Code";
  cout << "| " << left << setw(40) << "Client Name";
  cout << "| " << left << setw(12) << "Phone";
  cout << "| " << left << setw(12) << "Balance";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n"
       << endl;
  for (StClient &Client : vClients)
  {
    PrintClientRecordFile(Client);
    cout << endl;
  }
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n"
       << endl;
}



bool MarkClientForDeleteByAccountNumber(string accno, vector<StClient> &vclients)
{
  for (StClient &C : vclients)
  {
    if (C.account_number == accno)
    {
      C.Makrfordelete = true;
      return true;
    }
  }
  return false;
}
bool MarkUserForDeleteByUsername(string username, vector<StUsers> &vusers)
{
  for (StUsers &U : vusers)
  {
    if (U.username == username)
    {
      U.Makrfordelete = true;
      return true;
    }
  }
  return false;
}
StClient ChangeClientRecord(string AccountNumber)
{
  StClient S1;
  S1.account_number = AccountNumber;
  system("cls");
  cout << "Enter PinCode: ";
  getline(cin >> ws, S1.PinCode);
  cout << "Enter Name: ";
  getline(cin, S1.Name);
  cout << "Enter Phone: ";
  getline(cin, S1.Phone);
  cout << "Enter Account Palance: ";
  cin >> S1.AccPalance;
  return S1;
}
StUsers ChangeUserRecord(string Username)
{
  StUsers S1;
  S1.username = Username;
  system("cls");
  cout << "Enter Password: ";
  getline(cin >> ws, S1.password);
 
  S1.Permissions =  ReadPermissionsToSet();
  return S1;
}
vector<StClient> SaveClienttoFile(string Filename , vector<StClient> &Vclients)
{
  fstream Myfile;
  Myfile.open(Filename, ios::out);
  string stDataline;
  if (Myfile.is_open())
  {
    for (StClient C : Vclients)
    {
      if (C.Makrfordelete == false)
      {
        stDataline = ConverRecordToLine(C);
        Myfile << stDataline << endl;
      }
    }
    Myfile.close();
  }
  return Vclients;
}
vector<StUsers> SaveUsertoFile(string Filename, vector<StUsers> Vusers)
{
  fstream Myfile;
  Myfile.open(Filename, ios::out);
  string stDataline;
  if (Myfile.is_open())
  {
    for (StUsers U : Vusers)
    {
      if (U.Makrfordelete == false)
      {
        stDataline = ConverUserRecordToLine(U);
        Myfile << stDataline << endl;
      }
    }
    Myfile.close();
  }
  return Vusers;
}
vector<StClient> AddNewClient()
{
  fstream Myfile;
  Myfile.open(ClientFilename, ios::out | ios::app);
  string stDataline;
  if (Myfile.is_open())
  {
    StClient C;
    C = ReadClient();
    stDataline = ConverRecordToLine(C);
    Myfile << stDataline << endl;
    Myfile.close();
  }
  return SaveFiletoVectorClient(ClientFilename);
}
void ShowAddNewClientsScreen()
{
 if(!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
 {
   ShowAccessDeniedMessage();
   GoBackToMainMenue();
   return;
 }
 cout << "\n-----------------------------------\n";
 cout << "\tAdd New Clients Screen";
 cout << "\n-----------------------------------\n";
 AddNewClient();
}
vector<StUsers> AddUser()
{
  fstream Myfile;
  Myfile.open(UserFilename, ios::out | ios::app);
  string stDataline;
  if (Myfile.is_open())
  {
    StUsers U;
    U = ReadUser();
    stDataline = ConverUserRecordToLine(U);
    Myfile << stDataline << endl;
    Myfile.close();
  }
  return SaveFiletoVectorUsers(UserFilename);
}
short TotalBalances()
{
  vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  short Total = 0;
  for(StClient C : vClients)
  {
    Total+= C.AccPalance;
  }
  cout << "\n-----------------------------------\n";
  cout << "\tTotal Balances Screen";
  cout << "\n-----------------------------------\n";
  return Total;
}
short ShowClientBalance()
{
  cout <<"\n\nYour Balance is: ";
  return CurrentClient.AccPalance;
}
void Add()
{
  StUsers User;
  User = ReadNewUser();
  AddDataLineToFile(UserFilename, ConverUserRecordToLine(User));
}
void AddNewUsers()
{
char AddMore = 'Y';
do
{
   system("cls");
   cout << "Adding New User:\n\n";
   Add();
   cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
   cin >> AddMore;
} while (toupper(AddMore) == 'Y');
}
void ShowAddNewUserScreen()
{
  cout << "\n-----------------------------------\n";
  cout << "\tAdd New User Screen";
  cout << "\n-----------------------------------\n";
  AddNewUsers();
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<StClient> &Vclients)
{
  StClient Client;
  char Answer = 'n';

  if (FindClientByAccNumber(AccountNumber,  Client))
  {
    PrintClientRecord(Client);
    cout << "\nAre you sure you want delete this client ? y/n: ";
    cin >> Answer;
    if ((Answer == 'y') | (Answer == 'Y'))
    {
      MarkClientForDeleteByAccountNumber(AccountNumber, Vclients);
      SaveClienttoFile(ClientFilename ,Vclients);
      Vclients = SaveFiletoVectorClient(ClientFilename);
      cout << "\nClient Deleted Successfully. ";
      return true;
    }
  }
  else
  {
    cout << "\nClient with account number (" << AccountNumber << ") is NOT Found!";
  }
  return false;
}
bool DeleteUserByUsername(string Username, vector <StUsers>& vUsers)
{
  if (Username == "Admin")
  {
  cout << "\n\nYou cannot Delete This User.";
  return false;
  }
  StUsers User;
  char Answer = 'n';
  if (FindUserByUsername(Username, vUsers, User))
  {
    PrintUserRecord(User);
    cout << "\n\nAre you sure you want delete this User? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
     {
       MarkUserForDeleteByUsername(Username, vUsers);
       SaveUsertoFile(UserFilename, vUsers);
        //Refresh Clients
       vUsers = SaveFiletoVectorUsers(UserFilename);
       cout << "\n\nUser Deleted Successfully.";
       return true;
     }
  }
  else
  {
  cout << "\nUser with Username (" << Username << ") is Not Found!";
  }
return false;
}
void ShowDeleteClientScreen()
{
  if(!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
  {
    ShowAccessDeniedMessage();
    GoBackToMainMenue();
    return ;
  }
  cout << "\n-----------------------------------\n";
  cout << "\tDelete Clients Screen";
  cout << "\n-----------------------------------\n";
  vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  string Acc = ReadClientAccountNumber();
  DeleteClientByAccountNumber(Acc, vClients);
}
void ShowDeleteUserScreen()
{
  cout << "\n-----------------------------------\n";
  cout << "\tDelete Users Screen";
  cout << "\n-----------------------------------\n";
  vector <StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
  string Username = ReadUserName();
  DeleteUserByUsername(Username, vUsers);
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<StClient> &Vclients)
{
  StClient Client;
  char Answer = 'n';

  if (FindClientByAccNumber(AccountNumber,  Client))
  {
    PrintClientRecord(Client);
    cout << "\nAre you sure you want update this client ? y/n: ";
    cin >> Answer;
    if ((Answer == 'y') | (Answer == 'Y'))
    {
      for (StClient &C : Vclients)
      {
        if (C.account_number == AccountNumber)
        {
          C = ChangeClientRecord(AccountNumber);
          break;
        }
      }
      SaveClienttoFile(ClientFilename,Vclients);
      cout << "\nClient Updated Successfully. ";
      return true;
    }
  }
  else
  {
    cout << "\nClient with account number (" << AccountNumber << ") is NOT Found!";
  }
  return false;
}
bool UpdateUserByUsername(string Username, vector<StUsers> &Vusers)
{
  StUsers User;
  char Answer = 'n';

  if (FindUserByUsername(Username, Vusers,User))
  {
    PrintUserRecord(User);
    cout << "\nAre you sure you want update this user ? y/n: ";
    cin >> Answer;
    if ((Answer == 'y') | (Answer == 'Y'))
    {
      for (StUsers &U : Vusers)
      {
        if (U.username == Username)
        {
          U = ChangeUserRecord(Username);
          break;
        }
      }
      SaveUsertoFile(UserFilename, Vusers);
      cout << "\nUser Updated Successfully. ";
      return true;
    }
  }
  else
  {
    cout << "\nUser with Username (" << Username << ") is NOT Found!";
  }
  return false;
}
void ShowUpdateClientScreen()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pUpdateClient))
    {
     ShowAccessDeniedMessage();
     GoBackToMainMenue();
     return ;
    } 
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Clients Screen";
    cout << "\n-----------------------------------\n";
    vector <StClient> vClient = SaveFiletoVectorClient(ClientFilename);
    string Acc = ReadClientAccountNumber();
    UpdateClientByAccountNumber(Acc, vClient);
}
void ShowUpdateUserScreen()
{
  
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n-----------------------------------\n";
    vector <StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
    string Username = ReadUserName();
    UpdateUserByUsername(Username, vUsers);
}
bool DeposWithDraw(string accountno,short amount,StClient client , vector <StClient> vsClients)
{
  char Answer = 'n';
  cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
  cin >> Answer;
  if (Answer == 'y' || Answer == 'Y')
  {
   for (StClient &C : vsClients)
    if (accountno == C.account_number)
    {     
      C.AccPalance += amount;
      client = C;
      SaveClienttoFile(ClientFilename,vsClients);
   
      cout << "\n\nDone Successfully. New balance is: "<< C.AccPalance;
      return true;
    }

  }
  return false;
}

bool CheckAccessPermission (enMainMenuePermissions Permission)
{
  if(Permission == enMainMenuePermissions::eAll)
     return true;
  if((Permission & CurrentUser.Permissions) == Permission)
     return true;
  return false;    
}
void PrintUserRecordFile(StUsers User)
{
  cout << "| " << setw(15) << left << User.username;
  cout << "| " << setw(10) << left << User.password;
  cout << "| " << setw(40) << left << User.Permissions;
}

void PrintAllUsersData()
{
  vector<StUsers> vUsers = SaveFiletoVectorUsers(UserFilename);
  cout << "\n\t\t\t\t\t Users List (" << vUsers.size() << ") User(s).";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n"<< endl;

  cout << "| " << left << setw(15) << "Username";
  cout << "| " << left << setw(10) << "Password";
  cout << "| " << left << setw(40) << "Permissions";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n" << endl;
  if(vUsers.size() == 0)
     cout<<"\t\t\t\tNo Users Avilable In the System!";
  else
  {     
     for (StUsers &User : vUsers)
    {
    PrintUserRecordFile(User);
    cout << endl;
    }
  }
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n"<< endl;
}
double ReadDepositAmount()
{
  double Amount;
  cout << "\nEnter a positive Deposit Amount? ";
  cin >> Amount;
  while (Amount <= 0)
  {
    cout << "\nEnter a positive Deposit Amount? ";
    cin >> Amount;
  }
  return Amount;
}
void PerfromDepositOption()
{
 double DepositAmount = ReadDepositAmount();
 vector <StClient> vsClients = SaveFiletoVectorClient(ClientFilename);
 DeposWithDraw(CurrentClient.account_number,DepositAmount,CurrentClient, vsClients);
 CurrentClient.AccPalance += DepositAmount;
}
void ShowDepositScreen()
{
  system("cls");
  cout << "===========================================\n";
  cout << "\t\tDeposit Screen\n";
  cout << "===========================================\n";
  PerfromDepositOption();
}
void DeposiAmount()
{
  cout << "\n-----------------------------------\n";
  cout << "\tDeposit Screen";
  cout << "\n-----------------------------------\n";
  StClient Client;
  vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  string AccountNumber = ReadClientAccountNumber();
  while (!FindClientByAccNumber(AccountNumber,  Client))
 {
    cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
    AccountNumber = ReadClientAccountNumber();
 }
  PrintClientRecord(Client);
  double Amount = 0;
  cout << "\nPlease enter deposit amount? ";
  cin >> Amount;
  DeposWithDraw(AccountNumber, Amount ,Client, vClients);
  
}
void ShowWithDrawScreen()
{
  cout << "\n-----------------------------------\n";
  cout << "\tWithDraw Screen";
  cout << "\n-----------------------------------\n";
  StClient Client;
  vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);
  string AccountNumber = ReadClientAccountNumber();
  while (!FindClientByAccNumber(AccountNumber, Client))
 {
    cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
    AccountNumber = ReadClientAccountNumber();
 }
  PrintClientRecord(Client);
  double Amount = 0;
  cout << "\nPlease enter an amount? ";
  cin >> Amount;
  while (Amount > Client.AccPalance)
{
  cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccPalance << endl;
  cout << "Please enter another amount? ";
  cin >> Amount;
}
  DeposWithDraw(AccountNumber, Amount*-1 ,Client, vClients);
}
void GoBackToATMMenue()
{
  cout << "\n\nPress any key to go back to ATM Menue...";
  system("pause>0");
  ShowATMMenue();
}
int ReadWithDrawAmount()
{
  int amount = 0;
  cout <<"\nEnter an amount multiple of 5's ? ";

  cin>>amount;
  while ((amount%5)!=0)
  {
    cout <<"\nEnter an amount multiple of 5's ? ";
    cin>>amount;
  }

  return amount;
  
}
void PerformNormalWithdrawScreen()
{
   int WithDrawBalance = ReadWithDrawAmount();
   if(WithDrawBalance > CurrentClient.AccPalance)
   {
      cout << "\nThe amount exceeds the balance, make another choice.\n : ";
      cout << "Press any key to continue . . .";
      system("pause>0");
      ShowNormalWithDrawScreen();
      return ;
   }
   vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);

   DeposWithDraw(CurrentClient.account_number, WithDrawBalance*-1 ,CurrentClient, vClients);
   CurrentClient.AccPalance -= WithDrawBalance;
}
void ShowNormalWithDrawScreen()
{
  
  cout << "\n===================================\n";
  cout << "\tNormal WithDraw Screen";
  cout << "\n===================================\n";
  PerformNormalWithdrawScreen();
     
}
short getQuickWithDrawAmount(short QuickWithDrawOption)
{
  switch (QuickWithDrawOption)
  {
  case 1:
    return 20;
  
  case 2:
    return 50;

  case 3:
    return 100;
  
  case 4:
    return 200;
  
  case 5:
    return 400;

  case 6:
    return 600;
    
  case 7:
    return 800;
  
  case 8:
    return 1000;
  
  default:
    return 0;
  }
}
short ReadQuickWithDrawOption()
{
  short choice = 0;
  while((choice < 1) || (choice > 9 ))
  {
    cout <<"\nChoose what to do from [1] to [9] ? ";
    cin >> choice;
  }
  return choice;
}
void PerformQuickWithDrawOption(short QuickWithDrawOption)
{
  if(QuickWithDrawOption == 9)
     return ;
  short WithDrawBalance = getQuickWithDrawAmount(QuickWithDrawOption);   
  
  
  if (WithDrawBalance > CurrentClient.AccPalance)
{
  cout << "\nThe amount exceeds the balance, make another choice.\n : ";
  cout << "Press any key to continue . . .";
  system("pause>0");
  ShowQuickWithdrawScreen();
  return ;
}
vector <StClient> vClients = SaveFiletoVectorClient(ClientFilename);

DeposWithDraw(CurrentClient.account_number, WithDrawBalance*-1 ,CurrentClient, vClients);
CurrentClient.AccPalance -= WithDrawBalance;


}

void ShowQuickWithdrawScreen()
{
  cout << "\n============================================\n";
  cout << "\tQuick WithDraw ";
  cout << "\n============================================\n";
  cout <<setw(15)<<right<< "[1] 20 " << setw(15) << right << "[2] 50\n";
  cout <<setw(16)<<right<< "[3] 100 " << setw(15) << right << "[4] 200\n";
  cout <<setw(16)<<right<< "[5] 400 " << setw(15) << right << "[6] 600\n";
  cout <<setw(16)<<right<< "[7] 800 " << setw(16) << right << "[8] 1000\n";
  cout <<setw(17)<<right<< "[9] Exit ";
  cout << "\n============================================\n";
  cout << "Your Balance is: "<<CurrentClient.AccPalance;
  PerformQuickWithDrawOption(ReadQuickWithDrawOption());
}
void GoBackToManageUsersMenue()
{
 cout << "\n\nPress any key to go back to Transactions Menue...";
 system("pause>0");
 ShowManageUsersMenue();
}
void GoBackToTransactionsMenue()
{
  cout << "\n\nPress any key to go back to Transactions Menue...";
  system("pause>0");
  ShowTransactionsMenue();
}


short ReadTransactionsMenueOption()
{
  cout << "Choose what do you want to do? [1 to 4]? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}
short ReadATMmenueOption()
{
  cout << "Choose what do you want to do? [1 to 5]? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}



void PerfromTranactionsMenueOption(enTransactions TransactionMenueOption)
{
  switch (TransactionMenueOption)
  {
  case enTransactions::edeposit:
  {
    system("cls");
    ShowDepositScreen();
    GoBackToTransactionsMenue();
    break;
  }
  case enTransactions::ewithdraw:
  {
    system("cls");
    ShowWithDrawScreen();
    GoBackToTransactionsMenue();
    break;
  }
  case enTransactions::eTotalBalances:
  {
    system("cls");
    cout<< TotalBalances();
    GoBackToTransactionsMenue();
    break;
  }
  case enTransactions::eMainmenue:
  {
    ShowMainMenue();
  }
  }
}
void PerfromATMMenueOption(enATMmenue ATMMenueOption)
{
  switch (ATMMenueOption)
  {
  case enATMmenue::eQuickWithDraw:
  {
    system("cls");
    ShowQuickWithdrawScreen();
    GoBackToATMMenue();
    break;
  }
  case enATMmenue::eNormalWithDraw:
  {
    system("cls");
    ShowNormalWithDrawScreen();
    GoBackToATMMenue();
    break;
  }
  case enATMmenue::eDeposit:
  {
    system("cls");
    ShowDepositScreen();
    GoBackToATMMenue();
    break;
  }
  case enATMmenue::eCheckBalance:
  {
    system("cls");
    cout<<ShowClientBalance();
    GoBackToATMMenue();
    break;
  }
  default:
     Login();
     break;
  }
}
void ShowATMMenue()
{
  system("cls");
  cout << "===========================================\n";
  cout << "\t\tATM Main Menue Screen\n";
  cout << "===========================================\n";
  cout << "\t[1] Quick Withdraw.\n";
  cout << "\t[2] Normal Withdraw.\n";
  cout << "\t[3] Deposit.\n";
  cout << "\t[4] Check Balance.\n";
  cout << "\t[5] Logout.\n";
  cout << "===========================================\n";
  PerfromATMMenueOption((enATMmenue)ReadATMmenueOption());
}
void ShowTransactionsMenue()
{
 if(!CheckAccessPermission(enMainMenuePermissions::pTransaction))
  {
    ShowAccessDeniedMessage();
    GoBackToMainMenue();
    return;
  }
 system("cls");
 cout << "===========================================\n";
 cout << "\t\tTransactions Menue Screen\n";
 cout << "===========================================\n";
 cout << "\t[1] Deposit.\n";
 cout << "\t[2] Withdraw.\n";
 cout << "\t[3] Total Balances.\n";
 cout << "\t[4] Main Menue.\n";
 cout << "===========================================\n";
 PerfromTranactionsMenueOption((enTransactions)ReadTransactionsMenueOption());
}
void PerfromManageUsersMenueOption(enMainUsersOption ManageUsersMenueOption)
{
  switch (ManageUsersMenueOption)
  {
  case enMainUsersOption::eShowUser:
  {
    system("cls");
    PrintAllUsersData();
    GoBackToManageUsersMenue();
   break;
  }
  case enMainUsersOption::eAddUser:
  {
    system("cls");
    ShowAddNewUserScreen();
    //! Add user screen
    GoBackToManageUsersMenue();
    break;
  }
  case enMainUsersOption::eDeleteUser:
  {
    system("cls");
    ShowDeleteUserScreen();
    GoBackToManageUsersMenue();
    break;
  }
  case enMainUsersOption::UpdateUser:
  {
    system("cls");
    ShowUpdateUserScreen();
    GoBackToManageUsersMenue();
    break;
  }
  case enMainUsersOption::eFindUser:
  {
    system("cls");
    ShowFindUserScreen();
    GoBackToManageUsersMenue();
    break;
  }

  case enMainUsersOption::MainMenue:
  {
    ShowMainMenue();
  }
  }
}
short ReadManageUsersMenueOption()
{
   cout << "Choose what do you want to do? [1 to 6]? ";
   short Choice = 0;
   cin >> Choice;
   return Choice;
}
short ReadMainMenueOption()
{
  cout << "Choose what do you want to do? [1 to 8]? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}
void ShowManageUsersMenue()
{
  if(!CheckAccessPermission(enMainMenuePermissions::pManageusers))
  {
    ShowAccessDeniedMessage();
    GoBackToMainMenue();
    return ;
  }
  system("cls");
  cout << "===========================================\n";
  cout << "\t\tManage Users Menue Screen\n";
  cout << "===========================================\n";
  cout << "\t[1] List Users.\n";
  cout << "\t[2] Add New User.\n";
  cout << "\t[3] Delete User.\n";
  cout << "\t[4] Update User.\n";
  cout << "\t[5] Find User.\n";
  cout << "\t[6] Main Menue.\n";
  cout << "===========================================\n";
  PerfromManageUsersMenueOption((enMainUsersOption)ReadManageUsersMenueOption());
}
void PerfromMainMenueOption(enMainOption MainMenueOption)
{
switch (MainMenueOption)
{
case enMainOption::eShowClient:
{
    system("cls");
    PrintAllClientsData();
    GoBackToMainMenue();
    
    break;
}
case enMainOption::eAddNewClient:
    system("cls");
    ShowAddNewClientsScreen();
    GoBackToMainMenue();
    break;
case enMainOption::eDeleteClient:
    system("cls");
    ShowDeleteClientScreen();
    GoBackToMainMenue();
    break;
case enMainOption::Update:
    system("cls");
    ShowUpdateClientScreen();
    GoBackToMainMenue();
    break;
case enMainOption::eFind:
    system("cls");
    ShowFindClientScreen();
    GoBackToMainMenue();
    break;
case enMainOption::eTransactions:
    system("cls");
    ShowTransactionsMenue();
    break;

case enMainOption::eManageUsers:
    system("cls");
    ShowManageUsersMenue();
    break;
case enMainOption::eLogout:
    system("cls");
    // ShowEndScreen();
    Login();
    break;
}
}
void ShowMainMenue()
{
  system("cls");
  cout << "===========================================\n";
  cout << "\t\tMain Menue Screen\n";
  cout << "===========================================\n";
  cout << "\t[1] Show Client List.\n";
  cout << "\t[2] Add New Client.\n";
  cout << "\t[3] Delete Client.\n";
  cout << "\t[4] Update Client Info.\n";
  cout << "\t[5] Find Client.\n";
  cout << "\t[6] Transactions.\n";
  cout << "\t[7] ManageUsers.\n";
  cout << "\t[8] Logout.\n";
  cout << "===========================================\n";
  PerfromMainMenueOption((enMainOption)ReadMainMenueOption());
  
}

bool LoadUserInfo(string Username, string Password)
{
  if (FindUserByUsernameAndPassword(Username, Password,CurrentUser))
   return true;
return false;
}
bool LoadClientInfo(string AccountNo , string PinCode)
{
  if(FindClientByAccNumberAndPinCode(AccountNo,PinCode,CurrentClient))
     return true;
  return false;   
}
void Login()
{
  bool LoginFaild = false;
  string Username, Password;
  do
 {
    system("cls");
    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n---------------------------------\n";
    if (LoginFaild)
     {
      cout << "Invlaid Account Number/PinCode!\n";
     }
    cout << "Enter Account Number? ";
    cin >> Username;

    cout << "Enter PinCode? ";
    cin >> Password;
    LoginFaild = !LoadUserInfo(Username, Password);
    //LoginFaild = !LoadClientInfo(Username,Password);
 }while(LoginFaild);
 //ShowATMMenue();
   ShowMainMenue();
 
}
int main()
{
  srand((unsigned)time(NULL));
  system("cls");

 Login();


  return 0;
}


