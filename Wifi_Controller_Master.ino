//========================Library======================//
#include <Servo.h>
//=====================================================//

//========================Int Setup=====================//
Servo motor;
Servo wheel;
// 
int throttle, steering, sliderVal, button, sliderId;
int wheel_left, wheel_right, wheel_center;// Steering Servo variables
int forwards_fast, forwards_medium, forwards_slow, backwards_fast, backwards_medium, backwards_slow, throttle_off; // Motor Servo Varables

//=====================================================//

// Setup code runs once after program starts.
void setup() {
  
    // Servo/Motor Setup
    motor.attach(30);
    wheel.attach(40);
    motor.write(90); // Activating Motor
    motor.write(91); // Activating Motor
    
    // Start serial monitor at 9600 bps.
    Serial.begin(9600);
    delay(100);

    //==============Motor Activation Sequence==============//
    motor.write(90);delay(50);
    motor.write(91);delay(50);
    motor.write(90);delay(50);
    motor.write(91);delay(50);
    motor.write(90);delay(50);
    motor.write(91);delay(50);
    motor.write(90);delay(50);
    motor.write(91);delay(50);
    //=====================================================//

    // default//
    wheel_left = 140;
    wheel_right = 50;
    wheel_center = 88;
    forwards_fast = 300;
    forwards_medium = 105;
    forwards_slow = 98;
    backwards_fast = 30;
    backwards_medium = 50;
    backwards_slow = 70;
    throttle_off = 90;
    Serial.println("setup complete");
}

// Put your main code here, to run repeatedly:
void loop() {
    //========================Motor Arming======================//
    // Just incase motor still hasn't activated
    motor.write(91);delay(50); //motor arming
    motor.write(90);delay(50); //motor arming
    //==========================================================//

 
    //===========================Simple Control===============================//

    Serial.println("Drive Forwards");
    motor.write(forwards_slow);wheel.write(wheel_center); delay(4000);
    Serial.println("Stop");
    motor.write(throttle_off);wheel.write(wheel_center); delay(4000);
    Serial.println("Turn Left");
    motor.write(forwards_slow);wheel.write(wheel_left); delay(4000);
    Serial.println("Turn Right");
    motor.write(forwards_slow);wheel.write(wheel_right); delay(4000);


}
