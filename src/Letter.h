#pragma once

class Letter
{
//Variables
private:
  // Object Variables
  bool m_capitalized;
  char m_display;
  int m_pressCount;
  char m_type;

  // Arrays to represent the different button options
  const char num1[1] = {'1'};
  const char num2[4] = {'a', 'b', 'c', '2'};
  const char num3[4] = {'d', 'e', 'f', '3'};
  const char num4[4] = {'g', 'h', 'i', '4'};
  const char num5[4] = {'j', 'k', 'l', '5'};
  const char num6[4] = {'m', 'n', 'o', '6'};
  const char num7[5] = {'p', 'q', 'r', 's', '7'};
  const char num8[4] = {'t', 'u', 'v', '8'};
  const char num9[5] = {'w', 'x', 'y', 'z', '9'};
  const char num0[2] = {' ', '0'};

// Methods
public:
  Letter();

  void setCapitalization(bool capitalization);
  bool getCapitalization();
  char getDisplay();
  void setDisplay(char displayCharacter);
  int getPressCount();
  void setPressCount(int pressCount);
  void setType(char btnPressed);
  char getType();

  void capitalize();
  void chooseLetter();
  void incrementPressCount();
  void resetLetter();
};