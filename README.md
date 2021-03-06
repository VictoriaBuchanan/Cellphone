# Arduino Cell Phone Project

The goal of this project is to create a mini cellphone display using Arduino components. Once completed, the user will be able to type text using a number pad (the way the old cell phones used to do) and see the text on the LCD.

## 1.0 THE CIRCUIT
### 1.1 LCD Display
The LCD displays the text input by the membrane switch module. In this project, the first line of the LCD displays up to 16 characters of text, and the second line displays the cursor, which shows where the user is in the typing process.
#### 1.1.1 Components
- 10k Potentiometer (1)
- Breadboard (1)
- [LCD1602](https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/) module (1)
- Male to male wires (16)

#### 1.1.2 Connections
|LCD Pin|Arduino Pin|Potentiometer|
|:-------------:|:-------------:|:-------------:|
|1-VSS|GND|N/A|
|2-VDD|5V|N/A|
|3-V0|N/A|Vcc|
|4-RS|pin 12|N/A|
|5-RW|GND|N/A|
|6-EN|pin 11|N/A|
|11-D4|pin 5|N/A|
|12-D5|pin 4|N/A|
|13-D6|pin 3|N/A|
|14-D7|pin 2|N/A|
|15-A|5V|Output|
|16-K|GND|GND|

#### 1.1.3 Circuit Diagram
![LCD Circuit](photos/LCDCircuit.jpg?raw=true "LCD Circuit")

### 1.2 Number Pad
Text for this cellphone is inputted using a 4x4 Membrane Keypad. This keypad has the following buttons:
- Numbers 0-9
- \* and # buttons
- Letters A-D where A moves the cursor to the right, B moves the cursor to the left, C clears the entire screen and D deletes a letter.

#### 1.2.1 Components
- Male to male wires (8)
- [Membrane Switch Module with number](https://lastminuteengineers.com/arduino-keypad-tutorial/) (1)

#### 1.2.2 Connections
|Numberpad|Arduino Pin|
|:-----------:|:-----------:|
|row 1|pin 22|
|row 2|pin 26|
|row 3|pin 30|
|row 4|pin 34|
|col 1|pin 38|
|col 2|pin 42|
|col 3|pin 46|
|col 4|pin 50|

#### 1.2.3 Circuit Diagram
![Membrane Numberpad Circuit](photos/NumberpadCircuit.jpg?raw=true "Membrane Numberpad Circuit")

### 1.3 Buttons
Four pull buttons are used to mimic four arrow keys (left, up, down, and right).

#### 1.3.1 Components
- 4 pin buttons (4)
- 10k resistor (4)
- breadboard
- male to male wires (17)

#### 1.3.2 Connections
|Buttons|Arduino Pin|
|:------------------:|:------------------:|
|Button 1 (Left)|pin 45|
|Button 2 (Up)|pin 37|
|Button 3 (Down)|pin 33|
|Button 4 (Right)|pin 29|

#### 1.3.3 Circuit Diagram
![Buttons Circuit](/photos/ButtonCircuit.jpg?raw=true "Buttons Circuit")

## 2.0 BUILD INSTRUCTIONS
All the files in this project are in C++. The uploaded build works in VSCode with the [PlatformIO IDE](https://platformio.org/) add in.  To install PlatformIO you will need to install the Arduino IDE and the Visual Studio Code plugin for PlatformIO. Instructions on how to install these programs can be found [here](https://www.youtube.com/watch?v=dany7ae_0ks).

## 3.0 FURTHER READING
For more information on how to wire the circuits to the Arduino, DroneBot Workshop has several YouTube tutorials on the [Matrix Keypad](https://www.youtube.com/watch?v=vl1-R6NsejM&t=1343s) and the [LCD1602](https://www.youtube.com/watch?v=wEbGhYjn4QI&t=568s). Paul McWhorter also has a useful YouTube video on how the [pull buttons](https://www.youtube.com/watch?v=AgQW81zzR18) work.
