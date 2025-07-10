// -------------------------------------------------------------------------------- 
// Name: Chad A Hammons 
// Class: C++ 2 
// Abstract: Final Project. CSuperString Tests 
// -------------------------------------------------------------------------------- 

// -------------------------------------------------------------------------------- 
// // Includes – built-in libraries of functions 
// -------------------------------------------------------------------------------- 
#include <stdio.h> 
#include <iostream>
#include "CSuperString.h"
using namespace std;

// -------------------------------------------------------------------------------- 
// // Constants 
// -------------------------------------------------------------------------------- 


// -------------------------------------------------------------------------------- 
// // User Defined Types (UDT) 
// -------------------------------------------------------------------------------- 


// -------------------------------------------------------------------------------- 
// // Prototypes 
// -------------------------------------------------------------------------------- 
void Test1();
void Test2();
void constructorTests();
void operatorTests();
void indexTests();
void manipulationTests();
void conversionTests();

// -------------------------------------------------------------------------------- 
// // Name: main 
// Abstract: This is where the program starts 
// -------------------------------------------------------------------------------- 
int main()
{
	/*
	* Whew! Finally all finished! Its not the cleanest job, but it all does work at least.
	* This semester has taught me so much, and I have to say that I've enjoyed it a good bit.
	* Thank you for all your help this semester, and a wonderful class.
	*/

	cout << "---------------------------------------" << endl;
	cout << "-------- CSuperString Tests -----------" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;

	Test1();
	Test2();

	constructorTests();
	indexTests();
	manipulationTests();
	conversionTests();
	operatorTests(); // Will need input for cin >>

	return 0;
}

void constructorTests()
{
	

	//Constructors
	CSuperString ssSource1;
	CSuperString ssSource2("I love Star Trek");
	CSuperString ssSource3a(true);
	CSuperString ssSource3b(false);
	CSuperString ssSource4('A');
	CSuperString ssSource5a((short) SHRT_MAX);
	CSuperString ssSource5b((short) SHRT_MIN);
	CSuperString ssSource6a((int) INT_MAX);
	CSuperString ssSource6b((int) INT_MIN);
	CSuperString ssSource7a((long) LONG_MAX);
	CSuperString ssSource7b((long) LONG_MIN);
	CSuperString ssSource8a((float) FLT_MAX);
	CSuperString ssSource8b((float) FLT_MIN);
	CSuperString ssSource9a((double) DBL_MAX);
	CSuperString ssSource9b((double) DBL_MIN);
	CSuperString ssSource10(ssSource2);


	//Tests
	cout << "-------- Constructor Tests -----------" << endl;

	cout << "Default -- " << ssSource1 << endl;
	cout << "Boolean 'true' -- " << ssSource3a.ToString() << endl;
	cout << "Boolean 'false' -- " << ssSource3b.ToString() << endl;
	cout << "Const Char -- " << ssSource4 << endl;
	cout << "Float Max -- " << ssSource5a << endl;
	cout << "Float Min -- " << ssSource5b << endl;
	cout << "Integer Max -- " << ssSource6a << endl;
	cout << "Integer Min -- " << ssSource6b << endl;
	cout << "Long Max -- " << ssSource7a << endl;
	cout << "Long Min -- " << ssSource7b << endl;
	cout << "Float Max -- " << ssSource8a << endl;
	cout << "Float Min -- " << ssSource8b << endl;
	cout << "Double Max -- " << ssSource9a << endl;
	cout << "Double Min -- " << ssSource9b << endl;
	cout << "SuperString -- " << ssSource10 << endl;
	cout << endl;
	cout << endl;

}



void operatorTests()
{
	//---------------------
	// Operator =
	//---------------------
	CSuperString ssSource1 = "I love Star Trek";
	CSuperString ssSource2 = 'O';
	CSuperString ssSource3 = ssSource1;

	//---------------------
	// Operator +=
	//---------------------
	CSuperString ssSource1b = "I love ";
	ssSource1b += "Dungeons and Dragons!";
	CSuperString ssSource2b = "My favorite letter is ";
	ssSource2b += 'Z';
	CSuperString ssSource3b = ssSource1b;
	ssSource3b += ssSource2b;

	//---------------------
	// Operator +
	//---------------------
	CSuperString ssLeft("Star Trek is ");
	CSuperString ssRight("very cool!");
	const char* chrStringLeft = "Star Trek is ";
	const char* chrStringRight = "very cool!";
	CSuperString ssCombineda = ssLeft + ssRight;
	CSuperString ssCombinedb = chrStringLeft + ssRight;
	CSuperString ssCombinedc = ssLeft + chrStringRight;

	//---------------------
	// Comparison Operators
	//---------------------

	CSuperString ssCompare1a = "Red";
	CSuperString ssCompare1c = "Green";

	//---------------
	// >> Operator
	//---------------
	CSuperString ssIn;

	bool blnCompare1 = ssCompare1a == "Red";
	bool blnCompare1b = ssCompare1a == 'B';
	bool blnCompare1c = ssCompare1a == ssCompare1c;

	bool blnCompare2 = ssCompare1a != "Red";
	bool blnCompare2b = ssCompare1a != 'B';
	bool blnCompare2c = ssCompare1a != ssCompare1c;

	bool blnCompare3 = ssCompare1a < "Red";
	bool blnCompare3b = ssCompare1a < 'B';
	bool blnCompare3c = ssCompare1a < ssCompare1c;

	bool blnCompare4 = ssCompare1a <= "Red";
	bool blnCompare4b = ssCompare1a <= 'B';
	bool blnCompare4c = ssCompare1a <= ssCompare1c;

	bool blnCompare5 = ssCompare1a > "Red";
	bool blnCompare5b = ssCompare1a > 'B';
	bool blnCompare5c = ssCompare1a > ssCompare1c;

	bool blnCompare6 = ssCompare1a >= "Red";
	bool blnCompare6b = ssCompare1a >= 'B';
	bool blnCompare6c = ssCompare1a >= ssCompare1c;


	// = Tests
	cout << "----------- Operator = Tests ---------------" << endl;

	cout << " = Const Char* -- " << ssSource1 << endl;
	cout << " = const Char -- " << ssSource2 << endl;
	cout << " = SuperString -- " << ssSource3 << endl;
	cout << endl;
	cout << endl;

	// += Tests
	cout << "----------- Operator += Tests ---------------" << endl;

	cout << " += Const Char* -- " << ssSource1b << endl;
	cout << " += Const Char -- " << ssSource2b << endl;
	cout << " += SuperString -- " << ssSource3b << endl;
	cout << endl;
	cout << endl;

	//+ Tests
	cout << "----------- Operator + Tests ---------------" << endl;

	cout << "SuperString + SuperString -- " << ssCombineda << endl;
	cout << "const char* + SuperString -- " << ssCombineda << endl;
	cout << "SuperString + const char* -- " << ssCombineda << endl;
	cout << endl;
	cout << endl;

	//== Tests
	cout << "----------- Operator == Tests ---------------" << endl;
	cout << "----------- 1 = True 0 = False sorry I couldn't think of a better way to do this ---------------" << endl;

	cout << " == Const Char* (Red == Red) -- " << blnCompare1 << endl;
	cout << " == const Char (Red == B) -- " << blnCompare1b << endl;
	cout << " == SuperString (Red == Green) -- " << blnCompare1c << endl;
	cout << endl;
	cout << endl;

	//!= Tests
	cout << "----------- Operator != Tests ---------------" << endl;

	cout << " != Const Char* (Red != Red) -- " << blnCompare2 << endl;
	cout << " != const Char (Red != B) -- " << blnCompare2b << endl;
	cout << " != SuperString (Red != Green) -- " << blnCompare2c << endl;
	cout << endl;
	cout << endl;

	// < Tests
	cout << "----------- Operator < Tests ---------------" << endl;

	cout << " < Const Char* (Red < Red) -- " << blnCompare3 << endl;
	cout << " < const Char (Red < B) -- " << blnCompare3b << endl;
	cout << " < SuperString (Red < Green) -- " << blnCompare3c << endl;
	cout << endl;
	cout << endl;

	// <= Tests
	cout << "----------- Operator <= Tests ---------------" << endl;

	cout << " <= Const Char* (Red <= Red) -- " << blnCompare4 << endl;
	cout << " <= const Char (Red <= B) -- " << blnCompare4b << endl;
	cout << " <= SuperString (Red <= Green) -- " << blnCompare4c << endl;
	cout << endl;
	cout << endl;

	// > Tests
	cout << "----------- Operator < Tests ---------------" << endl;

	cout << " > Const Char* (Red > Red) -- " << blnCompare5 << endl;
	cout << " > const Char (Red > B) -- " << blnCompare5b << endl;
	cout << " > SuperString (Red > Green) -- " << blnCompare5c << endl;
	cout << endl;
	cout << endl;

	// >= Tests
	cout << "----------- Operator >= Tests ---------------" << endl;

	cout << " >= Const Char* (Red >= Red) -- " << blnCompare6 << endl;
	cout << " >= const Char (Red >= B) -- " << blnCompare6b << endl;
	cout << " >= SuperString (Red >= Green) -- " << blnCompare6c << endl;
	cout << endl;
	cout << endl;

	// [] Tests
	cout << "----------- Operator [] Tests ---------------" << endl;

	cout << " [] Char& -- " << ssSource1[0] << endl;
	cout << " [] const Char&  -- " << ssSource1[11] << endl;
	cout << endl;
	cout << endl;

	//>> test
	cout << "----------- Operator >> / << Test ---------------" << endl;

	cout << "Enter an input for ssIn (>> Operator)";
	cin >> ssIn;
	cout << "Input entered for ssIn: " << ssIn << endl;
}



void indexTests()
{
	CSuperString ssSource("I love love Star Trek");
	long lngFind1 = ssSource.FindFirstIndexOf('o');
	long lngFind2 = ssSource.FindFirstIndexOf('e', 8);
	long lngFind3 = ssSource.FindLastIndexOf('e');

	long lngFind4 = ssSource.FindFirstIndexOf("love");
	long lngFind5 = ssSource.FindFirstIndexOf("Trek", 8);
	long lngFind6 = ssSource.FindLastIndexOf("love");

	//Tests
	cout << "-------- Find Index Tests -----------" << endl;

	cout << "First Index of o -- " << lngFind1 << endl;
	cout << "First Index of e, starting at index 8 -- " << lngFind2 << endl;
	cout << "Last Index of e -- " << lngFind3 << endl;
	cout << "First Index of 'love' -- " << lngFind4 << endl;
	cout << "First Index of 'Trek', starting at index 8 -- " << lngFind5 << endl;
	cout << "Last Index of 'love' -- " << lngFind6 << endl;
	cout << endl;
	cout << endl;
}



void manipulationTests()
{
	CSuperString ssSource = "I love Star Trek.";
	CSuperString ssSource2 = "           I Love Star Trek             ";
	const char* chrStringUpper = ssSource.ToUpperCase();
	const char* chrStringLower = ssSource.ToLowerCase();
	const char* chrStringTrimLeft = ssSource2.TrimLeft();
	const char* chrStringTrimRight = ssSource2.TrimRight();
	const char* chrStringTrim = ssSource2.Trim();
	const char* chrStringReverse = ssSource.Reverse();
	const char* chrStringLeft = ssSource.Left(4);
	const char* chrStringRight = ssSource.Right(6);
	const char* chrStringSubstring = ssSource.Substring(4,10);
	const char* chrStringReplace = ssSource.Replace('e', 'z');
	const char* chrStringReplaceString = ssSource.Replace("love", "loathe");
	const char* chrStringInsert = ssSource.Insert('j', 6);
	const char* chrStringInsertString = ssSource.Insert("love", 6);


	cout << "-------- String Manipulation Tests -----------" << endl;

	//To Upper/Lower
	cout << "To UpperCase -- " << chrStringUpper << endl;
	delete chrStringUpper;
	chrStringUpper = 0;

	cout << "To LowerCase -- " << chrStringLower << endl;
	delete chrStringLower;
	chrStringLower = 0;

	//Trims
	cout << "Trim Left -- " << chrStringTrimLeft << "with Leading text." << endl;
	delete chrStringTrimLeft;
	chrStringTrimLeft = 0;

	cout << "Trim Right -- " << chrStringTrimRight << "with Leading text." << endl;
	delete chrStringTrimRight;
	chrStringTrimRight = 0;

	cout << "Trim  -- " << chrStringTrim << "with Leading text." << endl;
	delete chrStringTrim;
	chrStringTrim = 0;

	//Reverse
	cout << "Reverse  -- " << chrStringReverse << endl;
	delete chrStringReverse;
	chrStringReverse = 0;

	//Right and Left
	cout << "Left 4 indexes  -- " << chrStringLeft << endl;
	delete chrStringLeft;
	chrStringLeft = 0;

	cout << "Right 6 indexes -- " << chrStringRight << endl;
	delete chrStringRight;
	chrStringRight = 0;

	//Substring
	cout << "Substring from index 4 to 10 -- " << chrStringSubstring << endl;
	delete chrStringSubstring;
	chrStringSubstring = 0;

	//Replace
	cout << "Replace e to z -- " << chrStringReplace << endl;
	delete chrStringReplace;
	chrStringReplace = 0;

	cout << "Replace String love to loathe -- " << chrStringReplaceString << endl;
	delete chrStringReplaceString;
	chrStringReplaceString = 0;

	//Insert
	cout << "Insert j at index 6 -- " << chrStringInsert << endl;
	delete chrStringInsert;
	chrStringInsert = 0;

	cout << "Insert String love to index 6 -- " << chrStringInsertString << endl;
	delete chrStringInsertString;
	chrStringInsertString = 0;
	cout << endl;
	cout << endl;
}



void conversionTests()
{
	//Constructors
	CSuperString ssSource1(true);
	CSuperString ssSource2 = "500";
	CSuperString ssSource3 = "500.500";
	CSuperString ssSource4 = "true";

	cout << "To String (boolean true) -- " << ssSource1.ToString() << endl;
	cout << "To Boolean -- " << ssSource4.ToBoolean() << endl;
	cout << "To Short -- " << ssSource2.ToShort() << endl;
	cout << "To Integer -- " << ssSource2.ToInteger() << endl;
	cout << "To Long -- " << ssSource2.ToLong() << endl;
	cout << "To Float -- " << ssSource3.ToFloat() << endl;
	cout << "To Double -- " << ssSource3.ToDouble() << endl;
	cout << endl;
	cout << endl;
}



void Test1()
{
	CSuperString ssTest;
	cout << "Test #1: " << ssTest << endl;
	cout << endl;
	cout << endl;
}



void Test2()
{
	CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

	ssTest = ssTest.Replace("Love", "Really Love Love");

	cout << " Test #2: " << ssTest << endl;
	cout << endl;
	cout << endl;
}
