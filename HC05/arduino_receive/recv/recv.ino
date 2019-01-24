//Receive a number as text and convert it to an int

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
int valueOld = 0;
int valueNew = 0;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop() {
  int data[5], sign,value, i;
  value = 0 ;
  i = 0;
  sign = 1;
  if (mySerial.available()) {
    if (mySerial.read() == 'a') {
      while (1) {
        if (mySerial.available()) {
          data[i] = mySerial.read();
          if (data[i] == 's') break;
          if (data[i] == '-') {
            sign = -1;
          }else{
            value *= 10;
            value += data[i]-48;
          }
          i++;
        }
      }
      value *= sign;

      if((value < (valueOld + 100)) && (value > (valueOld - 100))){
        valueOld = valueNew;
        valueNew = value;
      }

    
      
    Serial.println(valueNew);
    }

  }
}
