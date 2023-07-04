# Stone-HMI-Bridge-Library
This library provides simplified functions for sending JSON commands to a STONE HMI and parsing data.
<br/><br/>
🚧 This Library and page is under construction and only includes basic functionality.
<br/>
<h2>📚 Library Functions currenlty supported</h2>
These functions only return the JSON string you must send them through a serial print command to your HMI.
<br/>
<br/>
Make sure to include libarary and initialize in your code with these commands:<br/>
<code>#include "StoneMhiBridge.h"</code>
<br/>
<code>StoneHmiBridge myHMI;</code>
<br/>
<br/>
<h2>•  🖥️ Parse incoming command and data</h2>
&emsp; example function call:<br/>
&emsp; <code>myHMI.parseData(mySerial, cmd, data)</code></br>
<h2>•  🏷️ Update Label as value or text</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "value", 100));</code>
<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "text", "your text here"));</code>
<br/>
<br/>
<h2>•  📜 Update Multi-line text</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_mledit_text("MyWidget", "Example text"));</code>
<br/>
<br/>
<h2>•  📈 Update Graph by pushing data</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_graph("MyLineSeries", 42));</code>
<br/>
<br/>
<h2>•  💡 Update Screen Brightness</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_brightness(75));</code>
<br/>
<br/>
<h2>•  🔊 Update Volume</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_volume("set_vol", 20));</code> (sets volume to 20%)<br/>
&emsp; <code>mySerial.println(update_volume("set_vol_inc", 5));</code> (increases volume by 5%)<br/>
&emsp; <code>mySerial.println(update_volume("set_vol_dec", 5));</code> (decreases volume by 5%)<br/>
&emsp; <code>mySerial.println(update_volume("set_mute", true));</code> (mutes volume can be true or false)
<h2>•  🔘 Update Radio Button</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_radio_button("MyRadioButton", true));</code> (sets radio button state to true or false)<br/>
<h2>•  🎚️ Update Switch</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_switch("MySwitch", true));</code> (sets switch state to true or false)<br/>
<h2>•  ✅ Update Check Button</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_check_button("MyCheckButton", true));</code> (sets check button state to true or false)<br/>
<h2>•  ➖ Update Progress Bar</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_progress_bar("set_max", "MyProgressBar", 100);</code> (set max value of progress bar)<br/>
&emsp; <code>mySerial.println(update_progress_bar("set_value", "MyProgressBar", 100);</code> (set current value of progress bar)<br/>
<h2>•  🕛 Update Progress Circle</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_progress_circle("set_max", "MyProgressCircle", 100);</code> (set max value of progress circle)<br/>
&emsp; <code>mySerial.println(update_progress_circle("set_value", "MyProgressCircle", 100);</code> (set current value of progress circle)<br/>
<br/>
<br/>
<a href="https://www.buymeacoffee.com/JoshMH91" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="50" width="200"></a>
