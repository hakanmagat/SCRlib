#include <SCRlib.h>

scr gLcd (30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42);

void setup() {
  gLcd.begin();
  gLcd.Print("Hello, World!");
}

void loop() {

}
