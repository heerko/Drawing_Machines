/*
 * Dit programma stuurt een stappenmotor aan via een CNC Shield V3.
 * De motor beweegt 200 stappen vooruit en vervolgens 200 stappen terug.
 *
 * Hardware:
 * - CNC Shield V3 geplaatst op een Arduino Uno
 * - Stepper driver (zoals A4988 of DRV8825) geplaatst in de X-driver socket van het shield
 * - Stappenmotor aangesloten op de X-uitgang van het shield
 * - Externe voeding (bijv. 12V) aangesloten op het CNC Shield voor de motorvoeding
 *
 * Belangrijk:
 * - Zorg ervoor dat er een koelblokje op de driver zit!
 * - De ENABLE-, DIR- en STEP-signalen worden automatisch toegewezen via het shield:
 *     X_STEP = pin 2
 *     X_DIR = pin 5
 *     X_ENABLE = pin 8
 */

// Pin-definities voor de X-as driver. Niet veranderen. 
#define X_STEP_PIN 2
#define X_DIR_PIN 5
#define X_ENABLE_PIN 8

void setup()
{
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);

  digitalWrite(X_ENABLE_PIN, LOW); // Driver inschakelen (LOW = actief)
}

void loop()
{
  digitalWrite(X_DIR_PIN, HIGH); // Richting instellen

  // 200 stappen vooruit
  for (int i = 0; i < 200; i++)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);

  digitalWrite(X_DIR_PIN, LOW); // Richting omkeren

  // 200 stappen terug
  for (int i = 0; i < 200; i++)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);
}