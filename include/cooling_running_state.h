#ifndef COOLING_RUNNING_STATE_H

#include <state.h>

#define COOLING_RUNNING_STATE_H

class Cooling_running_state : public State {
  void on_do() override;

  void on_entry() override;

  void on_exit() override;

  void on_ok() override;

  void on_failure() override;

  void on_too_hot() override;

  void on_too_cold() override;

  void on_compressor_running() override;

  void on_fan_running() override;

  void on_cleared() override;

  String get_name() override;

  String name = "Cooling running";
};

#endif // !COOLING_RUNNING_STATE_H
