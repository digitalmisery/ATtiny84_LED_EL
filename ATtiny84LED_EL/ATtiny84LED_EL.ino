//*********************************************************************
//* ATtiny84 LED + EL 
//* by Paul Martis
//* http://www.digitalmisery.com
//* January 26, 2013
//*********************************************************************
//Hardware Definitions
// ATtiny84 (PDIP or SOIC - 14)
// Using ATTinyCore from https://github.com/TCWORLD/ATTinyCore
// [TYPE] FUNCTION (Arduino) Pin
//
//                             +-\/-+
//                       VCC  1|    |14  GND
//  [GPIO] D0    (D  0)  PB0  2|    |13  PA0  (D10,A0) D10/A0  [ADC/IO]
//  [GPIO] D1    (D  1)  PB1  3|    |12  PA1  (D9,A1)  TXO     [ADC/IO]
//         RESET (D 11)  PB3  4|    |11  PA2  (D8,A2)  RXI     [ADC/IO]
//  [PWM]  LED1  (D  2)  PB2  5|    |10  PA3  (D7,A3)  D7/A3   [ADC/IO]  
//  [PWM]  LED2  (D  3)  PA7  6|    |9   PA4  (D  6)   SPI_SCK
//  [PWM]  LED3  (D  4)  PA6  7|    |8   PA5  (D  5)   EL_OPTO [PWM]
//                             +----+
#define DIO_0 0
#define DIO_1 1
#define LED1 2
#define LED2 3
#define LED3 4
#define EL_OPTO 5
#define DIO_7 7
#define AI_3 3
#define DIO_8 8
#define RXI 8
#define AI_2 2
#define DIO_9 9
#define TXO 9
#define AI_1 1
#define DIO_10 10
#define AI_0 0

long current_time = 0;
//*********************************************************************
//Delay macros
#define LED_FADE_DURATION 1000
#define LED_DELAY ceil(LED_FADE_DURATION / 255)
#define EL_BPM 70
#define EL_DELAY ceil(60000 / EL_BPM / 2 / 255)
#define TIME_DELAY 120000
//*********************************************************************
//Setup function
void setup()
{
  pinMode(EL_OPTO, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(EL_OPTO, HIGH);
  delay(3000);
  //Serial.begin(9600);
  for (int i = 0; i <=255; i++)
  {
    analogWrite(LED1, i);
    delay(LED_DELAY);
  }
  delay(500);
  for (int i = 0; i <=255; i++)
  {
    analogWrite(LED2, i);
    delay(LED_DELAY);
  }
  delay(500);
  for (int i = 0; i <=255; i++)
  {
    analogWrite(LED3, i);
    delay(LED_DELAY);
  }
  delay(500);
}
//*********************************************************************
//Main loop
void loop()
{
  if (millis() - current_time > TIME_DELAY)
  {
    current_time = millis();
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(EL_OPTO, HIGH);
    delay(3000);
    for (int i = 0; i <=255; i++)
    {
      analogWrite(LED1, i);
      delay(LED_DELAY);
    }
    delay(500);
    for (int i = 0; i <=255; i++)
    {
      analogWrite(LED2, i);
      delay(LED_DELAY);
    }
    delay(500);
    for (int i = 0; i <=255; i++)
    {
      analogWrite(LED3, i);
      delay(LED_DELAY);
    }
    delay(500);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(EL_OPTO, i);
    delay(EL_DELAY);
  }
  delay(EL_DELAY);
  for (int i = 0; i <=255; i++)
  {
    analogWrite(EL_OPTO, i);
    delay(EL_DELAY);
  }
//  digitalWrite(EL_OPTO, LOW);
//  Serial.println("Low");
//  delay(1000);
//  digitalWrite(EL_OPTO, HIGH);
//  Serial.println("High");
  delay(250);
}
//*********************************************************************
