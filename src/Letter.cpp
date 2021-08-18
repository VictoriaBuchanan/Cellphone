//-----------------------------------------------------------------
// LIBARIES & HEADERS
//-----------------------------------------------------------------
#include "Letter.h"

/*
    Constructor for the Letter class.
*/
Letter::Letter()
{
    m_type = ' ';
    m_pressCount = 0;
    m_capitalized = false;
    m_display = ' ';
}

//-----------------------------------------------------------------
// GETTER AND SETTERS
//-----------------------------------------------------------------

/*
    Sets the capitalization status of a letter.
    @param capitazation is a boolean = true if the character should be capitalized and false otherwise
*/
void Letter::setCapitalization(bool capitalization)
{
    m_capitalized = capitalization;
}

/*
    Gets the capitalization status of a letter.
    @return a boolean = true of the charater should be capitalized and false otherwise
*/
bool Letter::getCapitalization()
{
    return m_capitalized;
}

/*
    Sets the character that displays on the LCD for a Letter object.
    @param displayCharacter is a character that indicates what character will display on the LCD.
*/
void Letter::setDisplay(char displayCharacter)
{
    m_display = displayCharacter;
}

/*
    Gets the character of a Letter object to display on the LCD.
    @return a character indicating the character to be displayed on the LCD.
*/
char Letter::getDisplay()
{
    return m_display;
}

/*
    Sets the press count of a Letter object. This number tracks which character option in the array of characters the Letter object is at.
    @param pressCount is an integer that counts the number of times a button is pressed.
*/
void Letter::setPressCount(int pressCount)
{
    m_pressCount = pressCount;
}

/*
    Gets the press count of a Letter object.
    @return a integer indicating the number of times a character was pressed
*/
int Letter::getPressCount()
{
    return m_pressCount;
}

/*
    Sets the letter type for a Letter object.
    @param btnPressed character representing the number pressed (will be a number from 0 to 9, * or #).
*/
void Letter::setType(char btnPressed)
{
    m_type = btnPressed;
}
/*
    Gets the type of the Letter object.
    @return character representing the number pressed (will be a number from 0 to 9)
*/
char Letter::getType()
{
    return m_type;
}

//-----------------------------------------------------------------
// OTHER METHODS
//-----------------------------------------------------------------

/*
    Method that determines whether to capitalize a letter or not.
*/
void Letter::capitalize()
{
    int tempChar = (int)m_display;

    // If the character is a lower case ASCII number (97-122) and the capitalization flag is set (TRUE=1)
    if (m_capitalized == true && tempChar > 96 && tempChar < 123)
    {
        //Decrements the ASCII number to capitalize it
        tempChar = tempChar - 32;
        m_display = (char)tempChar;
    }

    // If the character is upper case ASCII number (65-90) and the lower case capitalization flag is set (FALSE=0)
    if (m_capitalized == false && m_display < 91 && m_display > 64)
    {
        //Increments the ASCII number to make it lower case
        tempChar = tempChar + 32;
        m_display = (char)tempChar;
    }
}

/*
    Method that maps the character to display based on the button clicked and number of times the button was clicked.
*/
void Letter::chooseLetter()
{
    switch (m_type)
    {
    case '1':
        m_display = m_type;
        break;
    case '2':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num2[m_pressCount];
        break;
    case '3':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num3[m_pressCount];
        break;
    case '4':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num4[m_pressCount];
        break;
    case '5':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num5[m_pressCount];
        break;
    case '6':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num6[m_pressCount];
        break;
    case '7':
        if (m_pressCount > 5)
        {
            m_pressCount = 0;
        }
        m_display = num7[m_pressCount];
        break;
    case '8':
        if (m_pressCount > 4)
        {
            m_pressCount = 0;
        }
        m_display = num8[m_pressCount];
        break;
    case '9':
        if (m_pressCount > 5)
        {
            m_pressCount = 0;
        }
        m_display = num9[m_pressCount];
        break;
    case '0':
        if (m_pressCount > 2)
        {
            m_pressCount = 0;
        }
        m_display = num0[m_pressCount];
        break;
    case '*':
        m_display = m_type;
        break;
    case '#':
        m_display = m_type;
        break;
    default:
        break;
    }
}

/*
    Tracks how many times in a row the same button was clicked to scroll through the letters.
*/
void Letter::incrementPressCount()
{
    m_pressCount++;
}

/*
    Resets the characteristics of a Letter object back to the values when it is constructed.
*/
void Letter::resetLetter()
{
    m_type = ' ';
    m_pressCount = 0;
    m_capitalized = false;
    m_display = ' ';
}
