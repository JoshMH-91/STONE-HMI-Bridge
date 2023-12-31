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

#ifndef StoneHmiBridge_h
#define StoneHmiBridge_h

#include <Arduino.h>

class StoneHmiBridge {

public:

  StoneHmiBridge();

  /**
  * This function processes data from the STONE HMI through a serial connection.
  * @param serialPort Name of the serial port used in the code for processing data.
  * @param cmd Holds the command being received from the STONE HMI.
  * @param data Holds the data value being received from the STONE HMI.
  */


  bool parseData(Stream& serial, String& cmd, String& data);

  /**
  * This function allows you to update a label on the HMI with a given text or value.
  *
  * @param label The name of the label to update.
  * @param type The type of the update. It can be "text" or "value".
  * @param value The new value or text for the label.
  *
  * @example
  * update_label("MyLabel", "text", "Hello World");
  * example serial output:  ST<{"cmd_code":"set_text","type":"label","widget":"label1","text":"Hello, World!"}>ET
  */

  template <typename T>
  void update_label(Stream& serial, const String& label, const String& type, const T& value) {
    String updateLabel = "ST<{\"cmd_code\":\"set_" + type + "\",\"type\":\"label\",\"widget\":\"";
    updateLabel += label;
    if (type == "text") {
      updateLabel += "\",\"text\":\"" + String(value) + "\"";
    }
    else if (type == "value") {
      updateLabel += "\",\"value\":" + String(value);
    }
    updateLabel += "}>ET";
    serial.println(updateLabel);
  } 

  /**
  * This function sets the text of a multi-line edit widget on the HMI.
  *
  * @param widget The name of the multi-line edit widget to update.
  * @param text The new text to set.
  *
  * @example
  * update_mledit_text("MyWidget", "Example text");
  * example serial output:  ST<{"cmd_code":"set_text","type":"mledit","widget":"mledit1","text":"This is a multi-line text."}>ET
  */

  template <typename T>
  void update_mledit_text(Stream& serial, const String& widget, const T& text) {
    String updateMlEdit = "ST<{\"cmd_code\":\"set_text\",\"type\":\"mledit\",\"widget\":\"";
    updateMlEdit += widget;
    updateMlEdit += "\",\"text\":\"";
    updateMlEdit += String(text);
    updateMlEdit += "\"}>ET";
    serial.println(updateMlEdit);
  }

  /**
  * This function updates a graph on the HMI with a new data point.
  *
  * @param lineSeries The name of the line series to update.
  * @param value The new data point.
  *
  * @example
  * update_graph("MyLineSeries", 42);
  * example serial output:  ST<{"cmd_code":"set_value","type":"line_series","widget":"lineSeries1","mode":"push","value":42}>ET
  */

  template <typename T>
  void update_graph(Stream& serial, const String& lineSeries, const T& value) {
    String graphCode = "ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"";
    graphCode += lineSeries;
    graphCode += "\",\"mode\":\"push\",\"value\":";
    graphCode += String(value);
    graphCode += "}>ET";
    serial.println(graphCode);
  }

  /**
  * This function updates the range of a graph widget on an HMI by sending a formatted command through a serial connection.
  * @param serial The serial stream for sending the command
  * @param axis The type of axis to update (x_axis or y_axis)
  * @param axisName The name of the widget representing the axis
  * @param min The minimum value of the chart range
  * @param max The maximum value of the chart range
  * The function constructs a JSON-like command string and sends it via the serial connection.
  */

  template <typename T>
  void update_graph_range(Stream& serial, const String& axis, const String& axisName, const T& min, const T& max) {
      String command = "ST<{\"cmd_code\":\"set_range\",\"type\":\"";
      command += axis;
      command += "\",\"widget\":\"";
      command += axisName;
      command += "\",\"min\":";
      command += min;
      command += ",\"max\":";
      command += max;
      command += "}ET";
      serial.println(command);
  }

  /**
  * This function updates a graph on the HMI by sending a formatted command through a serial connection.
  * @param serial The serial stream for sending the command
  * @param axis The type of axis to update (x_axis or y_axis)
  * @param axisName The name of the widget representing the axis
  * @param data The data points to update on the axis. (example:  "0,1,2,3,4,5,6,7,8,9,10")
  * example function call:  myHMI.update_graph_data(mySerial, "x_axis", "x_axis1", "0,1,2,3,4,5,6,7,8,9,10");
  */

  void update_graph_data(Stream& serial, const String& axis, const String& axisName, String& data){
    String command = "ST<{\"cmd_code\":\"set_data\",\"type\":\"";
    command += axis;
    command += "\",\"widget\":\"";
    command += axisName;
    command += "\",\"data\":\"[";
    command += data;
    command += "]\"}>ET";
    serial.println(command);
  }

  /**
  * This function sets the brightness of the HMI system.
  *
  * @param value The new brightness level.
  *
  * @example
  * update_brightness(50); // Set maximum brightness
  * example serial output:  ST<{"cmd_code":"set_brightness","type":"system","brightness":75}>ET
  */

  template <typename T>
  void update_brightness(Stream& serial, const T& value) {
    String updateBrightness = "ST<{\"cmd_code\":\"set_brightness\",\"type\":\"system\",\"brightness\":";
    updateBrightness += String(value);
    updateBrightness += "}>ET";
    serial.println(updateBrightness);
  }

  /**
  * This function sets the volume or mutes/unmutes the HMI system.
  *
  * @param command The command to execute. It can be "set_vol", "set_vol_inc", "set_vol_dec", or "set_mute".
  * @param value The new volume level, or true/false for the "set_mute" command.
  *
  * @example
  * update_volume("set_vol", 20); // Set volume level to 20
  * update_volume("set_mute", true); // Mute the system
  * example serial output
  * Output 1:  ST<{"cmd_code":"set_vol","type":"system","vol":50}>ET
  * Output 2:  ST<{"cmd_code":"set_vol_inc","type":"system","step":2}>ET
  * Output 3:  ST<{"cmd_code":"set_vol_dec","type":"system","step":1}>ET
  * Output 4:  ST<{"cmd_code":"set_mute","type":"system","mute":true}>ET
  */

  template <typename T>
  void update_volume(Stream& serial, const char* command, const T& value) {
    String updateVolume;

    if (strcmp(command, "set_vol") == 0) {
      updateVolume = "ST<{\"cmd_code\":\"set_vol\",\"type\":\"system\",\"vol\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_vol_inc") == 0) {
      updateVolume = "ST<{\"cmd_code\":\"set_vol_inc\",\"type\":\"system\",\"step\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_vol_dec") == 0) {
      updateVolume = "ST<{\"cmd_code\":\"set_vol_dec\",\"type\":\"system\",\"step\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_mute") == 0) {
      updateVolume = "ST<{\"cmd_code\":\"set_mute\",\"type\":\"system\",\"mute\":" + String(value ? "true" : "false") + "}>ET";
    }

    serial.println(updateVolume);
  }

  /**
  * This function updates the maximum value of a progress bar on the HMI.
  *
  * @param value set_max or set_value
  * @param widget The name of the progress circle widget to update.
  * @param set_value The new maximum value or progress circles current progress value.
  * 
  * @example
  * update_progress_bar("set_max, "MyProgressBar", 100);
  * update_progress_bar("set_value, "MyProgressBar", 100);
  * example serial output:  ST<{"cmd_code":"set_value","type":"progress_bar","widget":"progressBar1","value":75}>ET
  * example serial output:  ST<{"cmd_code":"set_max","type":"progress_bar","widget":"progressBar1","value":75}>ET
  */

  void update_progress_bar(Stream& serial, const String& value, const String& widget, int set_value){
    String command = "ST<{\"cmd_code\":\"";
    command += "\",\"type\":\"progress_bar\",\"widget\":\"";
    command += widget;
    command += "\"";
      if (value == "set_value") {
        command += ",\"value\":";
      }
      else if (value == "set_max") {
        command += ",\"max\":";
      }
      command += String(set_value);
      command += "}>ET";

      serial.println(command);
  }

  /**
  * This function updates the maximum value of a progress circle on the HMI.
  *
  * @param value set_max or set_value
  * @param widget The name of the progress circle widget to update.
  * @param set_value The new maximum value or progress circles current progress value.
  * 
  * @example
  * update_progress_circle("set_max, "MyProgressCircle", 100);
  * update_progress_circle("set_value, "MyProgressCircle", 100);
  * example serial output:  ST<{"cmd_code":"set_value","type":"progress_circle","widget":"progressCircle1","value":50}>ET
  * example serial output:  ST<{"cmd_code":"set_max","type":"progress_circle","widget":"progressCircle1","value":50}>ET
  */

  void update_progress_circle(Stream& serial, const String& value, const String& widget, int set_value) {
    String command = "ST<{\"cmd_code\":\"";
    command += value;
    command += "\",\"type\":\"progress_circle\",\"widget\":\"";
    command += widget;
    command += "\"";
    if (value == "set_value") {
      command += ",\"value\":";
    }
    else if (value == "set_max") {
      command += ",\"max\":";
    }
    command += String(set_value);
    command += "}>ET";

    serial.println(command);
  }

  /**
  * This function generates a command string to set the state of a radio button widget on the HMI.
  *
  * @param widget The name of the radio button widget to update.
  * @param state The new state of the radio button (true for selected, false for unselected).
  * 
  * @return The command string to be sent via serial communication to the HMI.
  *
  * @example
  * // Set the radio button named "MyRadioButton" to the selected state
  * String command = radio_button("MyRadioButton", true);
  * Serial.println(command);
  *
  * @note The widget name should match the name of the radio button widget on the HMI.
  * example serial output:  <ST{"cmd_code":"set_value","type":"radio_button","widget":"radioButton1","value":true}>ET
  */

  void update_radio_button(Stream& serial, const String& widget, bool state) {
      String command = "<ST{\"cmd_code\":\"set_value\",\"type\":\"radio_button\",\"widget\":\"";
      command += widget;
      command += "\",\"value\":";
      command += String(state ? "true" : "false");
      command += "}>ET";

      serial.println(command);
  }

  /**
  * example serial output:  ST{"cmd_code":"set_value","type":"switch","widget":"switch1","value":true}>ET
  */

  void  update_switch(Stream& serial, const String& widget, bool state){
    String command = "ST{\"cmd_code\":\"set_value\",\"type\":\"switch\",\"widget\":\"";
    command += widget;
    command += "\",\"value\":";
    command += String(state ? "true" : "false");
    command += "}>ET";

    serial.println(command);
  }

  /**
  * example serial output:  <ST{"cmd_code":"set_value","type":"check_button","widget":"checkButton1","value":true}>ET
  */

  void update_check_button(Stream& serial, const String& widget, bool state){
    String command = "<ST{\"cmd_code\":\"set_value\",\"type\":\"check_button\",\"widget\":\"";
    command += widget;
    command += "\",\"value\":";
    command += String(state ? "true" : "false");
    command += "}>ET";

    serial.println(command);
  }

};

#endif
   
