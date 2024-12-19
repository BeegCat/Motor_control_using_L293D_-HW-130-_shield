Thanks to the Discord user [Gotbread#2417](https://github.com/Gotbread/) (and others as well, from the embedded systems discord server) for their kind help with the code and technical guidance throughout the project.

As of the time of writing this readme, there are little to no documented ways to use an L293D shield with an esp32, although there is an article on how to use an L293D ic with esp32, and a github page that uses nodemcu and esp8266 with the shield. Every other article, video or forum have used the `AFmotor.h` library and/or just the IC.
This is a simple project that aims to run 1 motor using an ESP32 (ESP-wroom-32) and a HW-130 motor driver shield (L293D motor driver). Functionality for more motors can be included in the code.
The previous solution forced users to include the infamous `AFmotor.h` library, which unfortunately, does **NOT** work with ESP32 due to differences in hardware.
Our project does **NOT** use any predefined library. 

As of the time of writing this readme, there are little to no documented ways to use an L293D shield with an esp32, although there is an article on how to use an L293D ic with esp32, and a github page that uses nodemcu and esp8266 with the shield. Every other article, video or forum have used the `AFmotor.h` library.

**---IMPORTANT---**
- This shield is intended to be used as a "plug-and-play" shield for Arduino boards or other 5v-logic microcontrollers. When using with a different board, be careful with how you power the circuit. The shield was designed to use the Arduino Mega's 5v pin to power the shield. Esp32 might not be able to sufficiently power the board from its on board 5v pin, especially with motors under load.
- We also do **NOT** recommend to use a 9v battery in any case, owing to their high internal resistance and low capacity. The motor might draw more current than the capacity of the battery, draining it in no time.
- We used an external power supply, which is a 5v 2A(max) charging brick, and thus, the jumper on the shield was **__REMOVED__**.
- The motors used here were geared **DC motors**, voltage rating unknown. You might want to experiment the motor's performance with capacitors connected at the motor's terminals.
- Please verify with the datasheets for the ICs in your shield. Our shield is a cheap chinese knock-off but we referred the [official Adafruit motor shield](https://github.com/adafruit/Adafruit-Motor-Shield-library) due to the stark similarities involved with the hardware.
- It is important to connect the pin labelled as `5v` at the bottom of the shield. This goes to the Vcc of the shift register.
- We cannot guarantee the proper functioning of the circuit if you opt to use the esp32's on board 5v pin, and personally I do not recommend to use it for such an application that could be current intensive.
- Make sure to use a power supply that can deliver enough amperage if you are using many motors at once, although the L293D's max tolerance is ~1A per IC.
- The shield should work fine with the 3.3v logic levels of esp32, if it doesn't, cross check all your connections.
- The code is written according to the connections made in the below diagram.

![circuit diagram](https://github.com/user-attachments/assets/91a676e2-481f-4c19-b41e-186fa66f2386)
