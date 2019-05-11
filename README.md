# Ardwiino - Wii accessories as native game controller

This sketch allow you to use any Wii accessory, such as the Nunchuck, Classic controller or Guitar Hero guitar. It was initally made to play [Clone Hero](https://www.reddit.com/r/CloneHero/).

Currently the sketch defaults to the Guitar Hero, but other controllers are being implemented.

For the Guitar hero guitar the input is as follows:

- 5 fret buttons
- strum up/down: POV hat up/down
- starpower button
- start button
- joystick: POV hat
- Whammy: joystick axis

Joystick mapping:

![Joystick mapping](https://raw.githubusercontent.com/whitebird/Ardwiino/master/images/joystick_mapping.png)

Screenshot in Windows:

![Screenshot in Windows](https://raw.githubusercontent.com/whitebird/Ardwiino/master/images/window.png)

## Needed hardware

This project can be built with a Arduino Leonardo and a Nunchuck breakout board. My personal version was built with the 5V version of the Arduino Leonardo Micro, but the Wii nunchuck accessories are 3.3V, so I added a logic level converter and a LM1117 Low-Dropout Linear Regulator. Normally if you buy the 3.3V version of the Leonardo, you would only need the breakout board as well.

I bought mine on Aliexpress

5V Parts list:

- [Arduino Leonardo Micro 5V](https://www.aliexpress.com/w/wholesale-leonardo-5V.html?spm=2114.search0104.0.0.50ce517fCP5UiI&initiative_id=SB_20180714112849&site=glo&groupsort=1&SortType=total_tranpro_desc&g=y&SearchText=leonardo+5V)
- [Logic Level Converter](https://www.aliexpress.com/w/wholesale-logic-level-converter.html?spm=2114.search0104.0.0.4b4e10a8RYASV9&initiative_id=AS_20180714112900&site=glo&SortType=total_tranpro_desc&g=y&SearchText=logic+level+converter&CatId=400103)
- [LM1117](https://www.aliexpress.com/w/wholesale-LM1117-DIP.html?spm=2114.search0104.0.0.3d276b19y5GckD&initiative_id=SB_20180714113013&site=glo&groupsort=1&SortType=total_tranpro_desc&g=y&SearchText=LM1117+DIP)
- [WiiChuck - Wii nunchuck breakout board](https://www.aliexpress.com/w/wholesale-wiichuck.html?spm=2114.search0104.0.0.1c681659ojTNn4&initiative_id=AS_20180714113201&site=glo&SortType=total_tranpro_desc&g=y&SearchText=wiichuck&CatId=400103)


  3.3V Parts list:

- [Arduino Leonardo Micro 3.3V](https://www.aliexpress.com/w/wholesale-leonardo-3.3v.html?spm=2114.search0104.0.0.6d557b37GoixQ1&initiative_id=AS_20180714113208&site=glo&groupsort=1&SortType=total_tranpro_desc&g=y&SearchText=leonardo+3.3v)
- [WiiChuck - Wii nunchuck breakout board](https://www.aliexpress.com/w/wholesale-wiichuck.html?spm=2114.search0104.0.0.1c681659ojTNn4&initiative_id=AS_20180714113201&site=glo&SortType=total_tranpro_desc&g=y&SearchText=wiichuck&CatId=400103)

Soldering schematics are coming soon™, but it's not too hard. You connect 3.3V to the + and the groun to - of the breakout board, then the clock to D3 and data to D2.


This is my version that I soldered on a protoboard:

![Protoboard](https://raw.githubusercontent.com/whitebird/Ardwiino/master/images/prototype.jpg)

## Uploading the code

First install the Arduino IDE, you can download it [here](https://www.arduino.cc/en/Main/Software).

Then download and install the following libraries:

- [ArduinoJoystickLibrary
  ](https://github.com/MHeironimus/ArduinoJoystickLibrary)
- [NintendoExtensionCtrl
  ](https://github.com/dmadison/NintendoExtensionCtrl)

[This guide](https://www.arduino.cc/en/guide/libraries) can help you to install the libraries.

If all that is done (you go man!), then you can start the Arduino IDE and load the `Ardwiino.ino` sketch, select `Tools -> board -> Arduino Leonardo`. Then select the COM port in `Tools -> port`. It should look something like `COM19 (Arduino Leonardo)`, but the number will be different.

Now you just click the upload button and presto, your software is loaded!

## Change controller name

The default name is "Arduino Leonardo", but you can change that to something _cooler_ like, I don't know _**Ardwiino**_.

In order to do that, you have to follow instructions [here](https://github.com/MHeironimus/ArduinoJoystickLibrary/issues/14#issuecomment-263529830), but I copied them for ease of use.

## Special thanks

Special thanks go out to the members of the [Clone Hero discord](https://discordapp.com/invite/zd6JEn2), especially KubaF2K, dizzy, jaysonTM, Yuri™ shall conquer the earth!, Extended sustain tap Open notes, Josh and probably others I haven't mentioned. They helped a lot with debugging and information about all the other guitars. Thanks guys!
