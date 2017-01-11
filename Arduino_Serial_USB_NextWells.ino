/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example shows how to use ordinary Arduino Serial
 * to connect your project to Blynk.
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************
 *            USB HOWTO: http://tiny.cc/BlynkUSB
 **************************************************************/

 
 /***************************************************************
 * This part of the code was used in a test project under Windows and Arduino UNO with Luis Castillo and Yoimer Román from NextWells company. Venezuela-USA.
 * Instrucctions:
 * - Get on Google Play Store or IOS Store and Download blynk. After installing, sign up.
   - On your browser from you PC type http://docs.blynk.cc/. Check out the "Intro" section. Read this part carefully.
   - We will need the blink libraries in our Arduino IDE in order stablish a connection with the Cloud Blynk Service. To do that; get
      the lastest version of the libraries from here. https://github.com/blynkkk/blynk-library/releases/tag/v0.4.3 (Blynk_Release_v0.4.3.zip)
      At the time this document was made, the lastest release was v0.4.3. Yours may vary.
   - In case you've forgotten how to install libraries in Arduino IDE;
      check this link on "Manual installation" https://www.arduino.cc/en/guide/libraries
     After installing the Blink libraries, open an empty Scketch from Arduino IDE.
     Copy and paste the ***NextWells-BLINK-ARDUINO UNO******* code Upload it to the Arduino UNO board.(This code is above)
 
   - After succesfully uploading the code,extract the Blynk_Release_v0.4.3.zip files on C:\ directory.
     This is for running the script which will make us get online with the Cloud Blynk Service.
   - Run the blynk-ser.bat script. In order to do that , open cmd promt and get on this path C:\Blynk_Release_v0.4.3\libraries\Blynk\scripts>
     Issue this command : blynk-ser.bat -c COM3 (In your case check your Arduino COM port) and press Enter, Enter , Enter (Yes, 3 times)
     If there is Internet Connection and everything is OK, you should see something similar to this on the promt console:

     Connecting device at COM3 to blynk-cloud.com:8442...
     OpenC0C("\\.\COM3", baud=9600, data=8, parity=no, stop=1) - OK
     Connect("blynk-cloud.com", "8442") - OK
     InOut() START
     DSR is OFF
   
-   Now you should be able to play with the GPIO from the Blink app. For testing try Turning ON and Turning OFF the LED on PIN 13 using a botton.

 **************************************************************/

/***************************************NextWells-BLINK-ARDUINO UNO****************************************************/

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

// Type here your AuthToken. Please keep the quotes.
//It should be something like "369505e836ed435abe9c7e9db2db5471", not 369505e836ed435abe9c7e9db2db9090

//char auth[] = "Your AuthToken";

void setup()
{
  // Debug console
  DebugSerial.begin(9600);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
}