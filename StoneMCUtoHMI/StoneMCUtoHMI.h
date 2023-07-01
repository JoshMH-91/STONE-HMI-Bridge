#ifndef StoneMCUtoHMI_h
#define StoneMCUtoHMI_h

#include <Arduino.h>

class StoneMCUtoHMI {
public:

  /**
  * This function allows you to update a label on the HMI with a given text or value.
  *
  * @param label The name of the label to update.
  * @param type The type of the update. It can be "text" or "value".
  * @param value The new value or text for the label.
  *
  * @example
  * update_label("MyLabel", "text", "Hello World");
  */

  template <typename T>
  String update_label(const String& label, const String& type, const T& value) {
    String updateLabel = "ST<{\"cmd_code\":\"set_" + type + "\",\"type\":\"label\",\"widget\":\"";
    updateLabel += label;
    if (type == "text") {
      updateLabel += "\",\"text\":\"" + String(value) + "\"";
    }
    else if (type == "value") {
      updateLabel += "\",\"value\":" + String(value);
    }
    updateLabel += "}>ET";
    return updateLabel;
  } 

  /**
  * This function sets the text of a multi-line edit widget on the HMI.
  *
  * @param widget The name of the multi-line edit widget to update.
  * @param text The new text to set.
  *
  * @example
  * update_mledit_text("MyWidget", "Example text");
  */

  template <typename T>
  String update_mledit_text(const String& widget, const T& text) {
    String updateMlEdit = "ST<{\"cmd_code\":\"set_text\",\"type\":\"mledit\",\"widget\":\"";
    updateMlEdit += widget;
    updateMlEdit += "\",\"text\":\"";
    updateMlEdit += String(text);
    updateMlEdit += "\"}>ET";
    return updateMlEdit;
  }

  /**
  * This function updates a graph on the HMI with a new data point.
  *
  * @param lineSeries The name of the line series to update.
  * @param value The new data point.
  *
  * @example
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

  /**
  * This function sets the brightness of the HMI system.
  *
  * @param value The new brightness level.
  *
  * @example
  * update_brightness(50); // Set maximum brightness
  */

  template <typename T>
  String update_brightness(const T& value) {
    String updateBrightness = "ST<{\"cmd_code\":\"set_brightness\",\"type\":\"system\",\"brightness\":";
    updateBrightness += String(value);
    updateBrightness += "}>ET";
    return updateBrightness;
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
  */

  template <typename T>
  String update_volume(const char* command, const T& value) {
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

    return updateVolume;
  }

  /**
  * This function updates the maximum value of a progress circle on the HMI.
  *
  * @param widget The name of the progress circle widget to update.
  * @param max The new maximum value.
  * 
  * @example
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
  */

  String update_radio_button(const String& widget, bool state){
    String command = "<ST{\"cmd_code\":\"set_value\",\"type\":\"radio_button\",\"widget\":\"";
    command += widget;
    command += "\",\"value\":";
    command += state;
    command += "}>ET";
    
    return command;
  }

  String update_switch(const String& widget, bool state){
    String command = <"ST{\"cmd_code\":\"set_value\",\"type\":\"switch\",\"widget\":\"";
    command += widget;
    command += "\",\"value\":"
    command += state;
    command += "}>ET";

    return command;
  }

};

#endif
   
