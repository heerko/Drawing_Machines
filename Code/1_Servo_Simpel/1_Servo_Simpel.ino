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

int pos = 0;  // Variabele om de positie van de servo motor bij te houden
int speed = 1;  // Snelheid van de servo motor

void setup() {
  myservo.attach(3);  // de servo motor aansluiten op pin 3 van de Arduino
}

void loop() {
  pos = pos + speed;            // Verander de positie van de servo motor met de aangegeven snelheid
  if (pos >= 180 || pos <= 0) {  // Controleer of de hoek van de servo motor de grenzen van 0 en 180 graden overschrijdt
    speed = -speed;              // Als dat het geval is, omkeren van de snelheid om de servo in de tegenovergestelde richting te laten bewegen
  }

  myservo.write(pos);  // De servo motor bewegen naar de huidige hoek
  delay(50);            // Een korte pauze van 50 milliseconden zodat er tijd is voor de beweging
}
