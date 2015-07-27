void singleStep() {
  digitalWrite(step, HIGH);
  delayMicroseconds(speed);
  digitalWrite(step, LOW);
  delayMicroseconds(speed);
}
