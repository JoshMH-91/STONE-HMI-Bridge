#ifndef StoneMCUtoHMI_h
#define StoneMCUtoHMI_h

#include <Arduino.h>

class StoneMCUtoHMI {
public:

  /* This function allows you to update a label on the HMI with a given text or value.
  * Parameters:
  * - label: The name of the label to update.
  * - type: The type of the update, it can be "text" or "value".
  * - value: The new value or text for the label.
  * 
  * Example:
  * update_label("MyLabel", "text", "Hello World");
  */

  template <typename T>
String update_label(const String& label, const String& type, const T& value) {
    String labelCode = "ST<{\"cmd_code\":\"set_" + type + "\",\"type\":\"label\",\"widget\":\"";
    labelCode += label;

    if (type == "text") {
      labelCode += "\",\"text\":\"" + String(value) + "\"";
    }
    else if (type == "value") {
      labelCode += "\",\"value\":" + String(value);
    }

    labelCode += "}>ET";
    return labelCode;
}


  /* This function sets the text of a multi-line edit widget on the HMI.
  * Parameters:
  * - widget: The name of the multi-line edit widget to update.
  * - text: The new text to set.
  * 
  * Example:
  * set_mledit_text("MyWidget", "Example text");
  */

  template <typename T>
  String set_mledit_text(const String& widget, const T& text) {
    String setMlEdit = "ST<{\"cmd_code\":\"set_text\",\"type\":\"mledit\",\"widget\":\"";
    setMlEdit += widget;
    setMlEdit += "\",\"text\":\"";
    setMlEdit += String(text);
    setMlEdit += "\"}>ET";
    return setMlEdit;
  }

  /* This function updates a graph on the HMI with a new data point.
  * Parameters:
  * - lineSeries: The name of the line series to update.
  * - value: The new data point.
  * 
  * Example:
  * update_graph("MyLineSeries", 42);
  */

  template <typename T>
  String update_graph(const String& lineSeries, const T& value) {
    String graphCode = "ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"";
    graphCode += lineSeries;
    graphCode += "\",\"mode\":\"push\",\"value\":";
    graphCode += String(value);
    graphCode += "}>ET";
    return graphCode;
  }

  /* This function sets the brightness of the HMI system.
  * Parameters:
  * - value: The new brightness level.
  * 
  * Example:
  * set_brightness(255); // maximum brightness
  */

  template <typename T>
  String set_brightness(const T& value) {
    String setBrightness = "ST<{\"cmd_code\":\"set_brightness\",\"type\":\"system\",\"brightness\":";
    setBrightness += String(value);
    setBrightness += "}>ET";
    return setBrightness;
  }

  /* This function sets the volume or mutes/unmutes the HMI system.
  * Parameters:
  * - command: The command to execute, it can be "set_vol", "set_vol_inc", "set_vol_dec", or "set_mute".
  * - value: The new volume level, or true/false for the "set_mute" command.
  * 
  * Example:
  * set_volume("set_vol", 20); // set volume level to 20
  * set_volume("set_mute", true); // mute the system
  */

  template <typename T>
  String set_volume(const char* command, const T& value) {
    String setVolume;

    if (strcmp(command, "set_vol") == 0) {
      setVolume = "ST<{\"cmd_code\":\"set_vol\",\"type\":\"system\",\"vol\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_vol_inc") == 0) {
      setVolume = "ST<{\"cmd_code\":\"set_vol_inc\",\"type\":\"system\",\"step\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_vol_dec") == 0) {
      setVolume = "ST<{\"cmd_code\":\"set_vol_dec\",\"type\":\"system\",\"step\":" + String(value) + "}>ET";
    }
    else if (strcmp(command, "set_mute") == 0) {
      setVolume = "ST<{\"cmd_code\":\"set_mute\",\"type\":\"system\",\"mute\":" + String(value ? "true" : "false") + "}>ET";
    }

    return setVolume;
  }

  /* This function updates the maximum value of a progress circle on the HMI.
  * Parameters:
  * - widget: The name of the progress circle widget to update.
  * - max: The new maximum value.
  * 
  * Example:
  * update_progress_circle("MyProgressCircle", 100);
  */

  String update_progress_circle(const String& widget, int max) {
    String command = "ST<{\"cmd_code\":\"set_max\",\"type\":\"progress_circle\",\"widget\":\"";
    command += widget;
    command += "\",\"max\":";
    command += String(max);
    command += "}>ET";
    return command;
  }
};

#endif
   
