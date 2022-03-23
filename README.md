# DS1803

Mbed OS library for interfacing to Maxim Integrated's DS1803 series of digital potentiometers.

These devices can be controlled via I^2^C serial communication. The 7-bit address has the form 0b0101(A2)(A1)(A0) where the values of A0, A1, and A2 are set by the corresponding pins on the device.

The DS1803 family can operate in standard mode (100 kHz) or fast mode (400 kHz).
