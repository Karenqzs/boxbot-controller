
int motorRightForward   = 9;
int motorRightReverse   = 10;
int motorLeftForward    = 11;
int motorLeftReverse    = 12;
int headlight = 7;
int reverselight = 8;
int leftLight = 4;
int rightLight = 5;
unsigned long previousMillis = 0;
const long interval = 150;
int ledState = LOW;
bool leftBlink = false;
bool rightBlink = false;
unsigned long lastDebounceTime = 0;
unsigned long rlastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 500;    // the debounce time; increase if the output flickers



void setup() {
  Serial.begin(115200);
  
  pinMode(6,OUTPUT);
  pinMode(leftLight, OUTPUT);
  pinMode(rightLight, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightReverse, OUTPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftReverse, OUTPUT);
  analogWrite(6,255);
  
}

void forward() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,HIGH);
  digitalWrite(reverselight,LOW);
 
}

void reverse() {
  digitalWrite(motorRightForward, LOW);
  analogWrite(motorRightReverse, 140);
  digitalWrite(motorLeftForward, LOW);
  analogWrite(motorLeftReverse, 140);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,HIGH);
}

void left() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, HIGH);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);
}

void right() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, HIGH);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);
}

void halt() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);  
}

void dance() {
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  halt();

}

bool turnSignal(int side) {
   unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(side, ledState);
  }
}



void serialEvent() {
  String input = Serial.readStringUntil('\n');
  input.trim();

  if (input == "forward") {
    Serial.println("FORWARD!");
    // go forward
  } else if (input == "left") {
    // go left
  } else if (input == "right") {
    // go right
  } else if (input == "backwards") {
    // go back
  }

    if (input == "forward") {
      Serial.println("FORWARD");
      forward();
    } else if (input == "reverse") {
      Serial.println("REVERSE");
      reverse();
    } else if (input == "left") {
      Serial.println("LEFT");
      left();
    } else if (input == "right") {
      Serial.println("RIGHT");
      right();
    } else if (input == "halt") {
      Serial.println("HALT");
      halt();
    } else if (input == "dance") {
      Serial.println("DANCE");
      dance();
    }
    if (input == "left signal") {
      Serial.println("left turn signal");
      if ((millis() - lastDebounceTime) > debounceDelay) {
      leftBlink = !leftBlink;
      rightBlink = false;
      lastDebounceTime = millis();
      }
    }
    if (input == "right signal") {
      Serial.println("right turn signal");
      if ((millis() - rlastDebounceTime) > debounceDelay) {
      rightBlink = !rightBlink;
      leftBlink = false;
      rlastDebounceTime = millis();
      }
    }
    if (input == "set speed 1") {
      Serial.println("set speed one");
      analogWrite(6,140);
     
    }
    if (input == "set speed 2") {
      Serial.println("set speed two");
      analogWrite(6,190);
      
    }
    if (input == "set speed 3") {
      Serial.println("set speed three");
      analogWrite(6,255);
      
    }

  }

void loop(){
  if (leftBlink){
      turnSignal(leftLight);
    }else{
      digitalWrite(leftLight, LOW);
    }
  
    
  if (rightBlink){
      turnSignal(rightLight);
    }else{
      digitalWrite(rightLight, LOW);
    }    
}
