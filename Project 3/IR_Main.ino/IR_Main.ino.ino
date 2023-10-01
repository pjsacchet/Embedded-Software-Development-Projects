volatile byte rpmCount; // Total rpm count
int pd=2; //Photodiode to digital pin 2
unsigned int rpm; // Calculated rpm count
unsigned long timeOld; // Time from last read

void rpm_fun()
{
  // Update our rpm count 
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
  attachInterrupt(0, rpm_fun, FALLING);
}