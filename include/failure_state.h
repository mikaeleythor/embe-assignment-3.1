#ifndef FAILURE_STATE_H

#include <state.h>

#define FAILURE_STATE_H

class Failure_state : public State {
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

  String name = "Failure";
};

#endif // !FAILURE_STATE_H
