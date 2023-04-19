/*
 * In dit programma worden twee servo motoren tegelijkertijd aangestuurd om heen en weer te bewegen. 
 * Elke servo kan op zijn eigen tempo bewegen.
 * 
 * Hieronder staat uitgelegd hoe de servo motoren moeten worden aangesloten op de Arduino:
 *
 * Servo 1:
 * De servo motor aansluiten op pin 3 van de Arduino
 *
 * Servo 2:
 * De servo motor aansluiten op pin 5 van de Arduino
 */

#include <Servo.h>  // Bibliotheken importeren voor de Servo motor

Servo servo1;  // Servo object aanmaken om de eerste servo motor te besturen
Servo servo2;  // Servo object aanmaken om de tweede servo motor te besturen

int pos1 = 0;  // Variabele om de positie van de eerste servo motor bij te houden
int pos2 = 0;  // Variabele om de positie van de tweede servo motor bij te houden

int speed1 = 1;  // Snelheid van de eerste servo motor
int speed2 = 5;  // Snelheid van de tweede servo motor

void setup() {
  servo1.attach(3);  // De eerste servo motor aansluiten op pin 3 van de Arduino
  servo2.attach(5);  // De tweede servo motor aansluiten op pin 5 van de Arduino
}

void loop() {
  pos1 = pos1 + speed1;  // Verander de positie van de eerste servo motor met de aangegeven snelheid
  if(pos1 >= 180 || pos1 <= 0){  // Controleer of de hoek van de eerste servo motor de grenzen van 0 en 180 graden overschrijdt
    speed1 = -speed1;  // Als dat het geval is, omkeren van de snelheid om de servo in de tegenovergestelde richting te laten bewegen
  } 
  pos2 = pos2 + speed2;  // Verander de positie van de tweede servo motor met de aangegeven snelheid
  if(pos2 >= 180 || pos2 <= 0){  // Controleer of de hoek van de tweede servo motor de grenzen van 0 en 180 graden overschrijdt
    speed2 = -speed2;  // Als dat het geval is, omkeren van de snelheid om de servo in de tegenovergestelde richting te laten bewegen
  } 
  
  servo1.write(pos1);  // De eerste servo motor bewegen naar de huidige hoek
  servo2.write(pos2);  // De tweede servo motor bewegen naar de huidige hoek
  delay(50);  // Een korte pauze van 50 milliseconden zodat er tijd is voor de beweging
}
