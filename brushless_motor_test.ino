#include <Servo.h>
 
Servo test_motor;

int val=70;
 
void setup() {
  Serial.begin(9600);
  test_motor.attach(9);      
  test_motor.write(60);
  delay(3000);                        
}
 
void loop() {
  if(Serial.available()){
    char temp = Serial.read();
    if(temp=='u'){
      val += 5;
    }
    else if(temp=='d'){
      val -= 5;
    }
    test_motor.write(val);
  }
  Serial.print("current value : ");
  Serial.println(val); 
  delay(100);
}
