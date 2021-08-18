//-----------------------------------------------------------------
// LIBARIES & HEADERS
//-----------------------------------------------------------------
#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

#include "Letter.h"

//-----------------------------------------------------------------
// LCD DISPLAY
//-----------------------------------------------------------------

// Definition of the pins for the LCD
const int rs = 12;
const int e = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// Custom character for the position indicator
byte scrollBar[8] =
    {
        0b11111,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000};

// Array that holds the 16 characters displayed (stored in Letter Objects)
Letter text[16];

// Stores an integer representing where the cursor is
int underscore = 0;
// The delay for the arrow buttons
int btnDelay = 400;
// Represents the character of the last button pressed
char lastBtnPress;
//Tracks if this is the first time a letter was pressed or if the text was cleared
bool firstIteration = true;
// Tracks the number of characters that have been typed
int textSize = 0;

// Initializes the LiquidCrystal library with the interface pins
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//-----------------------------------------------------------------
// MEMBRANE NUMBER PAD
//-----------------------------------------------------------------

// Constants that define the rows and columns in the keypad
const byte ROWS = 4;
const byte COLUMNS = 4;

// An array to represent every button on the keypad
char hexKeys[ROWS][COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Defines the connections to the Arduino pins
byte rowPins[ROWS] = {22, 26, 30, 34};
byte colPins[COLUMNS] = {38, 42, 46, 50};

// Creates a Keypad object (map of keys, pins for rows, pins for columns, #rows, #columns)
Keypad cellpad = Keypad(makeKeymap(hexKeys), rowPins, colPins, ROWS, COLUMNS);

//-----------------------------------------------------------------
// BUTTONS
//-----------------------------------------------------------------

// Definition of the pins for the joystick
const int right = 29;
const int down = 33;
const int up = 37;
const int left = 45;

//Defines the variable that holds the button value
int rightBtnRead;
int leftBtnRead;
int upBtnRead;
int downBtnRead;

//-----------------------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------------------

/*
  Function that deletes a character when the D button is clicked.
*/
void removeElement()
{
  // Makes a copy of the text array of letters
  Letter tempArray2[16];
  memcpy(tempArray2, text, sizeof(text));

  // Loops through the copy and shifts the letters to the left that weren't deleted.
  for (int i = 0; i < 16; i++)
  {
    if (i >= textSize)
    {
      text[i].resetLetter();
    }
    else if (i >= underscore && (i < textSize))
    {
      text[i].setCapitalization(tempArray2[i + 1].getCapitalization());
      text[i].setDisplay(tempArray2[i + 1].getDisplay());
      text[i].setPressCount(tempArray2[i + 1].getPressCount());
      text[i].setType(tempArray2[i + 1].getType());
    }
  }
}

/*
  Prints the second line on the LCD display which shows the cursor.
*/
void printCursor(LiquidCrystal lcd)
{
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i, 1);

    if (i == underscore)
    {
      lcd.write(byte(0));
    }
    else if (i == 0 && (underscore == 0))
    {
      lcd.write(byte(0));
    }
    else
    {
      lcd.write(' ');
    }
  }
}

/*
  Prints the line of the LCD with the text typed.
*/
void printText(LiquidCrystal lcd)
{
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i, 0);
    lcd.write(text[i].getDisplay());
  }
}

//-----------------------------------------------------------------
// MAIN PROGRAM
//-----------------------------------------------------------------
void setup()
{
  // Starts the serial monitor
  Serial.begin(9600);
  // Sets the number of columns and rows for the LCD (16 columns by 2 rows)
  lcd.begin(16, 2);
  //Creates a custom character
  lcd.createChar(0, scrollBar);

  // Setup for the scroll buttons
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
}

void loop()
{
  // Gets the key value if pressed
  char key = cellpad.getKey();

  // Gets the value of the arrow buttons if pressed
  rightBtnRead = digitalRead(right);
  leftBtnRead = digitalRead(left);
  upBtnRead = digitalRead(up);
  downBtnRead = digitalRead(down);

  // Checks if the key exists
  if (key)
  {
    //Enter button
    if (key == 'A')
    {
      underscore++;
      textSize++;
    }
    // Moves cursor to the left
    else if (key == 'B')
    {
      underscore--;
    }
    // Clears the entire LCD Display
    else if (key == 'C')
    {
      for (int i = 0; i < 16; i++)
      {
        text[i].resetLetter();
      }

      // Resets all the counters
      underscore = 0;
      firstIteration = true;
      textSize = 0;
    }
    // Deletes a letter
    else if (key == 'D')
    {
      //Deletes the last letter
      if (underscore == textSize)
      {
        text[underscore].resetLetter();
        underscore--;
        textSize--;
      }
      // Logic if a letter inside the text is deleted
      else
      {
        removeElement();
        textSize--;
      }
    }
    // Makes sure the cursor updates properly when the first letter of the text is entered
    else if (firstIteration == true)
    {
      firstIteration = false;
      text[underscore].setType(key);
      text[underscore].chooseLetter();
    }
    // Updates the letter if the same button is pressed multiple times
    else if (key == lastBtnPress)
    {
      text[underscore].incrementPressCount();
      text[underscore].chooseLetter();
    }
    else if (underscore < textSize)
    {
      text[underscore].resetLetter();
      text[underscore].setType(key);
      text[underscore].chooseLetter();
    }
    else if (underscore < 16)
    {
      if(lastBtnPress != 'A'){
        underscore++;
        textSize++;
      }
      text[underscore].setType(key);
      text[underscore].chooseLetter();
    }
    lastBtnPress = key;
  }

  // Logic for the arrow buttons
  if (rightBtnRead == 0 && underscore < 16)
  {
    underscore++;
    printCursor(lcd);
    delay(btnDelay);
  }

  if (downBtnRead == 0)
  {
    text[underscore].setCapitalization(false);
    text[underscore].capitalize();
    delay(btnDelay);
  }

  if (upBtnRead == 0)
  {
    text[underscore].setCapitalization(true);
    text[underscore].capitalize();
    delay(btnDelay);
  }

  if (leftBtnRead == 0 && underscore > 1)
  {
    underscore--;
    printCursor(lcd);
    delay(btnDelay);
  }

  //Updates the text on the LCD display
  printText(lcd);
  printCursor(lcd);
}