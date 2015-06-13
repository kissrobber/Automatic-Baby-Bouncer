#define SOLENOID 2
#define SWITCH 3
#define FORCE_PUSH 4
#define POWER 5

void setup() {
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(FORCE_PUSH, INPUT_PULLUP);
  pinMode(POWER, INPUT_PULLUP);
  pinMode(SOLENOID, OUTPUT);
}

void loop(){
  int s, fp, p;
  p = digitalRead(POWER);
  fp = digitalRead(FORCE_PUSH);
  s = digitalRead(SWITCH);
  if(p == LOW){
    delay(1000);
    return;
  }
  if(fp == LOW || s == HIGH){
    push_up();
    return;
  }
}

void push_up(){
  digitalWrite(SOLENOID, HIGH);
  delay(200);
  digitalWrite(SOLENOID, LOW);
  delay(300);
}
