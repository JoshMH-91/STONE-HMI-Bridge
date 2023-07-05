# Stone-HMI-Bridge-Library
This library provides simplified functions for sending JSON commands to a STONE HMI and parsing data.
<br/><br/>
🚧 This Library and page is under construction.
<br/>
<h2>📚 Library Functions currenlty supported</h2>
These functions only return the JSON string you must send them through a serial print command to your HMI.
<br/>
<br/>
Make sure to include libarary and initialize in your code with these commands:<br/>
<code>#include "StoneHmiBridge.h"</code>
<br/>
<code>StoneHmiBridge myHMI;</code>
<br/>
<br/>
Please ensure that you replace the placeholder "mySerial" with the appropriate name of your serial setup in order to establish communication with the STONE HMI.
<br/>
<br/>
<h2>•  🖥️ Parse incoming command and data</h2>
&emsp; example function call:<br/>
&emsp; <code>myHMI.parseData(mySerial, cmd, data)</code> (this code will return both the cmd and data values)</br>
<h2>•  🏷️ Update Label as value or text</h2>
&emsp; example function call:<br/>
&emsp; <code>myHMI.update_label(mySerial, "label1", "value", 100);</code>
<br/>
&emsp; <code>myHMI.update_label(mySerial, "label1", "text", "your text here");</code>
<br/>
<br/>
&emsp; example serial output:
<br/>
&emsp; <code>ST<{"cmd_code":"set_text","type":"label","widget":"label1","text":"Hello, World!"}>ET</code><br/>
<br/>
<h2>•  📜 Update Multi-line text</h2>
&emsp; example function call:<br/>
&emsp; <code>update_mledit_text(mySerial, "MyWidget", "Example text");</code>
<br/>
<br/>
&emsp; example serial output:
<br/>
&emsp; <code>ST<{"cmd_code":"set_text","type":"mledit","widget":"mledit1","text":"This is a multi-line text."}>ET</code><br/>
<br/>
<h2>•  📈 Update Graph by pushing data</h2>
&emsp; example function call:<br/>
&emsp; <code>update_graph(mySerial, "MyLineSeries", 42);</code>
<br/>
<br/>
&emsp; example serial output:
<br/>
&emsp; <code>ST<{"cmd_code":"set_value","type":"line_series","widget":"lineSeries1","mode":"push","value":42}>ET</code><br/>
<br/>
<h2>•  📈 Update Graph Data</h2>
&emsp; example function call:<br/>
&emsp; <code>update_graph_data(mySerial, "x_axis", "x_axis1", "0,1,2,3,4,5,6,7,8,9,10");</code> (can be x or y axis)
<br/>
<br/>
<h2>•  📈 Update Graph Range</h2>
&emsp; example function call:<br/>
&emsp; <code>update_graph_data(mySerial, "x_axis", "x_axis1", 0, 100)</code> (can be x or y axis)
<br/>
<br/>
<h2>•  💡 Update Screen Brightness</h2>
&emsp; example function call:<br/>
&emsp; <code>update_brightness(mySerial, 75);</code>
<br/>
<br/>
<h2>•  🔊 Update Volume</h2>
&emsp; example function call:<br/>
&emsp; <code>update_volume(mySerial, "set_vol", 20);</code> (sets volume to 20%)<br/>
&emsp; <code>update_volume(mySerial, "set_vol_inc", 5);</code> (increases volume by 5%)<br/>
&emsp; <code>update_volume(mySerial, "set_vol_dec", 5);</code> (decreases volume by 5%)<br/>
&emsp; <code>update_volume(mySerial, "set_mute", true);</code> (mutes volume can be true or false)
<h2>•  🔘 Update Radio Button</h2>
&emsp; example function call:<br/>
&emsp; <code>update_radio_button(mySerial, "MyRadioButton", true);</code> (sets radio button state to true or false)<br/>
<h2>•  🎚️ Update Switch</h2>
&emsp; example function call:<br/>
&emsp; <code>update_switch(mySerial, "MySwitch", true);</code> (sets switch state to true or false)<br/>
<h2>•  ✅ Update Check Button</h2>
&emsp; example function call:<br/>
&emsp; <code>update_check_button(mySerial, "MyCheckButton", true);</code> (sets check button state to true or false)<br/>
<h2>•  ➖ Update Progress Bar</h2>
&emsp; example function call:<br/>
&emsp; <code>update_progress_bar(mySerial, "set_max", "MyProgressBar", 100);</code> (set max value of progress bar)<br/>
&emsp; <code>update_progress_bar(mySerial, "set_value", "MyProgressBar", 100);</code> (set current value of progress bar)<br/>
<h2>•  🕛 Update Progress Circle</h2>
&emsp; example function call:<br/>
&emsp; <code>update_progress_circle(mySerial, "set_max", "MyProgressCircle", 100);</code> (set max value of progress circle)<br/>
&emsp; <code>update_progress_circle(mySerial, "set_value", "MyProgressCircle", 100);</code> (set current value of progress circle)<br/>
<br/>
<br/>
<a href="https://www.buymeacoffee.com/JoshMH91" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="50" width="200"></a>
