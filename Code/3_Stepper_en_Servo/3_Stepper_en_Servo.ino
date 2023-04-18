/*
 * In dit programma wordt een servo en een stepper motor tegelijkertijd aangestuurd. 
 Hieronder staat uitgelegd hoe de componenten moeten worden aangesloten op de Arduino:
 *
 * Servo:
 * Bruine draad op GND van de Arduino
 * Rode draad op 5V van de Arduino
 * Oranje draad op pin 3 van de Arduino
 *
 * Stepper:
 * Sluit de stepper motor aan op de vier pinnen van de ULN2003 driver board. 
 * Sluit de IN1 pin van de driver board aan op pin 8 van de Arduino, 
 * de IN2 pin op pin 9, de IN3 pin op pin 10 en de IN4 pin op pin 11. 
 * Verbind de GND pin van de driver board met de GND pin van de Arduino 
 * en de VCC pin van de driver board met de Vin pin van de Arduino.
 *
 * Let op: Het is belangrijk om de juiste polariteit te gebruiken bij 
 * het aansluiten van de servo en de driver board van de stepper motor. 
 */
 
#include <Stepper.h> // Bibliotheken importeren voor de Stepper en Servo motoren
#include <Servo.h>

const int STEPS_PER_REVOLUTION = 2038; // Het aantal stappen dat nodig is om een volledige rotatie van de stepper motor te maken
const int STEPPER_PIN_1 = 8; // De pinnen die zijn aangesloten op de stepper motor
const int STEPPER_PIN_2 = 9;
const int STEPPER_PIN_3 = 10;
const int STEPPER_PIN_4 = 11;

const int SERVO_PIN = 3; // De pin die is aangesloten op de servo motor

int servoAngle = 0; // Variabelen om de hoek van de servo en het aantal stappen van de stepper bij te houden
int servoIncrement = 10;
int stepperSteps = 0;

Stepper stepper(STEPS_PER_REVOLUTION, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4); // Stepper object aanmaken met de pinnen en stappen per rotatie
Servo servo; // Servo object aanmaken

void setup() {
  servo.attach(SERVO_PIN); // De servo motor aansluiten op de aangegeven pin
  stepper.setSpeed(5); // De snelheid van de stepper motor instellen op 5 rotaties per seconde
}

void loop() {
  servoAngle += servoIncrement; // De hoek van de servo motor veranderen met de aangegeven increment
  if (servoAngle >= 180 || servoAngle <= 0) { // Controleren of de hoek de grenzen van 0 en 180 graden overschrijdt
    servoIncrement *= -1; // Als dat het geval is, de increment omkeren om de servo in de tegenovergestelde richting te laten bewegen
  }
  servo.write(servoAngle); // De servo motor bewegen naar de huidige hoek

  // De stepper motor bewegen
  int steps = 10; // Het aantal stappen dat de motor moet maken
  stepper.step(steps); // De aangegeven stappen uitvoeren
  delay(10); // Een korte pauze van 10 milliseconden om de motor te laten rusten
}

