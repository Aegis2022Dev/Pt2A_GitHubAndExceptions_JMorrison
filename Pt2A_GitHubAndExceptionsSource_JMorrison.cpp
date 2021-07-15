/*
* Joy Morrison
* CIS 1202
* 07/15/2021
*
* Week 11 – Exception Classes Part 2A: Build User Defined Classes & Source Code To Handle & Validate Data Input
*
* Program develops custom exception classes to validate user input using the ASCII Table & Codes from here:
* Source: http://theasciicode.com.ar/
* Program will use custom exception classes to filter and validate alphanumeric user input for alphabetic
* characters only i.e. keyboard character input in range a - z or A to Z inclusive
* Program disallows case transitions by user in the input process ie. user trying to use CAPS LOCK to enter a character
* Program will frquently utilize GitHub.com source management tool to push and commit changes to source code
* Program will use catch/try blocks in main() to test source code
* Program driver will test source code in main() displaying the appropriate error message to user
* Final program push will be submitted to GitHub for Instructor to clone
*
Methods:
*
* character(char start, int offset)
*
*/

#include <iostream> // allow use of cout/cin data stream objects
#include <algorithm> //allow copying of arrays
#include <fstream> // to enable input/output field handlers
#include <iomanip> // to allow field formatting using setprecision, setw etc.
#include <cstring>  // allow use of cstring library 
#include <cctype> // allow use of isalpha, isdigit and other native boolean char/integer methods
#include <ctime> // to make rand() generator dynamic
#include <string>  // allow use of STRING library to use methods like getline()
#include <cstdlib> //permit use of basic utility and math fx like transform()
#include <cmath> // allow use of math library where necessary
#include <cstdbool> // allow use of boolean data structures where necessary
#include <cctype> //allow use of isdigit(arg) and other native boolean alphanumeric/char methods

using namespace std;

/****DEFINE EXCEPTION CLASSES****/

// invalidCharacterExcpeption class handles exceptions
class invalidCharacterExcpeption
{

};

// invalidRangeException class handles range exceptions
class invalidRangeException
{

};

//class to handle caseConversionException
class caseConversionException
{

};

//DECLARE FORWARD DECLARATIONS, METHOD & STRUCTURES DEFINITIONS FOR FUNCTION PROTOTYPES

char character(char start, int offset);

/****BEGIN main() METHOD****/

int main()
{
    char target = NULL;
    char start = '0';

    cout << "\nBegin Exception module class testing...." << endl;
    cout << "\nThe source reference url ASCII to keyboard character table conversions used in this test program is" << endl;
    cout << "Source: http://theasciicode.com.ar/ \n" << endl;

    //call character() test exception cases to test exceptions module and validate several alpha numerical user input data
    character('a', 1);
    character('a', -1);
    character('Z', -1);
    character('?', 5);
    character('A', 32);

	system("pause");
	return 0;

}// End main()

/****METHOD DEFINITIONS****/

char character(char start, int offset)
{ 
    cout << "\nThe begining value for start is: " << start << endl;
    cout << "The begining value for offset is: " << offset << endl;

    //Find ASCII value for start variable    
   
    int startAsciiValue = int(start);

    //add the offset to start's ASCII value to determine value for target
    int target = startAsciiValue + offset;

    try 
    {
        // if start not upper (i.e  <65 & > 90) or lower (i.e. < 97 && > 122) case alphabet
        // then throw invalidCharacterExcpeption method
        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
        {
            throw invalidCharacterExcpeption();
        }
        //else if target is not lower or upper case alphabet throw invalidRangeException
        else if (target < 65 || (target > 90 && target < 97) || target > 122)
        {
            throw invalidRangeException();
        }
        //else if target is lower case and start is upper case, or vice versa, then throw caseConversionException
        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
        {
            throw caseConversionException();
        }//End if-else
    }//End try proceedure

    //catch all respective expressions and print appropriate message
    catch (invalidCharacterExcpeption exception1)
    {
        cout << " Invalid Character Exception!" << endl;
        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " Invalid Range Exception!" << endl;
        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Cannot make case changes from upper to lower or otherwise." << endl;
        return ' ';
    }//End catch prodceedure

    //if no exception caught then return the character value of the target
    cout << "The validated numeric value for the target character is: " << target << endl;
    cout << "The validated alphabetic value for the target character is: " << char(target) << endl;
    return char(target);
   
}//End character() method