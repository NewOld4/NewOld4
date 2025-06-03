#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{
private:
 
enum enMode {EmptyMode = 0, UpdateMode = 1};
      enMode _Mode;
      string _Country;
	  string _CurrencyCode;
	  string _CurrencyName;
	  float _Rate;
static clsCurrency _ConverLinetoCurrencyObject(string Line , string Seprator = "#//#")
{
	vector <string> vCurrencyData = clsString::Split(Line,Seprator);
    
	return clsCurrency(enMode::UpdateMode , vCurrencyData[0] , vCurrencyData[1] , vCurrencyData[2],
		 stof(vCurrencyData[3]));

}

static string _ConverCurrencyObjectToLine(clsCurrency Currency , string Seprator = "#//#")
{
	string stCurrencyRecord = "";
	stCurrencyRecord += Currency._Country + Seprator;
	stCurrencyRecord += Currency._CurrencyCode + Seprator;
	stCurrencyRecord += Currency._CurrencyName + Seprator;
	stCurrencyRecord += to_string(Currency._Rate);

	return stCurrencyRecord;
	
}

static vector <clsCurrency> _LoadCurrencyDataFromFile()
{
	vector <clsCurrency> vCurrencyData;

	fstream MyFile; 
	MyFile.open("Currencies.txt" , ios::in); //Read Only

	if(MyFile.is_open())
	{
         string Line ;
		 while(getline(MyFile,Line))
		 {
			clsCurrency CurrencyObject = _ConverLinetoCurrencyObject(Line);

			vCurrencyData.push_back(CurrencyObject);
		 }
		 MyFile.close();
	}

	return vCurrencyData;
}

static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
{
   fstream MyFile;
   MyFile.open("Currencies.txt",ios::out);
   string Dataline = "";
   if(MyFile.is_open())
   {
      for(clsCurrency Currency : vCurrencys)
	  {
		 Dataline = _ConverCurrencyObjectToLine(Currency);

		 MyFile << Dataline << endl;

	  }  
      MyFile.close();
   }

}
void _Update()
{
	vector <clsCurrency> _vCurrencys = _LoadCurrencyDataFromFile();

	for(clsCurrency &C : _vCurrencys)
	{
       if(C.CurrencyCode() == CurrencyCode())
	   {
		  C = *this;
		  break;
	   }
	}
	_SaveCurrencyDataToFile(_vCurrencys);
    
}

static clsCurrency _GetEmptyCurrency()
{
	return clsCurrency(enMode::EmptyMode , "","","",0);
}
    



public:
  clsCurrency (enMode Mode , string Country , string Code , string Name , float Rate)
  {
	 _Mode = Mode;
	 _Country = Country ;
	 _CurrencyCode = Code ;
	 _CurrencyName = Name;
	 _Rate = Rate;
  }

 



bool IsEmpty()
{
  return (_Mode == enMode::EmptyMode);
}
string Country()
{
	return _Country;
}

string CurrencyCode()
{
	return _CurrencyCode;
}

string CurrencyName()
{
	return _CurrencyName;
}

float Rate()
{
	return _Rate;
}

void UpdateRate(float NewRate)
{
	_Rate = NewRate;
	_Update();
}

static clsCurrency FindByCode(string CurrencyCode)
{
	CurrencyCode = clsString::UpperString(CurrencyCode);

	fstream MyFile;
	MyFile.open("Currencies.txt",ios::in);
	if(MyFile.is_open())
	{
		string Line ;
		while(getline(MyFile,Line))
		{
			clsCurrency Currency = _ConverLinetoCurrencyObject(Line);
			if(Currency.CurrencyCode() == CurrencyCode)
			{
				MyFile.close();
				return Currency;
			}
		}
		MyFile.close();
	}
	return _GetEmptyCurrency();
}

static clsCurrency FindByCountry (string CurrencyCountry)
{
	CurrencyCountry = clsString::UpperString(CurrencyCountry);

	fstream MyFile;
	MyFile.open("Currencies.txt",ios::in);
	if(MyFile.is_open())
	{
		string Line ;
		while(getline(MyFile,Line))
		{
			clsCurrency Currency = _ConverLinetoCurrencyObject(Line);
			if(clsString::UpperString(Currency.Country()) == CurrencyCountry)
			{
				MyFile.close();
				return Currency;
			}
		}
		MyFile.close();
	}
	return _GetEmptyCurrency();
}

static bool IsCurrencyExist(string CurrencyCode)
{
	clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
	return(!C1.IsEmpty());

}
static vector <clsCurrency> GetCurrenciesList()
{
	return _LoadCurrencyDataFromFile();
}

float ConvertToUSD(float amount)
{
	return (amount / Rate());
}

float ConvertToOtherCurrency(float amount , clsCurrency Currency2)
{
	float AmountInUSD = ConvertToUSD(amount);

	if(Currency2.CurrencyCode() == "USD")
	{
		return AmountInUSD;
	}
	return (AmountInUSD * Currency2.Rate());
}
};