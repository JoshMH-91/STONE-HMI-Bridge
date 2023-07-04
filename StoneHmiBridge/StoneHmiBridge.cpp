/***********************************************************************************
* MIT License
* 
* Copyright (c) 2023 JoshMH-91
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
***********************************************************************************/

#include "StoneHmiBridge.h"

StoneHmiBridge::StoneHmiBridge() {
}

bool StoneHmiBridge::parseData(Stream& serial, String& cmd, String& data) {
  byte buffer[256];
  size_t bytesRead = serial.readBytes(buffer, 256);

  if (bytesRead > 0) {


    // Print the bytes in hexadecimal format without the 0x prefix
    for (int i = 3; i < 5; i++) {
        if (String(buffer[i], HEX) == "1"){
            cmd += "0";
        }
      cmd += String(buffer[i], HEX);
    }

    int dataLength = bytesRead - 6;

    // Print the bytes in hexadecimal format without the 0x prefix
    for (int i = 7; i < dataLength; i++) {
      char character = char(buffer[i]);
      data += character;
    }

    return cmd;
    return data;
  }
}