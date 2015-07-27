void moveForward() {
  digitalWrite(direction,HIGH);
  for (int i = 0; i < stepsPerMove; i++) {
    singleStep();
    delayMicroseconds(speed);
  }

}

void moveBackward() {
  digitalWrite(direction,LOW);
  for (int i = 0; i < stepsPerMove; i++) {
    singleStep();
    delayMicroseconds(speed);
  }

}
