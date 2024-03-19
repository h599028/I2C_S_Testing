#include <Arduino.h>
#include <Wire.h>

#define I2C_DEV_ADDR 0x42



int myIndex;
byte list[] = {0, 1, 2, 4, 8, 16, 32, 64};

void receiveData(int byteCount)
{
  while (Wire.available()) {
    myIndex = Wire.read();
  }
}

void requestData()
{
  Serial.printf("myIndex: %u, list[myIndex]: %u\n", myIndex, list[myIndex]);
  Wire.write(list[myIndex]);
}

void setup()
{
  Wire.setPins(23, 22);           
  Wire.onReceive(receiveData); // Set the function to handle receiving data
  Wire.onRequest(requestData);
  Wire.begin(I2C_DEV_ADDR);    // Initialize I2C bus with address
  Serial.begin(115200); // Start serial communication
}

void loop()
{
  // Additional code can be added here if needed
}
