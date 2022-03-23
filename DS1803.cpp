#include <mbed.h>
#include "DS1803.h"

#define DS1803_BASE_ADDR 0b0101000
#define POT_0_REG_ADDR 0b10101001
#define POT_1_REG_ADDR 0b10101010
#define POT_BOTH_REG_ADDR 0b10101111

DS1803::DS1803(I2C* i2c, char three_bit_address) {
  _i2c = i2c;
  _addr = (DS1803_BASE_ADDR | three_bit_address) << 1;
}

bool DS1803::write(int pot, char value) {
  int nak;
  char cmd[2];
  switch (pot) {
    case 0: cmd[0] = POT_0_REG_ADDR; break;
    case 1: cmd[0] = POT_1_REG_ADDR; break;
    default: return false;
  }
  cmd[1] = value;
  _i2c->lock();
  nak = _i2c->write(_addr, cmd, 2);
  _i2c->unlock();
  return !nak;
}

bool DS1803::write_both(char value) {
  int nak;
  char cmd[2];
  cmd[0] = POT_BOTH_REG_ADDR;
  cmd[1] = value;
  _i2c->lock();
  nak = _i2c->write(_addr, cmd, 2);
  _i2c->unlock();
  return !nak;
}

bool DS1803::read_both(char values[]) {
  int nak;
  _i2c->lock();
  nak = _i2c->read(_addr, values, 2);
  _i2c->unlock();
  return !nak;
}

int DS1803::read(int pot) {
  char values[2];
  bool success = read_both(values);
  if (success) {
    switch (pot) {
      case 0: return values[0];
      case 1: return values[1];
      default: return false;
    }
  } else return false;
}