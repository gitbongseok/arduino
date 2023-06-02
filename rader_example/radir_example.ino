#include <Servo.h>

Servo myservo;

int TrigPin = 12;
int EchoPin = 13;
int servoPin = 6;

int min_angle = 15;
int max_angle = 165;

int pos = min_angle;
int increase = 1;


void setup() {
  myservo.attach(servoPin);

  Serial.begin (9600);
  //pinMode (servoPin, OUTPUT);
  pinMode (TrigPin, OUTPUT);
  pinMode (EchoPin, INPUT);
}

void loop() {

  //Serial.print ("Distance :");
  Serial.print(pos);
  Serial.print(",");
  Serial.print (distance());
  Serial.print(".");
  //Serial.println(" cm");
  //Serial.print (pos);

  myservo.write(pos);
  pos += increase;
  if (pos <= min_angle || pos >= max_angle) { increase *= -1; }

  delay(30);


}

unsigned long distance() {

  unsigned long d;

  digitalWrite (TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  d = pulseIn(EchoPin, HIGH) / 2 * 0.034; //cm
  return d;
}
