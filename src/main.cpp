#include <Arduino.h>
#include <digital_out.h>
#include <util/delay.h>

// State macros
#define IDLE 1
#define HEATING 2
#define FAILURE 3
#define COOLER_STARTUP 4
#define COOLER_READY 5
#define COOLER_RUNNING 6

// Transition macros
#define TOO_COOL 'c'
#define TOO_HOT 'h'
#define OK 'o'
#define FAIL 'f'
#define COMPRESSOR_RUNNING 'x'
#define FAN_RUNNING 'y'
#define CLEARED 'z'

int state = IDLE;

void set_state(int new_state) {
  String message =
      "State changed from " + String(state) + " to " + String(new_state);
  Serial.println(message);
  state = new_state;
}

int main() {
  init();
  int command = 0;
  Digital_out led(5);

  Serial.begin(9600); // Open serial port with baud rate 9600
  Serial.flush();

  while (1) {
    if (Serial.available() > 0) {
      // read the incoming byte:
      led.toggle();
      command = Serial.read();

      switch (state) {
      case IDLE:
        if (command == TOO_HOT) {
          set_state(COOLER_STARTUP);
          _delay_ms(2000); // Compressor running
          set_state(COOLER_READY);
          _delay_ms(2000); // Fan running
          set_state(COOLER_RUNNING);
        } else if (command == TOO_COOL)
          set_state(HEATING);
        break;
      case HEATING:
        if (command == OK) {
          set_state(IDLE);
        } else if (command == FAIL) {
          set_state(FAILURE);
        }
        break;
      case FAILURE:
        if (command == CLEARED) {
          set_state(IDLE);
        }
        break;
      case COOLER_RUNNING:
        if (command == OK) {
          set_state(IDLE);
        } else if (command == FAIL) {
          set_state(FAILURE);
        }
        break;
      }
    }
  }
}
