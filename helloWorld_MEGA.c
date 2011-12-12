//================================================
//  Example HelloWorld
//================================================
// SKETCH_NAME: HelloWorld
// BOARD_TYPE   MEGA
// SCENSIMLEN   600
//================================================
//  Scenario
//================================================
//
// SCENDIGPIN 10    1    0
// SCENDIGPIN 10   50    1
// SCENDIGPIN 10  100    0
// SCENDIGPIN 10  200    1
// SCENDIGPIN  9    1    0
// SCENDIGPIN  9   40    1
// SCENDIGPIN  9  130    0
//
// SCENANAPIN  4    1    5
// SCENANAPIN  5    1    8 
// SCENANAPIN  4   80   12
// SCENANAPIN  5  120   18 
//
//================================================
// Simuino log text customization
//================================================

// PINMODE_OUT: 11  "PIN: Led Urgent"
// PINMODE_OUT: 12  "PIN: Led Blink"

// DIGITALWRITE_LOW:  11  "Waiting"
// DIGITALWRITE_HIGH: 11  "Urgent"
// DIGITALWRITE_LOW:  12  "Led is off"
// DIGITALWRITE_HIGH: 12  "Led is on"

// DIGITALREAD:  9  "Read from nine"
// DIGITALREAD: 10  "Read from ten"


// ANALOGREAD: 4  "read analog four"
// ANALOGREAD: 5  "read analog five"


//-------- DIGITAL PIN settings ------------------

// Leds
int URGENTLED    = 31;
int BLINKLED     = 32;
int IN_PIN       = 20;
int CONTROL      = 19;
 
//-------- ANALOGUE PIN settings
int SENSOR1  = 4;
int SENSOR2  = 5;

//================================================
//  Function Declarations
//================================================

void blinkLed(int n);

//================================================
void urgent()
//================================================
{
      digitalWrite(URGENTLED, HIGH); 
      delay(401);
      digitalWrite(URGENTLED, LOW); 
}
//================================================
void very_urgent()
//================================================
{
      digitalWrite(URGENTLED, HIGH); 
      delay(402);
      digitalWrite(URGENTLED, LOW); 
}
//================================================
void setup()
//================================================
{
  Serial.begin(9600); 
  attachInterrupt(0,urgent, CHANGE);
  attachInterrupt(1,very_urgent, RISING);
  pinMode(BLINKLED,OUTPUT);   
  pinMode(URGENTLED,OUTPUT);   
  pinMode(IN_PIN,INPUT);
  pinMode(CONTROL,INPUT);
  pinMode(15,OUTPUT);
  pinMode(44,INPUT);
  pinMode(45,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(47,INPUT);
}
	 
//================================================ 
void loop()
//================================================
{
  int value1,value2,i;

  Serial.println("Hello Simuino!");
  value1 = analogRead(SENSOR1);
  value2 = analogRead(SENSOR2);
  Serial.print("Analog 1 value read: ");
  Serial.println(value1);
  Serial.print("Analog 2 value read: ");
  Serial.println(value2);
  blinkLed(value1);
  value1 = digitalRead(IN_PIN);
  value2 = digitalRead(CONTROL);
  Serial.print("Digital IN_PIN read: ");
  Serial.println(value1);
  Serial.print("Digital CONTROL read: ");
  Serial.println(value2);

  analogWrite(10,123);
  analogWrite(11,167);

  analogWrite(3,127);
  analogWrite(4,147);
  
  delay(1000); 
}

//================================================
void blinkLed(int n)
//================================================
{
  int i;
  for(i=1;i<=10;i++)
    {
      digitalWrite(BLINKLED, HIGH); 
      delay(500);
      digitalWrite(BLINKLED, LOW); 
    }
}
//================================================
// End of Sketch
//================================================