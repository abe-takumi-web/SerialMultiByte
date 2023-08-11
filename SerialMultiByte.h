#ifndef SERIAL_MULTI_BYTE_H
#define SERIAL_MULTI_BYTE_H

#define DEFAULT_BAUD 115200
#define DEFAULT_FIRST_HEADER 0xAA
#define DEFAULT_SECOND_HEADER 0xBB
#define DEFAULT_DATA_SIZE 4

#include "mbed.h"

class SerialMultiByte : public RawSerial {
 public:
  SerialMultiByte(PinName tx, PinName rx);
  SerialMultiByte(PinName tx, PinName rx, int baud);
  void setHeaders(uint8_t firstHeader, uint8_t secondHeader);
  void setHeaders(uint8_t headers[]);

  void startReceive(uint16_t dataSize);
  void getData(uint8_t data_[]);
  void sendData(uint8_t data_[], uint16_t length);

 private:
  void receiveLoop();
  void receiveByte();
  void checkData();
  uint8_t* buffer;
  uint8_t bufferPoint;
  uint8_t receivedBytes;

  uint8_t header[2];
  uint16_t bufferSize;
  uint8_t* data;
};

#endif