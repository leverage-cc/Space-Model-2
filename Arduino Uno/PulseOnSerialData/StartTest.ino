void startTest() {
  digitalWrite(direction,LOW);
  for (int i = 0; i < stepsPerMove; i++) {
    singleStep();
    delayMicroseconds(speed*10);
  }
  digitalWrite(direction,HIGH);
  for (int i = 0; i < stepsPerMove; i++) {
    singleStep();
    delayMicroseconds(speed*10);
  }
}
