#ifndef TTP229_MINIMAL_H_INCLUDED
#define TTP229_MINIMAL_H_INCLUDED


/* based on
   http://itimewaste.blogspot.com/2014/12/arduino-code-for-ttp229-touch-16-button.html
*/


#include <stdint.h>


class TTP229
{
    int sddPin;
    int sclPin;
    bool is16Buttons;

    static const int MAX_NUMBER_BUTTONS = 16;

    bool isPressed[MAX_NUMBER_BUTTONS];

  public:

    static const int NO_BUTTON_PRESSED = -1;

    TTP229(int theSddPin, int theSclPin, bool boardIs16Buttons = false)
    {
      sddPin = theSddPin;
      sclPin = theSclPin;
      is16Buttons = boardIs16Buttons;

      setupPins();
    }

    void setupPins()
    {
      pinMode(sclPin, OUTPUT);
      digitalWrite(sclPin, HIGH);  // by default HIGH, clock pulls low
      pinMode(sddPin, INPUT);
    }

    //! Return the one and only button that is pressed
    //! Return -1 if no button is pressed, value of the button otherwise
    int getPressedButton()
    {
      updateButtonStates();

      for (int i = 0; i < maxIndex(); ++i) {
        if (isPressed[i]) {
          return i + 1;  // index is 0-based, button number is 1-based
        }
      }
      return NO_BUTTON_PRESSED;
    }

    bool isButtonPressed(int buttonNumber)
    {
      updateButtonStates();
      int buttonIndex = buttonNumber - 1;  // index is 0-based, button number is 1-based
      return isPressed[buttonIndex];
    }

  private:

    int maxIndex()
    {
      int maxIndex = MAX_NUMBER_BUTTONS;
      if (not is16Buttons) {
        maxIndex = MAX_NUMBER_BUTTONS / 2;
      }
      return maxIndex;
    }

    void updateButtonStates()
    {
      for (int buttonIndex = 0; buttonIndex < maxIndex(); ++buttonIndex) {
        digitalWrite(sclPin, LOW);  // clock low
        delayMicroseconds(1);
        digitalWrite(sclPin, HIGH);  // clock high
        int val = digitalRead(sddPin);  // expect signal
        delayMicroseconds(1);
        isPressed[buttonIndex] = (val == LOW);
      }
    }
};

#endif  // TTP229_MINIMAL_H_INCLUDED
