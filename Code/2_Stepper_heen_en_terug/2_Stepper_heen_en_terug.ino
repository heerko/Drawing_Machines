/*

    In dit programma wordt een stepper motor aangestuurd.
    Hieronder staat uitgelegd hoe de componenten moeten worden aangesloten op de Arduino:
    Stepper:
    Sluit de stepper motor aan op de vier pinnen van de ULN2003 driver board.
    Sluit de IN1 pin van de driver board aan op pin 8 van de Arduino,
    de IN2 pin op pin 9, de IN3 pin op pin 10 en de IN4 pin op pin 11.
    Verbind de GND pin van de driver board met de GND pin van de Arduino
    en de VCC pin van de driver board met de Vin pin van de Arduino.
    Let op: Het is belangrijk om de juiste polariteit te gebruiken bij
    het aansluiten van de driver board van de stepper motor.
    */

#include <Stepper.h> // Bibliotheken importeren voor de Stepper motor

const int STEPS_PER_REVOLUTION = 2038; // Het aantal stappen dat nodig is om een volledige rotatie van de stepper motor te maken
const int STEPPER_PIN_1 = 8; // De pinnen die zijn aangesloten op de stepper motor
const int STEPPER_PIN_2 = 9;
const int STEPPER_PIN_3 = 10;
const int STEPPER_PIN_4 = 11;

Stepper stepper(STEPS_PER_REVOLUTION, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4); // Stepper object aanmaken met de pinnen en stappen per rotatie

void setup() {
stepper.setSpeed(5); // De snelheid van de stepper motor instellen op 5 rotaties per seconde
}

void loop() {
// De stepper motor bewegen
int steps = 2038; // Het aantal stappen dat de motor moet maken voor een volledige rotatie
stepper.step(steps); // De aangegeven stappen uitvoeren
delay(1000); // Een pauze van 1 seconde om de motor te laten rusten

// De stepper motor in omgekeerde richting bewegen
stepper.step(-steps); // De aangegeven stappen in omgekeerde richting uitvoeren
delay(1000); // Een pauze van 1 seconde om de motor te laten rusten
}