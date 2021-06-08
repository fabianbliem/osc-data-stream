#include <Arduino.h>
#include <OSCMessage.h>

int curVal;
int prevVal=0;
int EMGPin = A1;
int EMGVal = 0;

void setup() {
    Serial.begin(115200);
}

void loop(){

    EMGVal = analogRead(EMGPin);
    curVal=EMGVal;

    char buff[16];
    sprintf(buff, "/emg/%d", curVal);
    OSCMessage msg(buff);

    if (curVal != prevVal) {
        msg.add(curVal)
        msg.send(Serial);
        prevVal=curVal;
    }
    delay(20);
}