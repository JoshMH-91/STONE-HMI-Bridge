# Stone-MCU-to-HMI-Library
Library for sending JSON commands to a STONE HMI with simplified functions
<br/><br/>
🚧 This Library and page is under construction and only includes basic functionality.
<br/>
<h2>📚 Library Functions currenlty supported</h2>
These functions only return the JSON string you must send them through a serial print command to your HMI.
<br/>
<br/>
Make sure to include libarary and initialize in your code with these commands:<br/>
<code>#include "StoneMCUtoHMI.h"</code>
<br/>
<code>StoneMCUtoHMI myHMI;</code>
<br/>
<br/>
<h2>•  Update Label as value or text</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "value", 100));</code>
<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "text", "your text here"));</code>
<br/>
<br/>
<h2>•  Update Multi-line text</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_mledit_text("MyWidget", "Example text"));</code>
<br/>
<br/>
<h2>•  Update Graph by pushing data</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_graph("MyLineSeries", 42));</code>
<br/>
<br/>
<h2>•  Update Screen Brightness</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_brightness(75));</code>
<br/>
<br/>
<h2>•  Update Volume</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_volume("set_vol", 20));</code> (sets volume to 20%)<br/>
&emsp; <code>mySerial.println(update_volume("set_vol_inc", 5));</code> (increases volume by 5%)<br/>
&emsp; <code>mySerial.println(update_volume("set_vol_dec", 5));</code> (decreases volume by 5%)<br/>
&emsp; <code>mySerial.println(update_volume("set_mute", true));</code> (mutes volume can be true or false)
<h2>•  Update Radio Button</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_radio_button("MyRadioButton", true));</code> (sets radio button state to true or false)<br/>
<h2>•  Update Switch</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_switch("MySwitch", true));</code> (sets switch state to true or false)<br/>
<h2>•  Update Check Button</h2>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_check_button("MyCheckButton", true));</code> (sets check button state to true or false)<br/>
<br/>
<br/>
<a href="https://www.buymeacoffee.com/JoshMH91" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="50" width="200"></a>
