Thanks to Discord user @Gotbread#2417 (and others as well, from the embedded systems discord server) for their kind help with the code and technical guidance throughout the project.

This is a simple project that aims to run 1 motor using an ESP32 (ESP-wroom-32) and a HW-130 motor driver shield (L293D motor driver). 
The existing solution forced users to include the infamous `AFmotor.h` library, which unfortunately, does **NOT** work with ESP32 due to differences in hardware.
Our project does **NOT** use any predefined library. 

**---IMPORTANT---**
- We are using an external power supply, which is a 5v 2A(max) charging brick, and thus the jumper on the shield was **__REMOVED__**.
- The motors used are geared DC motors, voltage rating unknown.
- Please verify with the datasheets for the ICs in your shield. Our shield is a cheap chinese knock-off but we referred the [official Adafruit motor shield][https://github.com/adafruit/Adafruit-Motor-Shield-library] due to the stark similarities involved with the hardware.
- It is important to connect the pin labelled as `5v` at the bottom of the shield. This goes to the Vcc of the shift register.
- We cannot guarentee the proper functioning of the circuit if you opt to use the esp32's on board 5v pin, and personally I do not recommend to use it for such an application that could be current intensive.
- Make sure to use a power supply that can deliver enough amperage if you are using many motors at once, although the L293D's max tolerance is ~1A per IC.
- The shield should work fine with the 3.3v logic levels of esp32, if it doesnt, cross check all your connections.
- The code is written according to the connections made in the below diagram.

![circuit diagram](https://github.com/user-attachments/assets/91a676e2-481f-4c19-b41e-186fa66f2386)