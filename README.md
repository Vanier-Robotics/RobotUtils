# ArduinoExtra

## Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software). Use the new 2.0.0 version if possible as it is easier to work with.
2. Install CrcLib, ArduinoExtra, and [Paul Stoffergen's Encoder library](https://www.arduino.cc/reference/en/libraries/encoder/)
3. Clone this repository in the User/Documents/Arduino/libraries/ folder (or equivalent on Mac).
4. Open the Arduino IDE and create a new project. Select the `Arduino Mega or Mega 2560` board. Write `#include <RobotUtils.h>` at the top of the file and press verify to make sure everything is installed properly.
5. Open the cloned repository in VSCode or another text editor/IDE (make sure you don't commit your project files on accident). You can install an editorconfig extension for automatic file formatting ([VSCode Example](https://marketplace.visualstudio.com/items?itemName=EditorConfig.EditorConfig)).

**NOTE**: Write all the library code in this folder, but any tests should be done within the Arduino IDE.

## Technical info

**Project Code**: ROU
