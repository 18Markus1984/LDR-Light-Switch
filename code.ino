int ldr= A7;
int helligkeit = 0; //Der Lichtwert
int analogPin = A6; //Der Feuchtigkeits AnalogPin zum lesen der Werte

int maxVal = 653; //FeuchtigkeitsMax
int minVal = 340; //"" 
int val = 0;      //Der aktuelle Wert der gespeichert wird
int percent = 0;  //Die Prozentzahl anhand von den obrigen drei Werten

void setup(){
  Serial.begin(9600); //Startet eine Seriale-Verbindung um zu kommunizieren
  pinMode(7, OUTPUT); //Feuchtigkeitsensor
  pinMode(3, OUTPUT); //Relay

  digitalWrite(3,LOW);
}

void loop(){
  helligkeit =analogRead(ldr);  
  Serial.print("Helligkeit: ");
  Serial.println(helligkeit);

  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(200);
  val = analogRead(analogPin);  
  percent = map(val,maxVal,minVal,0,100);
  if(percent >= 100) {
    percent = 100;
  }
  else if (percent <= 0) {
    percent = 0;
  }

  Serial.print("Feuchtigkeit:");
  Serial.println(percent);
  
  if(percent <= 15 && helligkeit >= 100) {
    digitalWrite(3,LOW);
    Serial.println("Relay An");
  }else {
    digitalWrite(3,HIGH);
    Serial.println("Relay Aus");
  }
}
