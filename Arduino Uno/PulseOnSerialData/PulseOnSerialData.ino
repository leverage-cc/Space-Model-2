int incomingByte;        // for incoming serial data

int step = 9;            // pin for step command

int speed = 60;          // stepper speed in Microseconds, lower is faster.
int stepsPerMove = 100;  // for startTest & move
int amplitude = 1000;    // intensity of the heart beat. Higher is stronger (more steps);

int direction = 8;       // pin for direction command


void setup() {
  
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps

  pinMode(direction, OUTPUT);
  pinMode(step, OUTPUT);
     
  startTest();
    
}

void loop() {
  if (Serial.available()) {
    incomingByte = Serial.read();
    Serial.write(incomingByte);
    if (incomingByte == 1) {
      pulse();
    }
    if (incomingByte == 2) {
      moveForward();
    }
    if (incomingByte == 3) {
      moveBackward();
    }
  }
}
