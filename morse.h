/*
  Morse.h - A library form morse output
*/

#ifndef Morse_h
#define Morse_h
#include "Arduino.h"

class Morse
{
public:
  Morse(int pin, int time);
  void sendc(char c);
  void sends(char *str);
  void on();
  void off();
private:
  int _pin;
  int _time;
};

Morse::Morse(int pin, int time)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _time = time;
}

char *morse_pattern[] = {
  "._", "_...", "_._.", "_..", ".", ".._.", "__.",
  "....", "..", ".___", "_._", "._..", "__",
  "_.", "___", ".__.", "__._", "._.", "...", "_",
  ".._", "..._", ".__", "_.._", "__._", "__.."
};

void Morse::sendc(char c)
{
  int i;
  if (c == ' ') {
    delay(_time * 3);
  } else {
    char *pattern = morse_pattern[c - 'A'];
    for(i=0; i<strlen(pattern); i++) {
      on();
      delay(_time * (pattern[i] == '.' ? 1 : 3));
      off();
      if (i != strlen(pattern) - 1) {
        delay(_time * 1);
      }
    }
  }
}

void Morse::sends(char *str)
{
  int i;

  for (i=0; i<strlen(str); i++) {
    sendc(str[i]);
    if (i != strlen(str) - 1) {
      delay(_time * 3);
    }
  }
}

void Morse::on() {
  digitalWrite(_pin, HIGH);
}

void Morse::off() {
  digitalWrite(_pin, LOW);
}
#endif
