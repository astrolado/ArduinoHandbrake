# ArduinoHandbrake
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Want a Handbrake for a racing sim, but you only have an Arduino Uno, a potentiometer, and a 3D Printer?
That's the problem I had and was able to solve using this 3D Model made by HaraDaya on Thingiverse 

https://www.thingiverse.com/thing:2915581

Additionally, I created some code because unfortunately, they all used Arduino microcontrollers like the Arduino Teensy, which uses different code that the UNO cannot run. 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 1 — Put the Uno into DFU mode

Unplug USB

Short RESET ↔ GND on the USB-side ICSP header (the 6-pin header near the USB port)

Keep it shorted

Plug USB in

Wait 2–3 seconds

Release

In Device Manager you’ll see something like ATmega16U2 / USB Input Device / DFU.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 2 — Install the DFU driver (one-time)

dfu-programmer needs a libusb driver.

Run Zadig as Administrator

Options → ✅ List All Devices

Select the DFU device (often “USB Input Device” or “ATmega16U2”)

Driver: choose libusb-win32

Click Replace Driver

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 3 — Install dfu-programmer

Download the Windows release ZIP for dfu-programmer 1.1.0 (x64), extract it anywhere, e.g.:

C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\

In PowerShell, run it like:

& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" --version

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 4 — Restore Arduino COM port (so you can upload the sketch)

Put the Uno into DFU mode, then flash the stock Arduino USB-serial firmware:

Arduino usbserial HEX path (typical):

C:\Users\<YOU>\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\firmwares\atmegaxxu2\arduino-usbserial\Arduino-usbserial-atmega16u2-Uno-Rev3.hex

Flash it:

& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 erase
& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 flash "C:\Users\<YOU>\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\firmwares\atmegaxxu2\arduino-usbserial\Arduino-usbserial-atmega16u2-Uno-Rev3.hex"
& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 reset

Unplug/replug the Uno. You should now see Arduino Uno (COMx) in Device Manager.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 5 — Upload the handbrake sketch

Use the handbrake file in the repository.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 6 — Flash UnoJoy firmware (final joystick mode)

Put Uno into DFU mode again, then flash UnoJoy.hex:

& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 erase
& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 flash "PATH\TO\UnoJoy.hex"
& "C:\Users\<YOU>\Downloads\dfu-programmer-x64-1.1.0\dfu-programmer.exe" atmega16u2 reset

Unplug/replug.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Step 7 — Test + bind in game

Run:

Win + R → joy.cpl

Open Properties, move the handbrake.

Then bind it in Assetto Corsa as the Handbrake Axis.

UnoJoy library install (Arduino IDE)

Copy the UnoJoy library folder (the one containing UnoJoy.h) into:

C:\Users\<YOU>\Documents\Arduino\libraries\UnoJoy\

Restart Arduino IDE.
