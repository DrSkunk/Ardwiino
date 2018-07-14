/*
 *  Project     Ardwiino
 *  @author     Sebastiaan
 *  @link       /github.com/whitebird/ardwiino
 *  @license    LGPLv3 - Copyright (c) 2018 Sebastiaan Jansen
 *
 *  This file is part of the Ardwiino software.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Description:  Wii accessories as native game controller
 *                Based on the Nintendo Extension Controller Library by David Madison
 *                and ased on the ArduinoJoystickLibrary by Matthew Heironimus
 */
#include <Joystick.h>
#include <NintendoExtensionCtrl.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   7, 1,                 // Button Count, Hat Switch Count
                   true, false, false,   // X and Y, but no Z Axis
                   false, false, false,  // No Rx, Ry, or Rz
                   false, false,         // No rudder or throttle
                   false, false, false); // No accelerator, brake, or steering


GuitarController guitar;

const int joyMin = 0;
const int joyMax = 63;
const int deadzone = 15;

const int joyLow = joyMin + deadzone;
const int joyHigh = joyMax - deadzone;

void setup()
{
  Serial.begin(115200);
  guitar.begin();
  Joystick.begin();
  // Whammy range, about 15 - 27
  Joystick.setXAxisRange(15, 27);

  while (!guitar.connect())
  {
    Serial.println("Guitar controller not detected!");
    delay(1000);
  }
}

void loop()
{
  boolean success = guitar.update(); // Get new data from the controller
  Serial.println(success);
  if (!success)
  { // Ruh roh
    Serial.println("Controller disconnected!");
    delay(1000);
  }
  else
  {
    Joystick.setButton(0, guitar.fretGreen());
    Joystick.setButton(1, guitar.fretRed());
    Joystick.setButton(2, guitar.fretYellow());
    Joystick.setButton(3, guitar.fretBlue());
    Joystick.setButton(4, guitar.fretOrange());
    Joystick.setButton(5, guitar.buttonPlus());
    Joystick.setButton(6, guitar.buttonMinus());

    // Read the whammy bar (0-31, starting around 15-16)
    uint8_t whammy = guitar.whammyBar();
    Joystick.setXAxis(whammy);

    // Read the joystick axis (0-63 XY)
    int joyX = guitar.joyX();
    int joyY = guitar.joyY();

    bool joystickUsed = true;
    if (joyX < joyLow)
    { // down
      Joystick.setHatSwitch(0, 90);
    }
    else if (joyY < joyLow)
    { // right
      Joystick.setHatSwitch(0, 0);
    }
    else if (joyX > joyHigh)
    { // up
      Joystick.setHatSwitch(0, 270);
    }
    else if (joyY > joyHigh)
    { // left
      Joystick.setHatSwitch(0, 180);
    }
    else
    { // none
      joystickUsed = false;
    }

    if (guitar.strumUp())
    {
      Joystick.setHatSwitch(0, 0);
    }
    else if (guitar.strumDown())
    {
      Joystick.setHatSwitch(0, 180);
    }
    else if (!joystickUsed)
    {
      Joystick.setHatSwitch(0, -1);
    }

    // Print all the values!
    // guitar.printDebug();
  }
}
