/****************************************************************************
 * Class for interfacing with a Maxim DS1803 digital potentiometer via I2C
 * 
 * Written for Mbed OS 6 by John M. Larkin (March 2022)
 * 
 * Released under the MIT License (http://opensource.org/licenses/MIT).
 * 	
 * The MIT License (MIT)
 * Copyright (c) 2022 John M. Larkin
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 * associated documentation files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT 
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *******************************************************************************/
#ifndef DS1803_H
#define DS1803_H
#include <mbed.h>

class DS1803
{
public:
  DS1803(I2C* i2c, char three_bit_address);
  bool write(int pot, char value);
  bool write_both(char value);
  int read(int pot);
  bool read_both(char values[]);

private:
  uint8_t _addr;  // shifted I2C address for commands (from 7 bits to 8 bits)
  I2C* _i2c;      // Potentially shared connection to user's chosen I2C hardware
};

#endif