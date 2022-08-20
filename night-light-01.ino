#define rLedPin 6
#define gLedPin 5
#define bLedPin 3
#define irSensorPin 8
#define lightSensorPin A0

int ledR = 100;
int ledG = 0;
int ledB = 100;

bool irReading;
int lightReading;

void setup() {
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  
  Serial.begin(9600);
  Serial.println("This is a RGB Led Night light.");
}

void loop() {
  // Read data from the sensor
  lightReading = analogRead(lightSensorPin);
  irReading = digitalRead(irSensorPin);
  if(irReading == HIGH && lightReading >= 850){
    lightOn(1);
  } else{
    lightOn(0);
  }
  Serial.println("====Sensor Test Report====");
  Serial.print("lightReading = "); Serial.println(lightReading);
  Serial.print("irReading = "); Serial.println(irReading);
  Serial.println("==========================");
}

void lightOn(bool on){
  if (on == 1){
    digitalWrite(rLedPin, ledR);
    delay(10);
    digitalWrite(gLedPin, ledG);
    delay(10);
    digitalWrite(bLedPin, ledB);
    delay(10); 
  } else{
    digitalWrite(rLedPin, 0);
    delay(10);
    digitalWrite(gLedPin, 0);
    delay(10);
    digitalWrite(bLedPin, 0);
    delay(10); 
  }
}
