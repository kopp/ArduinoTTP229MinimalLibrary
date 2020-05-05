# Minimal Library to read button presses from a TTP229 module


# When (not) to use

[It seems like](http://itimewaste.blogspot.com/2014/12/arduino-code-for-ttp229-touch-16-button.html)
there are different variants of the TTP229 chip out there.
One that supports i2c communication and the other that does not.

To check, what kind you have, use
[the i2c scanner](https://playground.arduino.cc/Main/I2cScanner/)
to check the i2c address of the TTP229-board that you use.
In case that you don't find any i2c address, you can try to use this library.


An alternative is to use the Pins `OUT1`, `OUT2`, ..., `OUT8`.
If you don't use more than 8 buttons, you can use the output of `OUT`_i_ to
detect, whether button _i_ is pressed.

An example can be found in file [`ttp229_analog_pins.ino`](ttp229_analog_pins.ino).



# How to use

Copy the file
`ttp229_minimal.h`
into your arduino project (i.e. next to the `.ino`) file and in there use 

    #include "ttp229_minimal.h"

Then create an object of the `TTP229` class that contains the wiring information:

- First parameter is the pin number that is connected to the SDD pin
- First parameter is the pin number that is connected to the SCL pin
- Third parameter (optional) is `true` if you want to use all 16 buttons of the board.
  For this to work, you need to connect the pins highlighted in _yellow_
  [in this blogpost](http://itimewaste.blogspot.com/2014/12/arduino-code-for-ttp229-touch-16-button.html).

This can look like

    TTP229 ttp229(5, 4, false);

if you wired SCL--4, SDD--5.

Now you can use the method

    ttp229.getPressedButton();

which will either return `TTP229::NO_BUTTON_PRESSED` if no button is pressed or
the number of the pressed button (starting at 1, so if button 1 is pressed,
`getPressedButton()` returns `1`).

You can find an example in file [`ttp229_minimal.ino`](ttp229_minimal.ino).



# Acknowledgements

The code is based on
[this blogpost](http://itimewaste.blogspot.com/2014/12/arduino-code-for-ttp229-touch-16-button.html).

This also contains code to hook up the touchpad to an Arduino interrupt.
