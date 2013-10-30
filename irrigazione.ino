const int relayPin =  28;
int sensorPin = A0;
int relayState = LOW;
int sensorValue = 0;

void setup() {
  // set the digital pin as output:
  pinMode(relayPin, OUTPUT); 
  Serial.begin( 9600 );
  pinMode(sensorPin, INPUT);  
}

void loop()
{
    sensorValue = analogRead(A0);
    Serial.print("Value: ");
    Serial.println( sensorValue );
    if (sensorValue < 500  ){
      if(relayState == LOW){
        relayState = HIGH;
        digitalWrite(relayPin, relayState);
        Serial.println( "start irrigation" );
      }   
    }else{
      relayState = LOW;
      digitalWrite(relayPin, relayState);
   }
    delay(5000);
}

