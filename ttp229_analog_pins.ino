/* Wiring:
 *  VCC to Arduino 5V
 *  GND to Arduino GND
 *  Board Outputs Pin{6,7,8} wired to Arduino PIN_BUTTON_{6,7,8}.
 *  
 */

const int PIN_BUTTON_6 = 10;
const int PIN_BUTTON_7 = 8;
const int PIN_BUTTON_8 = 9;


bool is_key_pressed(int button_pin)
{
  int value = digitalRead(button_pin);
  return value == HIGH;
}


void setup() {
  Serial.begin(9600);
}


void loop() {
  
  Serial.print("Button 6: ");
  Serial.print(is_key_pressed(PIN_BUTTON_6));
  Serial.print(", Button 7: ");
  Serial.print(is_key_pressed(PIN_BUTTON_7));
  Serial.print(", Button 8: ");
  Serial.print(is_key_pressed(PIN_BUTTON_8));
  Serial.println(".");

}
