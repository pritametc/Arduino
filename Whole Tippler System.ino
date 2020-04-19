
#include <Servo.h>
int pos=0;
Servo servo_2;

void setup()
{
  pinMode(40, INPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(41, INPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(42, INPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(43, INPUT_PULLUP);
  servo_2.attach(2);

}

void loop()
{
  // NC3
  if (digitalRead(40) == HIGH) {
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
  } else {
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
  }

  // NC2
  if (digitalRead(40) == HIGH && digitalRead(41) == HIGH) {
    digitalWrite(24, HIGH);
    digitalWrite(25, LOW);
  } else {
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
  }

  // NC1
  if (digitalRead(40) == HIGH && digitalRead(42)==HIGH) {
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
  } else {
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
  }

  // Tippler
  if (digitalRead(43) == LOW) {
    for (pos=4; pos<=145; pos+=1)
 {
      servo_2.write(pos);
      delay(35);
 }
 delay(2000);
   for (pos=145; pos>=4; pos-=1)
 {
      servo_2.write(pos);
      delay(35);
 }
  }
  delay(10); // Delay a little bit to improve simulation performance
}
