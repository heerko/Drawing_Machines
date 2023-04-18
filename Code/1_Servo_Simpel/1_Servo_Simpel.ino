/*

    Dit programma laat een servo motor heen en weer bewegen tussen 0 en 180 graden.
    Hieronder staat uitgelegd hoe de servo moet worden aangesloten op de Arduino:
    Servo:
    Bruine draad op GND van de Arduino
    Rode draad op 5V van de Arduino
    Oranje draad op pin 3 van de Arduino
    Let op: Het is belangrijk om de juiste polariteit te gebruiken bij
    het aansluiten van de servo.
    */

#include <Servo.h>  // Bibliotheken importeren voor de Servo motor

Servo myservo;  // Servo object aanmaken om de servo motor te besturen
int pos = 0;    // Variabele om de positie van de servo motor bij te houden

void setup() {
  myservo.attach(3);  // De servo motor aansluiten op pin 3 van de Arduino
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {  // De servo motor van 0 graden naar 180 graden laten bewegen
    myservo.write(pos);                  // De servo motor bewegen naar de huidige hoek
    delay(15);                           // Een korte pauze van 15 milliseconden om de servo motor te laten rusten
  }
  for (pos = 180; pos >= 0; pos -= 1) {  // De servo motor van 180 graden naar 0 graden laten bewegen
    myservo.write(pos);                  // De servo motor bewegen naar de huidige hoek
    delay(15);                           // Een korte pauze van 15 milliseconden om de servo motor te laten rusten
  }
}