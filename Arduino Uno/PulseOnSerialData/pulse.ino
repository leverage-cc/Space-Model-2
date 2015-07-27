void pulse() {
  digitalWrite(direction,LOW);
  for (int i = 0; i < amplitude*0.8; i++) {
    singleStep();
  }
  digitalWrite(direction,HIGH);
  for (int i = 0; i < amplitude; i++) {
    singleStep();
  }
  digitalWrite(direction,LOW);
  for (int i = 0; i < amplitude*0.2; i++) {
    singleStep();
  }
}
