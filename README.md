# Stone-MCU-to-HMI-Library
Library for sending JSON commands to a STONE HMI with simplified functions
<br/><br/>
🚧 This Library and page is under construction and only includes basic functionality.
<br/>
<h3>📚 Library Functions currenlty supported</h3>
These functions only return the JSON string you must send them through a serial print command to your HMI.
<br/>
<br/>
•  Update label as value or text<br/>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "value", 100));</code>
<br/>
&emsp; <code>mySerial.println(myHMI.update_label("label1", "text", "your text here"));</code>
<br/>
<br/>
•  Update multi-line text<br/>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(set_mledit_text("MyWidget", "Example text"));</code>
<br/>
<br/>
•  Update graph by pushing data<br/>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(update_graph("MyLineSeries", 42));</code>
<br/>
<br/>
•  Update screen brightness<br/>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(set_brightness(75));</code>
<br/>
<br/>
•  Update volume <br/>
&emsp; example function call:<br/>
&emsp; <code>mySerial.println(set_volume("set_vol", 20));</code> (sets volume to 20%)<br/>
&emsp; <code>mySerial.println(set_volume("set_vol_inc", 5));</code> (increases volume by 5%)<br/>
&emsp; <code>mySerial.println(set_volume("set_vol_dec", 5));</code> (decreases volume by 5%)<br/>
&emsp; <code>mySerial.println(set_volume("set_mute", true));</code> (mutes volume can be true or false)
<br/>
<br/>
<a href="https://www.buymeacoffee.com/JoshMH91" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="50" width="200"></a>
