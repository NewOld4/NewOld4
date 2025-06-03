
#pragma once
#include <iostream>
using namespace std;
#include <vector>
class clsString 
{

private:
    string _Value;

public:
    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    
     
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }



   static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        unsigned short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };
  static void PrintFirstLetterOfEachWord(string Value)
  {
      short ValueLength = Value.length();
      bool isfirstletter = true;
      for (short i = 0; i < ValueLength; i++)
     {
        if (Value[i] != ' ' && isfirstletter)
        {
          cout << Value[i] << endl;
        }
        isfirstletter = (Value[i] == ' ' ? true : false);
      }
  }
 void PrintFirstLetterOfEachWord()
 {
    PrintFirstLetterOfEachWord(_Value);
 }

 static string UpperFirstLetterOfEachWord(string Value)
{
  short ValueLenth = Value.length();
  bool isfirstletter = true;
  for (short i = 0; i < ValueLenth; i++)
  {
    if (Value[i] != ' ' && isfirstletter)
    {
        Value[i] = toupper(Value[i]);
    }
    isfirstletter = ((Value[i] == ' ' )|( Value[i] == '-') ? true : false);
  }
  return Value;
}
void UpperFirstLetterOfEachWord()
{
  _Value = UpperFirstLetterOfEachWord(_Value);
}

static string LowerFirstLetterOfEachWord(string Value)
{
  short ValueLenth = Value.length();
  bool isfirstletter = true;
  for (short i = 0; i < ValueLenth; i++)
  {
    if (Value[i] != ' ' && isfirstletter)
    {
        Value[i] = tolower(Value[i]);
    }
    isfirstletter = ((Value[i] == ' ' )|( Value[i] == '-') ? true : false);
  }
  return Value;
}
void LowerFirstLetterOfEachWord()
{
   _Value =  LowerFirstLetterOfEachWord(_Value);
}

static string LowerString(string Value)
{
  short ValueLength = Value.length();
  for (short i = 0; i < ValueLength; i++)
  {
    Value[i] = tolower(Value[i]);
  }
  return Value;
}
void LowerString()
{
    _Value =  LowerString(_Value);
}
static string UpperString(string Value)
{
  short ValueLength = Value.length();
  for (short i = 0; i < ValueLength; i++)
  {
    Value[i] = toupper(Value[i]);
  }
  return Value;
}
void UpperString()
{
    _Value = UpperString(_Value);
}

static char Invertinglettercase(char char1)
{
  return isupper(char1) ? tolower(char1) : toupper(char1);
}
static string InvertingAllStringLettersCase(string String1)
{
  short Slength = String1.length();
  for (short i = 0; i < Slength; i++)
  {
    String1[i] = Invertinglettercase(String1[i]);
  }
  return String1;
}
void InvertingAllStringLettersCase()
{
  _Value =  InvertingAllStringLettersCase(_Value);
}

static short CountCapitalLetters(string S1)
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
short CountCapitalLetters()
{
    return CountCapitalLetters(_Value);
}
static short CountSmallLetters(string S1)
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
short CountSmallLetters()
{
    return CountSmallLetters(_Value);
}
enum enWhatToCount
{
  SmallLetters = 0,
  CapitalLetters = 1,
  All = 2
};
static short CountLetters(string S1, short WhatToCount = enWhatToCount::All)
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

static short CountSpecificLetter(string S1, char C, bool MatchCase = true)
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
short CountSpecificLetter(char C,bool MathCase = true)
{
  return CountSpecificLetter(_Value,C,MathCase);
}
bool static IsVowel(char letter)
{
  letter = tolower(letter);
  return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u');
}
static short CountVowels(string text)
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
short CountVowels()
{
  return CountVowels(_Value);
}
static void PrintVowels(string text)
{
  short txtlength = text.length();
  cout << "\nVowels in string are: ";
  for (short i = 0; i < txtlength; i++)
  {
    if (IsVowel(text[i]))
      cout << text[i] << " ";
  }
}
void PrintVowels()
{
  PrintVowels(_Value);
}
static void PrintEachWord(string S1)
{
  string delim = " ";
  cout << "your string words are: \n\n";
  unsigned short pos = 0;
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
void PrintEachWord()
{
  PrintEachWord(_Value);
}

static string JoinStrings(vector<string> vString, string delim)
{
  string S1 = "";
  for (string &s : vString)
  {
    S1 = S1 + s + delim;
  }
  return S1.substr(0, S1.length() - delim.length());
}

static string JoinStrings(clsString array[], short length, string delim)
{
  string S1 = "";
  for (short i = 0; i < length; i++)
  {
    S1 = S1 + array[i]._Value + delim;
  }
  return S1.substr(0, S1.length() - delim.length());
}

static string TrimRight(string S1)
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
string TrimRight()
{
  return TrimRight(_Value);
}

static string TrimLeft(string S1)
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
string TrimLeft()
{
  return TrimLeft(_Value);
}
static string Trim(string S1)
{
  return TrimRight(TrimLeft(S1));
}
string Trim()
{
  return Trim(_Value);
}
static vector<string> Split(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
         if (sWord != "")
       // {
            vString.push_back(sWord);
        //}

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

static string ReverseString(string S1)
{
  vector<string> vString;
  string S2 = "";
  vString = Split(S1, " ");
  vector<string>::iterator iter = vString.end();
  while (iter != vString.begin())
  {
    --iter;
    S2 += *iter + " ";
  }
  S2 = S2.substr(0, S2.length() - 1);
  return S2;
}
string ReverseString()
{
  return ReverseString(_Value);
}

string ReplaceWord(string S1, string Oldword, string Newword, bool matchcase = true) //! need to solve
{
  vector<string> vstring;
  vstring = Split(S1, " ");
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
  
  return JoinStrings(vstring," ");
} 


void ReplaceWord(string toreplace , string replaceto)
{
  _Value = ReplaceWord(_Value,toreplace,replaceto,true);
}

static string RemovePunctuaions(string S1)
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
void RemovePunctuaions()
{
  _Value = RemovePunctuaions(_Value);
}
};

