/*****************************************************************
   PORT Command is used to change the state of pin i.e. On or OFF

   DDR is used to set the pinmode whether as input/output,
   thus DDR register instead of using pinMode().
 *****************************************************************/

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)
int timer = 300;
 
void setup()
{
  Serial.begin(9600);
  DDRB = 0b00000111; //B0-B1(Set as output); DDR-Data Direvction Register is used to set the pin as input(0) or output(1)
  DDRD = 0b11111110; //D1-D7(Set as output)
}


void loop()
{
  //start();
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    timer -= 1;

  }
  int t = timer;
  int i = t % 10;
  t /= 10;
  int j = t % 10;
  t /= 10;
  int k = t % 10;
                
  disp(k, j, i);
}

void start()
{ int i = 3;
  while (i != 0)
  {
    if (i == 3)
    {
      PORTB = 0b00000011; //Turn ON B2-pin and other pins of port B are OFF.
    }
    if (i == 2)
    {
      PORTB = 0b00000101; //Turn ON B1-pin and other pins of port B are OFF.
    }
    if (i == 1)
    {
      PORTB = 0b00000110;
    }
    PORTD = 0b00000010;
    delay(100);
    PORTD = 0b00000110;
    delay(100);
    PORTD = 0b00001110;
    delay(100);
    PORTD = 0b00011110;
    delay(100);
    PORTD = 0b00111110;
    delay(100);
    PORTD = 0b01111110;
    delay(100);
    PORTD = 0b11111110;
    delay(200);
    PORTD = 0b01111110;
    delay(100);
    PORTD = 0b00111110;
    delay(100);
    PORTD = 0b00011110;
    delay(100);
    PORTD = 0b00001110;
    delay(100);
    PORTD = 0b00000110;
    delay(100);
    PORTD = 0b00000010;
    delay(100);
    PORTD = 0b00000000;
    delay(200);
    i--;
  }
}

void zero()
{
  PORTD = 0b01111110;
}

void one()
{
  PORTD = 0b00001100;
}

void two()
{
  PORTD = 0b10110110;
}

void three()
{
  PORTD = 0b10011110;
}

void four()
{
  PORTD = 0b11001100;
}

void five()
{
  PORTD = 0b11011010;
}

void six()
{
  PORTD = 0b11111010;
}

void seven()
{
  PORTD = 0b00001110;
}

void eight()
{
  PORTD = 0b11111110;
}

void nine()
{
  PORTD = 0b11001110;
}

void digit1(int x)
{
  PORTB = 0b000000110;
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 10: zero(); break;
    case 0: zero(); break;
  }
}

void digit2(int x)
{
  PORTB = 0b00000101;
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 0: zero(); break;
    case 10: zero(); break;
  }
}

void digit3(int x)
{
  PORTB = 0b000000011;
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 0: zero(); break;
    case 10: zero(); break;
  }
}

void disp(int i, int j, int k)
{
  digit1(i);
  delay(10);
  digit2(j);
  delay(10);
  digit3(k);
  delay(10);
}
