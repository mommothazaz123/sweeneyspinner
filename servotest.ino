#include <Servo.h>
Servo servo;
int incomingByte = 0;
int moveTime = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (moveTime > 0) {
    servo.write(180);
    moveTime--;
  } else {
    servo.write(94);
  }
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    if (incomingByte == 1) {
      moveTime = 1000;
    }
  }
  delay(5);
}
