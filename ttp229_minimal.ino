/*
   Wiring:
     VCC - 5V
     GND - GND
     See in the line `TTP229 ttp229(...)` for how to connect SDD, SCL
*/

#include "ttp229_minimal.h"


TTP229 ttp229(5, 4, false);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int buttonPressed = ttp229.getPressedButton();
  if (buttonPressed == TTP229::NO_BUTTON_PRESSED) {
    Serial.println("No button pressed");
  } else {
    Serial.print("Button ");
    Serial.print(buttonPressed);
    Serial.println(" pressed");
  }
  delay(200);
}
