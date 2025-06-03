#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
enum enCharType{Mix = 1, Small = 2,Capital = 3, Digit = 4 , SpecialCharacter = 5};
static void Srand()
{
    srand((unsigned)time(NULL));
}
static int RandomNumber(int from, int to)
{
 
   int randNum = rand()%(to - from + 1)+from; //*remember to use  srand((unsigned)time(NULL));   in the main 
   return randNum;
}
static string NumtoText(int number)
{ 
  if(number==0)
  {
    return "";
  }
  if(number>=1 && number <=19)
  {
    string arr[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    return arr[number];
  }
  if(number>=20 && number<=99)
  {
    string arr[] = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    return arr[number/10] + " " + NumtoText(number%10);
  }
  if(number>=100 && number<=199)
  {
    return "One Hundred " + NumtoText(number%100);
  }
  if(number>=200 && number<=999)
  {
    return NumtoText(number/100) + " Hundreds " + NumtoText(number%100);
  }
  if(number>=1000 && number<=1999)
  {
    return "One Thousand " + NumtoText(number%1000);
  }
  if(number>=2000 and number<=99999)
  {
    return NumtoText(number/1000) + " Thousands " + NumtoText(number%1000);
  }
  if(number>=1000000 and number<=1999999)
  {
    return "One Million " + NumtoText(number%1000000);
  }
  if(number>=2000000 and number <=999999999)
  {
    return NumtoText(number/1000000) + " Millions " + NumtoText(number%1000000);
  }
  if(number >= 1000000000 && number <= 1999999999)
  {
    return "One Billion " + NumtoText(number%1000000000);
  }

  return NumtoText(number/1000000000) + " Billions " + NumtoText(number%1000000000); 
}
static char GetRandomCharacter(enCharType CharType)
{
   if (CharType == Mix)
   {
       //Capital/Samll/Digits only
       CharType = (enCharType)RandomNumber(1, 3);

   }
   switch (CharType)
   {
   case enCharType::Small:
   {
      return char(RandomNumber(97, 122));
      break;
   }
   case enCharType::Capital:
   {
      return char(RandomNumber(65, 90));
      break;
   }
   case enCharType::SpecialCharacter:
   {
      return char(RandomNumber(33, 47));
      break;
   }
   case enCharType::Digit:
   {
      return char(RandomNumber(48, 57));
      break;
   }
   default:
      break;
   }
}
static string GenerateWord(enCharType CharType, short Length)
{
   string Word;
   for (int i = 1; i <= Length; i++)
   {
      Word = Word + GetRandomCharacter(CharType);
   }
   return Word;
}
static string GenerateKey(enCharType CharType = Capital)
{
   string Key = "";
   Key = GenerateWord(CharType, 4) + "-";
   Key = Key + GenerateWord(CharType, 4) + "-";
   Key = Key + GenerateWord(CharType, 4) + "-";
   Key = Key + GenerateWord(CharType, 4);
   return Key;
}
static void GenerateKeys(short NumberOfKeys ,enCharType CharType = Capital)
{
  for (short i = 1; i <= NumberOfKeys; i++)
  {
   cout << "Key [" << i << "] : ";
   cout << GenerateKey(CharType) << endl;

  }
}
static void FillArrayWithRandomNumbers(int arry[100],short lenght ,int From , int To)
{
   for (short i = 0; i <= lenght; i++)
   {
      arry[i] = RandomNumber(From,To);
   }  
}
static void FillArrayWithRandomWords(string arry[100],short Length ,enCharType CharType = Mix)
{
   for (short i = 0; i <= Length; i++)
   {
      arry[i] = GenerateWord(CharType,Length);
   }  
}
static void FillArrayWithRandomKeys(string arry[100],short lenght ,enCharType CharType = Capital )
{
   for (short i = 0; i <= lenght; i++)
   {
      arry[i] = GenerateKey(CharType);
   }  
}
static void Swap(int &A , int &B)
{
    int x = A;
    A = B;
    B = x;
}
static void Swap(double &A , double &B)
{
    double x = A;
    A = B;
    B = x;
}
static void Swap(bool &A , bool &B)
{
    bool x = A;
    A = B;
    B = x;
}
static void Swap(char &A , char &B)
{
    char x = A;
    A = B;
    B = x;
}
static void Swap(string &A , string &B)
{
    string x = A;
    A = B;
    B = x;
}
static void Swap(clsDate &A , clsDate &B)
{
    clsDate::SwapDates(A, B);   
}
static void ShuffleArry(int arr[100],int length)
{
   for (int i = 0; i <= length; i++)
   {
      
     Swap(arr[RandomNumber(1,length)-1],arr[RandomNumber(1,length)-1]);
   }  
}
static void ShuffleArry(string arr[100],int length)
{

   for (int i = 0; i < length; i++)
   {
      
     Swap(arr[RandomNumber(1,length)-1],arr[RandomNumber(1,length)-1]);
   }  
}
static string Tabs(short NumberOfTabs)
{
    string Tabs = "";
    for (short i = 1; i <= NumberOfTabs; i++)
    {
        Tabs += "\t";
    }
    return Tabs;
}
static string Encryption(string text, short EncryptionKey=3)
{
   int textlength = text.length();
   for (int i = 0; i <= textlength; i++)
   {
      text[i] = char(int(text[i])+EncryptionKey);
   }
   return text;
}
static string Decryption(string text, short EncryptionKey=3)
{
   int textlength = text.length();
   for (int i = 0; i <= textlength; i++)
   {
      text[i] = char((int)text[i]-EncryptionKey);
   }
   
   return text;
}
};