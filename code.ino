/* 
 *  This is the code uploaded onto the microcontroller (MC) that enables 
 *  certain pins that are used to communicate with other components
 *  such as the motor driver, ultrasonic sensor, etc. 
 */

int enable1 = 6; // Connects enable 1 to pin 6 on the microcontroller (MC)
int left1 = 7;  // Connects input1 to pin 7 on the microcontroller
int left2 = 8; // Connects input2 to pin 8 on the microcontroller

int enable2 = 11; // Connects enable2 to pin 11 on the MC
int right1 = 12; // Connects input3 to pin 12 on the MC
int right2 = 13; // Connects input4 to pin 13 on the MC

int LineSensor = 2; // Connects light sensor to pin 2 on the MC

int trig= 3; // Use digital pin 3
int echo= 4; // Use digital pin 4
float t = 0;
float distance = 0;


void setup() {   // Setup code that sets the input/output 
  Serial.begin(9600); // Determines the communication rate of the wires (?)

  // LEFT MOTOR SECTION
  pinMode(enable1, OUTPUT); // Passes info from MC to MD and sets speed
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);

  // RIGHT MOTOR SECTION
  pinMode(enable2, OUTPUT); // Passes info from MC to MD and sets speed
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(LineSensor, INPUT);
}


void loop() {
  digitalWrite(trig,LOW); // Deactivate if already on 
  delay(50); // Wait 50 ms
  digitalWrite(trig,HIGH); // Send a pulse
  delay(50);
  digitalWrite(trig,LOW); // Stop sending pulse
  t = pulseIn(echo,HIGH); // Echo receives. Turns receiver on. 
  distance = (0.034*t)/2; // Do weird computation to find distance 

  if (distance > 5){
    analogWrite(enable1, 255); 
    digitalWrite(left1, LOW);
    digitalWrite(left2, HIGH);
    analogWrite(enable2, 255);
    digitalWrite(right1, LOW);
    digitalWrite(right2, HIGH);
  } else {
  analogWrite(enable1, 255); 
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  analogWrite(enable2, 255);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  }
}


/*Serial.println(digitalRead(LineSensor));
if (digitalRead(LineSensor)==1){
  analogWrite(enable1, 255); 
  digitalWrite(left1, LOW);
  digitalWrite(left2, HIGH);
  analogWrite(enable2, 255);
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);
 // delay(2000);
 
} else {
  analogWrite(enable1, 255); 
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  analogWrite(enable2, 255);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  //delay(3000);
}

 
}
  

  
  /*analogWrite(enable1, 255); // Set speed of left motor to 255/255
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);

  analogWrite(enable2, 255);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);

  delay(3000);

  analogWrite(enable1, 255);
  digitalWrite(left1, LOW);
  digitalWrite(left2, HIGH);

  analogWrite(enable2, 255);
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);

  delay(4000);





  /*
    analogWrite(enable2, 255);
    delay(3000);
    digitalWrite(left1, HIGH);
    digitalWrite(left2, LOW);
    delay(8000);
  */
