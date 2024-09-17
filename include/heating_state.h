#ifndef HEATING_STATE_H

#include <state.h>
#define HEATING_STATE_H

class Heating_state : public State {
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

  String name = "Heating";
};

#endif // !HEATING_STATE_H
