// check ip address before start.

int num;
char received;
boolean isReady = false;

void setup() {
  Serial.begin(115200);      // open serial connection via USB-Serial
  Serial1.begin(250000);     // open serial connection to Linux
  Serial.println("START");
  
  while (!Serial1.find("associated")) {};    // wait for the Linux system to boot. "wlan associated" is the last line of linux boot log
  Serial.println("'associated' found");
  
  delay(100);
  
  while (!Serial1.find("/#")) {  // wait for the command prompt and feed linux with returns to force the prompt to come
    Serial1.println("");
  }
  Serial.println("'/#' found");

  delay(100);
  
  Serial1.println("netcat -u 192.168.1.101 5555");  // open netcat pointing to your local IP and desired port
  Serial.println("netcat started");
  
}

void loop() {
  
  num = analogRead(A0);  // read BioVolt Input
  Serial1.println(num);  // pump it into the open netcat instance
  delay(10);
  
  while (Serial1.available()) {  // as soon netcat instance breaks, force a new one
    received = Serial1.read();
    if (received == '#') {
      Serial1.println("netcat -u 192.168.1.101 5555");
      Serial.println("netcat restarted");
    }
  }
  
}
