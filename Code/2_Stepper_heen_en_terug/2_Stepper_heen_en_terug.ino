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

const int STEPS_PER_REVOLUTION = 2048; // Het aantal stappen dat nodig is om een volledige rotatie van de stepper motor te maken

Stepper stepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11); // Stepper object aanmaken met de pinnen en stappen per rotatie
// 8, 10, 9, 11 zijn de pinnen waarop de stepper is aangesloten. De volgorde is hier dus anders!

void setup() {
stepper.setSpeed(10); // De snelheid van de stepper motor instellen op 5 rotaties per seconde
}

void loop() {
// De stepper motor bewegen
stepper.step(STEPS_PER_REVOLUTION); // De aangegeven stappen uitvoeren
delay(1000); // Een pauze van 1 seconde om de motor te laten rusten

// De stepper motor in omgekeerde richting bewegen
stepper.step(-STEPS_PER_REVOLUTION); // De aangegeven stappen in omgekeerde richting uitvoeren
delay(1000); // Een pauze van 1 seconde om de motor te laten rusten
}