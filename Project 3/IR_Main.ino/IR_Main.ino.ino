int pd=2; //Photodiode to digital pin 2
int senRead=0; //Readings from sensor to analog pin 0 
int limit=650; //Threshold range of an obstacle 

volatile byte rpmCount;
volatile int status;

unsigned int rpm;

unsigned long timeOld;

void rpm_fun()
{
  // Each rotation, this interrupt is run twice
  // Update count (really just need this, not a flashy light)
  rpmCount++;
}


void setup() 
{ 
  // Setting serial monitor at a default baund rate of 9600 
  Serial.begin(9600); 

  // Actually only want this to fire when digital pin 2 rises 
  attachInterrupt(0, rpm_fun, RISING); 
  
  // Values for calculating RPM
  rpm = 0;
  rpmCount = 0;
  timeOld = 0;
  status = LOW;
  
} 
  
void loop() 
{ 
  delay(1000);

  // Dont process interrupts during calculations
  detachInterrupt(0);

  // We use 20 here since we have three propellers on our 'fan' (60/3)
  rpm = 20*1000/(millis() - timeOld)*rpmCount;
  timeOld = millis();
  rpmCount = 0;

  Serial.println(rpm, DEC);
 
  // restart interrupt
  attachInterrupt(0, rpm_fun, RISING);

  // Previous code I used for threashold handling 
  /**
  int val=analogRead(senRead); //variable to store values from the photodiode 
  Serial.println(val); // prints the values from the sensor in serial monitor 
  if(val <= limit) //If obstacle is nearer than the Threshold range 
  { 
    //digitalWrite(buzz,HIGH); // Buzzer will be in ON state    
    Serial.println("Value is less than  limit!");
    delay(1000); 
  } 
  else if(val > limit) //If obstacle is not in Threshold range 
  { 
    //digitalWrite(buzz,LOW); //Buzzer will be in OFF state 
    Serial.println("Value is greater than limit!");
    delay(1000); 
  } 
  */
}


 
