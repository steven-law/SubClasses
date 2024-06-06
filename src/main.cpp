#include <Arduino.h>

#include <persons.h>

Person Tom("Toll","Tom");
Student Homer("Simpson","Homer",1980, 7,9,2000);
Professor McGuire("McGuire","Richard",17);
// put function declarations here:

void setup() {
  Serial.begin(115200);
  delay(10000);
  Serial.println("Hello World");
  // put your setup code here, to run once:
  Tom.printName();
  Homer.printName();
  McGuire.printName();
  Homer.set_Potentiometer(4, 13);
  Homer.print_Potentiometer(4);
  McGuire.print_Potentiometer(4);
}

void loop() {
  // put your main code here, to run repeatedly:
}

