const int buttonPin = 2;
int n = 0;
unsigned long time = 0;

void buttonPressed() {
  //Serial.println("Interrupt");
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  // Interrupts can happen on "edges" of signals.  
  // Three edge types are supported: CHANGE, RISING, and FALLING 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, CHANGE);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin)== LOW){
    if (millis() > time) {
   time += 1000;
    n = n+1;
    Serial.print ("Number of times button has been pressed: ");
    Serial.println (n);
    }
  }
}
