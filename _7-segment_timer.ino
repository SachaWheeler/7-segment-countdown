/*****************************************************************
   PORT Command is used to change the state of pin i.e. On or OFF

   DDR is used to set the pinmode whether as input/output,
   thus DDR register instead of using pinMode().
 *****************************************************************/

unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned int displayMillis = 10;

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)
int timer = 300;

// encoder variables
int pinA = 12;  // Connected to CLK on KY-040
int pinB = 11;  // Connected to DT on KY-040
int encoderPosCount = 0; 
int pinALast;  
int aVal;
boolean bCW;
 
void setup()
{ 
  DDRB = 0b00000111; //B0-B1(Set as output); DDR-Data Direvction Register is used to set the pin as input(0) or output(1)
  DDRD = 0b11111110; //D1-D7(Set as output)

  pinMode (pinA,INPUT);
  pinMode (pinB,INPUT);
  // Read Pin A. Whatever state it's in will reflect the last position   
  pinALast = digitalRead(pinA);   

}

void loop()
{
  //start();
  aVal = digitalRead(pinA);
  if (aVal != pinALast){ // Means the knob is rotating
     // if the knob is rotating, we need to determine direction
     // We do that by reading pin B.
     if (digitalRead(pinB) != aVal) {  // Means pin A Changed first - We're Rotating Clockwise
       encoderPosCount ++;
       bCW = true;
     } else {// Otherwise B changed first and we're moving CCW
       bCW = false;
       encoderPosCount--;
     }
     //Serial.print ("Rotated: ");
     if (bCW){
       //Serial.println ("clockwise");
       timer += 30;
     }else{
       //Serial.println("counterclockwise");
       timer -= 30;
     }
     //Serial.print("Encoder Position: ");
     //Serial.println(encoderPosCount);
     
  } 
  pinALast = aVal;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    timer -= 1;

  }
  disp(timer);
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

void digit(int x)
{
  switch (x) {
    case 1: PORTD = 0b00001100; break;
    case 2: PORTD = 0b10110110; break;
    case 3: PORTD = 0b10011110; break;
    case 4: PORTD = 0b11001100; break;
    case 5: PORTD = 0b11011010; break;
    case 6: PORTD = 0b11111010; break;
    case 7: PORTD = 0b00001110; break;
    case 8: PORTD = 0b11111110; break;
    case 9: PORTD = 0b11001110; break;
    case 0:
    case 10: PORTD = 0b01111110; break;
  }
}


void digit1(int x)
{
  PORTB = 0b000000110;
  digit(x);
}

void digit2(int x)
{
  PORTB = 0b00000101;
  digit(x);
}

void digit3(int x)
{
  PORTB = 0b000000011;
  digit(x);
}

void disp(int t)
{
  int i = t % 10;
  t /= 10;
  int j = t % 10;
  t /= 10;
  int k = t % 10;
                
  digit1(k);
  delay(displayMillis);
  
  digit2(j);
  delay(displayMillis);
  
  digit3(i);
  delay(displayMillis);
  
}
