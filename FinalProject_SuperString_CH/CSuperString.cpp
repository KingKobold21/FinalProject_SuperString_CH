//------------------------------------------------
// Name: CSuperString
// Abstract: Definitions for CSuperString
//------------------------------------------------

//---------------------
// Includes
//---------------------
#define _CRT_SECURE_NO_WARNINGS
#include "CSuperString.h"

//-----------------------------------------------------------
// Name: Default Constructor
// Abstract: Default Constructor for CSuperString
//-----------------------------------------------------------
CSuperString::CSuperString() 
{
	Initialize("");
}



//-----------------------------------------------------------
// Name: Char* constructor
// Abstract: Constructor for CSuperString using a char*
//-----------------------------------------------------------
CSuperString::CSuperString(const char* pstrStringToCopy)
{
	Initialize(pstrStringToCopy);
}



//-----------------------------------------------------------
// Name: Boolean constructor
// Abstract: Constructor for CSuperString using a Boolean
//-----------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	Initialize("");

	if (blnBooleanToCopy == true)
	{
		*this = "true";
	}
	else
	{
		*this = "false";
	}
}



//-----------------------------------------------------------
// Name: Char constructor
// Abstract: Constructor for CSuperString using a char
//-----------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy)
{
	Initialize("");
	//char strSource[2] = { chrLetterToCopy, 0 };
	*this = chrLetterToCopy;
	
}



//-----------------------------------------------------------
// Name: short constructor
// Abstract: Constructor for CSuperString using a short
//-----------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy)
{
	char strSource[8] = "";

	sprintf_s(strSource, "%hd", shtShortToCopy);

	Initialize(strSource);

}



//-----------------------------------------------------------
// Name: Integer constructor
// Abstract: Constructor for CSuperString using an int
//-----------------------------------------------------------
CSuperString::CSuperString(const int intIntegerToCopy)
{
	char strSource[13] = "";

	sprintf_s(strSource, "%d", intIntegerToCopy);

	Initialize(strSource);

}



//-----------------------------------------------------------
// Name: Long constructor
// Abstract: Constructor for CSuperString using a long
//-----------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy)
{
	char strSource[23] = "";

	sprintf_s(strSource, "%ld", lngLongToCopy);

	Initialize(strSource);

}



//-----------------------------------------------------------
// Name: Float constructor
// Abstract: Constructor for CSuperString using an int
//-----------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy)
{
	char strSource[51] = "";

	//using %e since it looks nicer, otherwise float min looks empty and float max is a big ol' number.
	sprintf_s(strSource, "%e", sngFloatToCopy);

	Initialize(strSource);

}



//-----------------------------------------------------------
// Name: Double constructor
// Abstract: Constructor for CSuperString using an int
//-----------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy)
{
	char strSource[320] = "";

	//using %e since it looks nicer, otherwise double min looks empty and double max is a HUGE number.
	sprintf_s(strSource, "%e", dblDoubleToCopy);

	Initialize(strSource);

}



//-----------------------------------------------------------
// Name: Class Constructor
// Abstract: using Superstring variable as constructor for CSuperString
//-----------------------------------------------------------
CSuperString::CSuperString(const CSuperString &ssStringToCopy)
{
	//Initialize(ssStringToCopy.ToString());
	Initialize("");
	*this = ssStringToCopy;
}

	//-----------------------------------------------------------
	// Name: Initialize
	// Abstract: Sets the initial pointer to 0
	//-----------------------------------------------------------
	void CSuperString::Initialize(const char* pstrSource)
	{
		m_pstrSuperString = 0;

		//Memory allocatioin through Assignment operator

		*this = pstrSource;
	}


//-----------------------------------------------------------
// Name: Destructor
// Abstract: Makes everything nice and neat before the program closes
//-----------------------------------------------------------
CSuperString::~CSuperString()
{
	CleanUp();
}



	//-----------------------------------------------------------
	// Name: CleanUp
	// Abstract: Cleans everything so no memory leaks
	//-----------------------------------------------------------
	void CSuperString::CleanUp()
	{
		DeleteString(m_pstrSuperString);
	}

		//-----------------------------------------------------------
		// Name: DeleteString
		// Abstract: Sells the house and throws away the keys
		//-----------------------------------------------------------
		void CSuperString::DeleteString(char*& pstrSource)
		{
			//Is there anything TO delete?
			if (pstrSource != 0)
			{
				delete pstrSource; //Sell house
				pstrSource = 0; //Throw away keys, no memory leaks
			}
		}



//-----------------------------------------------------------
// Name: Length
// Abstract: REturns the length of the string
//-----------------------------------------------------------
long CSuperString::Length() const
{
	long lngLength = 0;
	lngLength = (long)strlen(m_pstrSuperString);
	
	return lngLength;
}


//-----------------------------------------------------------
// Name: operator =
// Abstract: Assignment operator (=) for char* (String)
//-----------------------------------------------------------
void CSuperString::operator =(const char* pstrSource)
{
	//Check to see if source equals the pointer string
	if (m_pstrSuperString != pstrSource)
	{
		//If not, clean up and deep copy.

		CleanUp();

		DeepCopy(pstrSource);
	}
}



//-----------------------------------------------------------
// Name: operator =
// Abstract: Assignment operator (=) for char
//-----------------------------------------------------------
void CSuperString::operator =(const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy, 0 };
	*this = strSource;

}



//-----------------------------------------------------------
// Name: operator =
// Abstract: Assignment operator (=) for SuperString
//-----------------------------------------------------------
void CSuperString::operator =(const CSuperString& ssStringToCopy)
{

	char strSource[50] = "";
	sprintf_s(strSource, ssStringToCopy.ToString());
	*this = strSource;

}



	//-----------------------------------------------------------
	// Name: DeepCopy
	// Abstract: Copies the source to a new location in memory.
	//-----------------------------------------------------------
	void CSuperString::DeepCopy(const char* pstrSource)
	{

		m_pstrSuperString = CloneString(pstrSource);

	}



		//-----------------------------------------------------------
		// Name: CloneString
		// Abstract: Copy the String
		//-----------------------------------------------------------
		char* CSuperString::CloneString(const char* pstrSource)
		{
			//Variables
			char* pstrClone = 0;
			long lngLength = 0;

			//Is the source null?
			if (pstrSource != 0)
			{
				//If not, make allocate memory to copy string
				lngLength = strlen(pstrSource);
				pstrClone = new char[lngLength + 1];
				strcpy_s(pstrClone, lngLength + 1, pstrSource);
			}
			else
			{
				//Already empty, make clone empty too.
				pstrClone = new char[1];
				*(pstrClone + 0) = 0;
			}

			return pstrClone;
		}



//-----------------------------------------------------------
// Name: operator ==
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator == (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists.
	if (strcmp(m_pstrSuperString, pstrStringToCompare) == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator ==
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator == (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists.

	if (m_pstrSuperString[0] == chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator ==
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator == (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists.

	if (strcmp(m_pstrSuperString, ssStringToCompare.ToString()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator !=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator != (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strcmp(m_pstrSuperString, pstrStringToCompare) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator !=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator != (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (m_pstrSuperString[0] != chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator !=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator != (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strcmp(m_pstrSuperString, ssStringToCompare.ToString()) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator < (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) < strlen(pstrStringToCompare))
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator < (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (m_pstrSuperString[0] < chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator < (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) < ssStringToCompare.Length())
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator <= (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) <= strlen(pstrStringToCompare))
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator <= (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (m_pstrSuperString[0] <= chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator <=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator <= (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) <= ssStringToCompare.Length())
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator > (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) > strlen(pstrStringToCompare))
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator > (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (m_pstrSuperString[0] > chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator > (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) > ssStringToCompare.Length())
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator >= (const char* pstrStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) >= strlen(pstrStringToCompare))
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator >= (const char chrLetterToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (m_pstrSuperString[0] >= chrLetterToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator >=
// Abstract: Compares two strings and returns true or false.
//-----------------------------------------------------------
bool CSuperString::operator >= (const CSuperString& ssStringToCompare)
{
	//Fairly simple, since strcmp exists, have to change to other symbol though.

	if (strlen(m_pstrSuperString) >= ssStringToCompare.Length())
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: operator += (char*)
// Abstract: Assignment operator (+=) for char* (String)
//-----------------------------------------------------------
void CSuperString::operator +=(const char* pstrStringToAppend)
{
	int intLength1 = 0;
	int intLength2 = 0;
	int intTotalLength = 0;

	intLength1 = strlen(pstrStringToAppend);
	intLength2 = strlen(m_pstrSuperString);

	//Combining two lengths and Giving it a small buffer just in case,
	//for null terminators and other things.
	intTotalLength = intLength1 + intLength2 + 3;

	//Making a new char array to hold the new stuff.
	char* chrNewString = new char[intTotalLength];

	//Strcat isn't deleting properly.... I wonder why...
	//Time to do roundabout things I guess.
	strcpy(chrNewString,m_pstrSuperString);
	strcat(chrNewString, pstrStringToAppend);

	//Deleting m_pstrSuperString, THEN reallocating it is the only way I've tried to get it
	//To stop the errors and supposedly "Writing to memory after end".
	//It works and its not seeming to cause issues so....
	delete m_pstrSuperString;

	m_pstrSuperString = new char[intTotalLength];

	strcpy(m_pstrSuperString, chrNewString);
	
	//Can't forget to delete the string I made, no memory leaks.
	delete[] chrNewString;
	chrNewString = 0;
}



//-----------------------------------------------------------
// Name: operator += (char)
// Abstract: Assignment operator (+=) for char* (String)
//-----------------------------------------------------------
void CSuperString::operator +=(const char chrCharacterToAppend)
{
	int IntLength = 0;
	int intTotalLength = 0;

	IntLength = strlen(m_pstrSuperString);

	//Making a new length
	//for null terminators and other things.
	intTotalLength = IntLength + 5;

	//Making a new char array to hold the new stuff.
	char* chrNewString = new char[intTotalLength];

	//Strcat isn't deleting properly.... I wonder why...
	//Time to do roundabout things I guess.
	strcpy(chrNewString, m_pstrSuperString);
	chrNewString[IntLength] = chrCharacterToAppend;

	//Telling the string to end AFTER I add the character (Does it work like this? Its working so...)
	chrNewString[IntLength + 1] = '\0';

	//Deleting m_pstrSuperString, THEN reallocating it is the only way I've tried to get it
	//To stop the errors and supposedly "Writing to memory after end".
	//It works and its not seeming to cause issues so....
	delete m_pstrSuperString;

	m_pstrSuperString = new char[intTotalLength];

	strcpy(m_pstrSuperString, chrNewString);

	//Can't forget to delete the string I made, no memory leaks.
	delete[] chrNewString;
	chrNewString = 0;
}



//-----------------------------------------------------------
// Name: operator += (SuperString)
// Abstract: Assignment operator (+=) for SuperString class
//-----------------------------------------------------------
void CSuperString::operator +=(const CSuperString& ssStringToAppend)
{
	int intLength1 = 0;
	int intLength2 = 0;
	int intTotalLength = 0;

	intLength1 = strlen(m_pstrSuperString);
	intLength2 = ssStringToAppend.Length();

	//Combining two lengths and Giving it a small buffer just in case,
	//for null terminators and other things.
	intTotalLength = intLength1 + intLength2 + 4;

	//Making a new char array to hold the new stuff.
	char* chrNewString = new char[intTotalLength];

	strcpy(chrNewString, m_pstrSuperString);
	strcat(chrNewString, ssStringToAppend.ToString());


	//Deleting m_pstrSuperString, THEN reallocating it is the only way I've tried to get it
	//To stop the errors and supposedly "Writing to memory after end".
	//It works and its not seeming to cause issues so....
	delete m_pstrSuperString;

	m_pstrSuperString = new char[intTotalLength];

	strcpy(m_pstrSuperString, chrNewString);

	//Can't forget to delete the string I made, no memory leaks.
	delete[] chrNewString;
	chrNewString = 0;
}



//-----------------------------------------------------------
// Name: operator + 
// Abstract: Assignment operator (+) for SuperString class
//-----------------------------------------------------------
CSuperString operator +(const CSuperString& ssLeft,
	const CSuperString& ssRight)
{
	CSuperString ssCombined;

	//Easy enough if we use what we've already made.
	ssCombined += ssLeft;
	ssCombined += ssRight;

	return ssCombined;
}



//-----------------------------------------------------------
// Name: operator + (const char Left)
// Abstract: Assignment operator (+) for SuperString class
//-----------------------------------------------------------
CSuperString operator + (const char* pstrLeftSide,
	const CSuperString& ssRightString)
{
	CSuperString ssCombined;

	//Easy enough if we use what we've already made.
	ssCombined = pstrLeftSide;
	ssCombined += ssRightString;

	return ssCombined;
}



//-----------------------------------------------------------
// Name: operator + (const char Right)
// Abstract: Assignment operator (+) for SuperString class
//-----------------------------------------------------------
CSuperString operator + (const CSuperString& ssLeftString,
	const char* pstrRightSide)
{
	CSuperString ssCombined;

	//Easy enough if we use what we've already made.
	ssCombined += ssLeftString;
	ssCombined += pstrRightSide;

	return ssCombined;
}



//-----------------------------------------------------------
// Name: FindFirstIndexOf
// Abstract: Finds the first instance of the specified char
//-----------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	long lngIndex = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);

	//Maybe use a for search?
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		//If it finds the char, return the index right away.
		if (m_pstrSuperString[lngIndex] == chrLetterToFind)
			return lngIndex;
	}

	cout << "The char doesn't exist." << endl;
	return 0;
}



//-----------------------------------------------------------
// Name: FindFirstIndexOf Overload
// Abstract: Finds the first instance of the specified char and start index
//-----------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	long lngIndex = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);

	//Maybe use a for search? This time with a starting index.
	for (lngIndex = lngStartIndex; lngIndex < lngLength; lngIndex += 1)
	{
		//If it finds the char, return the index right away.
		if (m_pstrSuperString[lngIndex] == chrLetterToFind)
			return lngIndex;
	}

	//If it finds nothing, say so.
	cout << "The char doesn't exist." << endl;
	return 0;
}



//-----------------------------------------------------------
// Name: FindLastIndexOf
// Abstract: Finds the last instance of the specified char
//-----------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	long lngIndex = 0;
	long lngReturnIndex = -1;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);

	//Maybe use a for search?
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		//If it finds the char, similar to min max, we add it to a holder, then return the holder
		//once the loop stops.
		if (m_pstrSuperString[lngIndex] == chrLetterToFind)
			lngReturnIndex = lngIndex;
	}

	//If it finds nothing, then say so.
	if (lngReturnIndex == -1)
	{
		cout << "The char doesn't exist." << endl;
		return 0;
	}

	return lngReturnIndex;
}



//-----------------------------------------------------------
// Name: FindFirstIndexOf (Substring)
// Abstract: Finds the first instance of the specified substring
//-----------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind)
{
	long lngIndex = 0;
	long lngLength = 0;
	long lngLength2 = 0;
	lngLength = strlen(m_pstrSuperString);
	lngLength2 = strlen(pstrSubStringToFind);
	const char* chrSubstring = new char[lngLength2];
	
	//Probably not a good way to do this, but lets use the substring class we've already made.
	CSuperString ssSubstring;
	ssSubstring = m_pstrSuperString;

	//Maybe use a for search?
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		chrSubstring = ssSubstring.Substring(lngIndex, (lngIndex + 4));
		//If it finds the char, return the index right away.
		if (strcmp(chrSubstring, pstrSubStringToFind) == 0)
		{
			delete[] chrSubstring;
			chrSubstring = 0;
			return lngIndex;
		}
	}

	cout << "The substring doesn't exist." << endl;
	return 0;
}



//-----------------------------------------------------------
// Name: FindFirstIndexOf (Substring, Index)
// Abstract: Finds the first instance of the specified substring
//-----------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex)
{
	long lngIndex = 0;
	long lngLength = 0;
	long lngLength2 = 0;
	lngLength = strlen(m_pstrSuperString);
	lngLength2 = strlen(pstrSubStringToFind);
	const char* chrSubstring = new char[lngLength2];

	//Probably not a good way to do this, but lets use the substring class we've already made.
	CSuperString ssSubstring;
	ssSubstring = m_pstrSuperString;

	//Maybe use a for search?
	for (lngIndex = lngStartIndex; lngIndex < lngLength; lngIndex += 1)
	{
		chrSubstring = ssSubstring.Substring(lngIndex, (lngIndex + 4));
		//If it finds the char, return the index right away.
		if (strcmp(chrSubstring, pstrSubStringToFind) == 0)
		{
			delete[] chrSubstring;
			chrSubstring = 0;
			return lngIndex;
		}
	}

	cout << "The substring doesn't exist." << endl;
	return 0;
}



//-----------------------------------------------------------
// Name: FindLastIndexOf (Substring)
// Abstract: Finds the Last instance of the specified substring
//-----------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind)
{
	long lngIndex = 0;
	long lngLength = 0;
	long lngLength2 = 0;
	long lngFoundIndex = -1;
	lngLength = strlen(m_pstrSuperString);
	lngLength2 = strlen(pstrSubStringToFind);
	const char* chrSubstring = new char[lngLength2];

	//Probably not a good way to do this, but lets use the substring class we've already made.
	CSuperString ssSubstring;
	ssSubstring = m_pstrSuperString;

	//Maybe use a for search?
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		chrSubstring = ssSubstring.Substring(lngIndex, (lngIndex + 4));
		//If it finds the char, return the index right away.
		if (strcmp(chrSubstring, pstrSubStringToFind) == 0)
		{
			lngFoundIndex = lngIndex;
		}
	}

	if(lngFoundIndex == -1)
	{ 
		cout << "The substring doesn't exist." << endl;
		delete[] chrSubstring;
		chrSubstring = 0;
		return -1;
	}

	delete[] chrSubstring;
	chrSubstring = 0;
	return lngFoundIndex;
	
}



//-----------------------------------------------------------
// Name: ToUpperCase
// Abstract: Makes all the letters in the sentence uppercase.
//-----------------------------------------------------------
const char* CSuperString::ToUpperCase()
{
	long lngIndex = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	//New string to return + space for null terminator and other stuff.
	char* chrNewString = new char[lngLength + 3];

	//strcpy to "initialize" the new string.
	strcpy(chrNewString, m_pstrSuperString);
	
	//Chars have numeric values. If greater than (or equal to) 97, its lowercase, and we minus 32 to make it uppercase
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		if (m_pstrSuperString[lngIndex] >= 97)
		{
			chrNewString[lngIndex] = (m_pstrSuperString[lngIndex] - 32);

		}
		else
		{
			chrNewString[lngIndex] = m_pstrSuperString[lngIndex];
		}
	}
	
	return chrNewString;
}



//-----------------------------------------------------------
// Name: ToLowerCase
// Abstract: Makes all the letters in the sentence lowercase.
//-----------------------------------------------------------
const char* CSuperString::ToLowerCase()
{
	long lngIndex = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	//New string to return + space for null terminator and other stuff.
	char* chrNewString = new char[lngLength + 3];

	//strcpy to "initialize" the new string.
	strcpy(chrNewString, m_pstrSuperString);

	//Chars have numeric values. If less than 97, its uppercase, and we add 32 to make it lowercase
	//Boundary checkign for most other charcaters and space
	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		if (m_pstrSuperString[lngIndex] < 97 && m_pstrSuperString[lngIndex] > 65)
		{
			chrNewString[lngIndex] = (m_pstrSuperString[lngIndex] + 32);

		}
		else
		{
			chrNewString[lngIndex] = m_pstrSuperString[lngIndex];
		}
	}

	return chrNewString;
}



//-----------------------------------------------------------
// Name: TrimLeft
// Abstract: Trims all extra space to the left of the string (whitespace)
//-----------------------------------------------------------
const char* CSuperString::TrimLeft()
{
	long lngIndex = 0;
	long lngIndex2 = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	//New string to return + space for null terminator and other stuff.
	char* chrNewString = new char[lngLength + 3];

	//Should I recopy the entire string minus the spaces? Feels like there could be a better way...
	//(Test with While Loop later)
	for (lngIndex = 0; lngIndex <lngLength; lngIndex += 1)
	{
		//Checking for spaces at the start, once there are no more...
		if (m_pstrSuperString[lngIndex] != ' ')
		{
			//We use a for loop to copy the remaining characters back to the start.
			for (lngIndex2 = lngIndex; lngIndex2 < lngLength; lngIndex2 += 1)
			{
				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;
			}
			//Null Terminator to forcibly end string and return to break loop.
			chrNewString[lngCopiedChars] = '\0';
			return chrNewString;
		}
			
		
	}

	//Return anyway if it hits the end without triggering any conditions
	//It SHOULDNT, but just to be safe.
	return chrNewString;
}



//-----------------------------------------------------------
// Name: TrimRight
// Abstract: Trims all extra space to the Right (whitespace)
//-----------------------------------------------------------
const char* CSuperString::TrimRight()
{
	long lngMinus = 0;
	long lngIndex2 = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	char* chrNewString = new char[lngLength + 3];

	//Had to refactor the code (again) after I found it was trimming everything, not just the right.
	for (lngIndex2 = lngLength - 1; lngIndex2 >= 0; lngIndex2 -= 1)
	{
		if (m_pstrSuperString[lngIndex2] != ' ')
		{
			for (lngIndex2 = 0; lngIndex2 < (lngLength - lngMinus); lngIndex2 += 1)
			{
				
				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;
			}

			//Null Terminator to forcibly end string.
			chrNewString[lngCopiedChars] = '\0';
			return chrNewString;
		}
		lngMinus += 1;
	}
		

	

	//Return anyway if it hits the end without triggering any conditions
	//It SHOULDNT, but just to be safe.
	return chrNewString;
}



//-----------------------------------------------------------
// Name: Trim
// Abstract: Trims all extra space of the string (whitespace)
//-----------------------------------------------------------
const char* CSuperString::Trim()
{
	long lngIndex = 0;
	long lngIndex2 = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	char* chrNewString = new char[lngLength + 3];

	//Trimming left space first
	while (m_pstrSuperString[lngIndex] != '\0')
	{
		//Checking for spaces at the start, once there are no more...
		if (m_pstrSuperString[lngIndex] != ' ')
		{
			//We use a for loop to copy the remaining characters back to the start.
			for (lngIndex2 = lngIndex; lngIndex2 < lngLength; lngIndex2 += 1)
			{
				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;
			}
			//Null Terminator to forcibly end string and return to break loop.
			chrNewString[lngCopiedChars] = '\0';
			break;
		}
		lngIndex += 1;
	}

	lngIndex = 0;
	lngIndex2 = 0;
	lngCopiedChars = 0;
	lngLength = strlen(m_pstrSuperString);

	//Then trim right space
	while(m_pstrSuperString[lngIndex] != '\0')
	{
		for (lngIndex2 = lngIndex; lngIndex2 < lngLength; lngIndex2 += 1)
		{
			if (m_pstrSuperString[lngIndex2] != ' ' || m_pstrSuperString[lngIndex2 + 1] != ' ')
			{
				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;
			}
		}
		//Null Terminator to forcibly end string.
		chrNewString[lngCopiedChars - 1] = '\0';
		return chrNewString;

	}

	//Return anyway if it hits the end without triggering any conditions
	//It SHOULDNT, but just to be safe.
	return chrNewString;
}



//-----------------------------------------------------------
// Name: Reverse
// Abstract: Reverses the characters in the string.
//-----------------------------------------------------------
const char* CSuperString::Reverse()
{
	long lngIndex = 0;
	long lngIndexReverse = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);

	char* chrNewString = new char[lngLength + 1];
	//strcpy to "initialize" it
	strcpy(chrNewString, m_pstrSuperString);

	//First, set up a for loop. It will go BACKWARDS, from the right to left.
	//As it goes, it copies the characters to a new string, going from left to right.
	//Oops, gotta start one back, else it copies the null terminator and just stops.
	for (lngIndexReverse = lngLength - 1; lngIndexReverse >= 0; lngIndexReverse -= 1)
	{
		chrNewString[lngIndex] = m_pstrSuperString[lngIndexReverse];
		lngIndex += 1;
	}
	

	
	return chrNewString;
}



//-----------------------------------------------------------
// Name: Left
// Abstract: Gets the first characters in the string up to a designated amount.
//-----------------------------------------------------------
const char* CSuperString::Left(long lngCharactersToCopy)
{
	long lngIndex = 0;
	long lngIndex2 = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	//New string to return + space for null terminator and other stuff.
	char* chrNewString = new char[lngLength + 3];

	//Should I recopy the entire string minus the spaces? Feels like there could be a better way...
	//(Test with WHile Loop later)
	while (m_pstrSuperString[lngIndex] != '\0')
	{

			//Copy characters until the wanted index.
			for (lngIndex2 = 0; lngIndex2 < lngCharactersToCopy; lngIndex2 += 1)
			{
				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;
			}
			//Null Terminator to forcibly end string and return to break loop.
			chrNewString[lngCopiedChars] = '\0';
			return chrNewString;

	}

	//Return anyway if it hits the end without triggering any conditions
	//It SHOULDNT, but just to be safe.
	return chrNewString;
}



//-----------------------------------------------------------
// Name: Right
// Abstract: Gets the last characters in the string up to a designated amount.
//-----------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy)
{
	long lngIndex = 0;
	long lngIndex2 = 0;
	long lngCopiedChars = 0;
	long lngLength = 0;
	lngLength = strlen(m_pstrSuperString);
	char* chrNewString = new char[lngLength + 3];

	
	while (m_pstrSuperString[lngIndex] != '\0')
	{
		for (lngIndex2 = (lngLength - lngCharactersToCopy); lngCopiedChars <= lngCharactersToCopy; lngIndex2 += 1)
		{

				chrNewString[lngCopiedChars] = m_pstrSuperString[lngIndex2];
				lngCopiedChars += 1;

		}
		//Null Terminator to forcibly end string.
		chrNewString[lngCopiedChars - 1] = '\0';
		return chrNewString;

	}

	//Return anyway if it hits the end without triggering any conditions
	//It SHOULDNT, but just to be safe.
	return chrNewString;
}



//-----------------------------------------------------------
// Name: Substring
// Abstract: Returns a small portion of a string.
//-----------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	long lngIndex = 0;
	long lngLength = 0;
	long lngCopiedChars = 0;
	char* pstrSubstring = new char[lngSubStringLength + 3];

	
	for (lngIndex = lngStart; lngIndex < lngSubStringLength; lngIndex += 1)
	{
		pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngIndex];
		lngCopiedChars += 1;

		
	}

	//Null Terminator to forcibly end string.
	pstrSubstring[lngCopiedChars] = '\0';
	return pstrSubstring;
}



//-----------------------------------------------------------
// Name: Replace (char)
// Abstract: Replaces instance of a letter with another.
//-----------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	long lngIndex = 0;
	long lngLength = 0;
	long lngCopiedChars = 0;
	lngLength = strlen(m_pstrSuperString);

	char* pstrSubstring = new char[lngLength + 3];


	for (lngIndex = 0; lngIndex < lngLength; lngIndex += 1)
	{
		if (m_pstrSuperString[lngIndex] == chrLetterToFind)
		{
			pstrSubstring[lngCopiedChars] = chrReplace;
			lngCopiedChars += 1;
		}
		else
		{
			pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngIndex];
			lngCopiedChars += 1;
		}

	}

	//Null Terminator to forcibly end string.
	pstrSubstring[lngCopiedChars] = '\0';
	return pstrSubstring;
}



//-----------------------------------------------------------
// Name: Replace (Substring)
// Abstract: Replaces a specified substring.
//-----------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	//Wow this is all super messy... but it works, I suppose.
	//This is a lot more verbose than the others, typing out my thoughts helped to solve it.
	long lngStringIndex = 0;
	long lngSubstringIndex = 0;
	long lngLength = 0;
	long lngSubstringLengthFind = 0;
	long lngSubstringLengthReplace = 0;
	long lngCopiedChars = 0;

	lngLength = strlen(m_pstrSuperString);
	lngSubstringLengthFind = strlen(pstrFind);
	lngSubstringLengthReplace = strlen(pstrReplace);
	//In case the Replace is longer than the find, we need a number to potentially
	//Use later as a difference to shift the pointer over by.

	long lngSubstringDifference = 0;
	lngSubstringDifference = lngSubstringLengthReplace - lngSubstringLengthFind;

	//One to use as a substring identifier with a SuperString, one to use to return with.
	char* strReturnString = new char[lngLength + lngSubstringLengthReplace + 3];
	const char* pchrSubstring = new char[lngLength + lngSubstringLengthReplace + 3];


	//Lets use the substring method to compare.
	CSuperString ssSubstring;
	ssSubstring = m_pstrSuperString;

	//For search to go through the string.
	for (lngStringIndex = 0; lngStringIndex < lngLength; lngStringIndex += 1)
	{
		pchrSubstring = ssSubstring.Substring(lngStringIndex, (lngStringIndex + lngSubstringLengthFind));
		//If it finds the substring, then we start the process of replacing. First, copy the substring over.
		if (strcmp(pchrSubstring, pstrFind) == 0)
		{
			//Insert the substring with a loop
			for (lngSubstringIndex = 0; lngSubstringIndex < lngSubstringLengthReplace; lngSubstringIndex += 1)
			{
				strReturnString[lngCopiedChars] = pstrReplace[lngSubstringIndex];
				lngCopiedChars += 1;
			}

			//Now we shift that many charactes over and continue the copy.
			for (lngStringIndex = (lngStringIndex + (lngSubstringLengthReplace - lngSubstringDifference)); lngStringIndex < lngLength; lngStringIndex += 1)
			{
				strReturnString[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
				lngCopiedChars += 1;
			}

			//Then we need to break the loop and return, also clean up duties.
			delete[] pchrSubstring;
			pchrSubstring = 0;
			strReturnString[lngCopiedChars] = '\0';
			return strReturnString;

		}
		else //Else we just copy whats there.
		{
			strReturnString[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
			lngCopiedChars += 1;

		}
	}


	//In case no such replacement was found, we cleanup here too as a precaution.
	delete[] pchrSubstring;
	pchrSubstring = 0;
	strReturnString[lngCopiedChars] = '\0';
	return strReturnString;
}



//-----------------------------------------------------------
// Name: Insert (char)
// Abstract: Inserts a character at a specified index.
//-----------------------------------------------------------
const char* CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	long lngStringIndex = 0;
	long lngLength = 0;
	long lngCopiedChars = 0;
	lngLength = strlen(m_pstrSuperString);

	char* pstrSubstring = new char[lngLength + 4];

	//Loop until we get to the proper index
	for (lngStringIndex = 0; lngStringIndex < lngIndex; lngStringIndex += 1)
	{
			pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
			lngCopiedChars += 1;
	}

	//Insert the char
	pstrSubstring[lngCopiedChars] = chrLetterToInsert;
	lngCopiedChars += 1;

	//Continue copy loop after
	for (lngStringIndex = lngIndex; lngStringIndex < lngLength; lngStringIndex += 1)
	{
		pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
		lngCopiedChars += 1;
	}

	//Null Terminator to forcibly end string.
	pstrSubstring[lngCopiedChars] = '\0';
	return pstrSubstring;
}



//-----------------------------------------------------------
// Name: Insert (Substring)
// Abstract: Inserts a character at a specified index.
//-----------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex)
{
	long lngStringIndex = 0;
	long lngSubstringIndex = 0;
	long lngLength = 0;
	long lngSubstringLength = 0;
	long lngCopiedChars = 0;
	lngLength = strlen(m_pstrSuperString);
	lngSubstringLength = strlen(pstrSubString);

	char* pstrSubstring = new char[lngLength + lngSubstringLength + 3];

	//Loop until we get to the proper index
	for (lngStringIndex = 0; lngStringIndex < lngIndex; lngStringIndex += 1)
	{
		pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
		lngCopiedChars += 1;
	}

	//Insert the substring with a loop
	for (lngSubstringIndex = 0; lngSubstringIndex < lngSubstringLength; lngSubstringIndex += 1)
	{
		pstrSubstring[lngCopiedChars] = pstrSubString[lngSubstringIndex];
		lngCopiedChars += 1;
	}

	//Continue copy loop after
	for (lngStringIndex = lngIndex; lngStringIndex < lngLength; lngStringIndex += 1)
	{
		pstrSubstring[lngCopiedChars] = m_pstrSuperString[lngStringIndex];
		lngCopiedChars += 1;
	}

	//Null Terminator to forcibly end string.
	pstrSubstring[lngCopiedChars] = '\0';
	return pstrSubstring;
}



//-----------------------------------------------------------
// Name: [] operator
// Abstract: returns the char at a specified index
//-----------------------------------------------------------
char& CSuperString::operator [ ] (long lngIndex)
{
	char chrCharacter = 'a';
	int intIndex = 0;

	//Searching for the index the user is looking for.
	for (intIndex = 0; intIndex < lngIndex; intIndex += 1)
	{
		chrCharacter = m_pstrSuperString[intIndex];
	}
	return chrCharacter;
}



//-----------------------------------------------------------
// Name: [] operator
// Abstract: returns the const char* at a specified index
//-----------------------------------------------------------
const char& CSuperString::operator [ ] (long lngIndex) const
{
	//Maybe I'm wrong but this feels like it should be... functionally identical
	//To the non-const char? At least coded that way maybe.
	char chrCharacter = 'a';
	int intIndex = 0;

	//Searching for the index the user is looking for.
	for (intIndex = 0; intIndex < lngIndex; intIndex += 1)
	{
		chrCharacter = m_pstrSuperString[intIndex];
	}

	return chrCharacter;
}



//-----------------------------------------------------------
// Name: ToString
// Abstract: Returns the string.
//-----------------------------------------------------------
const char* CSuperString::ToString() const
{
	return m_pstrSuperString;
}



//-----------------------------------------------------------
// Name: ToBoolean
// Abstract: Checks the string and returns true or False.
//-----------------------------------------------------------
bool CSuperString::ToBoolean()
{
	if (strcmp(m_pstrSuperString, "true") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}



//-----------------------------------------------------------
// Name: ToShort
// Abstract: Converts the string to an long.
//-----------------------------------------------------------
short CSuperString::ToShort()
{
	//Don't need the LONG explanation code in every post, Integer has my whole thought process.
	int intReturn = 0;
	short shtReturn = 0;
	int intIndex = 0;

	for (intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex += 1)
	{
		if (m_pstrSuperString[intIndex] - '0' >= 0 && m_pstrSuperString[intIndex] - '0' <= 9)
		{

			intReturn = intReturn * 10 + m_pstrSuperString[intIndex] - '0';
		}
	}

	//Need to boundary check, since short has a pretty small limit. (-32768 - 32767)
	if (intReturn > SHRT_MAX || intReturn < SHRT_MIN)
	{
		cout << "Number exceeds short boundaries.";
		return -1;
	}
	else
	{
		shtReturn = intReturn;
	}

	

	return shtReturn;

}



//-----------------------------------------------------------
// Name: ToInteger
// Abstract: Converts the string to an int.
//-----------------------------------------------------------
int CSuperString::ToInteger()
{
	//Had to do a good bit of research on this one. Had an understanding; use the ascii values again.
	//But it wasn't quite all the way there. So here we go...
	int intReturn = 0;
	int intIndex = 0;

	//We loop through the string, checking each character
	for (intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex += 1)
	{
		//Numbers in the ascii are all between 48-57 (0-9 respectively)
		//So if subtracting 48, or '0' from it makes it go above or below that, its not a number.
		if (m_pstrSuperString[intIndex] - '0' >= 0 && m_pstrSuperString[intIndex] - '0' <= 9)
		{
			//This was the tricky part. So, if I use the string 123, and convert it as is, I'd be effectively
			//Getting 6, beacsue it would be adding 1+2+3. So I have to multiply the previous result by 10
			//To keep it proper, so its 0 + 1 = 1, 1*10 = 10,  10+2=12, 12 * 10 = 120, then 120+3=123
			intReturn = intReturn * 10 + m_pstrSuperString[intIndex] - '0';
		}
	}
	//Then we return the result as an int.
	//Probably can use this for the others, just accounting for slight changes, like decimals and 
	//Number limits.
	return intReturn;

	/*
	* Afterthought: I now realize that this whole thing was... unneccessary to say the least, but it works and 
	* I worked for a long while on it, so I'm going to let it stay here as a pillar to remind myself not to overcomplicate
	* things; work smarter, not harder. I know now that I could have used atoi to convert it easier, same with toLong below.
	*/

}



//-----------------------------------------------------------
// Name: ToLong
// Abstract: Converts the string to an long.
//-----------------------------------------------------------
long CSuperString::ToLong()
{
	//Don't need the LONg explanation code in every post, Integer has my whole thought process.
	long lngReturn = 0;
	int intIndex = 0;

	for (intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex += 1)
	{
		if (m_pstrSuperString[intIndex] - '0' >= 0 && m_pstrSuperString[intIndex] - '0' <= 9)
		{
			
			lngReturn = lngReturn * 10 + m_pstrSuperString[intIndex] - '0';
		}
	}


	return lngReturn;

}



//-----------------------------------------------------------
// Name: ToFloat
// Abstract: Converts the string to a float.
//-----------------------------------------------------------
float CSuperString::ToFloat()
{
	//I might have been overcomplicating everything... I forgot we are allowed to use string functions, just not string library.
	long lngReturn = 0;
	int intIndex = 0;
	float fltReturn = 0;
	//atof = convert a string to a float(technically a double)
	fltReturn = atof(m_pstrSuperString);


	return fltReturn;

}



//-----------------------------------------------------------
// Name: ToDouble
// Abstract: Converts the string to a double.
//-----------------------------------------------------------
double CSuperString::ToDouble()
{
	//I might have been overcomplicating everything... I forgot we are allowed to use string functions, just not string library.
	long lngReturn = 0;
	int intIndex = 0;
	double dblReturn = 0;
	//atof = convert a string to a float(technically a double)
	dblReturn = atof(m_pstrSuperString);


	return dblReturn;

}



//-----------------------------------------------------------
// Name: operator <<
// Abstract: << overload, lets the << operator directly output the SuperString
//-----------------------------------------------------------
ostream& operator << (ostream& osOut, const CSuperString& ssOutput)
{
	//We have a to string, should just be able to use that.
	osOut << ssOutput.ToString();

	//return the stream.
	return osOut;

}



//-----------------------------------------------------------
// Name: operator >>
// Abstract: >> overload, lets the >> operator directly input to the SuperString
//-----------------------------------------------------------
istream& operator >> (istream& isIn, CSuperString& ssInput)
{
	//Little more tricky...Once again, may be over complicating this. I seem to be good at that.
	//Can't just Directly take in info (isIn >> ssInput.m_pstrSuperString();), 
	//cause the memory wasn't initialised, so lets hold it temporarily.

	char chrString[100]; //Temp storage of the in istream

	//Just reading input as >> wasn't working, it only read the first char,
	//but I learned of the std function getline, lets try that.

	isIn.getline(chrString, 100);


	//Take out whatever was there before
	delete ssInput.m_pstrSuperString;

	//Assign it new memory equal to whats in the temp storage + room for null terminator and other stuff
	int intLength = strlen(chrString);
	ssInput.m_pstrSuperString = new char[intLength + 3];

	//Copy data over
	strcpy(ssInput.m_pstrSuperString, chrString);


	//Return the stream.
	return isIn;

}



//-----------------------------------------------------------
// Name: Print
// Abstract: Prints string with caption.
//-----------------------------------------------------------
void CSuperString::Print(const char* pstrSource) const
{
	//Caption
	cout << endl;
	cout << "------------------------------" << endl;
	cout << pstrSource << endl;
	cout << "------------------------------" << endl;

	//Is there anything to print?
	if (Length() > 0)
	{
		//Yup
		cout << m_pstrSuperString << endl;
	}
	else
	{
		//Nope :(
		cout << "Empty String" << endl;
	}
}