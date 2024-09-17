#include <Arduino.h>
#include <context.h>
#include <idle_state.h>
#include <stdlib.h>
//
// Transition macros
#define TOO_COOL 'c'
#define TOO_HOT 'h'
#define OK 'o'
#define FAIL 'f'
#define COMPRESSOR_RUNNING 'x'
#define FAN_RUNNING 'y'
#define CLEARED 'z'

Context *context;
int command = 0;

int main() {
  init();
  Serial.begin(9600); // Open serial port with baud rate 9600
  Serial.flush();
  context = new Context(new Idle_state);

  while (1) {
    if (Serial.available() > 0) {
      command = Serial.read();
      // Serial.println(command);

      if (command == TOO_COOL)
        context->too_cold();
      if (command == TOO_HOT)
        context->too_hot();
      if (command == OK)
        context->ok();
      if (command == FAIL)
        context->failure();
      if (command == COMPRESSOR_RUNNING)
        context->compressor_running();
      if (command == FAN_RUNNING)
        context->fan_running();
      if (command == CLEARED)
        context->cleared();
    }
  }
  delete context;
}
